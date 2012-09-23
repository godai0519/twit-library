//
// v1.hpp
// ~~~~~~~~~~
//
// OAuth1.0用，定義リスト
//

#ifndef TWIT_LIB_COMMON_V1
#define TWIT_LIB_COMMON_V1

#include "../detail/oauth_version1.hpp"

namespace oauth{
namespace client{

template<class URL_Set>
class common_v1: public oauth::detail::oauth_version1{
public:
    common_v1(boost::shared_ptr<Key_Type> &key,boost::shared_ptr<bstcon::client> &client)
        : oauth_version1(key,client)
    {
    }
    virtual ~common_v1(){}
    
    virtual void get_request_token()
    {
        oauth_version1::get_request_token(
            URL_Set::get_request_method(),
            client_->service_protocol()+"://"+URL_Set::get_host()+URL_Set::get_request_path()
            );
    }

    virtual void get_access_token(const std::string& pin_code)
    {
        oauth_version1::get_access_token(
            URL_Set::get_access_method(),
            client_->service_protocol()+"://"+URL_Set::get_host()+URL_Set::get_access_path(),
            pin_code
            );
    }
};

} // namespace client
} // namespace oauth

#endif
