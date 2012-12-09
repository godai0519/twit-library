#define USE_SSL_BOOSTCONNECT

#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include <twit-library/client.hpp>
#include <twit-library/client/twitter.hpp>
#include <twit-library/client/yahoo.hpp>
#include <twit-library/keys/key_version2.hpp>
#include <map>
#include <vector>
//
//int main()
//{
//    boost::asio::io_service io_service;
//    boost::asio::ssl::context ctx(io_service,boost::asio::ssl::context_base::sslv3_client); //SSL用
//    
//    boost::shared_ptr<oauth::keys::key_version2> key(
//        new oauth::keys::key_version2("client_id","cient_secret"));
//
//    oauth::client<oauth::version::v2> client(key,boost::shared_ptr<bstcon::client>(new bstcon::client(io_service,ctx,bstcon::connection_type::async)));
//    //const auto str = client.authorization_request_uri("https://www.facebook.com/dialog/oauth","code","https://www.facebook.com/connect/login_success.html");
//    client.code_to_access_token("https://graph.facebook.com/oauth/authorize"
//    return 0;
//}

int main()
{
    std::map<std::string,std::string> map;
    map["Test1"] = "Test1";
    map["Test2"] = "Test2";

    oauth::utility::generator g;
    std::string generated(g.authorization_field(map));

    oauth::utility::parser p;
    std::map<std::string,std::string> reparsed(p.authorization_field(generated));

    //ただの準備です
    boost::asio::io_service io_service;
    boost::asio::ssl::context ctx(io_service,boost::asio::ssl::context_base::sslv3_client); //SSL用
    
//    //yahoo
//    {
//        boost::shared_ptr<oauth::keys::key_version1> key(
//            new oauth::keys::key_version1("consumer_key","consumer_secret"));
//        oauth::client<oauth::version::v1> client(
//            key,
//            boost::shared_ptr<bstcon::client>(new bstcon::client(io_service))
//            );
//    
//
//        client.get_request_token("POST","http://auth.login.yahoo.co.jp/oauth/v2/get_request_token");
//        const std::string auth_uri = "http://auth.login.yahoo.co.jp/oauth/v2/request_auth?oauth_token=" + key->get_access_token();
//
//        std::string pin;
//        std::cin >> pin;
//
//        client.get_access_token("POST","http://auth.login.yahoo.co.jp/oauth/v2/get_token",pin);
//    }

    {
        boost::shared_ptr<oauth::keys::key_version1> key(
            new oauth::keys::key_version1("consumer_key","consumer_secret"));

        boost::shared_ptr<bstcon::client> connect_client(new bstcon::client(io_service,ctx,bstcon::connection_type::async));
        oauth::twitter client(
            key,
            connect_client
            );

        // XAuth
        io_service.reset();
        client.get_xauth_token("user_id","password");
        io_service.run();
        
        io_service.reset();

        std::cout << 
           "       Consumer key: " << key->get_consumer_key() << std::endl <<
           "    Consumer secret: " << key->get_consumer_secret() << std::endl <<
           "       Access token: " << key->get_access_token() << std::endl <<
           "Access token secret: " << key->get_access_secret() << std::endl;

        //userstream
        client.request_urlencoded(
            "GET",
            "https://userstream.twitter.com/2/user.json",
            std::map<std::string,std::string>(),
            [](const boost::shared_ptr<bstcon::response>,const boost::system::error_code&)->void{},
            [](const boost::shared_ptr<bstcon::response> res,const boost::system::error_code&)->void{
                std::cout << res->body << std::flush;
                res->body.erase();
            });
        
        ////送ってみるテスト
        //std::map<std::string,std::string> params2 = boost::assign::map_list_of
        //    ("status","D godai_0519 aaaaaaaaaaaaaaaaa");
        //client.request_urlencoded("POST","https://api.twitter.com/1/statuses/update.xml",params2);
        //
        //std::map<std::string,std::string> params3 = boost::assign::map_list_of
        //    ("status","D godai_0519 bbbbbbbbbbbbbbbbb");
        //client.request_urlencoded("POST","https://api.twitter.com/1/statuses/update.xml",params3);

        //std::map<std::string,std::string> params4 = boost::assign::map_list_of
        //    ("status","D godai_0519 ccccccccccccccccc");
        //client.request_urlencoded("POST","https://api.twitter.com/1/statuses/update.xml",params4);

        //std::map<std::string,std::string> params5 = boost::assign::map_list_of
        //    ("status","D godai_0519 ddddddddddddddddd");
        //client.request_urlencoded("POST","https://api.twitter.com/1/statuses/update.xml",params5);

        //std::map<std::string,std::string> params6 = boost::assign::map_list_of
        //    ("status","D godai_0519 eeeeeeeeeeeeeeeee");
        //client.request_urlencoded("POST","https://api.twitter.com/1/statuses/update.xml",params6);

        //std::map<std::string,std::string> params7 = boost::assign::map_list_of
        //    ("status","D godai_0519 fffffffffffffffff");
        //client.request_urlencoded("POST","https://api.twitter.com/1/statuses/update.xml",params7);

        //実行
        io_service.run();
    }

    return 0;
}
