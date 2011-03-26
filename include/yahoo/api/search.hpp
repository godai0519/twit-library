#ifndef YAHOO_API_SEARCH_HPP
#define YAHOO_API_SEARCH_HPP

namespace oauth{
	namespace api{
		namespace yahoo{
			namespace search{
				//
				//POST WebSearchService/V2/webSearch
				//http://developer.yahoo.co.jp/webapi/search/websearch/v2/websearch.html
				//
				class web : public yahoo_base{
				public:
					web(const string_type appid,const string_type query,const string_type type="",const string_type results="",const string_type start="",const string_type format="",const string_type adult_ok="",const string_type similar_ok="",const string_type language="",const string_type country="",const string_type site="")
						: appid_(appid), query_(query), type_(type), results_(results), start_(start), format_(format), adult_ok_(adult_ok), similar_ok_(similar_ok), language_(language), country_(country), site_(site), yahoo_base("POST","http","search.yahooapis.jp","/WebSearchService/V2/webSearch"){}
					param_type sort() const{
						param_type sort;
						sort["appid"]=appid_;
						sort["query"]=query_;
						if(type_!="") sort["type"]=type_;
						if(results_!="") sort["results"]=results_;
						if(start_!="") sort["start"]=start_;
						if(format_!="") sort["format"]=format_;
						if(adult_ok_!="") sort["adult_ok"]=adult_ok_;
						if(similar_ok_!="") sort["similar_ok"]=similar_ok_;
						if(language_!="") sort["language"]=language_;
						if(country_!="") sort["country"]=country_;
						if(site_!="") sort["site"]=site_;
						return sort;
					}
				private:
					const string_type appid_;
					const string_type query_;
					const string_type type_;
					const string_type results_;
					const string_type start_;
					const string_type format_;
					const string_type adult_ok_;
					const string_type similar_ok_;
					const string_type language_;
					const string_type country_;
					const string_type site_;
				};

				//
				//POST ImageSearchService/V2/imageSearch
				//http://developer.yahoo.co.jp/webapi/search/imagesearch/v2/imagesearch.html
				//
				class image : public yahoo_base{
				public:
					image(const string_type appid,const string_type query,const string_type type="",const string_type results="",const string_type start="",const string_type format="",const string_type adult_ok="",const string_type coloration="",const string_type site="")
						: appid_(appid), query_(query), type_(type), results_(results), start_(start), format_(format), adult_ok_(adult_ok), coloration_(coloration), site_(site), yahoo_base("POST","http","search.yahooapis.jp","/ImageSearchService/V2/imageSearch"){}
					param_type sort() const{
						param_type sort;
						sort["appid"]=appid_;
						sort["query"]=query_;
						if(type_!="") sort["type"]=type_;
						if(results_!="") sort["results"]=results_;
						if(start_!="") sort["start"]=start_;
						if(format_!="") sort["format"]=format_;
						if(adult_ok_!="") sort["adult_ok"]=adult_ok_;
						if(coloration_!="") sort["coloration"]=coloration_;
						if(site_!="") sort["site"]=site_;
						return sort;
					}
				private:
					const string_type appid_;
					const string_type query_;
					const string_type type_;
					const string_type results_;
					const string_type start_;
					const string_type format_;
					const string_type adult_ok_;
					const string_type coloration_;
					const string_type site_;
				};

				//
				//POST VideoSearchService/V2/videoSearch
				//http://developer.yahoo.co.jp/webapi/search/videosearch/v2/videosearch.html
				//
				class video : public yahoo_base{
				public:
					video(const string_type appid,const string_type query,const string_type type="",const string_type results="",const string_type start="",const string_type format="",const string_type adult_ok="",const string_type site="")
						: appid_(appid), query_(query), type_(type), results_(results), start_(start), format_(format), adult_ok_(adult_ok), site_(site), yahoo_base("POST","http","search.yahooapis.jp","/VideoSearchService/V2/videoSearch"){}
					param_type sort() const{
						param_type sort;
						sort["appid"]=appid_;
						sort["query"]=query_;
						if(type_!="") sort["type"]=type_;
						if(results_!="") sort["results"]=results_;
						if(start_!="") sort["start"]=start_;
						if(format_!="") sort["format"]=format_;
						if(adult_ok_!="") sort["adult_ok"]=adult_ok_;
						if(site_!="") sort["site"]=site_;
						return sort;
					}
				private:
					const string_type appid_;
					const string_type query_;
					const string_type type_;
					const string_type results_;
					const string_type start_;
					const string_type format_;
					const string_type adult_ok_;
					const string_type site_;
				};

