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
#include "base64.hpp"
#include "url_encoded.hpp"

namespace oauth{
namespace utility{    

template<class Scheme>
class signature
{
    const Scheme scheme_;
    const oauth::utility::generator generator_;
    const oauth::utility::percent_encoder encoder_;
    const oauth::utility::base64 base64_;

public:
    signature(){}
    virtual ~signature(){} // = default;

    //Karma使える？のかな
    const std::string operator() (const std::string& method,const std::string& uri,const std::string& key,const std::map<std::string,std::string>& values) const
    {
        std::string base_string;
        {
            std::back_insert_iterator<std::string> base_out(base_string);
            std::string value_string(generator_.urlencode(values));

            std::copy(method.cbegin(), method.cend(), base_out);
            *base_out++ = '&';
            encoder_.encode(uri.cbegin(), uri.cend(), base_out);
            *base_out++ = '&';
            encoder_.encode(value_string.cbegin(), value_string.cend(), base_out);
        }

        const std::string schemed = scheme_(key,base_string);
        
        std::string result;
        std::back_insert_iterator<std::string> result_out(result);
        base64_.encode(schemed.cbegin(), schemed.cend(), result_out);
        return result;
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
