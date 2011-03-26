#ifndef YAHOO_API_CHIEBUKURO_HPP
#define YAHOO_API_CHIEBUKURO_HPP

namespace oauth{
	namespace api{
		namespace yahoo{
			namespace chiebukuro{
				//
				//GET Chiebukuro/V1/questionSearch
				//http://developer.yahoo.co.jp/webapi/chiebukuro/chiebukuro/v1/questionsearch.html
				//
				class question_search : public yahoo_base{
				public:
					question_search(
						const string_type appid,
						const string_type query,
						const string_type type="",
						const string_type categoryid="",
						const string_type condition="",
						const string_type sort="",
						const string_type posteddevice="",
						const string_type start="",
						const string_type results="",
						const string_type restype=""
						)
						: appid_(appid),
						query_(query),
						type_(type),
						categoryid_(categoryid),
						condition_(condition),
						sort_(sort),
						posteddevice_(posteddevice),
						start_(start),
						results_(results), 
						restype_(restype),
						yahoo_base("GET","http","chiebukuro.yahooapis.jp","/Chiebukuro/V1/questionSearch"){}
					param_type sort() const{
						param_type sort;
						sort["appid"]=appid_;
						sort["query"]=query_;
						if(type_!="") sort["type"]=type_;
						if(categoryid_!="") sort["categoryid"]=categoryid_;
						if(condition_!="") sort["condition"]=condition_;
						if(sort_!="") sort["sort"]=sort_;
						if(posteddevice_!="") sort["posteddevice"]=posteddevice_;
						if(start_!="") sort["start"]=start_;
						if(results_!="") sort["results"]=results_;
						if(restype_!="") sort["restype"]=restype_;
						return sort;
					}
				private:
					const string_type appid_;
					const string_type query_;
					const string_type type_;
					const string_type categoryid_;
					const string_type condition_;
					const string_type sort_;
					const string_type posteddevice_;
					const string_type start_;
					const string_type results_;
					const string_type restype_;
				};
				
				//
				//GET Chiebukuro/V1/categoryTree
				//http://developer.yahoo.co.jp/webapi/chiebukuro/chiebukuro/v1/categorytree.html
				//
				class category_tree : public yahoo_base{
				public:
					category_tree(
						const string_type appid,const string_type categoryid="")
						: appid_(appid),categoryid_(categoryid),yahoo_base("GET","http","chiebukuro.yahooapis.jp","/Chiebukuro/V1/categoryTree"){}
					param_type sort() const{
						param_type sort;
						sort["appid"]=appid_;
						if(categoryid_!="") sort["categoryid"]=categoryid_;
						return sort;
					}
				private:
					const string_type appid_;
					const string_type categoryid_;
				};
				
				//
				//GET Chiebukuro/V1/getNewQuestionList
				//http://developer.yahoo.co.jp/webapi/chiebukuro/chiebukuro/v1/getnewquestionlist.html
				//
				class get_new_questionlist : public yahoo_base{
				public:
					get_new_questionlist(
						const string_type appid,
						const string_type condition,
						const string_type sort="",
						const string_type category_id="",
						const string_type start="",
						const string_type results="",
						const string_type mobile_flg="",
						const string_type image_flg="",
						const string_type output=""
						)
						: appid_(appid),
						condition_(condition),
						sort_(sort),
						category_id_(category_id),
						start_(start),
						results_(results), 
						mobile_flg_(mobile_flg),
						image_flg_(image_flg),
						output_(output),
						yahoo_base("GET","http","chiebukuro.yahooapis.jp","/Chiebukuro/V1/getNewQuestionList"){}
					param_type sort() const{
						param_type sort;
						sort["appid"]=appid_;
						sort["condition"]=condition_;
						if(sort_!="") sort["sort"]=sort_;
						if(category_id_!="") sort["category_id"]=category_id_;
						if(start_!="") sort["start"]=start_;
						if(results_!="") sort["results"]=results_;
						if(mobile_flg_!="") sort["mobile_flg"]=mobile_flg_;
						if(image_flg_!="") sort["image_flg"]=image_flg_;
						if(output_!="") sort["output"]=output_;
						return sort;
					}
				private:
					const string_type appid_;
					const string_type condition_;
					const string_type sort_;
					const string_type category_id_;
					const string_type start_;
					const string_type results_;
					const string_type mobile_flg_;
					const string_type image_flg_;
					const string_type output_;
				};
				
