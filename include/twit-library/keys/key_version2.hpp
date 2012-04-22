//
// key_version2.hpp
// ~~~~~~~~~~
//
// OAuth Key‚ÌW‡‘ÌCVersion2—pŠg’£
//

#ifndef TWIT_LIB_KEYS_VERSION_2
#define TWIT_LIB_KEYS_VERSION_2

#include "key_base.hpp"

namespace oauth{
namespace keys{

class key_version2 : public key_base{
public:
  key_version2(){}
  virtual ~key_version2(){}

  //setter
  void set_client_id(const std::string& client_id){ client_id_ = client_id; }

  //getter
  std::string get_client_id(){ return client_id_; }
  std::string get_signature_key(){ return client_id_;}; //tekito-


private:
  //std::string response_type_ = "code"; //(REQUIRED)
  std::string client_id_; //(REQUIRED)
  //std::string redirect_uri_ = "urn:ietf:wg:oauth:2.0:oob"; //(REQUIRED)
};

} // namespace keys
} // namespace oauth

#endif
