#include <iostream>
#include "../../include/twitter.hpp"

//1.コンシューマキーとコンシューマシークレットを入手します
//2.これらに貼り付けて、defineにてください
//1.Get ConsumerKey and ConsumerSecret.
//2.Paste those defines.
#define CONSUMER_KEY			"Please ConsumerKey"
#define CONSUMER_SECRET		"Please ConsumerSecret"

int main()
{
	std::cout << "Standby...";
	
	//Twitter用のクラスを作成します
	//もしSSL通信を使うのであれば oauth::client::twitter<oauth::protocol::https<>> oauth_base; にしてください
	//Make Twitter Class
	//If use SSL oauth::client::twitter<oauth::protocol::https<>> twitter;
	oauth::client::twitter<oauth::protocol::http> twitter;
	
	//コンシューマキーとコンシューマシークレットを登録します
	//ConsumerKey and ConsumerSecret are Settings
	twitter.set_consumer(CONSUMER_KEY,CONSUMER_SECRET);

	std::cout << "\n\nConnect...";

	//OAuth認証を使用
	//Use OAuth
	{
		//OAuth認証(リクエストトークン取得)
		//OAuth Authorize(Request Token)
		twitter.oauth_req();

		//ピンを取得します
		//PIN Gets
		char pin[16];
		std::cout << "\n\n" << twitter.oauth_authorize() << "\n";
		std::cout << "Please PIN:";
		std::cin >> pin;

		//OAuth認証(アクセストークン取得)
		//OAuth Authorize(Accsess Token)
		twitter.oauth_acc(pin);
	}

	//xAuth認証を使用
	//Use xAuth
	{
		//IDとPasswordで認証します
		//Authorize with ID and Password.
		twitter.xauth("---user_ID---","---PassWord--");
	}

	//APIの使用
	//Use APIs
	{
		//ツイート
		//Tweet
		oauth::param_type status;
		status["status"] = util::url::encode("TEST TWEET");
		twitter.request("POST","/statuses/update.xml",status);

		//写真のアップロード
		//Picture Upload
		std::vector<oauth::content::multipart_form_data> datas;
		oauth::content::multipart_form_data(oauth::content::content_type::Image,"image","---file_path---/","---file_name---");
		twitter.request("POST","/account/update_profile_image.json",datas);

		//Twitpicの使用
		//Use TwitPic
		twitter.twitpic_upload("xml","---image_path---/","---image_name---","test message");

		//etc.
	}
}