				//
				//GET Chiebukuro/V1/detailSearch
				//http://developer.yahoo.co.jp/webapi/chiebukuro/chiebukuro/v1/detailsearch.html
				//
				class detail_search : public yahoo_base{
				public:
					detail_search(
						const string_type appid,
						const string_type question_id,
						const string_type sort="",
						const string_type answer_id="",
						const string_type start="",
						const string_type results="",
						const string_type use_title="",
						const string_type image_type="",
						const string_type output=""
						)
						: appid_(appid),
						question_id_(question_id),
						sort_(sort),
						answer_id_(answer_id),
						start_(start),
						results_(results), 
						use_title_(use_title),
						image_type_(image_type),
						output_(output),
						yahoo_base("GET","http","chiebukuro.yahooapis.jp","/Chiebukuro/V1/detailSearch"){}
					param_type sort() const{
						param_type sort;
						sort["appid"]=appid_;
						sort["question_id"]=question_id_;
						if(sort_!="") sort["sort"]=sort_;
						if(answer_id_!="") sort["answer_id"]=answer_id_;
						if(start_!="") sort["start"]=start_;
						if(results_!="") sort["results"]=results_;
						if(use_title_!="") sort["use_title"]=use_title_;
						if(image_type_!="") sort["image_type"]=image_type_;
						if(output_!="") sort["output"]=output_;
						return sort;
					}
				private:
					const string_type appid_;
					const string_type question_id_;
					const string_type sort_;
					const string_type answer_id_;
					const string_type start_;
					const string_type results_;
					const string_type use_title_;
					const string_type image_type_;
					const string_type output_;
				};
				
				//
				//POST Chiebukuro/V1/postQuestion
				//http://developer.yahoo.co.jp/webapi/chiebukuro/chiebukuro/v1/postquestion.html
				//
				class post_question : public yahoo_base{
				public:
					post_question(
						const string_type content,
						const string_type mobile_uid="",
						const string_type category_id="",
						const string_type coin="",
						const string_type is_mobile="",
						const string_type image="",
						const string_type code="",
						const string_type request_flg="",
						const string_type output=""
						)
						: content_(content),
						mobile_uid_(mobile_uid),
						category_id_(category_id),
						coin_(coin),
						is_mobile_(is_mobile),
						image_(image), 
						code_(code),
						request_flg_(request_flg),
						output_(output),
						yahoo_base("POST","http","chiebukuro.yahooapis.jp","/Chiebukuro/V1/postQuestion"){}
					param_type sort() const{
						param_type sort;
						sort["content"]=content_;
						if(mobile_uid_!="") sort["mobile_uid"]=mobile_uid_;
						if(category_id_!="") sort["category_id"]=category_id_;
						if(coin_!="") sort["coin"]=coin_;
						if(is_mobile_!="") sort["is_mobile"]=is_mobile_;
						if(image_!="") sort["image"]=image_;
						if(code_!="") sort["code"]=code_;
						if(request_flg_!="") sort["request_flg"]=request_flg_;
						if(output_!="") sort["output"]=output_;
						return sort;
					}
				private:
					const string_type content_;
					const string_type mobile_uid_;
					const string_type category_id_;
					const string_type coin_;
					const string_type is_mobile_;
					const string_type image_;
					const string_type code_;
					const string_type request_flg_;
					const string_type output_;
				};
				
