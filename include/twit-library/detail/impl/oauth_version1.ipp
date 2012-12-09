#ifndef TWIT_LIB_DETAIL_OAUTH_VER_1_IPP
#define TWIT_LIB_DETAIL_OAUTH_VER_1_IPP

#include <map>
#include <boost/assign.hpp>
#include <boost/bind.hpp>
#include <boostconnect/client.hpp>
#include "../oauth_version1.hpp"
#include "../../keys/key_version1.hpp"
#include "../../utility.hpp"

namespace oauth{
namespace detail{

oauth_version1::oauth_version1(boost::shared_ptr<Key_Type> &key,boost::shared_ptr<bstcon::client> &client)
{
    key_ = key;
    client_ = client;
}
oauth_version1::~oauth_version1(){}

void oauth_version1::get_request_token(const std::string& method,const std::string& uri)
{
    oauth::utility::uri_parser uri_parsed(uri);

    Param_Type params = boost::assign::map_list_of
        ("oauth_consumer_key",key_->get_consumer_key())
        ("oauth_signature_method","HMAC-SHA1")
        ("oauth_timestamp",oauth::utility::get_timestamp())
        ("oauth_nonce",oauth::utility::nonce())
        ("oauth_callback","oob")
        ("oauth_version","1.0");
        
    boost::assign::insert(params)
        ("oauth_signature",signature_(method,uri,key_->get_signature_key(),params));

    boost::shared_ptr<boost::asio::streambuf> buf(new boost::asio::streambuf());
    {
        std::ostream os(buf.get());
        os << method << " " << uri_parsed.get_path() << " HTTP/1.1" << "\r\n";
        os << "Host: " << uri_parsed.get_host() << "\r\n";
        os << "Content-Type: " << "application/x-www-form-urlencoded" << "\r\n";
        os << "Authorization: " << "OAuth " << generator_.authorization_field(params) << "\r\n\r\n";
    }

    boost::system::error_code ec;
    (*client_)(
        uri_parsed.get_host(),
        [buf,this](bstcon::client::connection_ptr connection,boost::system::error_code ec)
        {
            connection->send(buf,boost::bind(&oauth_version1::set_access_token,this,_1,_2));
        });

    //const boost::shared_ptr<bstcon::response> response = 
    //    client_->operator() (uri_parsed.get_host(),buf,ec,
    //        boost::bind(&oauth_version1::set_access_token,this,_1,_2));

    return;
}

void oauth_version1::get_access_token(const std::string& method,const std::string& uri,const std::string& pin_code)
{
    oauth::utility::uri_parser uri_parsed(uri);

    Param_Type params = boost::assign::map_list_of
        ("oauth_consumer_key",key_->get_consumer_key())
        ("oauth_token",key_->get_access_token())
        ("oauth_signature_method","HMAC-SHA1")
        ("oauth_timestamp",oauth::utility::get_timestamp())
        ("oauth_verifier",pin_code)
        ("oauth_nonce",oauth::utility::nonce())
        ("oauth_version","1.0");
        
    boost::assign::insert(params)
        ("oauth_signature",signature_(method,uri,key_->get_signature_key(),params));

    boost::shared_ptr<boost::asio::streambuf> buf(new boost::asio::streambuf());
    {
        std::ostream os(buf.get());
        os << method << " " << uri_parsed.get_path() << " HTTP/1.1" << "\r\n";
        os << "Host: " << uri_parsed.get_host() << "\r\n";
        os << "Content-Type: " << "application/x-www-form-urlencoded" << "\r\n";
        os << "Authorization: " << "OAuth " << generator_.authorization_field(params) << "\r\n\r\n";
    }

    boost::system::error_code ec;
    (*client_)(
        uri_parsed.get_host(),
        [buf,this](bstcon::client::connection_ptr connection,boost::system::error_code ec)
        {
            connection->send(buf,boost::bind(&oauth_version1::set_access_token,this,_1,_2));
        });

    //const boost::shared_ptr<bstcon::response> response = client_->operator() (uri_parsed.get_host(),buf,
    //        boost::bind(&oauth_version1::set_access_token,this,_1,_2));

    return;
}

void oauth_version1::request_urlencoded(
    const std::string& method,
    const std::string& uri,
    const Param_Type& params,
    RequestHandler handler,
    ChunkHandler chunk_handler
)
{
    oauth::utility::uri_parser uri_parsed(uri);

    Param_Type header_params = boost::assign::map_list_of
        ("oauth_consumer_key",key_->get_consumer_key())
        ("oauth_token",key_->get_access_token())
        ("oauth_signature_method","HMAC-SHA1")
        ("oauth_timestamp",oauth::utility::get_timestamp())
        ("oauth_nonce",oauth::utility::nonce())
        ("oauth_version","1.0");

    Param_Type signature_param = params;
    signature_param.insert(header_params.cbegin(),header_params.cend());

    boost::assign::insert(header_params)
        ("oauth_signature",signature_(method,uri_parsed.get_scheme()+"://"+uri_parsed.get_host()+uri_parsed.get_path(),key_->get_signature_key(),signature_param));

    const std::string body_string = (method!="GET") ? generator_.urlencode(params) : "";
    boost::shared_ptr<boost::asio::streambuf> buf(new boost::asio::streambuf());
    {
        std::ostream os(buf.get());
        os << method << " " << uri_parsed.get_path() << ((method=="GET") ? "?"+generator_.urlencode(params) : "") << " HTTP/1.1" << "\r\n";
        os << "Host: " << uri_parsed.get_host() << "\r\n";
        os << "Content-Length: " << body_string.size() << "\r\n";
        os << "Content-Type: " << "application/x-www-form-urlencoded" << "\r\n";
        os << "Authorization: " << "OAuth " << generator_.authorization_field(header_params) << "\r\n\r\n";
        os << body_string;
    }

    connection = (*client_)(
        uri_parsed.get_host(),
        [buf,handler,chunk_handler](bstcon::client::connection_ptr connection, boost::system::error_code ec)
        {
            connection->send(buf,handler,chunk_handler);
        });

    return;
}

void oauth_version1::set_access_token(const boost::shared_ptr<bstcon::response> response,const boost::system::error_code& ec)
{
    if(ec) return;
    if(200 <= response->status_code && response->status_code < 300)
    {
        const Param_Type parsed = parser_.urlencode(response->body);
        key_->set_access_token (parsed.at("oauth_token"));
        key_->set_access_secret(parsed.at("oauth_token_secret"));
    }
    return;
}

} // namespace detail
} // namespace oauth

#endif
