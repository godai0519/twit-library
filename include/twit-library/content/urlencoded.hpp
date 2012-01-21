//
// urlencoded.hpp
// ~~~~~~~~~~
//
// Content-Type: application/x-www-form-urlencoded
//

#ifndef TWIT_LIB_CONTENT_URLENCODED
#define TWIT_LIB_CONTENT_URLENCODED

#include <map>
#include <string>
#include "content_base.hpp"
#include "../utility/authentication.hpp"

namespace oauth{
namespace content{

class urlencoded : content_base{
public:
	typedef std::map<std::string,std::sting> Param_Type;

	urlencoded(const Param_Type& body_params) : body_params_(body_params){}
	virtual ~urlencoded(){}

	const std::string get_content_type(){ return "application/x-www-form-urlencoded"; };
	const Param_Type get_addition_param(){ return body_params_; }
	const std::string get_body(){ return oauth::utility::get_urlencoded(body_params_); }

private:
	const Param_Type body_params_;
};

} // namespace content
} // namespace oauth

#endif
