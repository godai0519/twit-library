//
// key_version2.hpp
// ~~~~~~~~~~
//
// OAuth Key‚ÌW‡‘ÌCVersion2—pŠg’£
//

#ifndef TWIT_LIB_KEYS_VERSION_2
#define TWIT_LIB_KEYS_VERSION_2

#include <string>
#include <boost/noncopyable.hpp>

namespace oauth{
namespace keys{

class key_version2 : boost::noncopyable{
    //std::string response_type_ = "code"; //(REQUIRED)
    std::string client_id_; //(REQUIRED)
    std::string client_secret_; //(REQUIRED)
    std::string access_token_;
    //std::string redirect_uri_ = "urn:ietf:wg:oauth:2.0:oob"; //(REQUIRED)

public:
    key_version2(){}
    key_version2(const std::string& client_id,const std::string& client_secret)
        : client_id_(client_id), client_secret_(client_secret){}
    ~key_version2(){}

    //setter
    void set_client_id(const std::string& client_id){ client_id_ = client_id; }
    void set_client_secret(const std::string& client_secret){ client_secret_ = client_secret; }
    void set_access_token     (const std::string& access_token)     { access_token_ = access_token; }

    //getter
    const std::string get_client_id() const { return client_id_; }
    const std::string get_client_secret() const { return client_secret_; }
    const std::string get_access_token() const { return access_token_; }
};

} // namespace keys
} // namespace oauth

#endif
