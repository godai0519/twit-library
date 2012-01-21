//
// authentication.hpp
// ~~~~~~~~~~
//
// 認証系機構のutility総集
//

#ifndef TWIT_LIB_UTILITY_AUTHENTICATION
#define TWIT_LIB_UTILITY_AUTHENTICATION

#include <map>
#include <string>
#include <boost/tuple/tuple.hpp>
#include <boost/foreach.hpp>
#include <boost/format.hpp>
#include <boost/random.hpp>
#include <boost/spirit/include/phoenix.hpp>
#include <boost/spirit/include/qi.hpp>
#include <boost/fusion/include/std_pair.hpp>
#include <boost/uuid/random_generator.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <openssl/bio.h>
#include <openssl/hmac.h>
#include <openssl/sha.h>

namespace oauth{
namespace utility{

const int hex_to_dec(const std::string& hex)
{
	namespace qi = boost::spirit::qi;

	int dec=0;
	qi::parse(hex.cbegin(),hex.cend(),qi::hex,dec);

	return dec;

}
const std::string url_encode(const std::string& base_string)
{
	std::string encoded="";
	for(std::string::const_iterator it = base_string.begin();it!=base_string.end();++it)
	{
		if((0x30<=*it && *it<=0x39) || (0x41<=*it && *it<=0x5A) || (0x61<=*it && *it<= 0x7A) || *it==0x2D || *it==0x2E || *it==0x5F || *it==0x7E)
			encoded.append(it,it+1);
		else
			encoded.append((boost::format("%%%02X") % (int)*it).str());
	}
	return encoded;
}

// +→' 'にはしない
const std::string url_decode(const std::string& base_string)
{
	std::string decoded="";
	for(std::string::const_iterator it = base_string.begin();it!=base_string.end();++it)
	{
		if(*it == '%') //%xx
		{
			decoded += (char)hex_to_dec(std::string(it+1,it+3));
			it+=2;
		}
		else decoded += *it;
	}
	return decoded;
}

// ' '→+にはしない
const std::string base64_encode(const std::string& data)
{	
	//フィルタ作成
	BIO *encoder = BIO_new(BIO_f_base64());
	BIO *bmem = BIO_new(BIO_s_mem());
	encoder = BIO_push(encoder,bmem);
	BIO_write(encoder,data.c_str(),data.length());
	BIO_flush(encoder);

	//結果をここに
	BUF_MEM *bptr;
	BIO_get_mem_ptr(encoder,&bptr);
  
	//charに移行処理
	char *buff = (char *)malloc(bptr->length);
	memcpy(buff, bptr->data, bptr->length-1);
	buff[bptr->length-1] = 0;
  
	//クリア
	BIO_free_all(encoder);

	return static_cast<std::string>(buff);
}

const std::string hmac_sha1_encode(const std::string& key,const std::string& data)
{
	unsigned char res[SHA_DIGEST_LENGTH + 1];
	std::size_t  reslen;
	std::size_t  keylen = key.length();
	std::size_t  datalen = data.length();

	//これで計算
	HMAC (EVP_sha1(), (const unsigned char*)key.c_str(), keylen, (const unsigned char*)data.c_str(), datalen, res, &reslen);

	std::string result((char*)res);
	result.erase(reslen);

	return result;
}

const std::string get_timestamp()
{
	return (boost::format("%1%") % static_cast<unsigned long>(std::time(0))).str();
}
/*
//boost::uuids::random_generator参考
template <typename UniformRandomNumberGenerator>
class basic_get_nonce{
private:
public:
	basic_get_nonce()
	{}
}
//
//typedef basic_get_nonce<boost::mt19937> get_nonce;*/
//
//
//	
//	boost::uniform_int<unsigned long> range(
//		(std::numeric_limits<unsigned long>::min)(),
//		(std::numeric_limits<unsigned long>::max)()
//		);
//	boost::variate_generator<
//		boost::mt19937&,boost::uniform_int<unsigned long>
//	> rand(gen,range);
	
template <class UniformRandomNumberGenerator>
const std::string get_nonce(UniformRandomNumberGenerator& gen)
{
	const unsigned char nonce_base[] = 
	{
		'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
		'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
		'1','2','3','4','5','6','7','8','9','0'
	};
	boost::uniform_int<unsigned long> range(0,62-1);
	boost::variate_generator<
		boost::mt19937&,boost::uniform_int<unsigned long>
	> rand(gen,range);
	
	unsigned int nonce_length = 0;
	while(nonce_length<12) nonce_length = rand();

	std::string nonce="";
	for(unsigned int i=0;i<nonce_length;++i)	nonce += nonce_base[rand()];
	
	return nonce;
}
const std::string get_nonce()
{
	return get_nonce(boost::mt19937(static_cast<unsigned long>(std::time(0))));
}


//Karma使える？のかな
const std::string get_signature(const std::string& method,const std::string& uri,const std::string& key,const std::map<std::string,std::string>& values)
{
	typedef std::pair<const std::string,std::string> Value_Pair;

	std::string base_string;
	BOOST_FOREACH(const Value_Pair& p,values)
		base_string += url_encode(p.first) + "=" + url_encode(p.second) + "&";

	base_string.erase(base_string.size()-1);
	base_string = method + "&" + url_encode(uri) + "&" + url_encode(base_string);

	return base64_encode(hmac_sha1_encode(key,base_string));
}

//get_authorization_fieldとget_urlencodedをまとめられそう．
const std::string get_authorization_field(const std::map<std::string,std::string>& values)
{
	typedef std::pair<const std::string,std::string> Value_Pair;

	std::string field_string = "";
	BOOST_FOREACH(const Value_Pair& p,values)
		field_string += (url_encode(p.first) + "=\"" + url_encode(p.second) + "\",");

	if(!field_string.empty()) field_string.erase(field_string.size()-1);
	return field_string;
}

const std::string get_urlencoded(const std::map<std::string,std::string>& values)
{
	typedef std::pair<const std::string,std::string> Value_Pair;
	
	std::string field_string = "";
	BOOST_FOREACH(const Value_Pair& p,values)
		field_string += (url_encode(p.first) + "=" + url_encode(p.second) + "&");

	if(!field_string.empty()) field_string.erase(field_string.size()-1);
	return field_string;
}

const std::map<std::string,std::string> parse_urlencoded(const std::string& encoded)
{
	namespace qi = boost::spirit::qi;

	const auto value_rule = ((+(qi::char_ - "&") >> -qi::lit("&")));
	const auto pair_rule =
		+(qi::char_ - "=") >> "=" >> value_rule;
	const auto rule = 
		*pair_rule;
	
	auto it = encoded.cbegin();
	std::map<std::string,std::string> parsed;
	qi::parse(it,encoded.cend(),rule,parsed);

	return parsed;
}

const boost::tuple<std::string,std::string,std::string> get_scheme_host_path(const std::string& uri)
{
	namespace qi = boost::spirit::qi;
	
	const auto rule = 
		+(qi::char_ - ":") >> qi::lit(":") >> *qi::lit("/") >> +(qi::char_ - "/") >> +(qi::char_ - "?");

	std::string::const_iterator it = uri.cbegin();
	std::string host,path,params="";
	qi::parse(it,uri.cend(),rule,host,path,params);

	return boost::tuple<std::string,std::string,std::string>(host,path,params);
}

const std::string get_scheme(const std::string& uri)
{
	return get_scheme_host_path(uri).get<0>();
}
const std::string get_host(const std::string& uri)
{
	return get_scheme_host_path(uri).get<1>();
}
const std::string get_path(const std::string& uri)
{
	return get_scheme_host_path(uri).get<2>();
}

} // namespace utility
} // namespace oauth

#endif
