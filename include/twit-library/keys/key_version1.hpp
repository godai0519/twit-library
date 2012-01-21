//
// key_version1.hpp
// ~~~~~~~~~~
//
// OAuth Key‚ÌW‡‘ÌCVersion1—pŠg’£
//

#ifndef TWIT_LIB_KEYS_VERSION_1
#define TWIT_LIB_KEYS_VERSION_1

#include "key_base.hpp"
#include "../utility/authentication.hpp"

namespace oauth{
namespace keys{

class key_version1 : public key_base{
public:
	key_version1(){}
	key_version1(const std::string& consumer_key,const std::string& consumer_secret)
	{
		consumer_key_ = consumer_key;
		consumer_secret_ = consumer_secret;
	}
	key_version1(const std::string& consumer_key,const std::string& consumer_secret,const std::string& access_token,const std::string& access_secret)
	{
		consumer_key_ = consumer_key;
		consumer_secret_ = consumer_secret;
		access_token_ = access_token;
		access_secret_ = access_secret;
	}
	virtual ~key_version1(){}
	
	//setter
	void set_consumer_key   (const std::string& consumer_key)   { consumer_key_ = consumer_key; }
	void set_consumer_secret(const std::string& consumer_secret){ consumer_secret_ = consumer_secret; }

	//getter
	std::string get_consumer_key()   { return consumer_key_; }
	std::string get_consumer_secret(){ return consumer_secret_; }
	std::string get_signature_key(){ return oauth::utility::url_encode(consumer_secret_) + "&" + oauth::utility::url_encode(access_secret_);};

private:
	std::string consumer_key_;
	std::string consumer_secret_;
};

} // namespace keys
} // namespace oauth

#endif
