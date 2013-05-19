//
// v1.hpp
// ~~~~~~~~~~
//
// OAuth1.0用，定義リスト
//

#ifndef TWIT_LIB_COMMON_V1_HPP
#define TWIT_LIB_COMMON_V1_HPP

#include "../detail/oauth_version1.hpp"

namespace oauth{
namespace client{

template<class URL_Set>
class common_v1: public oauth::detail::oauth_version1{
public:
    common_v1(const boost::shared_ptr<Key_Type>& key, const boost::shared_ptr<bstcon::client>& client);
    virtual ~common_v1();
    
    virtual void get_request_token();
    virtual void get_access_token(const std::string& pin_code);
};

} // namespace client
} // namespace oauth

#ifdef BOOSTCONNECT_LIB_BUILD
#include "impl/common_v1.ipp"
#endif

#endif
