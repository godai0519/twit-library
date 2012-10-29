//
// base64.hpp
// ~~~~~~~~~~
//
// Base64îFèÿ
//

#ifndef TWIT_LIB_UTILITY_BASE64
#define TWIT_LIB_UTILITY_BASE64

#include <string>

namespace oauth{
namespace utility{
    
class base64
{
public:
    base64(){}
    virtual ~base64(){} // = default;

    template<typename InputIterator, typename OutputIterator>
    OutputIterator encode(InputIterator first, InputIterator last, OutputIterator out)
    {
        static const std::string table = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
        //const size_t length = std::distance(first, last);

        while(first != last)
        {

                *out++ = table[(*first >> 2) & 0x3F/*0011 1111*/];
                if(first+1 == last)
                {
                    *out++ = table[(*first << 4) & 0x30/*0011 0000*/];
                    *out++ = '=';
                    *out++ = '=';
                    break;
                }
                ++first;

                *out++ = table[((*(first-1) << 4) & 0x30/*0011 0000*/) | ((*first >> 4) & 0x0F/*0000 1111*/)];
                if(first+1 == last)
                {
                    *out++ = table[(*first << 2) & 0x3C/*0011 1100*/];
                    *out++ = '=';
                    break;
                }
                ++first;

                *out++ = table[((*(first-1) << 2) & 0x3C/*0011 1100*/) | ((*first >> 6) & 0x03/*0000 0011*/)];
                *out++ = table[*first & 0x3F/*0011 1111*/];
                ++first;
        }


        return out;
    }

    const std::string encode(const std::string& data)
    {
        static const std::string table =
            "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

        std::string result;
        result.reserve(static_cast<std::string::size_type>(data.size() * 1.5));
        for(std::string::size_type i = 0; i<data.size(); ++i)
        {
            switch(i%3)
            {
            case 0:
                result.push_back(table[(data[i] >> 2) & 0x3F/*0011 1111*/]);
                if(i+1>=data.size())
                {
                    result.push_back(table[(data[i] << 4) & 0x30/*0011 0000*/]);
                    result.append("==");
                }
                break;
            case 1:
                result.push_back(table[((data[i-1] << 4) & 0x30/*0011 0000*/) | ((data[i] >> 4) & 0x0F/*0000 1111*/)]);
                if(i+1>=data.size())
                {
                    result.push_back(table[(data[i] << 2) & 0x3C/*0011 1100*/]);
                    result.append("=");
                }
                break;
            case 2:
                result.push_back(table[((data[i-1] << 2) & 0x3C/*0011 1100*/) | ((data[i] >> 6) & 0x03/*0000 0011*/)]);
                result.push_back(table[data[i] & 0x3F/*0011 1111*/]);
                break;
            }
        }
        return result;
    }
    
    const std::string decode(const std::string& data)
    {
        static const std::string table =
            "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

        if(data.size()%4 != 0) throw std::exception();
        
        std::string result;
        char word[4];
        for(std::string::size_type i = 0; i<data.size(); ++i)
        {
            const int value = table.find(data[i]);
            switch(i%4)
            {
            case 0:
                break;

            case 1:
                if(data[i] == '=')
                {
                    word[0] = (((int)table.find(data[i-1]) << 2) & 0xFC);
                    result.append(word, 1);
                    return result;
                }
                
                word[0] = (((int)table.find(data[i-1]) << 2) & 0xFC) | (((int)table.find(data[i]) >> 4) & 0x03);
                break;

            case 2:
                if(data[i] == '=')
                {
                    word[1] = (((int)table.find(data[i-1]) << 4) & 0xF0);
                    result.append(word, 2);
                    return result;
                }

                word[1] = (((int)table.find(data[i-1]) << 4) & 0xF0) | (((int)table.find(data[i]) >> 2) & 0x0F);
                break;
                
            case 3:
                if(data[i] == '=')
                    word[2] = (((int)table.find(data[i-1]) << 6) & 0xC0);
                else
                    word[2] = (((int)table.find(data[i-1]) << 6) & 0xC0) | ((int)table.find(data[i]) & 0x3F);
                
                result.append(word, 3);
                break;
            }
        }
        return result;
    }
private:
    //Ç±Ç±Ç…tableÇstatic const std::stringÇ≈îzíuÇµÇƒèâä˙âªÇµÇΩÇ¢(C++11)
};


const std::string base64_encode(const std::string& data)
{
    base64 encoder;

    std::string str;
    std::back_insert_iterator<std::string> out(str);
    encoder.encode(data.begin(), data.end(), out);
    return str;
}

} // namespace utility
} // namespace oauth

#endif
