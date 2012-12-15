//
// url.hpp
// ~~~~~~~~~~
//
// url
//

#ifndef TWIT_LIB_UTILITY_URL_HPP
#define TWIT_LIB_UTILITY_URL_HPP

#include <string>

namespace oauth{
namespace utility{    

class uri_parser{
    std::string uri_;
    std::string scheme_;
    std::string host_;
    std::string path_;

public:
    uri_parser();
    uri_parser(const std::string& uri);
    virtual ~uri_parser();

    bool set_uri(const std::string& uri);
    
    const std::string get_uri() const;
    const std::string get_scheme() const;
    const std::string get_host() const;
    const std::string get_path() const;
};

} // namespace utility
} // namespace oauth

#ifdef TWIT_LIB_BUILD
#include "impl/url.ipp"
#endif

#endif
