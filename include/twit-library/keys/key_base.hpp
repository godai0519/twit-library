//
// key_base.hpp
// ~~~~~~~~~~
//
// OAuthクライアントの基盤
//

#ifndef TWIT_LIB_KEYS_BASE
#define TWIT_LIB_KEYS_BASE

#include <string>
#include <boost/noncopyable.hpp>

namespace oauth{
namespace keys{

class key_base : boost::noncopyable{
public:
	key_base(){}
	key_base(const std::string& access_token,const std::string& access_secret) //token,secret初期化
	{
		access_token_  = access_token;
		access_secret_ = access_secret;
	}
	virtual ~key_base(){}

	//setter
	void set_access_token (const std::string& access_token) { access_token_ = access_token; }
	void set_access_secret(const std::string& access_secret){ access_secret_ = access_secret; }

	//getter
	std::string get_access_token() { return access_token_; }
	std::string get_access_secret(){ return access_secret_; }

	//派生クラスに丸投げ
	virtual std::string get_signature_key() = 0;

protected:
	std::string access_token_;
	std::string access_secret_;
};

} // namespace keys
} // namespace oauth

#endif
