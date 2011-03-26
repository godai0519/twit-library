#ifndef YAHOO_API_TEXT_HPP
#define YAHOO_API_TEXT_HPP

namespace oauth{
	namespace api{
		namespace yahoo{
			namespace text{
				//
				//POST MAService/V1/parse
				//http://developer.yahoo.co.jp/webapi/jlp/ma/v1/parse.html
				//
				class ma_parse : public yahoo_base{
				public:
					ma_parse(const string_type appid,const string_type sentence,const string_type results,const string_type response="",const string_type filter="",const string_type ma_response="",const string_type ma_filter="",const string_type uniq_response="",const string_type uniq_filter="",const string_type uniq_by_baseform="")
						: appid_(appid), sentence_(sentence), results_(results), response_(response), filter_(filter), ma_response_(ma_response), ma_filter_(ma_filter), uniq_response_(uniq_response), uniq_filter_(uniq_filter), uniq_by_baseform_(uniq_by_baseform), yahoo_base("POST","http","jlp.yahooapis.jp","/MAService/V1/parse"){}
					param_type sort() const{
						param_type sort;
						sort["appid"]=appid_;
						sort["sentence"]=sentence_;
						sort["results"]=results_;
						if(response_!="") sort["response"]=response_;
						if(filter_!="") sort["filter"]=filter_;
						if(ma_response_!="") sort["ma_response"]=ma_response_;
						if(ma_filter_!="") sort["ma_filter"]=ma_filter_;
						if(uniq_response_!="") sort["uniq_response"]=uniq_response_;
						if(uniq_filter_!="") sort["uniq_filter"]=uniq_filter_;
						if(uniq_by_baseform_!="") sort["uniq_by_baseform"]=uniq_by_baseform_;
						return sort;
					}
				private:
					const string_type appid_;
					const string_type sentence_;
					const string_type results_;
					const string_type response_;
					const string_type filter_;
					const string_type ma_response_;
					const string_type ma_filter_;
					const string_type uniq_response_;
					const string_type uniq_filter_;
					const string_type uniq_by_baseform_;
				};

				//
				//POST JIMService/V1/conversion
				//http://developer.yahoo.co.jp/webapi/jlp/jim/v1/conversion.html
				//
				class conversion : public yahoo_base{
				public:
					conversion(const string_type appid,const string_type sentence,const string_type format="",const string_type mode="",const string_type response="",const string_type dictionary="",const string_type results="")
						: appid_(appid), sentence_(sentence), format_(format), mode_(mode), response_(response), dictionary_(dictionary), results_(results), yahoo_base("POST","http","jlp.yahooapis.jp","/JIMService/V1/conversion"){}
					param_type sort() const{
						param_type sort;
						sort["appid"]=appid_;
						sort["sentence"]=sentence_;
						if(format_!="") sort["format"]=format_;
						if(mode_!="") sort["mode"]=mode_;
						if(response_!="") sort["response"]=response_;
						if(dictionary_!="") sort["dictionary"]=dictionary_;
						if(results_!="") sort["results"]=results_;
						return sort;
					}
				private:
					const string_type appid_;
					const string_type sentence_;
					const string_type format_;
					const string_type mode_;
					const string_type response_;
					const string_type dictionary_;
					const string_type results_;
				};

				//
				//POST FuriganaService/V1/furigana
				//http://developer.yahoo.co.jp/webapi/jlp/furigana/v1/furigana.html
				//
				class furigana : public yahoo_base{
				public:
					furigana(const string_type appid,const string_type sentence,const string_type grade="")
						: appid_(appid), sentence_(sentence), grade_(grade), yahoo_base("POST","http","jlp.yahooapis.jp","/FuriganaService/V1/furigana"){}
					param_type sort() const{
						param_type sort;
						sort["appid"]=appid_;
						sort["sentence"]=sentence_;
						if(grade_!="") sort["grade"]=grade_;
						return sort;
					}
				private:
					const string_type appid_;
					const string_type sentence_;
					const string_type grade_;
				};

				//
				//POST KouseiService/V1/kousei
				//http://developer.yahoo.co.jp/webapi/jlp/kousei/v1/kousei.html
				//
				class kousei : public yahoo_base{
				public:
					kousei(const string_type appid,const string_type sentence,const string_type filter_group="",const string_type no_filter="")
						: appid_(appid), sentence_(sentence), filter_group_(filter_group), no_filter_(no_filter), yahoo_base("POST","http","jlp.yahooapis.jp","/KouseiService/V1/kousei"){}
					param_type sort() const{
						param_type sort;
						sort["appid"]=appid_;
						sort["sentence"]=sentence_;
						if(filter_group_!="") sort["filter_group"]=filter_group_;
						if(no_filter_!="") sort["no_filter"]=no_filter_;
						return sort;
					}
				private:
					const string_type appid_;
					const string_type sentence_;
					const string_type filter_group_;
					const string_type no_filter_;
				};

				//
				//POST DAService/V1/parse
				//http://developer.yahoo.co.jp/webapi/jlp/da/v1/parse.html
				//
				class da_parse : public yahoo_base{
				public:
					da_parse(const string_type appid,const string_type sentence)
						: appid_(appid), sentence_(sentence), yahoo_base("POST","http","jlp.yahooapis.jp","/DAService/V1/parse"){}
					param_type sort() const{
						param_type sort;
						sort["appid"]=appid_;
						sort["sentence"]=sentence_;
						return sort;
					}
				private:
					const string_type appid_;
					const string_type sentence_;
				};

				//
				//KeyphraseService/V1/extract
				//http://developer.yahoo.co.jp/webapi/jlp/keyphrase/v1/extract.html
				//
				class extract : public yahoo_base{
				public:
					extract(const string_type appid,const string_type sentence,const string_type output="",const string_type callback="")
						: appid_(appid), sentence_(sentence), output_(output), callback_(callback), yahoo_base("POST","http","jlp.yahooapis.jp","/KeyphraseService/V1/extract"){}
					param_type sort() const{
						param_type sort;
						sort["appid"]=appid_;
						sort["sentence"]=sentence_;
						if(output_!="") sort["output"]=output_;
						if(callback_!="") sort["callback"]=callback_;
						return sort;
					}
				private:
					const string_type appid_;
					const string_type sentence_;
					const string_type output_;
					const string_type callback_;
				};
			}//End text namespace
		}//End yahoo namespace
	}//End api namespace
}//End oauth namespace

#endif
