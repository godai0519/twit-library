#ifndef YAHOO_API_SHOPPING_HPP
#define YAHOO_API_SHOPPING_HPP

namespace oauth{
	namespace api{
		namespace yahoo{
			namespace shopping{
				//
				//GET ShoppingWebService/V1/itemSearch
				//http://developer.yahoo.co.jp/webapi/shopping/shopping/v1/itemsearch.html
				//
				class item_search : public yahoo_base{
				public:
					item_search(
						const string_type appid,
						const string_type query="",
						const string_type jan="",
						const string_type isbn="",
						const string_type category_id="",
						const string_type product_id="",
						const string_type person_id="",
						const string_type brand_id="",
						const string_type store_id="",
						const string_type response_format="xml",
						const string_type affiliate_type="",
						const string_type affiliate_id="",
						const string_type type="",
						const string_type price_from="",
						const string_type price_to="",
						const string_type hits="",
						const string_type offset="",
						const string_type sort="",
						const string_type affiliate_from="",
						const string_type affiliate_to="",
						const string_type module="",
						const string_type availability="",
						const string_type discount="",
						const string_type shipping="",
						const string_type callback=""
						)
						: appid_(appid),
						query_(query), 
						jan_(jan), 
						isbn_(isbn), 
						category_id_(category_id), 
						product_id_(product_id), 
						person_id_(person_id), 
						brand_id_(brand_id), 
						store_id_(store_id), 
						affiliate_type_(affiliate_type), 
						affiliate_id_(affiliate_id), 
						type_(type), 
						price_from_(price_from), 
						price_to_(price_to), 
						hits_(hits), 
						offset_(offset), 
						sort_(sort), 
						affiliate_from_(affiliate_from), 
						affiliate_to_(affiliate_to), 
						module_(module), 
						availability_(availability), 
						discount_(discount), 
						shipping_(shipping), 
						callback_(callback), 
						yahoo_base("GET","http","shopping.yahooapis.jp","/ShoppingWebService/V1"+((response_format=="xml") ? ("") : ("/"+response_format))+"/itemSearch"){}
					param_type sort() const{
						param_type sort;
						sort["appid"]=appid_;
						if(!query_.empty()) sort["query"]=query_;
						if(!jan_.empty()) sort["jan"]=jan_;
						if(!isbn_.empty()) sort["isbn"]=isbn_;
						if(!category_id_.empty()) sort["category_id"]=category_id_;
						if(!product_id_.empty()) sort["product_id"]=product_id_;
						if(!person_id_.empty()) sort["person_id"]=person_id_;
						if(!brand_id_.empty()) sort["brand_id"]=brand_id_;
						if(!store_id_.empty()) sort["store_id"]=store_id_;
						if(!affiliate_type_.empty()) sort["affiliate_type"]=affiliate_type_;
						if(!affiliate_id_.empty()) sort["affiliate_id"]=affiliate_id_;
						if(!type_.empty()) sort["type"]=type_;
						if(!price_from_.empty()) sort["price_from"]=price_from_;
						if(!price_to_.empty()) sort["price_to"]=price_to_;
						if(!hits_.empty()) sort["hits"]=hits_;
						if(!offset_.empty()) sort["offset"]=offset_;
						if(!sort_.empty()) sort["sort"]=sort_;
						if(!affiliate_from_.empty()) sort["affiliate_from"]=affiliate_from_;
						if(!affiliate_to_.empty()) sort["affiliate_to"]=affiliate_to_;
						if(!module_.empty()) sort["module"]=module_;
						if(!availability_.empty()) sort["availability"]=availability_;
						if(!discount_.empty()) sort["discount"]=discount_;
						if(!shipping_.empty()) sort["shipping"]=shipping_;
						if(!callback_.empty()) sort["callback"]=callback_;
						return sort;
					}
				private:
					const string_type appid_;
					const string_type query_;
					const string_type jan_;
					const string_type isbn_;
					const string_type category_id_;
					const string_type product_id_;
					const string_type person_id_;
					const string_type brand_id_;
					const string_type store_id_;
					const string_type affiliate_type_;
					const string_type affiliate_id_;
					const string_type type_;
					const string_type price_from_;
					const string_type price_to_;
					const string_type hits_;
					const string_type offset_;
					const string_type sort_;
					const string_type affiliate_from_;
					const string_type affiliate_to_;
					const string_type module_;
					const string_type availability_;
					const string_type discount_;
					const string_type shipping_;
					const string_type callback_;
				};
				
