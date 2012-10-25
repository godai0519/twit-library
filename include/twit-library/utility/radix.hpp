//
// radix.hpp
// ~~~~~~~~~~
//
// Šî”•ÏŠ·—p
//

#ifndef TWIT_LIB_UTILITY_RADIX
#define TWIT_LIB_UTILITY_RADIX

#include <string>

namespace oauth{
namespace utility{

class radix_converter
{
public:
    radix_converter(){}
    ~radix_converter(){}

    const int hex_to_dec(const std::string& hex)
    {
        int dec = 0;
        for(std::string::const_iterator it = hex.cbegin(); it != hex.cend(); ++it)
        {
            dec *= 16;
            if(*it >= '0' && *it <= '9') dec += ((*it)-'0');
            else if(*it >= 'A' && *it <= 'F') dec += ((*it)-'A'+10);
            else if(*it >= 'a' && *it <= 'f') dec += ((*it)-'a'+10);
            else std::exception();
        }
        return dec;
    }
};

inline const int hex_to_dec(const std::string& hex)
{
    radix_converter conv;
    return conv.hex_to_dec(hex);
}

} // namespace utility
} // namespace oauth

#endif
