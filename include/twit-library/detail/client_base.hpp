//
// client_base.hpp
// ~~~~~~~~~~
//
// OAuthクライアントの基盤
//

#ifndef TWIT_LIB_DETAIL_CLIENT_BASE
#define TWIT_LIB_DETAIL_CLIENT_BASE

#include <algorithm>
#include <boost/noncopyable.hpp>
#include "oauth_base.hpp"
#include "../protocol.hpp"
#include "../keys/key_base.hpp"

namespace oauth{

//Version間の揺れを取るのが目的かなぁ
template<class OAuth_Version>
class client : public OAuth_Version::OAuth_Type{
public:
	client(std::shared_ptr<typename OAuth_Version::Key_Type> &key_set,std::shared_ptr<oauth::protocol::client> &client)
		: OAuth_Version::OAuth_Type(key_set,client) {}
	virtual ~client(){}
};

} // namespace oauth

#endif