				//
				//GET ShoppingWebService/V1/categoryRanking
				//http://developer.yahoo.co.jp/webapi/shopping/shopping/v1/categoryranking.html
				//
				class category_ranking : public yahoo_base{
				public:
					category_ranking(
						const string_type appid,
						const string_type response_format="xml",
						const string_type affiliate_type="",
						const string_type affiliate_id="",
						const string_type category_id="",
						const string_type gender="",
						const string_type generation="",
						const string_type period="",
						const string_type offset="",
						const string_type type="",
						const string_type callback=""
						)
						: appid_(appid),
						affiliate_type_(affiliate_type), 
						affiliate_id_(affiliate_id), 
						category_id_(category_id), 
						gender_(gender), 
						generation_(generation), 
						period_(period),
						offset_(offset), 
						type_(type),
						callback_(callback), 
						yahoo_base("GET","http","shopping.yahooapis.jp","/ShoppingWebService/V1"+((response_format=="xml") ? ("") : ("/"+response_format))+"/categoryRanking"){}
					param_type sort() const{
						param_type sort;
						sort["appid"]=appid_;
						if(!affiliate_type_.empty()) sort["affiliate_type"]=affiliate_type_;
						if(!affiliate_id_.empty()) sort["affiliate_id"]=affiliate_id_;
						if(!category_id_.empty()) sort["category_id"]=category_id_;
						if(!gender_.empty()) sort["gender"]=gender_;
						if(!period_.empty()) sort["period"]=period_;
						if(!generation_.empty()) sort["generation"]=generation_;
						if(!offset_.empty()) sort["offset"]=offset_;
						if(!type_.empty()) sort["type"]=type_;
						if(!callback_.empty()) sort["callback"]=callback_;
						return sort;
					}
				private:
					const string_type appid_;
					const string_type affiliate_type_;
					const string_type affiliate_id_;
					const string_type category_id_;
					const string_type gender_;
					const string_type generation_;
					const string_type period_;
					const string_type offset_;
					const string_type type_;
					const string_type callback_;
				};
				
				//
				//GET ShoppingWebService/V1/categorySearch
				//http://developer.yahoo.co.jp/webapi/shopping/shopping/v1/categoryranking.html
				//
				class category_search : public yahoo_base{
				public:
					category_search(
						const string_type appid,
						const string_type category_id,
						const string_type response_format="xml",
						const string_type affiliate_type="",
						const string_type affiliate_id="",
						const string_type callback=""
						)
						: appid_(appid),
						category_id_(category_id), 
						affiliate_type_(affiliate_type), 
						affiliate_id_(affiliate_id), 
						callback_(callback), 
						yahoo_base("GET","http","shopping.yahooapis.jp","/ShoppingWebService/V1"+((response_format=="xml") ? ("") : ("/"+response_format))+"/categorySearch"){}
					param_type sort() const{
						param_type sort;
						sort["appid"]=appid_;
						sort["category_id"]=category_id_;
						if(!affiliate_type_.empty()) sort["affiliate_type"]=affiliate_type_;
						if(!affiliate_id_.empty()) sort["affiliate_id"]=affiliate_id_;
						if(!callback_.empty()) sort["callback"]=callback_;
						return sort;
					}
				private:
					const string_type appid_;
					const string_type category_id_;
					const string_type affiliate_type_;
					const string_type affiliate_id_;
					const string_type callback_;
				};
				
