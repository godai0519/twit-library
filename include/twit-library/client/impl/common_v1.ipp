#ifndef TWIT_LIB_COMMON_V1_IPP
#define TWIT_LIB_COMMON_V1_IPP

#include <boost/shared_ptr.hpp>
#include "../common_v1.hpp"
#include "../../detail/oauth_version1.hpp"

namespace oauth{
namespace client{

template<class URL_Set>
common_v1<URL_Set>::common_v1(const boost::shared_ptr<Key_Type>& key, const boost::shared_ptr<bstcon::client>& client)
    : oauth_version1(key, client)
{
}
template<class URL_Set>
common_v1<URL_Set>::~common_v1()
{
}
    
template<class URL_Set>
void common_v1<URL_Set>::get_request_token()
{
    oauth_version1::get_request_token(
        URL_Set::get_request_method(),
        client_->service_protocol() + "://" + URL_Set::get_host() + URL_Set::get_request_path()
        );
}

template<class URL_Set>
void common_v1<URL_Set>::get_access_token(const std::string& pin_code)
{
    oauth_version1::get_access_token(
        URL_Set::get_access_method(),
        client_->service_protocol() + "://" + URL_Set::get_host() + URL_Set::get_access_path(),
        pin_code
        );
}

} // namespace client
} // namespace oauth

#endif
