//
// v1.hpp
// ~~~~~~~~~~
//
// OAuth1.0用，定義リスト
//

#ifndef TWIT_LIB_COMMON_V1
#define TWIT_LIB_COMMON_V1

#include "../detail/client_base.hpp"
#include "../version/v1.hpp"

namespace oauth{
//namespace client{
  
template<class URL_Set>
class common_v1: public oauth::client<oauth::version::v1>{
public:
  typedef oauth::version::v1           OAuth_Version;
  typedef oauth::client<OAuth_Version>  OAuth_Client;
  typedef OAuth_Version::OAuth_Type    OAuth_Type;
  typedef OAuth_Version::Key_Type      Key_Type;
  
public:
  common_v1(boost::shared_ptr<Key_Type> &key,boost::shared_ptr<bstcon::client> &client)
    : OAuth_Client(key,client)
  {
  }
  virtual ~common_v1(){}
  
  virtual void get_request_token()
  {
    OAuth_Client::get_request_token(
      URL_Set::get_request_method(),
      client_->service_protocol()+"://"+URL_Set::get_host()+URL_Set::get_request_path()
      );
  }

  virtual void get_access_token(const std::string& pin_code)
  {
    OAuth_Client::get_access_token(
      URL_Set::get_access_method(),
      client_->service_protocol()+"://"+URL_Set::get_host()+URL_Set::get_access_path(),
      pin_code
      );
  }

  virtual const boost::shared_ptr<bstcon::response> request_urlencoded(const std::string& method,const std::string& uri,const std::map<std::string,std::string>& params)
  {
    return OAuth_Client::request_urlencoded(
      method,
      uri,
      params
      );
  }


  
};

//} // namespace version
} // namespace oauth

#endif
