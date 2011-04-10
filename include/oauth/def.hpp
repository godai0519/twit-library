///////////////////////////////////////////////////////////////////////////////
// def.hpp header file
// twit-library : http://code.google.com/p/twit-library/
//
// 使用するdefine/typedef集だよー
// 解りやすくするために！

#ifndef OAUTH_DEF_HPP
#define OAUTH_DEF_HPP

#include <map>

namespace oauth{
	typedef std::string											string_type;
	typedef std::map<string_type, string_type>	param_type;
	typedef std::string											res_type;

	namespace content{
		typedef string_type data_type;
		enum content_type{
			Data,
			Image
		};

		struct multipart_form_data{
			const content::content_type content_type;
			const data_type value;
			const data_type name;
			const data_type filepath;
			const data_type filename;
			multipart_form_data(const content::content_type content_type, const data_type name, const data_type value)
				: content_type(content_type), name(name), value(value), filepath(""), filename(""){}
			multipart_form_data(const content::content_type content_type, const data_type name, const data_type filepath, const data_type filename)
				: content_type(content_type), name(name), value(""), filepath(filepath), filename(filename){}
			~multipart_form_data(){}
		};
	}//End content namespace
}//End oauth namespace

#endif
