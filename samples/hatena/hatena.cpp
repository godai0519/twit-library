#include <iostream>
#include <vector>
#include "../../include/hatena.hpp"


//1.コンシューマキーとコンシューマシークレットを入手します
//2.これらに貼り付けて、defineにてください
//1.Get ConsumerKey and ConsumerSecret.
//2.Paste those defines.
#define CONSUMER_KEY			"Please ConsumerKey"
#define CONSUMER_SECRET		"Please ConsumerSecret"

int main(){
	std::cout << "Standby...";
	
	//はてな用のクラスを作成します
	//Make Hatena Class
	oauth::client::hatena hatena;

	//コンシューマキーとコンシューマシークレットを登録します
	//ConsumerKey and ConsumerSecret are Setting
	hatena.set_consumer(CONSUMER_KEY,CONSUMER_SECRET);

	std::cout << "\n\nConnect...";
	
	//OAuth認証(リクエストトークン取得)
	//Scopeについての参照 : http://developer.hatena.ne.jp/ja/documents/auth/apis/oauth/scopes
	//スコープをコンマでつなげてください
	//OAuth Authorize(Request Token)
	//Scope Reference : http://developer.hatena.ne.jp/ja/documents/auth/apis/oauth/scopes
	//Combines with a comma
	hatena.oauth_req("read_public,read_private");

	//ピンを取得します
	//PIN Gets
	char pin[16];
	std::cout << "\n\n" << hatena.oauth_authorize() << "\n";
	std::cout << "Please PIN:";
	std::cin >> pin;

	//OAuth認証(アクセストークン取得)
	//OAuth Authorize(Accsess Token)
	hatena.oauth_acc(pin);

	//APIの使用
	//Use APIs
	{
		hatena.set_host("b.hatena.ne.jp");
		hatena.request("GET","/atom");

		//etc.
	}
}