//
// radix.hpp
// ~~~~~~~~~~
//
// Šî”•ÏŠ·—p
//

#ifndef TWIT_LIB_UTILITY_RADIX_HPP
#define TWIT_LIB_UTILITY_RADIX_HPP

#include <string>

namespace oauth{
namespace utility{

class radix_converter
{
public:
    radix_converter();
    virtual ~radix_converter();

    const int hex_to_dec(const std::string& hex);
};
inline const int hex_to_dec(const std::string& hex);

} // namespace utility
} // namespace oauth

#ifdef TWIT_LIB_BUILD
#include "impl/radix.ipp"
#endif

#endif