				//
				//GET ShoppingWebService/V1/itemLookup
				//http://developer.yahoo.co.jp/webapi/shopping/shopping/v1/itemlookup.html
				//
				class item_lookup : public yahoo_base{
				public:
					item_lookup(
						const string_type appid,
						const string_type itemcode,
						const string_type response_format="xml",
						const string_type affiliate_type="",
						const string_type affiliate_id="",
						const string_type responsegroup="",
						const string_type callback=""
						)
						: appid_(appid),
						itemcode_(itemcode), 
						affiliate_type_(affiliate_type), 
						affiliate_id_(affiliate_id),
						responsegroup_(responsegroup),
						callback_(callback), 
						yahoo_base("GET","http","shopping.yahooapis.jp","/ShoppingWebService/V1"+((response_format=="xml") ? ("") : ("/"+response_format))+"/itemLookup"){}
					param_type sort() const{
						param_type sort;
						sort["appid"]=appid_;
						sort["itemcode"]=itemcode_;
						if(!affiliate_type_.empty()) sort["affiliate_type"]=affiliate_type_;
						if(!affiliate_id_.empty()) sort["affiliate_id"]=affiliate_id_;
						if(!responsegroup_.empty()) sort["responsegroup"]=responsegroup_;
						if(!callback_.empty()) sort["callback"]=callback_;
						return sort;
					}
				private:
					const string_type appid_;
					const string_type itemcode_;
					const string_type affiliate_type_;
					const string_type affiliate_id_;
					const string_type responsegroup_;
					const string_type callback_;
				};
				
				//
				//GET ShoppingWebService/V1/queryRanking
				//http://developer.yahoo.co.jp/webapi/shopping/shopping/v1/categoryranking.html
				//
				class query_ranking : public yahoo_base{
				public:
					query_ranking(
						const string_type appid,
						const string_type response_format="xml",
						const string_type affiliate_type="",
						const string_type affiliate_id="",
						const string_type type="",
						const string_type hits="",
						const string_type offset="",
						const string_type category_id="",
						const string_type callback=""
						)
						: appid_(appid),
						affiliate_type_(affiliate_type), 
						affiliate_id_(affiliate_id), 
						type_(type),
						hits_(hits),
						offset_(offset), 
						category_id_(category_id), 
						callback_(callback), 
						yahoo_base("GET","http","shopping.yahooapis.jp","/ShoppingWebService/V1"+((response_format=="xml") ? ("") : ("/"+response_format))+"/queryRanking"){}
					param_type sort() const{
						param_type sort;
						sort["appid"]=appid_;
						if(!affiliate_type_.empty()) sort["affiliate_type"]=affiliate_type_;
						if(!affiliate_id_.empty()) sort["affiliate_id"]=affiliate_id_;
						if(!type_.empty()) sort["type"]=type_;
						if(!hits_.empty()) sort["hits"]=hits_;
						if(!offset_.empty()) sort["offset"]=offset_;
						if(!category_id_.empty()) sort["category_id"]=category_id_;
						if(!callback_.empty()) sort["callback"]=callback_;
						return sort;
					}
				private:
					const string_type appid_;
					const string_type affiliate_type_;
					const string_type affiliate_id_;
					const string_type type_;
					const string_type hits_;
					const string_type offset_;
					const string_type category_id_;
					const string_type callback_;
				};
				