				//
				//POST Chiebukuro/V1/postQuestionPreview
				//http://developer.yahoo.co.jp/webapi/chiebukuro/chiebukuro/v1/postquestionpreview.html
				//
				class post_question_preview : public yahoo_base{
				public:
					post_question_preview(
						const string_type content,
						const string_type mobile_uid="",
						const string_type category_id="",
						const string_type coin="",
						const string_type is_mobile="",
						const string_type image="",
						const string_type code="",
						const string_type request_flg="",
						const string_type output=""
						)
						: content_(content),
						mobile_uid_(mobile_uid),
						category_id_(category_id),
						coin_(coin),
						is_mobile_(is_mobile),
						image_(image), 
						code_(code),
						request_flg_(request_flg),
						output_(output),
						yahoo_base("POST","http","chiebukuro.yahooapis.jp","/Chiebukuro/V1/postQuestionPreview"){}
					param_type sort() const{
						param_type sort;
						sort["content"]=content_;
						if(mobile_uid_!="") sort["mobile_uid"]=mobile_uid_;
						if(category_id_!="") sort["category_id"]=category_id_;
						if(coin_!="") sort["coin"]=coin_;
						if(is_mobile_!="") sort["is_mobile"]=is_mobile_;
						if(image_!="") sort["image"]=image_;
						if(code_!="") sort["code"]=code_;
						if(request_flg_!="") sort["request_flg"]=request_flg_;
						if(output_!="") sort["output"]=output_;
						return sort;
					}
				private:
					const string_type content_;
					const string_type mobile_uid_;
					const string_type category_id_;
					const string_type coin_;
					const string_type is_mobile_;
					const string_type image_;
					const string_type code_;
					const string_type request_flg_;
					const string_type output_;
				};
				
				//
				//POST Chiebukuro/V1/postQueSupplement
				//http://developer.yahoo.co.jp/webapi/chiebukuro/chiebukuro/v1/postquesupplement.html
				//
				class post_que_supplement : public yahoo_base{
				public:
					post_que_supplement(
						const string_type question_id,
						const string_type content,
						const string_type is_mobile="",
						const string_type output=""
						)
						: question_id_(question_id),
						content_(content),
						is_mobile_(is_mobile),
						output_(output),
						yahoo_base("POST","http","chiebukuro.yahooapis.jp","/Chiebukuro/V1/postQueSupplement"){}
					param_type sort() const{
						param_type sort;
						sort["question_id"]=question_id_;
						sort["content"]=content_;
						if(is_mobile_!="") sort["is_mobile"]=is_mobile_;
						if(output_!="") sort["output"]=output_;
						return sort;
					}
				private:
					const string_type question_id_;
					const string_type content_;
					const string_type is_mobile_;
					const string_type output_;
				};
				
				//
				//POST Chiebukuro/V1/postQueSupplementPreview
				//http://developer.yahoo.co.jp/webapi/chiebukuro/chiebukuro/v1/postquesupplementpreview.html
				//
				class post_que_supplement_preview : public yahoo_base{
				public:
					post_que_supplement_preview(
						const string_type question_id,
						const string_type content,
						const string_type is_mobile="",
						const string_type output=""
						)
						: question_id_(question_id),
						content_(content),
						is_mobile_(is_mobile),
						output_(output),
						yahoo_base("POST","http","chiebukuro.yahooapis.jp","/Chiebukuro/V1/postQueSupplementPreview"){}
					param_type sort() const{
						param_type sort;
						sort["question_id"]=question_id_;
						sort["content"]=content_;
						if(is_mobile_!="") sort["is_mobile"]=is_mobile_;
						if(output_!="") sort["output"]=output_;
						return sort;
					}
				private:
					const string_type question_id_;
					const string_type content_;
					const string_type is_mobile_;
					const string_type output_;
				};
				
				//
				//POST Chiebukuro/V1/cancelQuestion
				//http://developer.yahoo.co.jp/webapi/chiebukuro/chiebukuro/v1/cancelquestion.html
				//
				class cancel_question : public yahoo_base{
				public:
					cancel_question(
						const string_type appid,
						const string_type question_id,
						const string_type cancel_comment,
						const string_type res_type="",
						const string_type output="",
						const string_type image_type=""
						)
						: appid_(appid),
						question_id_(question_id),
						cancel_comment_(cancel_comment),
						res_type_(res_type),
						output_(output),
						image_type_(image_type),
						yahoo_base("POST","http","chiebukuro.yahooapis.jp","/Chiebukuro/V1/cancelQuestion"){}
					param_type sort() const{
						param_type sort;
						sort["appid"]=appid_;
						sort["question_id"]=question_id_;
						sort["cancel_comment"]=cancel_comment_;
						if(res_type_!="") sort["res_type"]=res_type_;
						if(output_!="") sort["output"]=output_;
						if(image_type_!="") sort["image_type"]=image_type_;
						return sort;
					}
				private:
					const string_type appid_;
					const string_type question_id_;
					const string_type cancel_comment_;
					const string_type res_type_;
					const string_type output_;
					const string_type image_type_;
				};
				
