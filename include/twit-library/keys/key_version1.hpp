//
// key_version1.hpp
// ~~~~~~~~~~
//
// OAuth Keyの集合体，Version1用拡張
//

#ifndef TWIT_LIB_KEYS_VERSION_1_HPP
#define TWIT_LIB_KEYS_VERSION_1_HPP

#include <string>
#include <boost/noncopyable.hpp>
#include "../utility/percent_encoding.hpp"

namespace oauth{
namespace keys{

class key_version1 : boost::noncopyable{
    std::string consumer_key_;
    std::string consumer_secret_;
    std::string access_token_;
    std::string access_secret_;

public:
    key_version1();
    key_version1(const std::string& consumer_key, const std::string& consumer_secret);
    key_version1(const std::string& consumer_key, const std::string& consumer_secret, const std::string& access_token, const std::string& access_secret);
    virtual ~key_version1();
    
    //setter
    void set_consumer_key     (const std::string& consumer_key);
    void set_consumer_secret  (const std::string& consumer_secret);
    void set_access_token     (const std::string& access_token);
    void set_access_secret    (const std::string& access_secret);

    //getter
    const std::string get_consumer_key()    const;
    const std::string get_consumer_secret() const;
    const std::string get_access_token()    const;
    const std::string get_access_secret()   const;
    const std::string get_signature_key()   const;

private:
    const oauth::utility::percent_encoder encoder_;
};

} // namespace keys
} // namespace oauth

#ifdef TWIT_LIB_BUILD
#include "impl/key_version1.ipp"
#endif

#endif
