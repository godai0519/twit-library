//
// twitter.hpp
// ~~~~~~~~~~
//
// Twitter URL Listとその実用化
//

#ifndef TWIT_LIB_TWITTER_HPP
#define TWIT_LIB_TWITTER_HPP

#include <string>
#include <boost/shared_ptr.hpp>
#include "common_v1.hpp"

namespace oauth{

struct twitter_set{
    static std::string get_host();
    static std::string get_request_method();
    static std::string get_request_path();
    static std::string get_access_method();
    static std::string get_access_path();
};

class twitter : public oauth::client::common_v1<oauth::twitter_set>{
    typedef oauth::client::common_v1<oauth::twitter_set> MyParent;
    typedef oauth::twitter_set URL_Set;
public:
    twitter(boost::shared_ptr<Key_Type> &key,boost::shared_ptr<bstcon::client> &client);
    virtual ~twitter();

    std::string get_user_id() const;
    std::string get_screen_name() const;

#ifdef USE_SSL_BOOSTCONNECT
    void get_xauth_token(const std::string& id, const std::string& password, GetTokenHandler handler = [](const boost::shared_ptr<bstcon::response>,const boost::system::error_code&)->void{});
#endif
    
protected:
    void set_access_token(const boost::shared_ptr<bstcon::response> response,const boost::system::error_code& ec,GetTokenHandler handler);

    std::string user_id_;
    std::string screen_name_;
};

} // namespace oauth

#ifdef BOOSTCONNECT_LIB_BUILD
#include "impl/twitter.ipp"
#endif

#endif
