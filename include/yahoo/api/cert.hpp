#ifndef YAHOO_API_CERT_HPP
#define YAHOO_API_CERT_HPP

namespace oauth{
	namespace api{
		namespace yahoo{
			namespace cert{
				//
				//GET MinnaCertWebService/V1/certList
				//http://developer.yahoo.co.jp/webapi/cert/minnacert/v1/certlist.html
				//
				class cert_list : public yahoo_base{
				public:
					cert_list(
						const string_type appid,
						const string_type userstr="",
						const string_type keyword="",
						const string_type extract="",
						const string_type order="",
						const string_type start="",
						const string_type amount="",
						const string_type output="",
						const string_type callback=""
						)
						: appid_(appid),
						userstr_(userstr),
						keyword_(keyword),
						extract_(extract),
						order_(order),
						start_(start),
						amount_(amount),
						output_(output),
						callback_(callback),
						yahoo_base("GET","http","cert.yahooapis.jp","/MinnaCertWebService/V1/certList"){}
					param_type sort() const{
						param_type sort;
						sort["appid"]=appid_;
						if(!userstr_.empty()) sort["userstr"]=userstr_;
						if(!keyword_.empty()) sort["keyword"]=keyword_;
						if(!extract_.empty()) sort["extract"]=extract_;
						if(!order_.empty()) sort["order"]=order_;
						if(!start_.empty()) sort["start"]=start_;
						if(!amount_.empty()) sort["amount"]=amount_;
						if(!output_.empty()) sort["output"]=output_;
						if(!callback_.empty()) sort["callback"]=callback_;
						return sort;
					}
				private:
					const string_type appid_;
					const string_type userstr_;
					const string_type keyword_;
					const string_type extract_;
					const string_type order_;
					const string_type start_;
					const string_type amount_;
					const string_type output_;
					const string_type callback_;
				};
				
				//
				//GET MinnaCertWebService/V1/certDetail
				//http://developer.yahoo.co.jp/webapi/cert/minnacert/v1/certdetail.html
				//
				class cert_detail : public yahoo_base{
				public:
					cert_detail(
						const string_type appid,
						const string_type cert_id,
						const string_type get_q="",
						const string_type order_number="",
						const string_type output="",
						const string_type callback=""
						)
						: appid_(appid),
						cert_id_(cert_id),
						get_q_(get_q),
						order_number_(order_number),
						output_(output),
						callback_(callback),
						yahoo_base("GET","http","cert.yahooapis.jp","/MinnaCertWebService/V1/certDetail"){}
					param_type sort() const{
						param_type sort;
						sort["appid"]=appid_;
						sort["cert_id"]=cert_id_;
						if(!get_q_.empty()) sort["get_q"]=get_q_;
						if(!order_number_.empty()) sort["order_number"]=order_number_;
						if(!output_.empty()) sort["output"]=output_;
						if(!callback_.empty()) sort["callback"]=callback_;
						return sort;
					}
				private:
					const string_type appid_;
					const string_type cert_id_;
					const string_type get_q_;
					const string_type order_number_;
					const string_type output_;
					const string_type callback_;
				};
				
				//
				//GET MinnaCertWebService/V1/certExam
				//http://developer.yahoo.co.jp/webapi/cert/minnacert/v1/certexam.html
				//
				class cert_exam : public yahoo_base{
				public:
					cert_exam(
						const string_type appid,
						const string_type cert_id,
						const string_type qid,
						const string_type answer,
						const string_type output="",
						const string_type callback=""
						)
						: appid_(appid),
						cert_id_(cert_id),
						qid_(qid),
						answer_(answer),
						output_(output),
						callback_(callback),
						yahoo_base("GET","http","cert.yahooapis.jp","/MinnaCertWebService/V1/certExam"){}
					param_type sort() const{
						param_type sort;
						sort["appid"]=appid_;
						sort["cert_id"]=cert_id_;
						sort["qid"]=qid_;
						sort["answer"]=answer_;
						if(!output_.empty()) sort["output"]=output_;
						if(!callback_.empty()) sort["callback"]=callback_;
						return sort;
					}
				private:
					const string_type appid_;
					const string_type cert_id_;
					const string_type qid_;
					const string_type answer_;
					const string_type output_;
					const string_type callback_;
				};
			}//End cert namespace
		}//End yahoo namespace
	}//End api namespace
}//End oauth namespace

#endif
