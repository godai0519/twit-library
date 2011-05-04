///////////////////////////////////////////////////////////////////////////////
// core.hpp header file
// twit-library : http://code.google.com/p/twit-library/
//
// Googleのコアクラスだよー
// これを使うと、認証が簡単！

#ifndef GOOGLE_CORE_HPP
#define GOOGLE_CORE_HPP

#include <boost/property_tree/json_parser.hpp>

namespace oauth{
	namespace client{
		class google : public virtual oauth::client::client_base<oauth::protocol::https<>,oauth::version::oauth_ver2>
		{
		public:
			google(){set_host("accounts.google.com");}
			~google(){}

			std::string oauth_start(const std::string& scope,const std::string& state="")
			{
				std::string temp = "https://accounts.google.com/o/oauth2/auth?client_id="+client_id_+"&response_type=code&redirect_uri=urn:ietf:wg:oauth:2.0:oob&scope="+scope;
				if(!state.empty()) return temp + "&state="+state;
				return temp;
			}
			std::string oauth_authorization_code(const std::string& code)
			{
				std::string host_temp;
				get_host(host_temp);
				set_host("accounts.google.com");

				std::string res;
				try{
					res =client_base::oauth_authorization_code("/accounts/o8/oauth2/token",code,"urn:ietf:wg:oauth:2.0:oob");
				
					boost::property_tree::ptree pt;
					boost::property_tree::read_json(std::istringstream(res),pt);
					access_token_ = pt.get<std::string>("access_token");
					refresh_token_ = pt.get<std::string>("refresh_token");
					expires_in_ = pt.get<int>("expires_in");
				}
				catch(...){}
				
				set_host(host_temp);

				return res;
			}
			std::string oauth_refresh_token()
			{
				std::string host_temp;
				get_host(host_temp);
				set_host("accounts.google.com");
				
				std::string res;
				try{
					res = client_base::oauth_refresh_token("/accounts/o8/oauth2/token",refresh_token_);
				
					boost::property_tree::ptree pt;
					boost::property_tree::read_json(std::istringstream(res),pt);
					access_token_ = pt.get<std::string>("access_token");
					expires_in_ = pt.get<int>("expires_in");
				}
				catch(...){}

				set_host(host_temp);

				return res;
			}
		private:
			std::string refresh_token_;
			int expires_in_;
		};
	}//End client namespace
}//End oauth namespace

#endif