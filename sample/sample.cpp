#define USE_SSL_BOOSTCONNECT

#include <twit-library/version.hpp>
#include <twit-library/client.hpp>
#include <twit-library/client/twitter.hpp>
#include <twit-library/version/v2.hpp>
#include <twit-library/keys/key_version2.hpp>
#include <map>
#include <vector>
//
//int main()
//{
//  boost::asio::io_service io_service;
//  boost::asio::ssl::context ctx(io_service,boost::asio::ssl::context_base::sslv3_client); //SSL用
//  
//  boost::shared_ptr<oauth::keys::key_version2> key(
//    new oauth::keys::key_version2("179248975459720","65054809a265a3539770c04dc101b202"));
//
//  oauth::client<oauth::version::v2> client(key,boost::shared_ptr<bstcon::client>(new bstcon::client(io_service,ctx,bstcon::connection_type::async)));
//  //const auto str = client.authorization_request_uri("https://www.facebook.com/dialog/oauth","code","https://www.facebook.com/connect/login_success.html");
//  client.code_to_access_token("https://graph.facebook.com/oauth/authorize"
//  return 0;
//}

/*#include <boost/thread.hpp>
#include <boost/property_tree/ptree.hpp>
*/
#include <babel.h>

int main()
{
  babel::init_babel();

  //ただの準備です
  boost::asio::io_service io_service;
  boost::asio::ssl::context ctx(io_service,boost::asio::ssl::context_base::sslv3_client); //SSL用
  
//  //yahoo
//  /*{
//    boost::shared_ptr<oauth::keys::key_version1> key(
//      new oauth::keys::key_version1("consumer_key","consumer_secret"));
//    oauth::client<oauth::version::v1> client(
//      key,
//      boost::shared_ptr<bstcon::client>(new bstcon::client(io_service))
//      );
//  
//
//    client.get_request_token("POST","http://auth.login.yahoo.co.jp/oauth/v2/get_request_token");
//    const std::string auth_uri = "http://auth.login.yahoo.co.jp/oauth/v2/request_auth?oauth_token=" + key->get_access_token();
//
//    std::string pin;
//    std::cin >> pin;
//
//    client.get_access_token("POST","http://auth.login.yahoo.co.jp/oauth/v2/get_token",pin);
//  }
//  */

  {
    boost::asio::io_service io_service;
    boost::asio::ssl::context ctx(io_service,boost::asio::ssl::context_base::sslv3_client); //SSL用

    boost::shared_ptr<oauth::keys::key_version1> key(
          new oauth::keys::key_version1("consumer_key","consumer_secret"));
    oauth::twitter client(
      key,
      boost::shared_ptr<bstcon::client>(new bstcon::client(io_service,ctx,bstcon::connection_type::async))
      );

    // XAuth
    client.get_xauth_token("user_id","user_password");
    io_service.run();
    io_service.reset();

    std::map<std::string,std::string> params = boost::assign::map_list_of
      ("status",babel::sjis_to_utf8("テスト"));
    const boost::shared_ptr<bstcon::response> response
      = client.request_urlencoded("POST","https://api.twitter.com/1/statuses/update.xml",params);
    io_service.run();

  }
//  //{
//  //  boost::shared_ptr<oauth::keys::key_version1> key(
//  //    new oauth::keys::key_version1("consumer_key","consumer_secret"));
//  //  oauth::twitter client(
//  //    key,
//  //    boost::shared_ptr<bstcon::client>(new bstcon::client(io_service,ctx))
//  //    );
//
//  //  // XAuth
//  //  client.get_xauth_token("user_id","user_password");
//
//  //  std::map<std::string,std::string> params = boost::assign::map_list_of
//  //    ("status","hoge");
//  //  const boost::shared_ptr<bstcon::response> response
//  //    = client.request_urlencoded("POST","http://api.twitter.com/1/statuses/update.xml",params);
//  //}
//
//  //twitter
//  /*
//  {
//    boost::shared_ptr<oauth::keys::key_version1> key(
//      new oauth::keys::key_version1("consumer_key","consumer_secret"));
//    oauth::client<oauth::version::v1> client(
//      key,
//      boost::shared_ptr<bstcon::client>(new bstcon::client(io_service))
//      );
//  
//
//    client.get_request_token("POST","http://api.twitter.com/oauth/request_token");
//    const std::string auth_uri = "http://api.twitter.com/oauth/authorize?oauth_token=" + key->get_access_token();
//
//    std::string pin;
//    std::cin >> pin;
//
//    client.get_access_token("POST","http://api.twitter.com/oauth/access_token",pin);
//
//    std::map<std::string,std::string> params = boost::assign::map_list_of
//      ("status","hoge");
//    const boost::shared_ptr<bstcon::response> response
//      = client.request_urlencoded("POST","http://api.twitter.com/1/statuses/update.xml",params);
//  }*/
//
//  //boost::system::error_code ec;
//  //const std::string host("www.hatena.ne.jp");
//  //boost::asio::streambuf buf;
//  //std::ostream os(&buf);
//  //os << "GET / HTTP/1.1\r\nHost: " << host << "\r\nConnection: close\r\n\r\n"; //ただのリクエスト
//
//  ////
//  //// 同期・HTTP通信
//  ////
//  //{
//  //  bstcon::client client(io_service/*,oauth::protocol::connection_type::sync*/);
//  //  client(host,buf,ec);
//  //  
//  //  //終了
//  //}
//
//  ////
//  //// 同期・SSL通信
//  ////
//  //{
//  //  bstcon::client client(io_service,ctx/*,oauth::protocol::connection_type::sync*/);
//  //  client(host,buf,ec);
//
//  //  //終了
//  //}
//  
//  ////
//  //// 非同期・HTTP通信
//  ////
//  //{
//  //  bstcon::client client(io_service,oauth::protocol::connection_type::async);
//  //  client(host,buf,ec);
//
//  //  //何か
//
//  //  io_service.run(); //通信を走らせる
//
//  //  //終了
//  //  return 0;
//  //}
//
//  ////
//  //// 非同期・SSL通信
//  ////
//  //{
//  //  bstcon::client client(io_service,ctx,oauth::protocol::connection_type::async);
//  //  client(host,buf,ec);
//
//  //  //何か
//
//  //  io_service.run(); //通信を走らせる
//
//  //  //終了
//  //}
  
  return 0;
}
