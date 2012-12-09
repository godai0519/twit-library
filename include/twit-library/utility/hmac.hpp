//
// hmac.hpp
// ~~~~~~~~~~
//
// Šî”•ÏŠ·—p
//

#ifndef TWIT_LIB_UTILITY_HMAC_HPP
#define TWIT_LIB_UTILITY_HMAC_HPP

#include <string>
#include "sha1.hpp"

namespace oauth{
namespace utility{

template<class Digest>
class hmac
{
    const Digest digest_;
public:
    hmac();
    virtual ~hmac(); // = default;
    std::string operator() (const std::string& key,const std::string& data) const;
};

typedef hmac<sha1> hmac_sha1;

} // namespace utility
} // namespace oauth

#ifdef TWIT_LIB_BUILD
#include "impl/hmac.ipp"
#endif

#endif
