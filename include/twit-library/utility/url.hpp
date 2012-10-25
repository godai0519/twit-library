//
// url.hpp
// ~~~~~~~~~~
//
// url
//

#ifndef TWIT_LIB_UTILITY_URL
#define TWIT_LIB_UTILITY_URL

#include <string>
#include <boost/spirit/include/qi.hpp>

namespace oauth{
namespace utility{    

class uri_parser{
    std::string uri_;
    std::string scheme_;
    std::string host_;
    std::string path_;

public:
    uri_parser(){}
    uri_parser(const std::string& uri){set_uri(uri);}
    virtual ~uri_parser(){}

    bool set_uri(const std::string& uri)
    {
        namespace qi = boost::spirit::qi;
            
        uri_ = uri;
        std::string::const_iterator it = uri_.cbegin();
        bool success = qi::parse(it,uri_.cend(),+(qi::char_ - ":") >> qi::lit(":") >> *qi::lit("/") >> +(qi::char_ - "/") >> +(qi::char_ - "?"),scheme_,host_,path_);

        return success && it == uri_.cend();
    }
    
    const std::string get_uri() const
    {
        return uri_;
    }
    const std::string get_scheme() const
    {
        return scheme_;
    }
    const std::string get_host() const
    {
        return host_;
    }
    const std::string get_path() const
    {
        return path_;
    }
};


} // namespace utility
} // namespace oauth

#endif
