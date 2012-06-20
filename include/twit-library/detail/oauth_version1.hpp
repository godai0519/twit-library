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
    Param_Type params = boost::assign::map_list_of
      ("oauth_consumer_key",key_->get_consumer_key())
      ("oauth_signature_method","HMAC-SHA1")
      ("oauth_timestamp",oauth::utility::get_timestamp())
      ("oauth_nonce",oauth::utility::get_nonce())
      ("oauth_callback","oob")
      ("oauth_version","1.0");
    
    boost::assign::insert(params)
      ("oauth_signature",oauth::utility::get_signature(method,uri,key_->get_signature_key(),params));

    boost::shared_ptr<boost::asio::streambuf> buf(new boost::asio::streambuf());
    {
      std::ostream os(buf.get());
      os << method << " " << oauth::utility::get_path(uri) << " HTTP/1.1" << "\r\n";
      os << "Host: " << oauth::utility::get_host(uri) << "\r\n";
      os << "Content-Type: " << "application/x-www-form-urlencoded" << "\r\n";
      os << "Authorization: " << "OAuth " << oauth::utility::get_authorization_field(params) << "\r\n\r\n";
    }

    boost::system::error_code ec;
    const boost::shared_ptr<bstcon::response> response = 
      client_->operator() (oauth::utility::get_host(uri),buf,ec,
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
    Param_Type params = boost::assign::map_list_of
      ("oauth_consumer_key",key_->get_consumer_key())
      ("oauth_token",key_->get_access_token())
      ("oauth_signature_method","HMAC-SHA1")
      ("oauth_timestamp",oauth::utility::get_timestamp())
      ("oauth_verifier",pin_code)
      ("oauth_nonce",oauth::utility::get_nonce())
      ("oauth_version","1.0");
    
    boost::assign::insert(params)
      ("oauth_signature",oauth::utility::get_signature(method,uri,key_->get_signature_key(),params));

    boost::shared_ptr<boost::asio::streambuf> buf(new boost::asio::streambuf());
    {
      std::ostream os(buf.get());
      os << method << " " << oauth::utility::get_path(uri) << " HTTP/1.1" << "\r\n";
      os << "Host: " << oauth::utility::get_host(uri) << "\r\n";
      os << "Content-Type: " << "application/x-www-form-urlencoded" << "\r\n";
      os << "Authorization: " << "OAuth " << oauth::utility::get_authorization_field(params) << "\r\n\r\n";
    }

    boost::system::error_code ec;
    const boost::shared_ptr<bstcon::response> response = client_->operator() (oauth::utility::get_host(uri),buf,
        boost::bind(&oauth_version1::set_access_token,this,_1,_2));

    return;
  }

  virtual const boost::shared_ptr<bstcon::response> request_urlencoded(const std::string& method,const std::string& uri,const Param_Type& params)
  {
    const auto parsed_uri = oauth::utility::get_scheme_host_path(uri);

    Param_Type header_params = boost::assign::map_list_of
      ("oauth_consumer_key",key_->get_consumer_key())
      ("oauth_token",key_->get_access_token())
      ("oauth_signature_method","HMAC-SHA1")
      ("oauth_timestamp",oauth::utility::get_timestamp())
      ("oauth_nonce",oauth::utility::get_nonce())
      ("oauth_version","1.0");

    Param_Type signature_param = params;
    signature_param.insert(header_params.cbegin(),header_params.cend());

    boost::assign::insert(header_params)
      ("oauth_signature",oauth::utility::get_signature(method,parsed_uri.get<0>()+"://"+parsed_uri.get<1>()+parsed_uri.get<2>(),key_->get_signature_key(),signature_param));

    const std::string body_string = (method!="GET") ? oauth::utility::get_urlencoded(params) : "";
    boost::shared_ptr<boost::asio::streambuf> buf(new boost::asio::streambuf());
    {
      std::ostream os(buf.get());
      os << method << " " << parsed_uri.get<2>() << ((method=="GET") ? "?"+oauth::utility::get_urlencoded(params) : "") << " HTTP/1.1" << "\r\n";
      os << "Host: " << parsed_uri.get<1>() << "\r\n";
      os << "Content-Length: " << body_string.size() << "\r\n";
      os << "Content-Type: " << "application/x-www-form-urlencoded" << "\r\n";
      os << "Authorization: " << "OAuth " << oauth::utility::get_authorization_field(header_params) << "\r\n\r\n";
      os << body_string;
    }

    boost::system::error_code ec;
    const boost::shared_ptr<bstcon::response> response =  client_->operator() (parsed_uri.get<1>(),buf,ec);

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
};

} // namespace detail
} // namespace oauth

#endif
