//
// oauth_version2.hpp
// ~~~~~~~~~~
//
// OAuth Version2ópägí£
//

#ifndef TWIT_LIB_DETAIL_OAUTH_VER_2
#define TWIT_LIB_DETAIL_OAUTH_VER_2

#include "../protocol/client.hpp"
#include "../keys/key_version2.hpp"
#include "oauth_base.hpp"

namespace oauth{
namespace detail{

class oauth_version2 : public oauth_base{
public:
	typedef oauth::keys::key_version2 Key_Type;
	oauth_version2(std::shared_ptr<Key_Type> &key,std::shared_ptr<oauth::protocol::client> &client)
	{
		key_ = key;
		client_ = client;
	}
	virtual ~oauth_version2(){}
protected:
	std::shared_ptr<Key_Type> key_;
	std::shared_ptr<oauth::protocol::client> client_;
};

} // namespace detail
} // namespace oauth

#endif
