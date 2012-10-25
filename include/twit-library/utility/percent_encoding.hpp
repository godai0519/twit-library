//
// url_encoder.hpp
// ~~~~~~~~~~
//
// URL Encoder
//

#ifndef TWIT_LIB_UTILITY_PERCENT_ENCODING
#define TWIT_LIB_UTILITY_PERCENT_ENCODING

#include <string>
#include <boost/format.hpp>
#include "radix.hpp"

namespace oauth{
namespace utility{


class percent_encoder
{
public:
    percent_encoder(){}
    ~percent_encoder(){}

    const std::string encode(const std::string& base_string)
    {
        std::string encoded="";
        for(std::string::const_iterator it = base_string.cbegin();it!=base_string.cend();++it)
        {
            if((0x30<=*it && *it<=0x39) || (0x41<=*it && *it<=0x5A) || (0x61<=*it && *it<= 0x7A) || *it==0x2D || *it==0x2E || *it==0x5F || *it==0x7E)
                encoded.append(it,it+1);
            else
                encoded.append((boost::format("%%%02X") % (*it & 0xff)).str());
        }
        return encoded;
    }

    // +¨' '‚É‚Í‚µ‚È‚¢
    const std::string decode(const std::string& base_string)
    {
        std::string decoded="";
        for(std::string::const_iterator it = base_string.begin();it!=base_string.end();++it)
        {
            if(*it == '%') //%xx
            {
                decoded += (char)hex_to_dec(std::string(it+1,it+3));
                it+=2;
            }
            else decoded += *it;
        }
        return decoded;
    }
};

inline const std::string percent_encode(const std::string& base_string)
{
    percent_encoder encoder;
    return encoder.encode(base_string);
}

inline const std::string percent_decode(const std::string& base_string)
{
    percent_encoder encoder;
    return encoder.decode(base_string);
}

} // namespace utility
} // namespace oauth

#endif
