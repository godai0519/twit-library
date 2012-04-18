//
// oauth_base.hpp
// ~~~~~~~~~~
//
// OAuth‚Ì—h‚ê‚ğ§Œä‚·‚éƒx[ƒX
//

#ifndef TWIT_LIB_DETAIL_OAUTH_BASE
#define TWIT_LIB_DETAIL_OAUTH_BASE

#include <algorithm>
#include <boost/noncopyable.hpp>
#include <boostconnect/client.hpp>

namespace oauth{
namespace detail{

class oauth_base : boost::noncopyable{
public:
	typedef std::map<std::string,std::string> Param_Type;
	oauth_base(){}
	virtual ~oauth_base(){}
protected:
	boost::shared_ptr<bstcon::client> client_;
};

} // namespace detail
} // namespace oauth

#endif
