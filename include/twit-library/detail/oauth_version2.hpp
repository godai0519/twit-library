//
// oauth_version2.hpp
// ~~~~~~~~~~
//
// OAuth Version2用拡張
//

#ifndef TWIT_LIB_DETAIL_OAUTH_VER_2_HPP
#define TWIT_LIB_DETAIL_OAUTH_VER_2_HPP

#include <map>
#include <boost/assign.hpp>
#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>
#include "../keys/key_version2.hpp"

namespace oauth{
namespace detail{

class oauth_version2 : boost::noncopyable{
public:
    typedef oauth::keys::key_version2         Key_Type;
    typedef std::map<std::string,std::string> Param_Type;
    oauth_version2(const boost::shared_ptr<Key_Type> &key, const boost::shared_ptr<bstcon::client> &client);
    virtual ~oauth_version2();

    virtual const std::string authorization_request_uri(const std::string& uri, const std::string& response_type, const std::string& redirect_uri="", const std::string& scope="", const std::string& state="");
    virtual void code_to_access_token(const std::string& uri, const std::string& code, const std::string& redirect_uri="");
    
protected:
    void set_access_token(const boost::shared_ptr<bstcon::response> response, const boost::system::error_code& ec);

    boost::shared_ptr<Key_Type> key_;
    boost::shared_ptr<bstcon::client> client_;
    oauth::utility::generator generator_;
    oauth::utility::parser parser_;
};

} // namespace detail
} // namespace oauth

#ifdef TWIT_LIB_BUILD
#include "impl/oauth_version2.ipp"
#endif

#endif
//http://openid-foundation-japan.github.com/draft-ietf-oauth-v2.ja.html#user-authorization
