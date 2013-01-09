//
// percent_encoding.hpp
// ~~~~~~~~~~
//
// URL Encoder
//

#ifndef TWIT_LIB_UTILITY_PERCENT_ENCODING
#define TWIT_LIB_UTILITY_PERCENT_ENCODING

#include <string>
#include "radix.hpp"

namespace oauth{
namespace utility{

class percent_encoder
{
public:
    percent_encoder();
    virtual ~percent_encoder();// = default;

    template<typename InputIterator, typename OutputIterator>
    OutputIterator encode(InputIterator first, InputIterator last, OutputIterator out) const;

    template<typename InputIterator, typename OutputIterator>
    OutputIterator decode(InputIterator first, InputIterator last, OutputIterator out) const;
};

} // namespace utility
} // namespace oauth

#ifdef TWIT_LIB_BUILD
#include "impl/percent_encoding.ipp"
#endif

#endif
