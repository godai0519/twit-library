//
// key_version1.hpp
// ~~~~~~~~~~
//
// OAuth Keyの集合体，Version1用拡張
//

#ifndef TWIT_LIB_KEYS_VERSION_1
#define TWIT_LIB_KEYS_VERSION_1

#include <string>
#include <boost/noncopyable.hpp>
#include "../utility/authentication.hpp"

namespace oauth{
namespace keys{

class key_version1 : boost::noncopyable{
    std::string consumer_key_;
    std::string consumer_secret_;
    std::string access_token_;
    std::string access_secret_;

public:
    key_version1(){}
    key_version1(const std::string& consumer_key,const std::string& consumer_secret)
        : consumer_key_(consumer_key), consumer_secret_(consumer_secret) { }
    key_version1(const std::string& consumer_key,const std::string& consumer_secret,const std::string& access_token,const std::string& access_secret)
        : consumer_key_ (consumer_key), consumer_secret_(consumer_secret), access_token_(access_token), access_secret_(access_secret) {}
    virtual ~key_version1(){}
    
    //setter
    void set_consumer_key     (const std::string& consumer_key)     { consumer_key_ = consumer_key; }
    void set_consumer_secret(const std::string& consumer_secret){ consumer_secret_ = consumer_secret; }
    void set_access_token     (const std::string& access_token)     { access_token_ = access_token; }
    void set_access_secret    (const std::string& access_secret)    { access_secret_ = access_secret; }

    //getter
    const std::string get_consumer_key()        const { return consumer_key_; }
    const std::string get_consumer_secret() const { return consumer_secret_; }
    const std::string get_access_token()        const { return access_token_; }
    const std::string get_access_secret()     const { return access_secret_; }
    const std::string get_signature_key()     const { return oauth::utility::url_encode(consumer_secret_) + "&" + oauth::utility::url_encode(access_secret_);};
};

} // namespace keys
} // namespace oauth

#endif