				//
				//POST Chiebukuro/V1/cancelQuestionPreview
				//http://developer.yahoo.co.jp/webapi/chiebukuro/chiebukuro/v1/cancelquestionpreview.html
				//
				class cancel_question_preview : public yahoo_base{
				public:
					cancel_question_preview(
						const string_type appid,
						const string_type question_id,
						const string_type cancel_comment,
						const string_type res_type="",
						const string_type output="",
						const string_type image_type=""
						)
						: appid_(appid),
						question_id_(question_id),
						cancel_comment_(cancel_comment),
						res_type_(res_type),
						output_(output),
						image_type_(image_type),
						yahoo_base("POST","http","chiebukuro.yahooapis.jp","/Chiebukuro/V1/cancelQuestionPreview"){}
					param_type sort() const{
						param_type sort;
						sort["appid"]=appid_;
						sort["question_id"]=question_id_;
						sort["cancel_comment"]=cancel_comment_;
						if(res_type_!="") sort["res_type"]=res_type_;
						if(output_!="") sort["output"]=output_;
						if(image_type_!="") sort["image_type"]=image_type_;
						return sort;
					}
				private:
					const string_type appid_;
					const string_type question_id_;
					const string_type cancel_comment_;
					const string_type res_type_;
					const string_type output_;
					const string_type image_type_;
				};
				
				//
				//POST Chiebukuro/V1/selectBestAnswer
				//http://developer.yahoo.co.jp/webapi/chiebukuro/chiebukuro/v1/selectbestanswer.html
				//
				class select_best_answer : public yahoo_base{
				public:
					select_best_answer(
						const string_type question_id,
						const string_type answer_id,
						const string_type comment="",
						const string_type icon="",
						const string_type output=""
						)
						: question_id_(question_id),
						answer_id_(answer_id),
						comment_(comment),
						icon_(icon),
						output_(output),
						yahoo_base("POST","http","chiebukuro.yahooapis.jp","/Chiebukuro/V1/selectBestAnswer"){}
					param_type sort() const{
						param_type sort;
						sort["question_id"]=question_id_;
						sort["answer_id"]=answer_id_;
						if(comment_!="") sort["comment"]=comment_;
						if(icon_!="") sort["icon"]=icon_;
						if(output_!="") sort["output"]=output_;
						return sort;
					}
				private:
					const string_type question_id_;
					const string_type answer_id_;
					const string_type comment_;
					const string_type icon_;
					const string_type output_;
				};
				
				//
				//POST Chiebukuro/V1/postAnswer
				//http://developer.yahoo.co.jp/webapi/chiebukuro/chiebukuro/v1/postanswer.html
				//
				class post_answer : public yahoo_base{
				public:
					post_answer(
						const string_type content,
						const string_type question_id,
						const string_type answer_id="",
						const string_type mobile_uid="",
						const string_type is_mobile="",
						const string_type image="",
						const string_type code="",
						const string_type output=""
						)
						: content_(content),
						question_id_(question_id),
						answer_id_(answer_id),
						mobile_uid_(mobile_uid),
						is_mobile_(is_mobile),
						image_(image),
						code_(code),
						output_(output),
						yahoo_base("POST","http","chiebukuro.yahooapis.jp","/Chiebukuro/V1/postAnswer"){}
					param_type sort() const{
						param_type sort;
						sort["content"]=content_;
						sort["question_id"]=question_id_;
						if(answer_id_!="") sort["answer_id"]=answer_id_;
						if(mobile_uid_!="") sort["mobile_uid"]=mobile_uid_;
						if(is_mobile_!="") sort["is_mobile"]=is_mobile_;
						if(image_!="") sort["image"]=image_;
						if(code_!="") sort["code"]=code_;
						if(output_!="") sort["output"]=output_;
						return sort;
					}
				private:
					const string_type content_;
					const string_type question_id_;
					const string_type answer_id_;
					const string_type mobile_uid_;
					const string_type is_mobile_;
					const string_type image_;
					const string_type code_;
					const string_type output_;
				};
				
