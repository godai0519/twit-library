//
// multipart_form_data.hpp
// ~~~~~~~~~~
//
// Content-Type: multipart/form-data; boundary=~~
//

#ifndef TWIT_LIB_CONTENT_MULTIPART_FORM_DATA
#define TWIT_LIB_CONTENT_MULTIPART_FORM_DATA

#include <map>
#include <string>
#include "multipart_content_base.hpp"
#include "../utility/authentication.hpp"

namespace oauth{
namespace content{

class multipart_form_data : public multipart_content_base{
public:
  typedef std::vector<multipart_content_base*> Param_Type;
  //typedef boost::variate_generator<boost::mt19937&,boost::uniform_int<unsigned long>> Variate_Type;
  //typedef boost::uniform_int<unsigned int> Uniform_Type;
  
  multipart_form_data(const Param_Type& body_params,const std::string& disposition="")
    : disposition_(disposition),body_params_(body_params),boundary_("-"+oauth::utility::nonce<std::string>())
  {}

  template <class UniformRandomNumberGenerator>
  multipart_form_data(UniformRandomNumberGenerator& gen,const Param_Type& body_params,const std::string& disposition="")
    : disposition_(disposition),body_params_(body_params),boundary_("-"+oauth::utility::get_nonce(gen))
  {}

  virtual ~multipart_form_data(){}

  const std::string get_content_type() const { return "multipart/form-data; boundary="+boundary_; };
  const std::string get_body()const
  {
    if(body_params_.empty()) return "";

    std::string body="";
    BOOST_FOREACH(multipart_content_base* content,body_params_)
    {
      body += ("--" + boundary_ + "\r\n");
      body += (content->get_part_body() + "\r\n");
    }
    body += ("--" + boundary_ + "--"); //End

    return body;
  }
  const std::string get_part_body() const
  {
    std::string body="";
    if(!disposition_.empty()) body += "Content-Disposition: "+disposition_+"\r\n";
    body += "Content-Type: multipart/form-data; boundary="+boundary_+"\r\n";
    body += "\r\n";
    body += get_body();

    return body;
  }

private:
  const Param_Type body_params_;
  const std::string boundary_;
  const std::string disposition_; //form-data;
  const std::string content_type; //multipart/mixed; boundary=~~~
};

//typedef multipart_form_data_base<boost::mt19937> multipart_form_data;

} // namespace content
} // namespace oauth

#endif
