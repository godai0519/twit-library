//
// sha1.hpp
// ~~~~~~~~~~
//
// Šî”•ÏŠ·—p
//

#ifndef TWIT_LIB_UTILITY_SHA1_HPP
#define TWIT_LIB_UTILITY_SHA1_HPP

#include <string>

namespace oauth{
namespace utility{

class sha1
{
private:
    inline unsigned int left_shift(int bits, unsigned int word) const;

public:
    sha1();
    virtual ~sha1(); // = default;
    std::string operator() (std::string data, unsigned long long length) const;
};

} // namespace utility
} // namespace oauth

#ifdef TWIT_LIB_BUILD
#include "impl/sha1.ipp"
#endif

#endif
