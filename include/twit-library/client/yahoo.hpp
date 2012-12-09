//
// yahoo.hpp
// ~~~~~~~~~~
//
// Yahoo URL Listとその実用化
//

#ifndef TWIT_LIB_YAHOO_HPP
#define TWIT_LIB_YAHOO_HPP

#include <string>
#include "common_v1.hpp"

namespace oauth{

struct yahoo_set{
    static std::string get_host();
    static std::string get_request_method();
    static std::string get_request_path();
    static std::string get_access_method();
    static std::string get_access_path();
};

typedef oauth::client::common_v1<oauth::yahoo_set> yahoo;

} // namespace oauth

#ifdef BOOSTCONNECT_LIB_BUILD
#include "impl/yahoo.ipp"
#endif

#endif
