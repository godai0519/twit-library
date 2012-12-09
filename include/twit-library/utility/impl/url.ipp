#ifndef TWIT_LIB_UTILITY_URL_IPP
#define TWIT_LIB_UTILITY_URL_IPP

#include <string>
#include <boost/spirit/include/qi.hpp>
#include "../url.hpp"

namespace oauth{
namespace utility{    

uri_parser::uri_parser()
{
}
uri_parser::uri_parser(const std::string& uri)
{
    set_uri(uri);
}
uri_parser::~uri_parser()
{
}

bool uri_parser::set_uri(const std::string& uri)
{
    namespace qi = boost::spirit::qi;
            
    uri_ = uri;
    std::string::const_iterator it = uri_.cbegin();
    bool success = qi::parse(it,uri_.cend(),+(qi::char_ - ":") >> qi::lit(":") >> *qi::lit("/") >> +(qi::char_ - "/") >> +(qi::char_ - "?"),scheme_,host_,path_);

    return success && it == uri_.cend();
}
    
const std::string uri_parser::get_uri() const
{
    return uri_;
}
const std::string uri_parser::get_scheme() const
{
    return scheme_;
}
const std::string uri_parser::get_host() const
{
    return host_;
}
const std::string uri_parser::get_path() const
{
    return path_;
}

} // namespace utility
} // namespace oauth

#endif
