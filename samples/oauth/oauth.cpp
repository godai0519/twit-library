#include <iostream>
#include <vector>
#include "../../include/oauth.hpp"

//1.コンシューマキーとコンシューマシークレットを入手します
//2.これらに貼り付けて、defineにてください
//1.Get ConsumerKey and ConsumerSecret.
//2.Paste those defines.
#define CONSUMER_KEY			"Please ConsumerKey"
#define CONSUMER_SECRET		"Please ConsumerSecret"

int main(){
	std::cout << "Standby...";
	
	//OAuth用のクラスを作成します
	//もしSSL通信を使うのであれば oauth::client::twitter<oauth::protocol::https<>> oauth_base; にしてください
	//Make OAuth Class
	//If use SSL "oauth::client::twitter<oauth::protocol::https<>> oauth_base;"
	oauth::client::client_base<oauth::protocol::http> oauth_base;

	//ホストのアドレスを指定します
	//Host Address are Setting
	oauth_base.set_host("api.twitter.com");

	//コンシューマキーとコンシューマシークレットを登録します
	//ConsumerKey and ConsumerSecret are Setting
	oauth_base.set_consumer(CONSUMER_KEY,CONSUMER_SECRET);

	std::cout << "\n\nConnect...";

	//OAuth認証(リクエストトークン取得)
	//OAuth Authorize(Request Token)
	oauth_base.oauth_req("/oauth/request_token");

	//ピンを取得します
	//PIN Gets
	char pin[16];
	std::cout << "\n\n" << oauth_base.oauth_authorize("http://api.twitter.com/oauth/authorize") << "\n";
	std::cout << "Please PIN:";
	std::cin >> pin;

	//OAuth認証(アクセストークン取得)
	//OAuth Authorize(Accsess Token)
	oauth_base.oauth_acc(pin,"/oauth/access_token");

	//APIの使用
	//Use APIs
	{
		//application/x-www-form-urlencoded
		oauth::param_type status;
		status["status"] = util::url::encode("TEST TWEET");
		oauth_base.request("POST","/statuses/update.xml",status);

		//multipart/form-data
		std::vector<oauth::content::multipart_form_data> datas;
		oauth::content::multipart_form_data(oauth::content::content_type::Image,"image","---file_path---/","---file_name---");
		oauth_base.request("POST","/account/update_profile_image.json",datas);
		
		//etc.
	}
}