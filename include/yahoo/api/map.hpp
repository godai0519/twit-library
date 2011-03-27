#ifndef YAHOO_API_MAP_HPP
#define YAHOO_API_MAP_HPP

namespace oauth{
	namespace api{
		namespace yahoo{
			namespace map{
				//
				//GET OpenLocalPlatform/V1/geoCoder
				//http://developer.yahoo.co.jp/webapi/map/openlocalplatform/v1/geocoder.html
				//
				class geocoder : public yahoo_base{
				public:
					geocoder(const string_type appid,const string_type query="",const string_type ei="UTF-8",const string_type lat="",const string_type lon="",const string_type datum="",const string_type sort="",const string_type bbox="",const string_type start="",const string_type results="",const string_type page="",const string_type output="",const string_type callback=""	)
						: appid_(appid), query_(query), ei_(ei), lat_(lat), lon_(lon), datum_(datum), sort_(sort), bbox_(bbox), start_(start), results_(results), page_(page), output_(output), callback_(callback), yahoo_base("GET","http","geo.search.olp.yahooapis.jp","/OpenLocalPlatform/V1/geoCoder"){}
					param_type sort() const{
						param_type sort;
						sort["appid"]=appid_;
						if(!query_.empty()) sort["query"]=query_;
						if(!ei_.empty()) sort["ei"]=ei_;
						if(!lat_.empty()) sort["lat"]=lat_;
						if(!lon_.empty()) sort["lon"]=lon_;
						if(!datum_.empty()) sort["datum"]=datum_;
						if(!sort_.empty()) sort["sort"]=sort_;
						if(!bbox_.empty()) sort["bbox"]=bbox_;
						if(!start_.empty()) sort["start"]=start_;
						if(!results_.empty()) sort["results"]=results_;
						if(!page_.empty()) sort["page"]=page_;
						if(!output_.empty()) sort["output"]=output_;
						if(!callback_.empty()) sort["callback"]=callback_;
						return sort;
					}
				private:
					const string_type appid_;
					const string_type query_;
					const string_type ei_;
					const string_type lat_;
					const string_type lon_;
					const string_type datum_;
					const string_type sort_;
					const string_type bbox_;
					const string_type start_;
					const string_type results_;
					const string_type page_;
					const string_type output_;
					const string_type callback_;
				};
				
				//
				//GET OpenLocalPlatform/V1/reverseGeoCoder
				//http://developer.yahoo.co.jp/webapi/map/openlocalplatform/v1/reversegeocoder.html
				//
				class reverse_geocoder : public yahoo_base{
				public:
					reverse_geocoder(const string_type appid,const string_type coordinates,const string_type output="",const string_type callback="")
						: appid_(appid), coordinates_(coordinates), output_(output), callback_(callback), yahoo_base("GET","http","reverse.search.olp.yahooapis.jp","/OpenLocalPlatform/V1/reverseGeoCoder"){}
					param_type sort() const{
						param_type sort;
						sort["appid"]=appid_;
						sort["coordinates"]=coordinates_;
						if(!output_.empty()) sort["output"]=output_;
						if(!callback_.empty()) sort["callback"]=callback_;
						return sort;
					}
				private:
					const string_type appid_;
					const string_type coordinates_;
					const string_type output_;
					const string_type callback_;
				};
				
				//
				//POST OpenLocalPlatform/V1/getAltitude
				//http://developer.yahoo.co.jp/webapi/map/openlocalplatform/v1/altitude.html
				//
				class get_altitube : public yahoo_base{
				public:
					get_altitube(const string_type appid,const string_type coordinates,const string_type output="",const string_type callback="")
						: appid_(appid), coordinates_(coordinates), output_(output), callback_(callback), yahoo_base("POST","http","alt.search.olp.yahooapis.jp","/OpenLocalPlatform/V1/getAltitude"){}
					param_type sort() const{
						param_type sort;
						sort["appid"]=appid_;
						sort["coordinates"]=coordinates_;
						if(!output_.empty()) sort["output"]=output_;
						if(!callback_.empty()) sort["callback"]=callback_;
						return sort;
					}
				private:
					const string_type appid_;
					const string_type coordinates_;
					const string_type output_;
					const string_type callback_;
				};
				