				//
				//GET ShoppingWebService/V1/contentMatchItem
				//http://developer.yahoo.co.jp/webapi/shopping/shopping/v1/contentmatchitem.html
				//
				class content_match_item : public yahoo_base{
				public:
					content_match_item(
						const string_type appid,
						const string_type url,
						const string_type response_format="xml",
						const string_type affiliate_type="",
						const string_type affiliate_id="",
						const string_type type="",
						const string_type hits="",
						const string_type store_id="",
						const string_type responsegroup="",
						const string_type affiliate_from="",
						const string_type affiliate_to="",
						const string_type callback=""
						)
						: appid_(appid),
						url_(url), 
						affiliate_type_(affiliate_type), 
						affiliate_id_(affiliate_id), 
						type_(type), 
						hits_(hits), 
						store_id_(store_id), 
						responsegroup_(responsegroup), 
						affiliate_from_(affiliate_from), 
						affiliate_to_(affiliate_to), 
						callback_(callback), 
						yahoo_base("GET","http","shopping.yahooapis.jp","/ShoppingWebService/V1"+((response_format=="xml") ? ("") : ("/"+response_format))+"/contentMatchItem"){}
					param_type sort() const{
						param_type sort;
						sort["appid"]=appid_;
						sort["url"]=url_;
						if(!affiliate_type_.empty()) sort["affiliate_type"]=affiliate_type_;
						if(!affiliate_id_.empty()) sort["affiliate_id"]=affiliate_id_;
						if(!type_.empty()) sort["type"]=type_;
						if(!hits_.empty()) sort["hits"]=hits_;
						if(!store_id_.empty()) sort["store_id"]=store_id_;
						if(!responsegroup_.empty()) sort["responsegroup"]=responsegroup_;
						if(!affiliate_from_.empty()) sort["affiliate_from"]=affiliate_from_;
						if(!affiliate_to_.empty()) sort["affiliate_to"]=affiliate_to_;
						if(!callback_.empty()) sort["callback"]=callback_;
						return sort;
					}
				private:
					const string_type appid_;
					const string_type url_;
					const string_type affiliate_type_;
					const string_type affiliate_id_;
					const string_type type_;
					const string_type hits_;
					const string_type store_id_;
					const string_type responsegroup_;
					const string_type affiliate_from_;
					const string_type affiliate_to_;
					const string_type callback_;
				};
				
				//
				//GET ShoppingWebService/V1/contentMatchRanking
				//http://developer.yahoo.co.jp/webapi/shopping/shopping/v1/contentmatchranking.html
				//
				class content_match_ranking : public yahoo_base{
				public:
					content_match_ranking(
						const string_type appid,
						const string_type url,
						const string_type response_format="xml",
						const string_type affiliate_type="",
						const string_type affiliate_id="",
						const string_type callback=""
						)
						: appid_(appid),
						url_(url), 
						affiliate_type_(affiliate_type), 
						affiliate_id_(affiliate_id), 
						callback_(callback), 
						yahoo_base("GET","http","shopping.yahooapis.jp","/ShoppingWebService/V1"+((response_format=="xml") ? ("") : ("/"+response_format))+"/contentMatchRanking"){}
					param_type sort() const{
						param_type sort;
						sort["appid"]=appid_;
						sort["url"]=url_;
						if(!affiliate_type_.empty()) sort["affiliate_type"]=affiliate_type_;
						if(!affiliate_id_.empty()) sort["affiliate_id"]=affiliate_id_;
						if(!callback_.empty()) sort["callback"]=callback_;
						return sort;
					}
				private:
					const string_type appid_;
					const string_type url_;
					const string_type affiliate_type_;
					const string_type affiliate_id_;
					const string_type callback_;
				};
				
				//
				//GET ShoppingWebService/V1/getModule
				//http://developer.yahoo.co.jp/webapi/shopping/shopping/v1/getmodule.html
				//
				class get_module : public yahoo_base{
				public:
					get_module(
						const string_type appid,
						const string_type position,
						const string_type response_format="xml",
						const string_type affiliate_type="",
						const string_type affiliate_id="",
						const string_type category_id="",
						const string_type callback=""
						)
						: appid_(appid),
						position_(position), 
						affiliate_type_(affiliate_type), 
						affiliate_id_(affiliate_id), 
						category_id_(category_id),
						callback_(callback), 
						yahoo_base("GET","http","shopping.yahooapis.jp","/ShoppingWebService/V1"+((response_format=="xml") ? ("") : ("/"+response_format))+"/getModule"){}
					param_type sort() const{
						param_type sort;
						sort["appid"]=appid_;
						sort["position"]=position_;
						if(!affiliate_type_.empty()) sort["affiliate_type"]=affiliate_type_;
						if(!affiliate_id_.empty()) sort["affiliate_id"]=affiliate_id_;
						if(!category_id_.empty()) sort["category_id"]=category_id_;
						if(!callback_.empty()) sort["callback"]=callback_;
						return sort;
					}
				private:
					const string_type appid_;
					const string_type position_;
					const string_type affiliate_type_;
					const string_type affiliate_id_;
					const string_type category_id_;
					const string_type callback_;
				};
				
