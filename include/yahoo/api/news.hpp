#ifndef YAHOO_API_NEWS_HPP
#define YAHOO_API_NEWS_HPP

namespace oauth{
	namespace api{
		namespace yahoo{
			namespace news{
				//
				//GET NewsWebService/V2/topics
				//http://developer.yahoo.co.jp/webapi/news/news/v2/topics.html
				//
				class topics : public yahoo_base{
				public:
					topics(
						const string_type appid,
						const string_type topicname="",
						const string_type category="",
						const string_type pickupcategory="",
						const string_type query="",
						const string_type relatedinformation="",
						const string_type sort="",
						const string_type results="",
						const string_type start=""
						)
						: appid_(appid),
						topicname_(topicname),
						category_(category),
						pickupcategory_(pickupcategory),
						query_(query),
						relatedinformation_(relatedinformation),
						sort_(sort), 
						results_(results), 
						start_(start), 
						yahoo_base("GET","http","news.yahooapis.jp","/NewsWebService/V2/topics"){}
					param_type sort() const{
						param_type sort;
						sort["appid"]=appid_;
						if(!topicname_.empty()) sort["topicname"]=topicname_;
						if(!category_.empty()) sort["category"]=category_;
						if(!pickupcategory_.empty()) sort["pickupcategory"]=pickupcategory_;
						if(!query_.empty()) sort["query"]=query_;
						if(!relatedinformation_.empty()) sort["relatedinformation"]=relatedinformation_;
						if(!sort_.empty()) sort["sort"]=sort_;
						if(!results_.empty()) sort["results"]=results_;
						if(!start_.empty()) sort["start"]=start_;
						return sort;
					}
				private:
					const string_type appid_;
					const string_type topicname_;
					const string_type category_;
					const string_type pickupcategory_;
					const string_type query_;
					const string_type relatedinformation_;
					const string_type sort_;
					const string_type results_;
					const string_type start_;
				};
				
				//
				//GET NewsWebService/V1/heading
				//http://developer.yahoo.co.jp/webapi/news/news/v1/heading.html
				//
				class heading : public yahoo_base{
				public:
					heading(
						const string_type appid,
						const string_type topicname="",
						const string_type category="",
						const string_type query="",
						const string_type startdate="",
						const string_type enddate="",
						const string_type unit="",
						const string_type sort="",
						const string_type results="",
						const string_type start=""
						)
						: appid_(appid),
						topicname_(topicname),
						category_(category),
						query_(query),
						startdate_(startdate),
						enddate_(enddate),
						unit_(unit),
						sort_(sort), 
						results_(results), 
						start_(start), 
						yahoo_base("GET","http","news.yahooapis.jp","/NewsWebService/V1/heading"){}
					param_type sort() const{
						param_type sort;
						sort["appid"]=appid_;
						if(!topicname_.empty()) sort["topicname"]=topicname_;
						if(!category_.empty()) sort["category"]=category_;
						if(!query_.empty()) sort["query"]=query_;
						if(!startdate_.empty()) sort["startdate"]=startdate_;
						if(!enddate_.empty()) sort["enddate"]=enddate_;
						if(!unit_.empty()) sort["unit"]=unit_;
						if(!sort_.empty()) sort["sort"]=sort_;
						if(!results_.empty()) sort["results"]=results_;
						if(!start_.empty()) sort["start"]=start_;
						return sort;
					}
				private:
					const string_type appid_;
					const string_type topicname_;
					const string_type category_;
					const string_type query_;
					const string_type startdate_;
					const string_type enddate_;
					const string_type unit_;
					const string_type sort_;
					const string_type results_;
					const string_type start_;
				};

				
				//
				//GET NewsWebService/V1/topicsLog
				//http://developer.yahoo.co.jp/webapi/news/news/v1/topicslog.html
				//
				class topics_log : public yahoo_base{
				public:
					topics_log(
						const string_type appid,
						const string_type topicname="",
						const string_type category="",
						const string_type query="",
						const string_type minpickupnum="",
						const string_type sort="",
						const string_type results="",
						const string_type start=""
						)
						: appid_(appid),
						topicname_(topicname),
						category_(category),
						query_(query),
						minpickupnum_(minpickupnum),
						sort_(sort), 
						results_(results), 
						start_(start), 
						yahoo_base("GET","http","news.yahooapis.jp","/NewsWebService/V1/topicsLog"){}
					param_type sort() const{
						param_type sort;
						sort["appid"]=appid_;
						if(!topicname_.empty()) sort["topicname"]=topicname_;
						if(!category_.empty()) sort["category"]=category_;
						if(!query_.empty()) sort["query"]=query_;
						if(!minpickupnum_.empty()) sort["minpickupnum"]=minpickupnum_;
						if(!sort_.empty()) sort["sort"]=sort_;
						if(!results_.empty()) sort["results"]=results_;
						if(!start_.empty()) sort["start"]=start_;
						return sort;
					}
				private:
					const string_type appid_;
					const string_type topicname_;
					const string_type category_;
					const string_type query_;
					const string_type minpickupnum_;
					const string_type sort_;
					const string_type results_;
					const string_type start_;
				};

			}//End news namespace
		}//End yahoo namespace
	}//End api namespace
}//End oauth namespace

#endif