				//
				//POST AssistSearchService/V1/webunitSearch
				//http://developer.yahoo.co.jp/webapi/search/assistsearch/v1/webunitsearch.html
				//
				class webunit : public yahoo_base{
				public:
					webunit(const string_type appid,const string_type query,const string_type type="",const string_type results="",const string_type start="",const string_type term="",const string_type output="",const string_type callback="")
						: appid_(appid), query_(query), results_(results), start_(start), yahoo_base("POST","http","search.yahooapis.jp","/AssistSearchService/V1/webunitSearch"){}
					param_type sort() const{
						param_type sort;
						sort["appid"]=appid_;
						sort["query"]=query_;
						if(results_!="") sort["results"]=results_;
						if(start_!="") sort["start"]=start_;
						return sort;
					}
				private:
					const string_type appid_;
					const string_type query_;
					const string_type results_;
					const string_type start_;
				};

				//
				//POST BlogSearchService/V1/blogSearch
				//http://developer.yahoo.co.jp/webapi/search/blogsearch/v1/blogsearch.html
				//
				class blog : public yahoo_base{
				public:
					blog(const string_type appid,const string_type query,const string_type type="",const string_type results="",const string_type start="",const string_type term="",const string_type output="",const string_type callback="")
						: appid_(appid), query_(query), type_(type), results_(results), start_(start), term_(term), output_(output), callback_(callback), yahoo_base("POST","http","search.yahooapis.jp","/BlogSearchService/V1/blogSearch"){}
					param_type sort() const{
						param_type sort;
						sort["appid"]=appid_;
						sort["query"]=query_;
						if(type_!="") sort["type"]=type_;
						if(results_!="") sort["results"]=results_;
						if(start_!="") sort["start"]=start_;
						if(term_!="") sort["term"]=term_;
						if(output_!="") sort["output"]=output_;
						if(callback_!="") sort["callback"]=callback_;
						return sort;
					}
				private:
					const string_type appid_;
					const string_type query_;
					const string_type type_;
					const string_type results_;
					const string_type start_;
					const string_type term_;
					const string_type output_;
					const string_type callback_;
				};
				
#ifdef USE_PREMIUM
				//
				//POST PremiumWebSearchService/V1/webSearch
				//http://developer.yahoo.co.jp/webapi/search/premium.html
				//
				class premium_web : public yahoo_base{
				public:
					premium_web(const string_type appid,const string_type query,const string_type type="",const string_type results="",const string_type start="",const string_type format="",const string_type adult_ok="",const string_type similar_ok="",const string_type language="",const string_type country="",const string_type site="")
						: appid_(appid), query_(query), type_(type), results_(results), start_(start), format_(format), adult_ok_(adult_ok), similar_ok_(similar_ok), language_(language), country_(country), site_(site), yahoo_base("POST","http","search.yahooapis.jp","/PremiumWebSearchService/V1/webSearch"){}
					param_type sort() const{
						param_type sort;
						sort["appid"]=appid_;
						sort["query"]=query_;
						if(type_!="") sort["type"]=type_;
						if(results_!="") sort["results"]=results_;
						if(start_!="") sort["start"]=start_;
						if(format_!="") sort["format"]=format_;
						if(adult_ok_!="") sort["adult_ok"]=adult_ok_;
						if(similar_ok_!="") sort["similar_ok"]=similar_ok_;
						if(language_!="") sort["language"]=language_;
						if(country_!="") sort["country"]=country_;
						if(site_!="") sort["site"]=site_;
						return sort;
					}
				private:
					const string_type appid_;
					const string_type query_;
					const string_type type_;
					const string_type results_;
					const string_type start_;
					const string_type format_;
					const string_type adult_ok_;
					const string_type similar_ok_;
					const string_type language_;
					const string_type country_;
					const string_type site_;
				};

				//
				//POST PremiumImageSearchService/V1/imageSearch
				//http://developer.yahoo.co.jp/webapi/search/premium.html
				//
				class premium_image : public yahoo_base{
				public:
					premium_image(const string_type appid,const string_type query,const string_type type="",const string_type results="",const string_type start="",const string_type format="",const string_type adult_ok="",const string_type coloration="",const string_type site="")
						: appid_(appid), query_(query), type_(type), results_(results), start_(start), format_(format), adult_ok_(adult_ok), coloration_(coloration), site_(site), yahoo_base("POST","http","search.yahooapis.jp","/PremiumImageSearchService/V1/imageSearch"){}
					param_type sort() const{
						param_type sort;
						sort["appid"]=appid_;
						sort["query"]=query_;
						if(type_!="") sort["type"]=type_;
						if(results_!="") sort["results"]=results_;
						if(start_!="") sort["start"]=start_;
						if(format_!="") sort["format"]=format_;
						if(adult_ok_!="") sort["adult_ok"]=adult_ok_;
						if(coloration_!="") sort["coloration"]=coloration_;
						if(site_!="") sort["site"]=site_;
						return sort;
					}
				private:
					const string_type appid_;
					const string_type query_;
					const string_type type_;
					const string_type results_;
					const string_type start_;
					const string_type format_;
					const string_type adult_ok_;
					const string_type coloration_;
					const string_type site_;
				};
#endif
			}//End search namespace
		}//End yahoo namespace
	}//End api namespace
}//End oauth namespace

#endif