				//
				//GET ShoppingWebService/V1/eventSearch
				//http://developer.yahoo.co.jp/webapi/shopping/shopping/v1/eventsearch.html
				//
				class event_search : public yahoo_base{
				public:
					event_search(
						const string_type appid,
						const string_type response_format="xml",
						const string_type affiliate_type="",
						const string_type affiliate_id="",
						const string_type event_type="",
						const string_type event_id="",
						const string_type sort="",
						const string_type hits="",
						const string_type offset="",
						const string_type callback=""
						)
						: appid_(appid),
						affiliate_type_(affiliate_type), 
						affiliate_id_(affiliate_id), 
						event_type_(event_type),
						event_id_(event_id),
						sort_(sort),
						hits_(hits),
						offset_(offset),
						callback_(callback), 
						yahoo_base("GET","http","shopping.yahooapis.jp","/ShoppingWebService/V1"+((response_format=="xml") ? ("") : ("/"+response_format))+"/eventSearch"){}
					param_type sort() const{
						param_type sort;
						sort["appid"]=appid_;
						if(!affiliate_type_.empty()) sort["affiliate_type"]=affiliate_type_;
						if(!affiliate_id_.empty()) sort["affiliate_id"]=affiliate_id_;
						if(!event_type_.empty()) sort["event_type"]=event_type_;
						if(!event_id_.empty()) sort["event_id"]=event_id_;
						if(!sort_.empty()) sort["sort"]=sort_;
						if(!hits_.empty()) sort["hits"]=hits_;
						if(!offset_.empty()) sort["offset"]=offset_;
						if(!callback_.empty()) sort["callback"]=callback_;
						return sort;
					}
				private:
					const string_type appid_;
					const string_type affiliate_type_;
					const string_type affiliate_id_;
					const string_type event_type_;
					const string_type event_id_;
					const string_type sort_;
					const string_type hits_;
					const string_type offset_;
					const string_type callback_;
				};
				
				//
				//GET ShoppingWebService/V1/reviewSearch
				//http://developer.yahoo.co.jp/webapi/shopping/shopping/v1/eventsearch.html
				//
				class review_search : public yahoo_base{
				public:
					review_search(
						const string_type appid,
						const string_type jan="",
						const string_type category_id="",
						const string_type product_id="",
						const string_type person_id="",
						const string_type store_id="",
						const string_type response_format="xml",
						const string_type affiliate_type="",
						const string_type affiliate_id="",
						const string_type results="",
						const string_type start="",
						const string_type sort="",
						const string_type callback=""
						)
						: appid_(appid),
						jan_(jan), 
						category_id_(category_id), 
						product_id_(product_id), 
						person_id_(person_id), 
						store_id_(store_id), 
						affiliate_type_(affiliate_type), 
						affiliate_id_(affiliate_id), 
						results_(results),
						start_(start),
						sort_(sort),
						callback_(callback), 
						yahoo_base("GET","http","shopping.yahooapis.jp","/ShoppingWebService/V1"+((response_format=="xml") ? ("") : ("/"+response_format))+"/reviewSearch"){}
					param_type sort() const{
						param_type sort;
						sort["appid"]=appid_;
						if(!jan_.empty()) sort["jan"]=jan_;
						if(!category_id_.empty()) sort["category_id"]=category_id_;
						if(!product_id_.empty()) sort["product_id"]=product_id_;
						if(!person_id_.empty()) sort["person_id"]=person_id_;
						if(!store_id_.empty()) sort["store_id"]=store_id_;
						if(!affiliate_type_.empty()) sort["affiliate_type"]=affiliate_type_;
						if(!affiliate_id_.empty()) sort["affiliate_id"]=affiliate_id_;
						if(!results_.empty()) sort["results"]=results_;
						if(!start_.empty()) sort["start"]=start_;
						if(!sort_.empty()) sort["sort"]=sort_;
						if(!callback_.empty()) sort["callback"]=callback_;
						return sort;
					}
				private:
					const string_type appid_;
					const string_type jan_;
					const string_type category_id_;
					const string_type product_id_;
					const string_type person_id_;
					const string_type store_id_;
					const string_type affiliate_type_;
					const string_type affiliate_id_;
					const string_type results_;
					const string_type start_;
					const string_type sort_;
					const string_type callback_;
				};
				
