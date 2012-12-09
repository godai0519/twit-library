#ifndef TWIT_LIB_YAHOO_IPP
#define TWIT_LIB_YAHOO_IPP

#include <string>
#include "../common_v1.hpp"
#include "../yahoo.hpp"

namespace oauth{

std::string yahoo_set::get_host()
{
    return "auth.login.yahoo.co.jp";
}
std::string yahoo_set::get_request_method()
{
    return "POST";
}
std::string yahoo_set::get_request_path()
{
    return "/oauth/v2/get_request_token";
}
std::string yahoo_set::get_access_method()
{
    return "POST";
}
std::string yahoo_set::get_access_path()
{
    return "/oauth/v2/get_token";
}

} // namespace oauth

#endif