				//
				//POST Chiebukuro/V1/postAnswerPreview
				//http://developer.yahoo.co.jp/webapi/chiebukuro/chiebukuro/v1/postanswerpreview.html
				//
				class post_answer_preview : public yahoo_base{
				public:
					post_answer_preview(
						const string_type content,
						const string_type question_id,
						const string_type answer_id="",
						const string_type mobile_uid="",
						const string_type is_mobile="",
						const string_type image="",
						const string_type code="",
						const string_type output=""
						)
						: content_(content),
						question_id_(question_id),
						answer_id_(answer_id),
						mobile_uid_(mobile_uid),
						is_mobile_(is_mobile),
						image_(image),
						code_(code),
						output_(output),
						yahoo_base("POST","http","chiebukuro.yahooapis.jp","/Chiebukuro/V1/postAnswerPreview"){}
					param_type sort() const{
						param_type sort;
						sort["content"]=content_;
						sort["question_id"]=question_id_;
						if(answer_id_!="") sort["answer_id"]=answer_id_;
						if(mobile_uid_!="") sort["mobile_uid"]=mobile_uid_;
						if(is_mobile_!="") sort["is_mobile"]=is_mobile_;
						if(image_!="") sort["image"]=image_;
						if(code_!="") sort["code"]=code_;
						if(output_!="") sort["output"]=output_;
						return sort;
					}
				private:
					const string_type content_;
					const string_type question_id_;
					const string_type answer_id_;
					const string_type mobile_uid_;
					const string_type is_mobile_;
					const string_type image_;
					const string_type code_;
					const string_type output_;
				};
				
				//
				//POST Chiebukuro/V1/cancelAnswer
				//http://developer.yahoo.co.jp/webapi/chiebukuro/chiebukuro/v1/cancelanswer.html
				//
				class cancel_answer : public yahoo_base{
				public:
					cancel_answer(
						const string_type content,
						const string_type question_id,
						const string_type answer_id,
						const string_type res_type="",
						const string_type output="",
						const string_type image_type=""
						)
						: content_(content),
						question_id_(question_id),
						answer_id_(answer_id),
						res_type_(res_type),
						output_(output),
						image_type_(image_type),
						yahoo_base("POST","http","chiebukuro.yahooapis.jp","/Chiebukuro/V1/cancelAnswer"){}
					param_type sort() const{
						param_type sort;
						sort["content"]=content_;
						sort["question_id"]=question_id_;
						sort["answer_id"]=answer_id_;
						if(res_type_!="") sort["res_type"]=res_type_;
						if(output_!="") sort["output"]=output_;
						if(image_type_!="") sort["image_type"]=image_type_;
						return sort;
					}
				private:
					const string_type content_;
					const string_type question_id_;
					const string_type answer_id_;
					const string_type res_type_;
					const string_type output_;
					const string_type image_type_;
				};
				
				//
				//POST Chiebukuro/V1/cancelAnswerPreview
				//http://developer.yahoo.co.jp/webapi/chiebukuro/chiebukuro/v1/cancelanswerpreview.html
				//
				class cancel_answer_preview : public yahoo_base{
				public:
					cancel_answer_preview(
						const string_type content,
						const string_type question_id,
						const string_type answer_id,
						const string_type res_type="",
						const string_type output="",
						const string_type image_type=""
						)
						: content_(content),
						question_id_(question_id),
						answer_id_(answer_id),
						res_type_(res_type),
						output_(output),
						image_type_(image_type),
						yahoo_base("POST","http","chiebukuro.yahooapis.jp","/Chiebukuro/V1/cancelAnswerPreview"){}
					param_type sort() const{
						param_type sort;
						sort["content"]=content_;
						sort["question_id"]=question_id_;
						sort["answer_id"]=answer_id_;
						if(res_type_!="") sort["res_type"]=res_type_;
						if(output_!="") sort["output"]=output_;
						if(image_type_!="") sort["image_type"]=image_type_;
						return sort;
					}
				private:
					const string_type content_;
					const string_type question_id_;
					const string_type answer_id_;
					const string_type res_type_;
					const string_type output_;
					const string_type image_type_;
				};
			}//End chiebukuro namespace
		}//End yahoo namespace
	}//End api namespace
}//End oauth namespace

#endif
