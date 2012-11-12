﻿//
// oauth_version2.hpp
// ~~~~~~~~~~
//
// OAuth Version2用拡張
//

#ifndef TWIT_LIB_DETAIL_OAUTH_VER_2
#define TWIT_LIB_DETAIL_OAUTH_VER_2

#include <map>
#include <boost/assign.hpp>
#include "../keys/key_version2.hpp"

namespace oauth{
namespace detail{

class oauth_version2 : boost::noncopyable{
public:
    typedef oauth::keys::key_version2 Key_Type;
    typedef std::map<std::string,std::string> Param_Type;
    oauth_version2(boost::shared_ptr<Key_Type> &key,boost::shared_ptr<bstcon::client> &client)
    {
        key_ = key;
        client_ = client;
    }
    virtual ~oauth_version2(){}

    virtual const std::string authorization_request_uri(const std::string& uri,const std::string& response_type,const std::string& redirect_uri="",const std::string& scope="",const std::string& state="")
    {
        Param_Type param = boost::assign::map_list_of
            ("client_id"        ,key_->get_client_id())
            ("response_type",response_type);

        if(!redirect_uri.empty()) param["redirect_uri"] = redirect_uri; //MAY
        if(!scope.empty())                param["scope"] = scope;       //Option
        if(!state.empty())                param["state"] = state;       //Option
        
        return uri + "?" + generator_.urlencode(param);
    }

    virtual void code_to_access_token(const std::string& uri, const std::string& code, const std::string& redirect_uri="")
    {
        oauth::utility::uri_parser uri_parsed(uri);

        Param_Type param = boost::assign::map_list_of
            ("client_id",key_->get_client_id())
            ("client_secret",key_->get_client_secret())
            ("redirect_uri",redirect_uri)
            ("code",code)
            ("grant_type","authorization_code");

        const auto body = generator_.urlencode(param);

        boost::shared_ptr<boost::asio::streambuf> buf(new boost::asio::streambuf());
        {
            std::ostream os(buf.get());
            os << "POST " << uri_parsed.get_path() << " HTTP/1.1" << "\r\n";
            os << "Host: " << uri_parsed.get_host() << "\r\n";
            os << "Content-Length: " << body.length() << "\r\n";
            os << "Content-Type: " << "application/x-www-form-urlencoded" << "\r\n\r\n";
            os << body;
        }
    
        (*client_)(
            uri_parsed.get_host(),
            [buf,this](bstcon::connection_type::connection_base::connection_ptr connection, boost::system::error_code ec)
            {
                connection->send(buf, boost::bind(&oauth_version2::set_access_token,this,_1,_2));
            });
        
    return;
    }

protected:
    void set_access_token(const boost::shared_ptr<bstcon::response> response,const boost::system::error_code& ec)
    {
        if(ec) return;
        if(200 <= response->status_code && response->status_code < 300)
        {
            const Param_Type parsed = parser_.urlencode(response->body);
            key_->set_access_token(parsed.at("access_token"));
        }
        return;
    }

    boost::shared_ptr<Key_Type> key_;
    boost::shared_ptr<bstcon::client> client_;
    oauth::utility::generator generator_;
    oauth::utility::parser parser_;
};

} // namespace detail
} // namespace oauth

#endif
//http://openid-foundation-japan.github.com/draft-ietf-oauth-v2.ja.html#user-authorization