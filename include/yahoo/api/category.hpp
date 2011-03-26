#ifndef YAHOO_API_CATEGORY_HPP
#define YAHOO_API_CATEGORY_HPP

namespace oauth{
	namespace api{
		namespace yahoo{
			namespace category{
				//
				//GET Category/V1/Category
				//http://developer.yahoo.co.jp/webapi/dir/category/v1/category.html
				//
				class category : public yahoo_base{
				public:
					category(
						const string_type appid,
						const string_type id="",
						const string_type path="",
						const string_type type="",
						const string_type expand=""
						)
						: appid_(appid),
						id_(id),
						path_(path),
						type_(type),
						expand_(expand),
						yahoo_base("GET","http","dir.yahooapis.jp","/Category/V1/Category"){}
					param_type sort() const{
						param_type sort;
						sort["appid"]=appid_;
						if(id_!="") sort["id"]=id_;
						if(path_!="") sort["path"]=path_;
						if(type_!="") sort["type"]=type_;
						if(expand_!="") sort["expand"]=expand_;
						return sort;
					}
				private:
					const string_type appid_;
					const string_type id_;
					const string_type path_;
					const string_type type_;
					const string_type expand_;
				};
				
				//
				//GET Category/V1/directorySearch
				//http://developer.yahoo.co.jp/webapi/dir/category/v1/directorysearch.html
				//
				class directory_search : public yahoo_base{
				public:
					directory_search(
						const string_type appid,
						const string_type query,
						const string_type type="",
						const string_type results="",
						const string_type start="",
						const string_type adult_ok="",
						const string_type path="",
						const string_type new_="",
						const string_type picks=""
						)
						: appid_(appid),
						query_(query),
						type_(type),
						results_(results),
						start_(start),
						adult_ok_(adult_ok),
						path_(path),
						new_(new_),
						picks_(picks),
						yahoo_base("GET","http","dir.yahooapis.jp","/Category/V1/directorySearch"){}
					param_type sort() const{
						param_type sort;
						sort["appid"]=appid_;
						sort["query"]=query_;
						if(type_!="") sort["type"]=type_;
						if(results_!="") sort["results"]=results_;
						if(start_!="") sort["start"]=start_;
						if(adult_ok_!="") sort["adult_ok"]=adult_ok_;
						if(path_!="") sort["path"]=path_;
						if(new_!="") sort["new"]=new_;
						if(picks_!="") sort["picks"]=picks_;
						return sort;
					}
				private:
					const string_type appid_;
					const string_type query_;
					const string_type type_;
					const string_type results_;
					const string_type start_;
					const string_type adult_ok_;
					const string_type path_;
					const string_type new_;
					const string_type picks_;
				};
			}//End category namespace
		}//End yahoo namespace
	}//End api namespace
}//End oauth namespace

#endif
