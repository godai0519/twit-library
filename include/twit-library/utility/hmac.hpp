//
// hmac.hpp
// ~~~~~~~~~~
//
// Šî”•ÏŠ·—p
//

#ifndef TWIT_LIB_UTILITY_HMAC
#define TWIT_LIB_UTILITY_HMAC

#include <string>
#include "sha1.hpp"

namespace oauth{
namespace utility{

template<class Digest>
class hmac{
    Digest digest_;
public:
    const std::string operator() (const std::string& key,const std::string& data)
    {
        std::string k_ipad,k_opad;
        k_ipad = k_opad = (key.length() > 64) ? digest_(key,key.length()) : key;
    
        while(k_ipad.length()!=64)
        {
            k_ipad.push_back((char)0x00);
            k_opad.push_back((char)0x00);
        }

        for(int i=0;i<64;++i)
        {
            k_ipad[i] ^= 0x36;
            k_opad[i] ^= 0x5c;
        }

        return digest_(k_opad + digest_(k_ipad + data, 64+data.length()), 64 + 20);
    }
};

typedef hmac<sha1> hmac_sha1;

} // namespace utility
} // namespace oauth

#endif
