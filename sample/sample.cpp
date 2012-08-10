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
//  boost::asio::io_service io_service;
//  boost::asio::ssl::context ctx(io_service,boost::asio::ssl::context_base::sslv3_client); //SSL�p
//  
//  boost::shared_ptr<oauth::keys::key_version2> key(
//    new oauth::keys::key_version2("client_id","cient_secret"));
//
//  oauth::client<oauth::version::v2> client(key,boost::shared_ptr<bstcon::client>(new bstcon::client(io_service,ctx,bstcon::connection_type::async)));
//  //const auto str = client.authorization_request_uri("https://www.facebook.com/dialog/oauth","code","https://www.facebook.com/connect/login_success.html");
//  client.code_to_access_token("https://graph.facebook.com/oauth/authorize"
//  return 0;
//}

bool loop = true;
void print(std::string* body)
{
    while(loop)
    {
      if(!body->empty())
      {
        std::cout << *body << "\n" << std::flush;
        body->erase();
      }
    }
    return;
}

int main()
{
  //�����̏����ł�
  boost::asio::io_service io_service;
  boost::asio::ssl::context ctx(io_service,boost::asio::ssl::context_base::sslv3_client); //SSL�p
  
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
    const boost::shared_ptr<bstcon::response> response
      = client.request_urlencoded("GET","https://userstream.twitter.com/2/user.json",std::map<std::string,std::string>());
    boost::thread th(boost::bind(&boost::asio::io_service::run,&io_service));
    boost::thread loop_th(boost::bind(&print,&response->body));

    th.join();
    loop = false;
    loop_th.join();
  }
  
  ////twitter
  //{
  //  boost::shared_ptr<oauth::keys::key_version1> key(
  //    new oauth::keys::key_version1("consumer_key","consumer_secret"));
  //  oauth::twitter client(
  //    key,
  //    boost::shared_ptr<bstcon::client>(new bstcon::client(io_service,ctx,bstcon::connection_type::async))
  //    );  

  //  io_service.reset();
  //  client.get_request_token();
  //  io_service.run();

  //  const std::string auth_uri = "http://api.twitter.com/oauth/authorize?oauth_token=" + key->get_access_token();    
  //  std::string pin;
  //  std::cin >> pin;

  //  io_service.reset();
  //  client.get_access_token(pin);
  //  io_service.run();
  //  
  //  std::string status;
  //  std::cin >> status;

  //  io_service.reset();
  //  std::map<std::string,std::string> params = boost::assign::map_list_of
  //    ("status",babel::sjis_to_utf8(status));
  //  const boost::shared_ptr<bstcon::response> response
  //    = client.request_urlencoded("POST","https://api.twitter.com/1/statuses/update.xml",params);
  //  io_service.run();
  //}

  return 0;
}