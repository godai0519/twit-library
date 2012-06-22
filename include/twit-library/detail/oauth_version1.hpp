//
// oauth_version1.hpp
// ~~~~~~~~~~
//
// OAuth Version1ópägí£
//

#ifndef TWIT_LIB_DETAIL_OAUTH_VER_1
#define TWIT_LIB_DETAIL_OAUTH_VER_1

#include <map>
#include <boost/assign.hpp>
#include <boost/noncopyable.hpp>
#include <boostconnect/client.hpp>
#include "../keys/key_version1.hpp"
#include "../utility/authentication.hpp"

namespace oauth{
namespace detail{

class oauth_version1 : boost::noncopyable{
public:
  typedef std::map<std::string,std::string> Param_Type;
  typedef oauth::keys::key_version1 Key_Type;
  oauth_version1(boost::shared_ptr<Key_Type> &key,boost::shared_ptr<bstcon::client> &client)
  {
    key_ = key;
    client_ = client;
  }
  virtual ~oauth_version1(){}

  virtual void get_request_token(const std::string& method,const std::string& uri)
  {
    oauth::utility::uri_parser uri_parsed(uri);

    Param_Type params = boost::assign::map_list_of
      ("oauth_consumer_key",key_->get_consumer_key())
      ("oauth_signature_method","HMAC-SHA1")
      ("oauth_timestamp",oauth::utility::get_timestamp())
      ("oauth_nonce",oauth::utility::nonce<std::string>())
      ("oauth_callback","oob")
      ("oauth_version","1.0");
    
    boost::assign::insert(params)
      ("oauth_signature",signature_(method,uri,key_->get_signature_key(),params));

    boost::shared_ptr<boost::asio::streambuf> buf(new boost::asio::streambuf());
    {
      std::ostream os(buf.get());
      os << method << " " << uri_parsed.get_path() << " HTTP/1.1" << "\r\n";
      os << "Host: " << uri_parsed.get_host() << "\r\n";
      os << "Content-Type: " << "application/x-www-form-urlencoded" << "\r\n";
      os << "Authorization: " << "OAuth " << oauth::utility::get_authorization_field(params) << "\r\n\r\n";
    }

    boost::system::error_code ec;
    const boost::shared_ptr<bstcon::response> response = 
      client_->operator() (uri_parsed.get_host(),buf,ec,
        boost::bind(&oauth_version1::set_access_token,this,_1,_2));

    //const int status_code = response->status_code;
    //if(200 <= status_code && status_code < 300)
    //{
    //  const Param_Type parsed = oauth::utility::parse_urlencoded(response->body);
    //  key_->set_access_token (oauth::utility::url_decode(parsed.at("oauth_token")));
    //  key_->set_access_secret(oauth::utility::url_decode(parsed.at("oauth_token_secret")));
    //}

    return;
  }

  virtual void get_access_token(const std::string& method,const std::string& uri,const std::string& pin_code)
  {
    oauth::utility::uri_parser uri_parsed(uri);

    Param_Type params = boost::assign::map_list_of
      ("oauth_consumer_key",key_->get_consumer_key())
      ("oauth_token",key_->get_access_token())
      ("oauth_signature_method","HMAC-SHA1")
      ("oauth_timestamp",oauth::utility::get_timestamp())
      ("oauth_verifier",pin_code)
      ("oauth_nonce",oauth::utility::nonce<std::string>())
      ("oauth_version","1.0");
    
    boost::assign::insert(params)
      ("oauth_signature",signature_(method,uri,key_->get_signature_key(),params));

    boost::shared_ptr<boost::asio::streambuf> buf(new boost::asio::streambuf());
    {
      std::ostream os(buf.get());
      os << method << " " << uri_parsed.get_path() << " HTTP/1.1" << "\r\n";
      os << "Host: " << uri_parsed.get_host() << "\r\n";
      os << "Content-Type: " << "application/x-www-form-urlencoded" << "\r\n";
      os << "Authorization: " << "OAuth " << oauth::utility::get_authorization_field(params) << "\r\n\r\n";
    }

    boost::system::error_code ec;
    const boost::shared_ptr<bstcon::response> response = client_->operator() (uri_parsed.get_host(),buf,
        boost::bind(&oauth_version1::set_access_token,this,_1,_2));

    return;
  }

  virtual const boost::shared_ptr<bstcon::response> request_urlencoded(const std::string& method,const std::string& uri,const Param_Type& params)
  {
    oauth::utility::uri_parser uri_parsed(uri);

    Param_Type header_params = boost::assign::map_list_of
      ("oauth_consumer_key",key_->get_consumer_key())
      ("oauth_token",key_->get_access_token())
      ("oauth_signature_method","HMAC-SHA1")
      ("oauth_timestamp",oauth::utility::get_timestamp())
      ("oauth_nonce",oauth::utility::nonce<std::string>())
      ("oauth_version","1.0");

    Param_Type signature_param = params;
    signature_param.insert(header_params.cbegin(),header_params.cend());

    boost::assign::insert(header_params)
      ("oauth_signature",signature_(method,uri_parsed.get_scheme()+"://"+uri_parsed.get_host()+uri_parsed.get_path(),key_->get_signature_key(),signature_param));

    const std::string body_string = (method!="GET") ? oauth::utility::get_urlencoded(params) : "";
    boost::shared_ptr<boost::asio::streambuf> buf(new boost::asio::streambuf());
    {
      std::ostream os(buf.get());
      os << method << " " << uri_parsed.get_path() << ((method=="GET") ? "?"+oauth::utility::get_urlencoded(params) : "") << " HTTP/1.1" << "\r\n";
      os << "Host: " << uri_parsed.get_host() << "\r\n";
      os << "Content-Length: " << body_string.size() << "\r\n";
      os << "Content-Type: " << "application/x-www-form-urlencoded" << "\r\n";
      os << "Authorization: " << "OAuth " << oauth::utility::get_authorization_field(header_params) << "\r\n\r\n";
      os << body_string;
    }

    boost::system::error_code ec;
    const boost::shared_ptr<bstcon::response> response =  client_->operator() (uri_parsed.get_host(),buf,ec);

    return response;
  }

protected:
  void set_access_token(const boost::shared_ptr<bstcon::response> response,const boost::system::error_code& ec)
  {
    if(ec) return;
    if(200 <= response->status_code && response->status_code < 300)
    {
      const Param_Type parsed = oauth::utility::parse_urlencoded(response->body);
      key_->set_access_token (oauth::utility::url_decode(parsed.at("oauth_token")));
      key_->set_access_secret(oauth::utility::url_decode(parsed.at("oauth_token_secret")));
    }
    return;
  }

  boost::shared_ptr<Key_Type> key_;
  boost::shared_ptr<bstcon::client> client_;
  oauth::utility::signature<oauth::utility::hmac_sha1> signature_;
};

} // namespace detail
} // namespace oauth

#endif