				//
				//GET ShoppingWebService/V1/json/urlItemMatchSearch
				//http://developer.yahoo.co.jp/webapi/shopping/shopping/v1/urlitemmatchsearch.html
				//
				class url_item_match_search : public yahoo_base{
				public:
					url_item_match_search(
						const string_type appid,
						const string_type url,
						const string_type query,
						const string_type affiliate_type="",
						const string_type affiliate_id="",
						const string_type category_id="",
						const string_type results="",
						const string_type start="",
						const string_type callback=""
						)
						: appid_(appid),
						url_(url),
						query_(query),
						affiliate_type_(affiliate_type), 
						affiliate_id_(affiliate_id), 
						category_id_(category_id), 
						results_(results),
						start_(start),
						callback_(callback), 
						yahoo_base("GET","http","shopping.yahooapis.jp","/ShoppingWebService/V1/json/urlItemMatchSearch"){}
					param_type sort() const{
						param_type sort;
						sort["appid"]=appid_;
						sort["url"]=url_;
						sort["query"]=query_;
						if(!affiliate_type_.empty()) sort["affiliate_type"]=affiliate_type_;
						if(!affiliate_id_.empty()) sort["affiliate_id"]=affiliate_id_;
						if(!category_id_.empty()) sort["category_id"]=category_id_;
						if(!results_.empty()) sort["results"]=results_;
						if(!start_.empty()) sort["start"]=start_;
						if(!callback_.empty()) sort["callback"]=callback_;
						return sort;
					}
				private:
					const string_type appid_;
					const string_type url_;
					const string_type query_;
					const string_type affiliate_type_;
					const string_type affiliate_id_;
					const string_type category_id_;
					const string_type results_;
					const string_type start_;
					const string_type callback_;
				};
				
				//
				//GET ShoppingWebService/V1/json/urlItemMatchLookup
				//http://developer.yahoo.co.jp/webapi/shopping/shopping/v1/urlitemmatchlookup.html
				//
				class url_item_match_lookup : public yahoo_base{
				public:
					url_item_match_lookup(
						const string_type appid,
						const string_type url,
						const string_type affiliate_type="",
						const string_type affiliate_id="",
						const string_type results="",
						const string_type start="",
						const string_type callback=""
						)
						: appid_(appid),
						url_(url),
						affiliate_type_(affiliate_type), 
						affiliate_id_(affiliate_id), 
						results_(results),
						start_(start),
						callback_(callback), 
						yahoo_base("GET","http","shopping.yahooapis.jp","/ShoppingWebService/V1/json/urlItemMatchLookup"){}
					param_type sort() const{
						param_type sort;
						sort["appid"]=appid_;
						sort["url"]=url_;
						if(!affiliate_type_.empty()) sort["affiliate_type"]=affiliate_type_;
						if(!affiliate_id_.empty()) sort["affiliate_id"]=affiliate_id_;
						if(!results_.empty()) sort["results"]=results_;
						if(!start_.empty()) sort["start"]=start_;
						if(!callback_.empty()) sort["callback"]=callback_;
						return sort;
					}
				private:
					const string_type appid_;
					const string_type url_;
					const string_type affiliate_type_;
					const string_type affiliate_id_;
					const string_type results_;
					const string_type start_;
					const string_type callback_;
				};
				
