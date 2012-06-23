//
// twitter.hpp
// ~~~~~~~~~~
//
// Twitter URL List‚Æ‚»‚ÌŽÀ—p‰»
//

#ifndef TWIT_LIB_TWITTER
#define TWIT_LIB_TWITTER

#include "common_v1.hpp"

namespace oauth{

struct twitter_set{
  static std::string get_host()
  {
    return "api.twitter.com";
  }
  static std::string get_request_method()
  {
    return "POST";
  }
  static std::string get_request_path()
  {
    return "/oauth/request_token";
  }
  static std::string get_access_method()
  {
    return "POST";
  }
  static std::string get_access_path()
  {
    return "/oauth/access_token";
  }
};

class twitter : public oauth::client::common_v1<oauth::twitter_set>{
  typedef oauth::client::common_v1<oauth::twitter_set> MyParent;
  typedef oauth::twitter_set URL_Set;
public:
  twitter(boost::shared_ptr<Key_Type> &key,boost::shared_ptr<bstcon::client> &client): MyParent(key,client){}
  virtual ~twitter(){}

#ifdef USE_SSL_BOOSTCONNECT
  void get_xauth_token(const std::string& id, const std::string& password)
  {
    Param_Type params = boost::assign::map_list_of
      ("oauth_consumer_key",key_->get_consumer_key())
      ("oauth_signature_method","HMAC-SHA1")
      ("oauth_timestamp",oauth::utility::get_timestamp())
      ("oauth_nonce",oauth::utility::nonce<std::string>())
      ("oauth_callback","oob")
      ("oauth_version","1.0")
      ("x_auth_password",password)
      ("x_auth_username",id)
      ("x_auth_mode","client_auth");
    
    Param_Type xauth_params = boost::assign::map_list_of
      ("x_auth_password",password)
      ("x_auth_username",id)
      ("x_auth_mode","client_auth");

    boost::assign::insert(params)
      ("oauth_signature",signature_(URL_Set::get_access_method(),client_->service_protocol()+"://"+URL_Set::get_host()+URL_Set::get_access_path(),key_->get_signature_key(),params));

    params.erase("x_auth_password");
    params.erase("x_auth_username");
    params.erase("x_auth_mode");

    const std::string body = oauth::utility::get_urlencoded(xauth_params);

    boost::shared_ptr<boost::asio::streambuf> buf(new boost::asio::streambuf());
    {
      std::ostream os(buf.get());
      os << URL_Set::get_access_method() << " " << URL_Set::get_access_path() << " HTTP/1.1" << "\r\n";
      os << "Host: " << URL_Set::get_host() << "\r\n";
      os << "Content-Type: " << "application/x-www-form-urlencoded" << "\r\n";
      os << "Content-Length: " << body.length() << "\r\n";
      os << "Authorization: " << "OAuth " << oauth::utility::get_authorization_field(params) << "\r\n\r\n";
      os << body;
    }

    client_->operator() (URL_Set::get_host(),buf,
      boost::bind(&twitter::set_access_token,this,_1,_2));
    
    return;
  }
#endif

};

} // namespace oauth

#endif
