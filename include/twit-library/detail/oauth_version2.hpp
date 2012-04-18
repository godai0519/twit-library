//
// oauth_version2.hpp
// ~~~~~~~~~~
//
// OAuth Version2ópägí£
//

#ifndef TWIT_LIB_DETAIL_OAUTH_VER_2
#define TWIT_LIB_DETAIL_OAUTH_VER_2

#include "../keys/key_version2.hpp"
#include "oauth_base.hpp"

namespace oauth{
namespace detail{

class oauth_version2 : public oauth_base{
public:
	typedef oauth::keys::key_version2 Key_Type;
	oauth_version2(boost::shared_ptr<Key_Type> &key,boost::shared_ptr<bstcon::client> &client)
	{
		key_ = key;
		client_ = client;
	}
	virtual ~oauth_version2(){}
protected:
	boost::shared_ptr<Key_Type> key_;
	boost::shared_ptr<bstcon::client> client_;
};

} // namespace detail
} // namespace oauth

#endif
