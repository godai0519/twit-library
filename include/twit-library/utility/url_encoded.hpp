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
#include <boost/bind.hpp>
#include <boost/function.hpp>
#include <boost/foreach.hpp>
#include <boost/fusion/include/std_pair.hpp>
#include <boost/spirit/include/phoenix.hpp>
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/karma.hpp>

#include "percent_encoding.hpp"

namespace oauth{
namespace utility{    

class generator
{
public:
    std::string operator() (const std::map<std::string,std::string>& data, boost::function<std::string (const std::string&) > f, const std::string& key_value_separator = "=", const std::string& field_separator = "&", const std::string& value_container = "")
    {
        namespace karma = boost::spirit::karma;

        //BOOST_FOREACH(const std::map<Key,T,Compare,Allocator>::value_type& value, data)
        //{
        //    result.append();
        //}
        
        const karma::rule<std::back_insert_iterator<std::string>, std::string()> key = karma::string;
        const karma::rule<std::back_insert_iterator<std::string>, std::string()> value = karma::lit(value_container) << karma::string << karma::lit(value_container);
        const karma::rule<std::back_insert_iterator<std::string>, std::map<std::string,std::string>::value_type()> field = key << karma::lit(key_value_separator) << value;
        const karma::rule<std::back_insert_iterator<std::string>, std::map<std::string,std::string>()> body = field % karma::lit(field_separator);

        std::string result;
        std::back_insert_iterator<std::string> out(result);
        karma::generate(out, body, data);

        return result;
    }

   inline std::string urlencode(const std::map<std::string,std::string>& data)
   {
       return (*this)(data, oauth::utility::percent_encode);
   }
   inline std::string authorization_field(const std::map<std::string,std::string>& data)
   {
       return (*this)(data, oauth::utility::percent_encode, "=", ",", "\"");
   }

private:
    //oauth::utility::percent_encoder encoder_;
};

class parser
{
public:
    std::map<std::string,std::string> operator() (const std::string& src, const std::string& key_value_separator = "=", const std::string& field_separator = "&", const std::string& value_container = "")
    {
        namespace qi = boost::spirit::qi;
                
        const qi::rule<std::string::const_iterator, std::string(), qi::space_type> key = +(qi::char_ - qi::lit(key_value_separator));
        const qi::rule<std::string::const_iterator, std::string(), qi::space_type> value = (qi::lit(value_container) >> +(qi::char_ - qi::lit(value_container)) >> qi::lit(value_container)) | (+(qi::char_ - qi::lit(field_separator)));
        const qi::rule<std::string::const_iterator,std::pair<std::string,std::string>(), qi::space_type> pair = key >> key_value_separator >> value;
        const qi::rule<std::string::const_iterator,std::map<std::string,std::string>(), qi::space_type> rule = pair % qi::lit(field_separator);

        std::map<std::string,std::string> data;
        std::string::const_iterator it = src.cbegin();
        qi::phrase_parse(it, src.cend(), rule, qi::space, data);

        return data;
    }
    
   inline std::map<std::string,std::string> urlencode(const std::string& src)
   {
       return (*this)(src);
   }
   inline std::map<std::string,std::string> authorization_field(const std::string& src)
   {
       return (*this)(src, "=", ",", "\"");
   }
};

//
//
//
////get_authorization_fieldとget_urlencodedをまとめられそう．
//inline const std::string get_authorization_field(const std::map<std::string,std::string>& values)
//{
//    typedef std::map<std::string,std::string>::value_type Value_Pair;
//
//    std::string field_string = "";
//    BOOST_FOREACH(const Value_Pair& p,values)
//        field_string += (percent_encode(p.first) + "=\"" + percent_encode(p.second) + "\",");
//
//    if(!field_string.empty()) field_string.erase(field_string.size()-1);
//    return field_string;
//}
//
//inline const std::string get_urlencoded(const std::map<std::string,std::string>& values)
//{
//    typedef std::pair<const std::string,std::string> Value_Pair;
//    
//    std::string field_string = "";
//    BOOST_FOREACH(const Value_Pair& p,values)
//        field_string += (percent_encode(p.first) + "=" + percent_encode(p.second) + "&");
//
//    if(!field_string.empty()) field_string.erase(field_string.size()-1);
//    return field_string;
//}
//
//inline const std::map<std::string,std::string> parse_urlencoded(const std::string& encoded)
//{
//    namespace qi = boost::spirit::qi;
//
//    qi::rule<std::string::const_iterator,std::string()> key     = +(qi::char_ - qi::lit("="));
//    qi::rule<std::string::const_iterator,std::string()> value = +(qi::char_ - qi::lit("&"));
//    qi::rule<std::string::const_iterator,std::pair<std::string,std::string>()> pair = key >> qi::lit("=") >> value;
//    qi::rule<std::string::const_iterator,std::map<std::string,std::string>()> rule = pair % qi::lit("&");
//        
//    std::string::const_iterator it = encoded.cbegin();
//    std::map<std::string,std::string> parsed;
//    std::pair<std::string,std::string> p;
//    qi::parse(it,encoded.cend(),rule,parsed);
//
//    return parsed;
//}

} // namespace utility
} // namespace oauth

#endif
