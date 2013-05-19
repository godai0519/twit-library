//
// key_version2.hpp
// ~~~~~~~~~~
//
// OAuth Keyの集合体，Version2用拡張
//

#ifndef TWIT_LIB_KEYS_VERSION_2_HPP
#define TWIT_LIB_KEYS_VERSION_2_HPP

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
    key_version2();
    key_version2(const std::string& client_id, const std::string& client_secret);
    ~key_version2();

    //setter
    void set_client_id(const std::string& client_id);
    void set_client_secret(const std::string& client_secret);
    void set_access_token(const std::string& access_token);

    //getter
    const std::string get_client_id() const;
    const std::string get_client_secret() const;
    const std::string get_access_token() const;
};

} // namespace keys
} // namespace oauth

#ifdef TWIT_LIB_BUILD
#include "impl/key_version2.ipp"
#endif

#endif
