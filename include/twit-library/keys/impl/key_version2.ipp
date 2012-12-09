#ifndef TWIT_LIB_KEYS_VERSION_2_IPP
#define TWIT_LIB_KEYS_VERSION_2_IPP

#include <string>
#include "../key_version2.hpp"

namespace oauth{
namespace keys{

key_version2::key_version2()
{
}
key_version2::key_version2(const std::string& client_id,const std::string& client_secret)
        : client_id_(client_id), client_secret_(client_secret)
{
}
key_version2::~key_version2()
{
}

//setter
void key_version2::set_client_id(const std::string& client_id)
{
    client_id_ = client_id;
}
void key_version2::set_client_secret(const std::string& client_secret)
{
    client_secret_ = client_secret;
}
void key_version2::set_access_token(const std::string& access_token)
{
    access_token_ = access_token;
}

//getter
const std::string key_version2::get_client_id() const
{
    return client_id_;
}
const std::string key_version2::get_client_secret() const
{
    return client_secret_;
}
const std::string key_version2::get_access_token() const
{
    return access_token_;
}

} // namespace keys
} // namespace oauth

#endif
