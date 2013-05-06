#ifndef TWIT_LIB_TWITTER_IPP
#define TWIT_LIB_TWITTER_IPP

#include <string>
#include "../common_v1.hpp"
#include "../twitter.hpp"

namespace oauth{

std::string twitter_set::get_host()
{
    return "api.twitter.com";
}
std::string twitter_set::get_request_method()
{
    return "POST";
}
std::string twitter_set::get_request_path()
{
    return "/oauth/request_token";
}
std::string twitter_set::get_access_method()
{
    return "POST";
}
std::string twitter_set::get_access_path()
{
    return "/oauth/access_token";
}

twitter::twitter(boost::shared_ptr<Key_Type> &key,boost::shared_ptr<bstcon::client> &client)
    : MyParent(key,client)
{
}
twitter::~twitter()
{
}

std::string twitter::get_user_id() const
{
    return user_id_;
}
std::string twitter::get_screen_name() const
{
    return screen_name_;
}

#ifdef USE_SSL_BOOSTCONNECT
std::future<void> twitter::get_xauth_token(const std::string& id, const std::string& password)
{
    Param_Type params = boost::assign::map_list_of
        ("oauth_consumer_key",key_->get_consumer_key())
        ("oauth_signature_method","HMAC-SHA1")
        ("oauth_timestamp",oauth::utility::get_timestamp())
        ("oauth_nonce",oauth::utility::nonce())
        ("oauth_callback","oob")
        ("oauth_version","1.0")
        ("x_auth_password",password)
        ("x_auth_username",id)
        ("x_auth_mode","client_auth");
        
    Param_Type xauth_params = boost::assign::map_list_of
        ("x_auth_password",password)
        ("x_auth_username",id)
        ("x_auth_mode","client_auth");

    boost::assign::insert(params)
        ("oauth_signature",signature_(URL_Set::get_access_method(),client_->service_protocol()+"://"+URL_Set::get_host()+URL_Set::get_access_path(),key_->get_signature_key(),params));

    params.erase("x_auth_password");
    params.erase("x_auth_username");
    params.erase("x_auth_mode");

    const std::string body = generator_.urlencode(xauth_params);

    boost::shared_ptr<boost::asio::streambuf> buf(new boost::asio::streambuf());
    {
        std::ostream os(buf.get());
        os << URL_Set::get_access_method() << " " << URL_Set::get_access_path() << " HTTP/1.1" << "\r\n";
        os << "Host: " << URL_Set::get_host() << "\r\n";
        os << "Content-Type: " << "application/x-www-form-urlencoded" << "\r\n";
        os << "Content-Length: " << body.length() << "\r\n";
        os << "Authorization: " << "OAuth " << generator_.authorization_field(params) << "\r\n\r\n";
        os << body;
    }

    auto promise = boost::make_shared<std::promise<void>>();        
    (*client_)(
        URL_Set::get_host(),
        [buf,promise,this](bstcon::client::connection_ptr connection, boost::system::error_code ec)
        {
            connection->send(buf,boost::bind(&twitter::set_access_token,this,_1,_2,promise));
        });

    return promise->get_future();
}
#endif
    
void twitter::set_access_token(const boost::shared_ptr<bstcon::response> response,const boost::system::error_code& ec, boost::shared_ptr<std::promise<void>> p)
{
    if(!ec && 200 <= response->status_code && response->status_code < 300)
    {
        const Param_Type parsed = parser_.urlencode(response->body);
        key_->set_access_token (parsed.at("oauth_token"));
        key_->set_access_secret(parsed.at("oauth_token_secret"));
        user_id_ = parsed.at("user_id");
        screen_name_ = parsed.at("screen_name");
    }

    p->set_value();
    return;
}

} // namespace oauth

#endif
