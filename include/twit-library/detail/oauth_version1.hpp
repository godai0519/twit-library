//
// oauth_version1.hpp
// ~~~~~~~~~~
//
// OAuth Version1用拡張
//

#ifndef TWIT_LIB_DETAIL_OAUTH_VER_1_HPP
#define TWIT_LIB_DETAIL_OAUTH_VER_1_HPP

#include <map>
#include <future>
#include <boost/assign.hpp>
#include <boost/noncopyable.hpp>
#include <boostconnect/client.hpp>
#include "../keys/key_version1.hpp"
#include "../utility.hpp"

namespace oauth{
namespace detail{

class oauth_version1 : boost::noncopyable{
public:
    typedef std::map<std::string, std::string>                     Param_Type;
    typedef oauth::keys::key_version1                              Key_Type;
    typedef bstcon::connection_type::connection_base::ChunkHandler ChunkHandler;
    typedef bstcon::connection_type::connection_base::EndHandler   RequestHandler;

    oauth_version1(const boost::shared_ptr<Key_Type>& key, const boost::shared_ptr<bstcon::client>& client);
    virtual ~oauth_version1();

    virtual std::future<void> get_request_token(const std::string& method, const std::string& uri);
    virtual std::future<void> get_access_token(const std::string& method, const std::string& uri, const std::string& pin_code);

    virtual std::future<void> request_urlencoded(
        const std::string& method,
        const std::string& uri,
        const Param_Type& params,
        RequestHandler handler = [](const boost::shared_ptr<bstcon::response>, const boost::system::error_code&)->void{},
        ChunkHandler chunk_handler = [](const boost::shared_ptr<bstcon::response>, const boost::system::error_code&)->bool{ return true; }
    );

protected:
    void set_access_token(const boost::shared_ptr<bstcon::response> response, const boost::system::error_code& ec, boost::shared_ptr<std::promise<void>> p);

    boost::shared_ptr<Key_Type> key_;
    boost::shared_ptr<bstcon::client> client_;
    
    oauth::utility::signature<oauth::utility::hmac_sha1> signature_;
    oauth::utility::generator generator_;
    oauth::utility::parser parser_;

    bstcon::client::connection_ptr connection;
};

} // namespace detail
} // namespace oauth

#ifdef TWIT_LIB_BUILD
#include "impl/oauth_version1.ipp"
#endif


#endif
