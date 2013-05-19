#ifndef TWIT_LIB_KEYS_VERSION_1_IPP
#define TWIT_LIB_KEYS_VERSION_1_IPP

#include <string>
#include <iterator>
#include "../key_version1.hpp"
#include "../../utility/percent_encoding.hpp"

namespace oauth{
namespace keys{

key_version1::key_version1()
{
}
key_version1::key_version1(const std::string& consumer_key, const std::string& consumer_secret)
    : consumer_key_(consumer_key), consumer_secret_(consumer_secret)
{
}
key_version1::key_version1(const std::string& consumer_key, const std::string& consumer_secret, const std::string& access_token, const std::string& access_secret)
    : consumer_key_ (consumer_key), consumer_secret_(consumer_secret), access_token_(access_token), access_secret_(access_secret)
{
}
key_version1::~key_version1()
{
}
    
//setter
void key_version1::set_consumer_key     (const std::string& consumer_key)     { consumer_key_ = consumer_key; }
void key_version1::set_consumer_secret  (const std::string& consumer_secret)  { consumer_secret_ = consumer_secret; }
void key_version1::set_access_token     (const std::string& access_token)     { access_token_ = access_token; }
void key_version1::set_access_secret    (const std::string& access_secret)    { access_secret_ = access_secret; }

//getter
const std::string key_version1::get_consumer_key()    const { return consumer_key_; }
const std::string key_version1::get_consumer_secret() const { return consumer_secret_; }
const std::string key_version1::get_access_token()    const { return access_token_; }
const std::string key_version1::get_access_secret()   const { return access_secret_; }
const std::string key_version1::get_signature_key()   const
{
    std::string key;
    std::back_insert_iterator<std::string> out(key);

    encoder_.encode(consumer_secret_.cbegin(), consumer_secret_.cend(), out);
    *out++ = '&';
    encoder_.encode(access_secret_.cbegin(),   access_secret_.cend(),   out);

    return key;
}

} // namespace keys
} // namespace oauth

#endif
