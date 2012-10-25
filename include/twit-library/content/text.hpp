//
// text.hpp
// ~~~~~~~~~~
//
// Content-Type: */*
//

#ifndef TWIT_LIB_CONTENT_TEXT
#define TWIT_LIB_CONTENT_TEXT

#include <map>
#include <string>
#include "multipart_content_base.hpp"
//#include "../utility.hpp"

namespace oauth{
namespace content{

class text : public multipart_content_base{
public:
    text(const std::string& body,const std::string& disposition,const std::string& content_type="text/plain")
        : body_(body),disposition_(disposition),content_type_(content_type)
    {}
    virtual ~text(){}

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
