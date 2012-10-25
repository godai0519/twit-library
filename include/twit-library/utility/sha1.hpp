//
// sha1.hpp
// ~~~~~~~~~~
//
// Šî”•ÏŠ·—p
//

#ifndef TWIT_LIB_UTILITY_SHA1
#define TWIT_LIB_UTILITY_SHA1

#include <string>

namespace oauth{
namespace utility{

class sha1{
    inline unsigned int left_shift(int bits, unsigned int word)
    {
        return (((word) << (bits)) | ((word) >> (32-(bits))));
    }
public:
    const std::string operator() (std::string data, unsigned long long length)
    {
        // 0x80‚ğ‹l‚ß‚é
        data.push_back((char)0x80);

        // 64*n + (64-8)bit‚É’B‚·‚é‚æ‚¤‚É0x00‚ğ‹l‚ß‚é
        const int add_length = 56 - data.length() % 64;
        data.append((add_length < 0) ? add_length + 64 : add_length, (char)0x00);
    
        //’·‚³‚ğ8ƒoƒCƒg‚Å‹l‚ß‚é
        length *= 8;
        for(int i=56; i>=0; i-=8) data.push_back((char)(length >> i) & 0xFF);
    
        unsigned int hash[5] = {0x67452301, 0xEFCDAB89, 0x98BADCFE, 0x10325476, 0xC3D2E1F0};
        unsigned int w[80];
        const unsigned int num_block = data.length() / 64;
        for(unsigned int i = 0; i < num_block; ++i)
        {
            for(int j = 0; j < 16; ++j)
            {
                w[j]    = ((unsigned char)data[i*64+j*4    ] << 24);
                w[j] |= ((unsigned char)data[i*64+j*4+1] << 16);
                w[j] |= ((unsigned char)data[i*64+j*4+2] <<    8);
                w[j] |= ((unsigned char)data[i*64+j*4+3]            );
            }
            for(int j = 16; j < 80; ++j) w[j] = left_shift(1, w[j-3] ^ w[j-8] ^ w[j-14] ^ w[j-16]);
        
            unsigned int a = hash[0];
            unsigned int b = hash[1];
            unsigned int c = hash[2];
            unsigned int d = hash[3];
            unsigned int e = hash[4];

            for(int i = 0; i < 80; ++i)
            {
                unsigned int f, k;
                if(i<20)
                {
                    f = (b & c) | (~b & d);
                    k = 0x5A827999;
                }
                else if(i<40)
                {
                    f = b ^ c ^ d;
                    k = 0x6ED9EBA1;
                }
                else if(i<60)
                {
                    f = (b & c) | (b & d) | (c & d);
                    k = 0x8F1BBCDC;
                }
                else
                {
                    f = b ^ c ^ d;
                    k = 0xCA62C1D6;
                }

                unsigned int temp = left_shift(5,a) + f + e + k + w[i];
                e = d;
                d = c;
                c = left_shift(30,b);
                b = a;
                a = temp;
            }

            hash[0] += a;
            hash[1] += b;
            hash[2] += c;
            hash[3] += d;
            hash[4] += e;
        }
    
        std::string result;
        for(int i = 0; i < 5; ++i) for(int shift = 24; shift >= 0; shift -= 8) result.push_back((char)(hash[i] >> shift) & 0xFF);
        return result;
    }
};

} // namespace utility
} // namespace oauth

#endif
