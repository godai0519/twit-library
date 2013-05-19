//
// authentication.hpp
// ~~~~~~~~~~
//
// 認証系機構のutility総集
//

#ifndef TWIT_LIB_UTILITY_AUTHENTICATION_HPP
#define TWIT_LIB_UTILITY_AUTHENTICATION_HPP

#include <string>
#include <map>
#include "base64.hpp"
#include "url_encoded.hpp"

namespace oauth{
namespace utility{    

template<class Scheme>
class signature
{
    const Scheme scheme_;
    const oauth::utility::generator generator_;
    const oauth::utility::percent_encoder encoder_;
    const oauth::utility::base64 base64_;

public:
    signature();
    virtual ~signature(); // = default;

    //Karma使える？のかな
    const std::string operator() (const std::string& method, const std::string& uri, const std::string& key, const std::map<std::string,std::string>& values) const;
};

inline const std::string get_timestamp();
inline const std::string nonce();

} // namespace utility
} // namespace oauth

#ifdef TWIT_LIB_BUILD
#include "impl/authentication.ipp"
#endif

#endif
