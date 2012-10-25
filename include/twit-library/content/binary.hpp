//
// binary.hpp
// ~~~~~~~~~~
//
// Content-Type: */*
//

#ifndef TWIT_LIB_CONTENT_BINARY
#define TWIT_LIB_CONTENT_BINARY

#include <map>
#include <string>
#include "multipart_content_base.hpp"
//#include "../utility.hpp"

namespace oauth{
namespace content{

class binary : public multipart_content_base{
public:
    binary(const std::string& body,const std::string& disposition,const std::string& content_type="image/*")
        : body_(body),disposition_(disposition),content_type_(content_type)
    {}
    virtual ~binary(){}

    const std::string get_content_type() const { return content_type_; };
    const std::string get_body()const
    {
        return body_;
    }
    const std::string get_part_body() const
    {
        std::string body="";
        if(!disposition_.empty()) body += "Content-Disposition: "+disposition_+"\r\n";
        body += "Content-Type: " + content_type_+"\r\n";
        body += "Content-Transfer-Encoding: binary\r\n";
        body += "\r\n";
        body += get_body();

        return body;
    }

private:
    const std::string body_;
    const std::string disposition_; //form-data;
    const std::string content_type_;
};

} // namespace content
} // namespace oauth

#endif
