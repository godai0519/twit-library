//
// client.hpp
// ~~~~~~~~~~
//
// OAuth認証の主要ファイルの寄せ集め
//

#ifndef TWIT_LIB_CLIENT
#define TWIT_LIB_CLIENT

#include "detail/oauth_version1.hpp"
#include "detail/oauth_version2.hpp"

namespace oauth{
  typedef oauth::detail::oauth_version1 client_v1;
  typedef oauth::detail::oauth_version2 client_v2;
}

#endif
