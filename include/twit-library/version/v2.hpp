//
// v2.hpp
// ~~~~~~~~~~
//
// OAuth2.0用，定義リスト
//

#ifndef TWIT_LIB_VERSION_2
#define TWIT_LIB_VERSION_2

#include "../detail/oauth_version2.hpp"
#include "../keys/key_version2.hpp"

namespace oauth{
namespace version{

class v2{
public:
  typedef oauth::detail::oauth_version2  OAuth_Type;
  typedef oauth::keys::key_version2      Key_Type;
private:
  v2(){}
};

} // namespace version
} // namespace oauth

#endif
