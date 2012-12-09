//
// url_encoded.hpp
// ~~~~~~~~~~
//
// 認証系機構のutility総集
//

#ifndef TWIT_LIB_UTILITY_URLENCODED_HPP
#define TWIT_LIB_UTILITY_URLENCODED_HPP

#include <map>
#include <string>
#include "percent_encoding.hpp"

namespace oauth{
namespace utility{    

class generator
{
public:
    generator();
    virtual ~generator(); // =default;

    std::string operator() (const std::map<std::string,std::string>& data, const std::string& key_value_separator = "=", const std::string& field_separator = "&", const std::string& value_container = "") const;

    inline std::string urlencode(const std::map<std::string,std::string>& data) const;
    inline std::string authorization_field(const std::map<std::string,std::string>& data) const;

private:
    const oauth::utility::percent_encoder encoder_;
};

class parser
{
public:
    parser();
    virtual ~parser(); // =default;

    std::map<std::string,std::string> operator() (const std::string& src, const std::string& key_value_separator = "=", const std::string& field_separator = "&", const std::string& value_container = "") const;
    
    inline std::map<std::string,std::string> urlencode(const std::string& src) const;
    inline std::map<std::string,std::string> authorization_field(const std::string& src) const;

private:
    const oauth::utility::percent_encoder encoder_;
};

} // namespace utility
} // namespace oauth

#ifdef TWIT_LIB_BUILD
#include "impl/url_encoded.ipp"
#endif

#endif
