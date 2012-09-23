//
// yahoo.hpp
// ~~~~~~~~~~
//
// Yahoo URL List‚Æ‚»‚ÌŽÀ—p‰»
//

#ifndef TWIT_LIB_YAHOO
#define TWIT_LIB_YAHOO

#include "common_v1.hpp"

namespace oauth{

struct yahoo_set{
    static std::string get_host()
    {
        return "auth.login.yahoo.co.jp";
    }
    static std::string get_request_method()
    {
        return "POST";
    }
    static std::string get_request_path()
    {
        return "/oauth/v2/get_request_token";
    }
    static std::string get_access_method()
    {
        return "POST";
    }
    static std::string get_access_path()
    {
        return "/oauth/v2/get_token";
    }
};

typedef oauth::client::common_v1<oauth::yahoo_set> yahoo;

} // namespace oauth

#endif
