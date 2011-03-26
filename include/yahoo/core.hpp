#ifndef YAHOO_CORE_HPP
#define YAHOO_CORE_HPP

namespace oauth{
	namespace client{
		//template<class Protocol_Type>
		class yahoo : public oauth::client::client_base<oauth::protocol::https<>>, public oauth::client::client_base<oauth::protocol::http>
		{
		public:
			typedef oauth::client::client_base<oauth::protocol::https<>> https;
			typedef oauth::client::client_base<oauth::protocol::http> http;

			yahoo(){}
			~yahoo(){}
			
			//
			// トークンの有効期限の確認
			// 戻り値: -1･･･有効期限切れ
			// 戻り値:  0･･･有効期限内、トークン有効
			//
			int oauth_token_expires()
			{
				//現在時間を取得
				unsigned int now = std::atoi(util::make_time().c_str());

				//前回取得時の時間と有効期限を足した物が、現在時刻より前なら-1を返す
				if((token_gettime_+expires_)<now)	return -1;

				return 0;
			}
		
			//
			// リクエストトークン取得(オーバーライド)
			//
			// Yahoo特有の認証。
			res_type oauth_req()
			{
				set_host("auth.login.yahoo.co.jp");
				string_type path = "/oauth/v2/get_request_token";

				//通信用クラス生成
				https::client_  = new oauth::protocol::https<>(https::io_service_);

				//基本情報の用意
				const string_type method = "POST";
				const string_type url = https::client_->protocol()+"://"+host_+path;

				//列挙
				param_type args = https::get_request_args();
				args["oauth_callback"]="oob";

				//ボディーの生成
				auto body = util::map::serialization(https::make_request_signature(method,url,args));

				//ヘッダーの作成
				param_type head;
				head["Content-Type"] = "application/x-www-form-urlencoded";
				

				//通信
				boost::asio::streambuf buffer;
				https::client_->write(
					host_,
					&https::make_request(buffer,method,host_,path,head,body)
					);
				https::io_service_.run();

				string_type res;
				https::client_->read(res);
				delete https::client_;
				https::client_=NULL;
			
				param_type res_sort = util::map::deserialization(res);
				access_token_ = util::url::decode(res_sort["oauth_token"]);
				access_token_secret_ = util::url::decode(res_sort["oauth_token_secret"]);

				return res;
			}

			//
			// authorizeのURLを取得(オーバーライド)
			//
			string_type oauth_authorize() const
			{
				return https::oauth_authorize("https://auth.login.yahoo.co.jp/oauth/v2/request_auth");
			}


			// authorizeのPINを元にアクセストークンを取得
			// Yahoo特有の認証。
			// pin : *******
			res_type oauth_acc(const std::string& pin)
			{
				set_host("auth.login.yahoo.co.jp");
				const string_type path = "/oauth/v2/get_token";

				//通信用クラス生成
				https::client_  = new oauth::protocol::https<>(https::io_service_);

				//基本情報の用意
				const string_type method = "POST";
				const string_type url = https::client_->protocol()+"://"+host_+path;

				const string_type key =util::url::encode(consumer_secret_)+"&"+util::url::encode(access_token_secret_);
				auto args = https::get_basic_args();
				args["oauth_verifier"]=pin; 
				args["oauth_signature"] = util::crypt::signature(key,method+"&"+util::url::encode(url)+"&"+util::url::encode(util::map::serialization(args)));
				
				//タイムスタンプの時間を記録
				token_gettime_ = std::atoi(args["oauth_timestamp"].c_str());

				//ヘッダーの作成
				param_type head;
				head["Content-Type"] = "application/x-www-form-urlencoded";
				
				//ボディーの生成
				auto body = util::map::serialization(args);

				//通信
				boost::asio::streambuf buffer;
				https::client_->write(
					host_,
					&https::make_request(buffer,method,host_,path,head,body)
					);
				https::io_service_.run();

				string_type res;
				https::client_->read(res);
				delete https::client_;
				https::client_=NULL;
			
				param_type res_sort = util::map::deserialization(res);
				access_token_ = util::url::decode(res_sort["oauth_token"]);
				access_token_secret_ = util::url::decode(res_sort["oauth_token_secret"]);
				expires_ = std::atoi(res_sort["oauth_expires_in"].c_str());
				session_handle_ = res_sort["oauth_session_handle"];
				return res;
			}

			//
			// Yahoo専用AccessTokenの更新
			//
			res_type oauth_acc_update()
			{
				set_host("auth.login.yahoo.co.jp");
				const string_type path = "/oauth/v2/get_token";
				
				//通信用クラス生成
				https::client_  = new oauth::protocol::https<>(https::io_service_);
				
				const string_type method = "POST";
				const string_type url = https::client_->protocol()+"://"+host_+path;

				const string_type key =util::url::encode(consumer_secret_)+"&"+util::url::encode(access_token_secret_);
				auto args = https::get_basic_args();
				args["oauth_session_handle"] = session_handle_;
				args["oauth_signature"] = util::crypt::signature(key,method+"&"+util::url::encode(url)+"&"+util::url::encode(util::map::serialization(args)));
				
				//タイムスタンプの時間を記録
				token_gettime_ = std::atoi(args["oauth_timestamp"].c_str());

				//ヘッダーの作成
				param_type head;
				head["Content-Type"] = "application/x-www-form-urlencoded";
				
				//ボディーの生成
				auto body = util::map::serialization(args);
				
				//通信
				boost::asio::streambuf buffer;
				https::client_->write(
					host_,
					&https::make_request(buffer,method,host_,path,head,body)
					);
				https::io_service_.run();

				string_type res;
				https::client_->read(res);
				delete https::client_;
				https::client_=NULL;

				param_type res_sort = util::map::deserialization(res);
				access_token_		= util::url::encode(res_sort["oauth_token"]);
				access_token_secret_ = util::url::encode(res_sort["oauth_token_secret"]);
				expires_ = std::atoi(res_sort["oauth_expires_in"].c_str());
				session_handle_ = res_sort["oauth_session_handle"];
			}
			
			res_type request(const string_type& host,const string_type& method,const string_type& path,param_type& add_arg=param_type())
			{
				http::set_host(host);
				return http::request(method,path,add_arg);
			}
			res_type request(const string_type& host,const string_type& method,const string_type& path,const std::vector<oauth::content::multipart_form_data>& data)
			{
				http::set_host(host);
				return http::request(method,path,data);
			}
			res_type request(const oauth::api::yahoo_base *api_type)
			{
				return http::request(api_type);
			}

		private:
			string_type session_handle_;
			unsigned int expires_;
			unsigned int token_gettime_;
		};
	}//End client namespace
}//End oauth namespace

#endif
