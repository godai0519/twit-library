//
// content_base.hpp
// ~~~~~~~~~~
//
// Content-TypeìôÅXê∂ê¨ägí£ëO
//

#ifndef TWIT_LIB_CONTENT_BASE
#define TWIT_LIB_CONTENT_BASE

#include <map>
#include <boost/noncopyable.hpp>

namespace oauth{
namespace content{

class content_base{
public:
  content_base(){}
  virtual ~content_base(){}

  virtual const std::string get_content_type() const { return ""; }
  virtual const std::map<std::string,std::string> get_addition_param() const { return std::map<std::string,std::string>(); }
  virtual const std::string get_body() const { return ""; }
};

} // namespace content
} // namespace oauth

#endif
