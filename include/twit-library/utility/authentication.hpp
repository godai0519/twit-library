//
// authentication.hpp
// ~~~~~~~~~~
//
// 認証系機構のutility総集
//

#ifndef TWIT_LIB_UTILITY_AUTHENTICATION
#define TWIT_LIB_UTILITY_AUTHENTICATION

#include <ctime>
#include <map>
#include <string>
#include <boost/foreach.hpp>
#include <boost/random.hpp>

namespace oauth{
namespace utility{    

template<class Scheme>
class signature{
    Scheme scheme_;

public:
    //Karma使える？のかな
    const std::string operator() (const std::string& method,const std::string& uri,const std::string& key,const std::map<std::string,std::string>& values)
    {
        typedef std::pair<const std::string,std::string> Value_Pair;

        std::string base_string;
        BOOST_FOREACH(const Value_Pair& p,values)
            base_string += percent_encode(p.first) + "=" + percent_encode(p.second) + "&";

        base_string.erase(base_string.size()-1);
        base_string = method + "&" + percent_encode(uri) + "&" + percent_encode(base_string);

        oauth::utility::base64 base64;
        return base64.encode(scheme_(key,base_string));
    }
};

inline const std::string get_timestamp()
{
    return (boost::format("%1%") % static_cast<unsigned long>(std::time(0))).str();
}

inline const std::string nonce()
{
    static const boost::uniform_int<unsigned long> range(0,62-1);
    static boost::mt19937 gen(static_cast<unsigned long>(std::time(0)));
    static boost::variate_generator<
        boost::mt19937&,boost::uniform_int<unsigned long>
    > rand(gen,range);
    static const unsigned char nonce_base[62] = 
    {
        'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
        'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
        '1','2','3','4','5','6','7','8','9','0'
    };

    std::string result;
    unsigned int nonce_length = 0;

    while(nonce_length<12) nonce_length = rand();
    result.reserve(nonce_length);
    
    for(unsigned int i=0;i<nonce_length;++i) result.push_back(nonce_base[rand()]);
    return result;
}

} // namespace utility
} // namespace oauth

#endif
