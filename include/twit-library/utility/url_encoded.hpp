//
// url_encoded.hpp
// ~~~~~~~~~~
//
// 認証系機構のutility総集
//

#ifndef TWIT_LIB_UTILITY_URLENCODED
#define TWIT_LIB_UTILITY_URLENCODED

#include <map>
#include <string>
#include <boost/foreach.hpp>
#include <boost/fusion/include/std_pair.hpp>
#include <boost/spirit/include/phoenix.hpp>
#include <boost/spirit/include/qi.hpp>
#include "percent_encoding.hpp"

namespace oauth{
namespace utility{    

//get_authorization_fieldとget_urlencodedをまとめられそう．
inline const std::string get_authorization_field(const std::map<std::string,std::string>& values)
{
    typedef std::pair<const std::string,std::string> Value_Pair;

    std::string field_string = "";
    BOOST_FOREACH(const Value_Pair& p,values)
        field_string += (percent_encode(p.first) + "=\"" + percent_encode(p.second) + "\",");

    if(!field_string.empty()) field_string.erase(field_string.size()-1);
    return field_string;
}

inline const std::string get_urlencoded(const std::map<std::string,std::string>& values)
{
    typedef std::pair<const std::string,std::string> Value_Pair;
    
    std::string field_string = "";
    BOOST_FOREACH(const Value_Pair& p,values)
        field_string += (percent_encode(p.first) + "=" + percent_encode(p.second) + "&");

    if(!field_string.empty()) field_string.erase(field_string.size()-1);
    return field_string;
}

inline const std::map<std::string,std::string> parse_urlencoded(const std::string& encoded)
{
    namespace qi = boost::spirit::qi;

    qi::rule<std::string::const_iterator,std::string()> key     = +(qi::char_ - qi::lit("="));
    qi::rule<std::string::const_iterator,std::string()> value = +(qi::char_ - qi::lit("&"));
    qi::rule<std::string::const_iterator,std::pair<std::string,std::string>()> pair = key >> qi::lit("=") >> value;
    qi::rule<std::string::const_iterator,std::map<std::string,std::string>()> rule = pair % qi::lit("&");
        
    std::string::const_iterator it = encoded.cbegin();
    std::map<std::string,std::string> parsed;
    std::pair<std::string,std::string> p;
    qi::parse(it,encoded.cend(),rule,parsed);

    return parsed;
}

} // namespace utility
} // namespace oauth

#endif
