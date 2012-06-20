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

namespace oauth{

//Version間の揺れを取るのが目的かなぁ
template<class OAuth_Version>
class client : public OAuth_Version::OAuth_Type{
public:
  client(boost::shared_ptr<typename OAuth_Version::Key_Type> &key_set,boost::shared_ptr<bstcon::client> &client)
    : OAuth_Version::OAuth_Type(key_set,client) {}
  virtual ~client(){}
};

} // namespace oauth

#endif
