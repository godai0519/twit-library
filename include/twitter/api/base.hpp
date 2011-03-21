#ifndef TWITTER_API_BASE_HPP
#define TWITTER_API_BASE_HPP

namespace oauth{
	namespace api{
		class twitter_base : public oauth::api::base{
		public:
			twitter_base(const string_type method,const string_type protocol,const string_type host,const string_type path,const string_type content_type="application/x-www-form-urlencoded")
				: base(method,protocol,host,path,content_type){}
		};
	}//End api namespace
}//End oauth namespace

#endif