				//
				//GET ShoppingWebService/V1/json/urlItemMatchAdd
				//http://developer.yahoo.co.jp/webapi/shopping/shopping/v1/urlitemmatchadd.html
				//
				class url_item_match_add : public yahoo_base{
				public:
					url_item_match_add(
						const string_type appid,
						const string_type url,
						const string_type itemcode,
						const string_type start_at,
						const string_type end_at,
						const string_type signature,
						const string_type affiliate_type="",
						const string_type affiliate_id="",
						const string_type callback=""
						)
						: appid_(appid),
						url_(url),
						itemcode_(itemcode),
						start_at_(start_at),
						end_at_(end_at),
						signature_(signature),
						affiliate_type_(affiliate_type), 
						affiliate_id_(affiliate_id), 
						callback_(callback), 
						yahoo_base("GET","http","shopping.yahooapis.jp","/ShoppingWebService/V1/json/urlItemMatchAdd"){}
					param_type sort() const{
						param_type sort;
						sort["appid"]=appid_;
						sort["url"]=url_;
						sort["itemcode"]=itemcode_;
						sort["start_at"]=start_at_;
						sort["end_at"]=end_at_;
						sort["signature"]=signature_;
						if(!affiliate_type_.empty()) sort["affiliate_type"]=affiliate_type_;
						if(!affiliate_id_.empty()) sort["affiliate_id"]=affiliate_id_;
						if(!callback_.empty()) sort["callback"]=callback_;
						return sort;
					}
				private:
					const string_type appid_;
					const string_type url_;
					const string_type itemcode_;
					const string_type start_at_;
					const string_type end_at_;
					const string_type signature_;
					const string_type affiliate_type_;
					const string_type affiliate_id_;
					const string_type callback_;
				};
				
				//
				//GET ShoppingWebService/V1/json/urlItemMatchRemove
				//http://developer.yahoo.co.jp/webapi/shopping/shopping/v1/urlitemmatchadd.html
				//
				class url_item_match_remove : public yahoo_base{
				public:
					url_item_match_remove(
						const string_type appid,
						const string_type url,
						const string_type itemcode,
						const string_type start_at,
						const string_type end_at,
						const string_type signature,
						const string_type affiliate_type="",
						const string_type affiliate_id="",
						const string_type callback=""
						)
						: appid_(appid),
						url_(url),
						itemcode_(itemcode),
						start_at_(start_at),
						end_at_(end_at),
						signature_(signature),
						affiliate_type_(affiliate_type), 
						affiliate_id_(affiliate_id), 
						callback_(callback), 
						yahoo_base("GET","http","shopping.yahooapis.jp","/ShoppingWebService/V1/json/urlItemMatchRemove"){}
					param_type sort() const{
						param_type sort;
						sort["appid"]=appid_;
						sort["url"]=url_;
						sort["itemcode"]=itemcode_;
						sort["start_at"]=start_at_;
						sort["end_at"]=end_at_;
						sort["signature"]=signature_;
						if(!affiliate_type_.empty()) sort["affiliate_type"]=affiliate_type_;
						if(!affiliate_id_.empty()) sort["affiliate_id"]=affiliate_id_;
						if(!callback_.empty()) sort["callback"]=callback_;
						return sort;
					}
				private:
					const string_type appid_;
					const string_type url_;
					const string_type itemcode_;
					const string_type start_at_;
					const string_type end_at_;
					const string_type signature_;
					const string_type affiliate_type_;
					const string_type affiliate_id_;
					const string_type callback_;
				};
			}//End shopping namespace
		}//End yahoo namespace
	}//End api namespace
}//End oauth namespace

#endif
