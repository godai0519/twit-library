//
// v1.hpp
// ~~~~~~~~~~
//
// OAuth1.0用，定義リスト
//

#ifndef TWIT_LIB_VERSION_1
#define TWIT_LIB_VERSION_1

#include "../detail/oauth_version1.hpp"
#include "../keys/key_version1.hpp"

namespace oauth{
namespace version{

class v1{
public:
	typedef oauth::detail::oauth_version1	OAuth_Type;
	typedef oauth::keys::key_version1		Key_Type;
private:
	v1(){}
};

} // namespace version
} // namespace oauth

#endif
