#include <twit-library/version.hpp>
#include <twit-library/client.hpp>
#include <map>
#include <vector>
/*#include <boost/thread.hpp>
#include <boost/property_tree/ptree.hpp>
*/

int main()
{
	//ただの準備です
	boost::asio::io_service io_service;
	boost::asio::ssl::context ctx(io_service,boost::asio::ssl::context_base::sslv3_client); //SSL用
	
	//yahoo
	{
		std::shared_ptr<oauth::keys::key_version1> key(
			new oauth::keys::key_version1("consumer_key","consumer_secret"));
		oauth::client<oauth::version::v1> client(
			key,
			std::shared_ptr<oauth::protocol::client>(new oauth::protocol::client(io_service,ctx))
			);
	

		client.get_request_token("POST","https://auth.login.yahoo.co.jp/oauth/v2/get_request_token");
		const std::string auth_uri = "https://auth.login.yahoo.co.jp/oauth/v2/request_auth?oauth_token=" + key->get_access_token();

		std::string pin;
		std::cin >> pin;

		client.get_access_token("POST","https://auth.login.yahoo.co.jp/oauth/v2/get_token",pin);
	}

	//twitter
	{
		std::shared_ptr<oauth::keys::key_version1> key(
			new oauth::keys::key_version1("consumer_key","consumer_secret"));
		oauth::client<oauth::version::v1> client(
			key,
			std::shared_ptr<oauth::protocol::client>(new oauth::protocol::client(io_service,ctx))
			);
	

		client.get_request_token("POST","https://api.twitter.com/oauth/request_token");
		const std::string auth_uri = "http://api.twitter.com/oauth/authorize?oauth_token=" + key->get_access_token();

		std::string pin;
		std::cin >> pin;

		client.get_access_token("POST","http://api.twitter.com/oauth/access_token",pin);

		std::map<std::string,std::string> params = boost::assign::map_list_of
			("status","hoge");
		const std::shared_ptr<oauth::protocol::response_reader::response_container> response
			= client.request_urlencoded("POST","https://api.twitter.com/1/statuses/update.xml",params);
	}

	//boost::system::error_code ec;
	//const std::string host("www.hatena.ne.jp");
	//boost::asio::streambuf buf;
	//std::ostream os(&buf);
	//os << "GET / HTTP/1.1\r\nHost: " << host << "\r\nConnection: close\r\n\r\n"; //ただのリクエスト

	////
	//// 同期・HTTP通信
	////
	//{
	//	oauth::protocol::client client(io_service/*,oauth::protocol::connection_type::sync*/);
	//	client(host,buf,ec);
	//	
	//	//終了
	//}

	////
	//// 同期・SSL通信
	////
	//{
	//	oauth::protocol::client client(io_service,ctx/*,oauth::protocol::connection_type::sync*/);
	//	client(host,buf,ec);

	//	//終了
	//}
	
	////
	//// 非同期・HTTP通信
	////
	//{
	//	oauth::protocol::client client(io_service,oauth::protocol::connection_type::async);
	//	client(host,buf,ec);

	//	//何か

	//	io_service.run(); //通信を走らせる

	//	//終了
	//	return 0;
	//}

	////
	//// 非同期・SSL通信
	////
	//{
	//	oauth::protocol::client client(io_service,ctx,oauth::protocol::connection_type::async);
	//	client(host,buf,ec);

	//	//何か

	//	io_service.run(); //通信を走らせる

	//	//終了
	//}
	
	return 0;
}