				//
				//GET OpenLocalPlatform/V1/localSearch
				//http://developer.yahoo.co.jp/webapi/map/openlocalplatform/v1/localsearch.html
				//
				class local_search : public yahoo_base{
				public:
					local_search(const string_type appid,const string_type cid="",const string_type gid="",const string_type query="",const string_type sort="",const string_type start="",const string_type results="",const string_type detail="",const string_type output="",const string_type lat="",const string_type lon="",const string_type bbox="",const string_type dist="",const string_type ac="",const string_type uid="",const string_type callback="")
						: appid_(appid), cid_(cid), gid_(gid), query_(query), sort_(sort), start_(start), results_(results), detail_(detail), output_(output), lat_(lat), lon_(lon), bbox_(bbox), dist_(dist), ac_(ac), uid_(uid), callback_(callback), yahoo_base("GET","http","search.olp.yahooapis.jp","/OpenLocalPlatform/V1/localSearch"){}
					param_type sort() const{
						param_type sort;
						sort["appid"]=appid_;
						if(!cid_.empty()) sort["cid"]=cid_;
						if(!gid_.empty()) sort["gid"]=gid_;
						if(!query_.empty()) sort["query"]=query_;
						if(!sort_.empty()) sort["sort"]=sort_;
						if(!start_.empty()) sort["start"]=start_;
						if(!results_.empty()) sort["results"]=results_;
						if(!detail_.empty()) sort["detail"]=detail_;
						if(!output_.empty()) sort["output"]=output_;
						if(!lat_.empty()) sort["lat"]=lat_;
						if(!lon_.empty()) sort["lon"]=lon_;
						if(!bbox_.empty()) sort["bbox"]=bbox_;
						if(!dist_.empty()) sort["dist"]=dist_;
						if(!ac_.empty()) sort["ac"]=ac_;
						if(!uid_.empty()) sort["uid"]=uid_;
						if(!callback_.empty()) sort["callback"]=callback_;
						return sort;
					}
				private:
					const string_type appid_;
					const string_type cid_;
					const string_type gid_;
					const string_type query_;
					const string_type sort_;
					const string_type start_;
					const string_type results_;
					const string_type detail_;
					const string_type output_;
					const string_type lat_;
					const string_type lon_;
					const string_type bbox_;
					const string_type dist_;
					const string_type ac_;
					const string_type uid_;
					const string_type callback_;
				};
				
				//
				//GET OpenLocalPlatform/V1/getGid
				//http://developer.yahoo.co.jp/webapi/map/openlocalplatform/v1/getgid.html
				//
				class get_gid : public yahoo_base{
				public:
					get_gid(const string_type appid,const string_type name,const string_type lat,const string_type lon,const string_type address="",const string_type phone="",const string_type output="",const string_type callback="")
						: appid_(appid), name_(name), lat_(lat), lon_(lon), address_(address), phone_(phone), output_(output), callback_(callback), yahoo_base("GET","http","storage.olp.yahooapis.jp","/OpenLocalPlatform/V1/getGid"){}
					param_type sort() const{
						param_type sort;
						sort["appid"]=appid_;
						sort["name"]=name_;
						sort["lat"]=lat_;
						sort["lon"]=lon_;
						if(!address_.empty()) sort["address"]=address_;
						if(!phone_.empty()) sort["phone"]=phone_;
						if(!output_.empty()) sort["output"]=output_;
						if(!callback_.empty()) sort["callback"]=callback_;
						return sort;
					}
				private:
					const string_type appid_;
					const string_type name_;
					const string_type lat_;
					const string_type lon_;
					const string_type address_;
					const string_type phone_;
					const string_type output_;
					const string_type callback_;
				};
				
				//
				//GET OpenLocalPlatform/V1/contentsGeoCoder
				//http://developer.yahoo.co.jp/webapi/map/openlocalplatform/v1/contentsgeocoder.html
				//
				class contents_geocoder : public yahoo_base{
				public:
					contents_geocoder(const string_type appid,const string_type query,const string_type ei="",const string_type category="",const string_type results="",const string_type output="",const string_type callback="")
						: appid_(appid), query_(query), ei_(ei), category_(category), results_(results), output_(output), callback_(callback), yahoo_base("GET","http","contents.search.olp.yahooapis.jp","/OpenLocalPlatform/V1/contentsGeoCoder"){}
					param_type sort() const{
						param_type sort;
						sort["appid"]=appid_;
						sort["query"]=query_;
						if(!ei_.empty()) sort["ei"]=ei_;
						if(!category_.empty()) sort["category"]=category_;
						if(!results_.empty()) sort["results"]=results_;
						if(!output_.empty()) sort["output"]=output_;
						if(!callback_.empty()) sort["callback"]=callback_;
						return sort;
					}
				private:
					const string_type appid_;
					const string_type query_;
					const string_type ei_;
					const string_type category_;
					const string_type results_;
					const string_type output_;
					const string_type callback_;
				};
				
				//
				//POST  OpenLocalPlatform/V1/datumConvert
				//http://developer.yahoo.co.jp/webapi/map/openlocalplatform/v1/datum.html
				//
				class datum_convert : public yahoo_base{
				public:
					datum_convert(const string_type appid,const string_type coordinates,const string_type datum="",const string_type output="",const string_type callback="")
						: appid_(appid), coordinates_(coordinates), datum_(datum), output_(output), callback_(callback), yahoo_base("POST","http","datum.search.olp.yahooapis.jp","/OpenLocalPlatform/V1/datumConvert"){}
					param_type sort() const{
						param_type sort;
						sort["appid"]=appid_;
						sort["coordinates"]=coordinates_;
						if(!datum_.empty()) sort["datum"]=datum_;
						if(!output_.empty()) sort["output"]=output_;
						if(!callback_.empty()) sort["callback"]=callback_;
						return sort;
					}
				private:
					const string_type appid_;
					const string_type coordinates_;
					const string_type datum_;
					const string_type output_;
					const string_type callback_;
				};
			}//End map namespace
		}//End yahoo namespace
	}//End api namespace
}//End oauth namespace

#endif
