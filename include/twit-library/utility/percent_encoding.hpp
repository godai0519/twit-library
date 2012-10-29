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
    virtual ~percent_encoder(){};// = default;

    template<typename InputIterator, typename OutputIterator>
    OutputIterator encode(InputIterator first, InputIterator last, OutputIterator out)
    {
        while(first != last)
        {
            if((0x30<=*first && *first<=0x39) || (0x41<=*first && *first<=0x5a) || (0x61<=*first && *first<= 0x7a) || *first==0x2d || *first==0x2e || *first==0x5f || *first==0x7e)
            {
                *out++ = *first++;
            }
            else
            {
                std::string ss((boost::format("%%%02X") % (*first++ & 0xff)).str());
                out = std::copy(ss.begin(), ss.end(), out);
            }
        }
        return out;
    }

    template<typename InputIterator, typename OutputIterator>
    OutputIterator decode(InputIterator first, InputIterator last, OutputIterator out)
    {
        while(first != last)
        {
            if(*first == '%') //%xx
            {
                *out++ = (char)hex_to_dec(std::string(first+1,first+3));
                first+=3;
            }
            else *out++ = *first++;
        }
        return out;
    }
};

inline std::string percent_encode(const std::string& base_string)
{
    percent_encoder encoder;

    std::string str;
    std::back_insert_iterator<std::string> out(str);
    encoder.encode(base_string.cbegin(), base_string.cend(), out);
    return str;
}

inline std::string percent_decode(const std::string& base_string)
{
    percent_encoder encoder;

    std::string str;
    std::back_insert_iterator<std::string> out(str);    
    encoder.decode(base_string.cbegin(), base_string.cend(), out);
    return str;
}

} // namespace utility
} // namespace oauth

#endif
