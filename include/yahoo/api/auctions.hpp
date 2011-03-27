#ifndef YAHOO_API_AUCTIONS_HPP
#define YAHOO_API_AUCTIONS_HPP

namespace oauth{
	namespace api{
		namespace yahoo{
			namespace auctions{
				//
				//POST AuctionWebService/V2/categoryTree
				//http://developer.yahoo.co.jp/webapi/auctions/auction/v2/categorytree.html
				//
				class categorytree : public yahoo_base{
				public:
					categorytree(const string_type appid,const string_type response_format="xml",const string_type callback="",const string_type category="")
						: appid_(appid), callback_(callback), category_(category), yahoo_base("POST","http","auctions.yahooapis.jp","/AuctionWebService/V2"+((response_format=="xml") ? ("") : ("/"+response_format))+"/categoryTree"){}
					param_type sort() const{
						param_type sort;
						sort["appid"]=appid_;
						if(!callback_.empty()) sort["callback"]=callback_;
						if(!category_.empty()) sort["category"]=category_;
						return sort;
					}
				private:
					const string_type appid_;
					const string_type callback_;
					const string_type category_;
				};
				
				//
				//POST AuctionWebService/V2/php/categoryLeaf
				//http://developer.yahoo.co.jp/webapi/auctions/auction/v2/categoryleaf.html
				//
				class categoryleaf : public yahoo_base{
				public:
					categoryleaf(
						const string_type appid,
						const string_type category,
						const string_type response_format="xml",
						const string_type callback="",
						const string_type page="",
						const string_type sort="",
						const string_type order="",
						const string_type store="",
						const string_type aucminprice="",
						const string_type aucmaxprice="",
						const string_type aucmin_bidorbuy_price="",
						const string_type aucmax_bidorbuy_price="",
						const string_type escrow="",
						const string_type easypayment="",
						const string_type ybank="",
						const string_type _new="",
						const string_type freeshipping="",
						const string_type wrappingicon="",
						const string_type buynow="",
						const string_type thumbnail="",
						const string_type attn="",
						const string_type english="",
						const string_type point="",
						const string_type gift_icon="",
						const string_type item_status="",
						const string_type offer=""
						)
						: appid_(appid),
						category_(category), 
						callback_(callback), 
						page_(page), 
						sort_(sort), 
						order_(order), 
						store_(store), 
						aucminprice_(aucminprice), 
						aucmaxprice_(aucmaxprice), 
						aucmin_bidorbuy_price_(aucmin_bidorbuy_price), 
						aucmax_bidorbuy_price_(aucmax_bidorbuy_price), 
						escrow_(escrow), 
						easypayment_(easypayment), 
						ybank_(ybank), 
						new_(_new), 
						freeshipping_(freeshipping), 
						wrappingicon_(wrappingicon), 
						buynow_(buynow), 
						thumbnail_(thumbnail), 
						attn_(attn), 
						english_(english), 
						point_(point), 
						gift_icon_(gift_icon), 
						item_status_(item_status), 
						offer_(offer),
						yahoo_base("POST","http","auctions.yahooapis.jp","/AuctionWebService/V2"+((response_format=="xml") ? ("") : ("/"+response_format))+"/categoryLeaf"){}
					param_type sort() const{
						param_type sort;
						sort["appid"]=appid_;
						sort["category"]=category_;
						if(!callback_.empty()) sort["callback"]=callback_;
						if(!page_.empty()) sort["page"]=page_;
						if(!sort_.empty()) sort["sort"]=sort_;
						if(!order_.empty()) sort["order"]=order_;
						if(!store_.empty()) sort["store"]=store_;
						if(!aucminprice_.empty()) sort["aucminprice"]=aucminprice_;
						if(!aucmaxprice_.empty()) sort["aucmaxprice"]=aucmaxprice_;
						if(!aucmin_bidorbuy_price_.empty()) sort["aucmin_bidorbuy_price"]=aucmin_bidorbuy_price_;
						if(!aucmax_bidorbuy_price_.empty()) sort["aucmax_bidorbuy_price"]=aucmax_bidorbuy_price_;
						if(!escrow_.empty()) sort["escrow"]=escrow_;
						if(!easypayment_.empty()) sort["easypayment"]=easypayment_;
						if(!ybank_.empty()) sort["ybank"]=ybank_;
						if(!new_.empty()) sort["new"]=new_;
						if(!freeshipping_.empty()) sort["freeshipping"]=freeshipping_;
						if(!wrappingicon_.empty()) sort["wrappingicon"]=wrappingicon_;
						if(!buynow_.empty()) sort["buynow"]=buynow_;
						if(!thumbnail_.empty()) sort["thumbnail"]=thumbnail_;
						if(!attn_.empty()) sort["attn"]=attn_;
						if(!english_.empty()) sort["english"]=english_;
						if(!point_.empty()) sort["point"]=point_;
						if(!gift_icon_.empty()) sort["gift_icon"]=gift_icon_;
						if(!item_status_.empty()) sort["item_status"]=item_status_;
						if(!offer_.empty()) sort["offer"]=offer_;
						return sort;
					}
				private:
					const string_type appid_;
					const string_type category_;
					const string_type callback_;
					const string_type page_;
					const string_type sort_;
					const string_type order_;
					const string_type store_;
					const string_type aucminprice_;
					const string_type aucmaxprice_;
					const string_type aucmin_bidorbuy_price_;
					const string_type aucmax_bidorbuy_price_;
					const string_type escrow_;
					const string_type easypayment_;
					const string_type ybank_;
					const string_type new_;
					const string_type freeshipping_;
					const string_type wrappingicon_;
					const string_type buynow_;
					const string_type thumbnail_;
					const string_type attn_;
					const string_type english_;
					const string_type point_;
					const string_type gift_icon_;
					const string_type item_status_;
					const string_type offer_;
				};
				
				//
				//POST AuctionWebService/V2/sellingList
				//http://developer.yahoo.co.jp/webapi/auctions/auction/v2/sellinglist.html
				//
				class sellinglist : public yahoo_base{
				public:
					sellinglist(
						const string_type appid,
						const string_type sellerID,
						const string_type response_format="xml",
						const string_type callback="",
						const string_type page="",
						const string_type sort="",
						const string_type order="",
						const string_type store="",
						const string_type aucminprice="",
						const string_type aucmaxprice="",
						const string_type aucmin_bidorbuy_price="",
						const string_type aucmax_bidorbuy_price="",
						const string_type escrow="",
						const string_type easypayment="",
						const string_type ybank="",
						const string_type _new="",
						const string_type freeshipping="",
						const string_type wrappingicon="",
						const string_type buynow="",
						const string_type thumbnail="",
						const string_type attn="",
						const string_type english="",
						const string_type point="",
						const string_type gift_icon="",
						const string_type item_status="",
						const string_type offer=""
						)
						: appid_(appid),
						sellerID_(sellerID), 
						callback_(callback), 
						page_(page), 
						sort_(sort), 
						order_(order), 
						store_(store), 
						aucminprice_(aucminprice), 
						aucmaxprice_(aucmaxprice), 
						aucmin_bidorbuy_price_(aucmin_bidorbuy_price), 
						aucmax_bidorbuy_price_(aucmax_bidorbuy_price), 
						escrow_(escrow), 
						easypayment_(easypayment), 
						ybank_(ybank), 
						new_(_new), 
						freeshipping_(freeshipping), 
						wrappingicon_(wrappingicon), 
						buynow_(buynow), 
						thumbnail_(thumbnail), 
						attn_(attn), 
						english_(english), 
						point_(point), 
						gift_icon_(gift_icon), 
						item_status_(item_status), 
						offer_(offer),
						yahoo_base("POST","http","auctions.yahooapis.jp","/AuctionWebService/V2"+((response_format=="xml") ? ("") : ("/"+response_format))+"/sellingList"){}
					param_type sort() const{
						param_type sort;
						sort["appid"]=appid_;
						sort["sellerID"]=sellerID_;
						if(!callback_.empty()) sort["callback"]=callback_;
						if(!page_.empty()) sort["page"]=page_;
						if(!sort_.empty()) sort["sort"]=sort_;
						if(!order_.empty()) sort["order"]=order_;
						if(!store_.empty()) sort["store"]=store_;
						if(!aucminprice_.empty()) sort["aucminprice"]=aucminprice_;
						if(!aucmaxprice_.empty()) sort["aucmaxprice"]=aucmaxprice_;
						if(!aucmin_bidorbuy_price_.empty()) sort["aucmin_bidorbuy_price"]=aucmin_bidorbuy_price_;
						if(!aucmax_bidorbuy_price_.empty()) sort["aucmax_bidorbuy_price"]=aucmax_bidorbuy_price_;
						if(!escrow_.empty()) sort["escrow"]=escrow_;
						if(!easypayment_.empty()) sort["easypayment"]=easypayment_;
						if(!ybank_.empty()) sort["ybank"]=ybank_;
						if(!new_.empty()) sort["new"]=new_;
						if(!freeshipping_.empty()) sort["freeshipping"]=freeshipping_;
						if(!wrappingicon_.empty()) sort["wrappingicon"]=wrappingicon_;
						if(!buynow_.empty()) sort["buynow"]=buynow_;
						if(!thumbnail_.empty()) sort["thumbnail"]=thumbnail_;
						if(!attn_.empty()) sort["attn"]=attn_;
						if(!english_.empty()) sort["english"]=english_;
						if(!point_.empty()) sort["point"]=point_;
						if(!gift_icon_.empty()) sort["gift_icon"]=gift_icon_;
						if(!item_status_.empty()) sort["item_status"]=item_status_;
						if(!offer_.empty()) sort["offer"]=offer_;
						return sort;
					}
				private:
					const string_type appid_;
					const string_type sellerID_;
					const string_type callback_;
					const string_type page_;
					const string_type sort_;
					const string_type order_;
					const string_type store_;
					const string_type aucminprice_;
					const string_type aucmaxprice_;
					const string_type aucmin_bidorbuy_price_;
					const string_type aucmax_bidorbuy_price_;
					const string_type escrow_;
					const string_type easypayment_;
					const string_type ybank_;
					const string_type new_;
					const string_type freeshipping_;
					const string_type wrappingicon_;
					const string_type buynow_;
					const string_type thumbnail_;
					const string_type attn_;
					const string_type english_;
					const string_type point_;
					const string_type gift_icon_;
					const string_type item_status_;
					const string_type offer_;
				};
				
				//
				//POST AuctionWebService/V2/search
				//http://developer.yahoo.co.jp/webapi/auctions/auction/v2/search.html
				//
				class search : public yahoo_base{
				public:
					search(
						const string_type appid,
						const string_type query,
						const string_type response_format="xml",
						const string_type callback="",
						const string_type type="",
						const string_type category="",
						const string_type page="",
						const string_type sort="",
						const string_type order="",
						const string_type store="",
						const string_type aucminprice="",
						const string_type aucmaxprice="",
						const string_type aucmin_bidorbuy_price="",
						const string_type aucmax_bidorbuy_price="",
						const string_type escrow="",
						const string_type easypayment="",
						const string_type ybank="",
						const string_type _new="",
						const string_type freeshipping="",
						const string_type wrappingicon="",
						const string_type buynow="",
						const string_type thumbnail="",
						const string_type attn="",
						const string_type english="",
						const string_type point="",
						const string_type gift_icon="",
						const string_type item_status="",
						const string_type offer=""
						)
						: appid_(appid),
						query_(query), 
						callback_(callback), 
						type_(type), 
						category_(category), 
						page_(page), 
						sort_(sort), 
						order_(order), 
						store_(store), 
						aucminprice_(aucminprice), 
						aucmaxprice_(aucmaxprice), 
						aucmin_bidorbuy_price_(aucmin_bidorbuy_price), 
						aucmax_bidorbuy_price_(aucmax_bidorbuy_price), 
						escrow_(escrow), 
						easypayment_(easypayment), 
						ybank_(ybank), 
						new_(_new), 
						freeshipping_(freeshipping), 
						wrappingicon_(wrappingicon), 
						buynow_(buynow), 
						thumbnail_(thumbnail), 
						attn_(attn), 
						english_(english), 
						point_(point), 
						gift_icon_(gift_icon), 
						item_status_(item_status), 
						offer_(offer),
						yahoo_base("POST","http","auctions.yahooapis.jp","/AuctionWebService/V2"+((response_format=="xml") ? ("") : ("/"+response_format))+"/search"){}
					param_type sort() const{
						param_type sort;
						sort["appid"]=appid_;
						sort["query"]=query_;
						if(!callback_.empty()) sort["callback"]=callback_;
						if(!type_.empty()) sort["type"]=type_;
						if(!category_.empty()) sort["category"]=category_;
						if(!page_.empty()) sort["page"]=page_;
						if(!sort_.empty()) sort["sort"]=sort_;
						if(!order_.empty()) sort["order"]=order_;
						if(!store_.empty()) sort["store"]=store_;
						if(!aucminprice_.empty()) sort["aucminprice"]=aucminprice_;
						if(!aucmaxprice_.empty()) sort["aucmaxprice"]=aucmaxprice_;
						if(!aucmin_bidorbuy_price_.empty()) sort["aucmin_bidorbuy_price"]=aucmin_bidorbuy_price_;
						if(!aucmax_bidorbuy_price_.empty()) sort["aucmax_bidorbuy_price"]=aucmax_bidorbuy_price_;
						if(!escrow_.empty()) sort["escrow"]=escrow_;
						if(!easypayment_.empty()) sort["easypayment"]=easypayment_;
						if(!ybank_.empty()) sort["ybank"]=ybank_;
						if(!new_.empty()) sort["new"]=new_;
						if(!freeshipping_.empty()) sort["freeshipping"]=freeshipping_;
						if(!wrappingicon_.empty()) sort["wrappingicon"]=wrappingicon_;
						if(!buynow_.empty()) sort["buynow"]=buynow_;
						if(!thumbnail_.empty()) sort["thumbnail"]=thumbnail_;
						if(!attn_.empty()) sort["attn"]=attn_;
						if(!english_.empty()) sort["english"]=english_;
						if(!point_.empty()) sort["point"]=point_;
						if(!gift_icon_.empty()) sort["gift_icon"]=gift_icon_;
						if(!item_status_.empty()) sort["item_status"]=item_status_;
						if(!offer_.empty()) sort["offer"]=offer_;
						return sort;
					}
				private:
					const string_type appid_;
					const string_type query_;
					const string_type callback_;
					const string_type type_;
					const string_type category_;
					const string_type page_;
					const string_type sort_;
					const string_type order_;
					const string_type store_;
					const string_type aucminprice_;
					const string_type aucmaxprice_;
					const string_type aucmin_bidorbuy_price_;
					const string_type aucmax_bidorbuy_price_;
					const string_type escrow_;
					const string_type easypayment_;
					const string_type ybank_;
					const string_type new_;
					const string_type freeshipping_;
					const string_type wrappingicon_;
					const string_type buynow_;
					const string_type thumbnail_;
					const string_type attn_;
					const string_type english_;
					const string_type point_;
					const string_type gift_icon_;
					const string_type item_status_;
					const string_type offer_;
				};

				//
				//POST AuctionWebService/V2/auctionItem
				//http://developer.yahoo.co.jp/webapi/auctions/auction/v2/auctionitem.html
				//
				class auction_item : public yahoo_base{
				public:
					auction_item(const string_type appid,const string_type auctionID,const string_type response_format="xml",const string_type callback="")
						: appid_(appid), auctionID_(auctionID), callback_(callback), yahoo_base("POST","http","auctions.yahooapis.jp","/AuctionWebService/V2"+((response_format=="xml") ? ("") : ("/"+response_format))+"/auctionItem"){}
					param_type sort() const{
						param_type sort;
						sort["appid"]=appid_;
						sort["auctionID"]=auctionID_;
						if(!callback_.empty()) sort["callback"]=callback_;
						return sort;
					}
				private:
					const string_type appid_;
					const string_type auctionID_;
					const string_type callback_;
				};

				//
				//POST AuctionWebService/V1/BidHistory
				//http://developer.yahoo.co.jp/webapi/auctions/auction/v1/bidhistory.html
				//
				class bid_history : public yahoo_base{
				public:
					bid_history(const string_type appid,const string_type auctionID,const string_type page="")
						: appid_(appid), auctionID_(auctionID), page_(page), yahoo_base("POST","http","auctions.yahooapis.jp","/AuctionWebService/V1/BidHistory"){}
					param_type sort() const{
						param_type sort;
						sort["appid"]=appid_;
						sort["auctionID"]=auctionID_;
						if(!page_.empty()) sort["page"]=page_;
						return sort;
					}
				private:
					const string_type appid_;
					const string_type auctionID_;
					const string_type page_;
				};

				//
				//POST AuctionWebService/V1/BidHistoryDetail
				//http://developer.yahoo.co.jp/webapi/auctions/auction/v1/bidhistorydetail.html
				//
				class bid_history_detail : public yahoo_base{
				public:
					bid_history_detail(const string_type appid,const string_type auctionID,const string_type page="")
						: appid_(appid), auctionID_(auctionID), page_(page), yahoo_base("POST","http","auctions.yahooapis.jp","/AuctionWebService/V1/BidHistoryDetail"){}
					param_type sort() const{
						param_type sort;
						sort["appid"]=appid_;
						sort["auctionID"]=auctionID_;
						if(!page_.empty()) sort["page"]=page_;
						return sort;
					}
				private:
					const string_type appid_;
					const string_type auctionID_;
					const string_type page_;
				};

				//
				//POST AuctionWebService/V1/ShowQandA
				//http://developer.yahoo.co.jp/webapi/auctions/auction/v1/showqanda.html
				//
				class show_qa : public yahoo_base{
				public:
					show_qa(const string_type appid,const string_type auctionID)
						: appid_(appid), auctionID_(auctionID), yahoo_base("POST","http","auctions.yahooapis.jp","/AuctionWebService/V1/ShowQandA"){}
					param_type sort() const{
						param_type sort;
						sort["appid"]=appid_;
						sort["auctionID"]=auctionID_;
						return sort;
					}
				private:
					const string_type appid_;
					const string_type auctionID_;
				};

				//
				//POST AuctionWebService/V1/ShowRating
				//http://developer.yahoo.co.jp/webapi/auctions/auction/v1/showrating.html
				//
				class show_rating : public yahoo_base{
				public:
					show_rating(const string_type appid,const string_type id,const string_type auctionID="",const string_type author="",const string_type page="")
						: appid_(appid), id_(id), auctionID_(auctionID), author_(author), page_(page), yahoo_base("POST","http","auctions.yahooapis.jp","/AuctionWebService/V1/ShowRating"){}
					param_type sort() const{
						param_type sort;
						sort["appid"]=appid_;
						sort["id"]=id_;
						if(!auctionID_.empty()) sort["auctionID"]=auctionID_;
						if(!author_.empty()) sort["author"]=author_;
						if(!page_.empty()) sort["page"]=page_;
						return sort;
					}
				private:
					const string_type appid_;
					const string_type id_;
					const string_type auctionID_;
					const string_type author_;
					const string_type page_;
				};

				//
				//GET AuctionWebService/V2/openWatchList
				//http://developer.yahoo.co.jp/webapi/auctions/auction/v2/openwatchlist.html
				//
				class open_watchlist : public yahoo_base{
				public:
					open_watchlist(const string_type start="")
						: start_(start), yahoo_base("GET","http","auctions.yahooapis.jp","/AuctionWebService/V2/openWatchList"){}
					param_type sort() const{
						param_type sort;
						if(!start_.empty()) sort["start"]=start_;
						return sort;
					}
				private:
					const string_type start_;
				};

				//
				//GET AuctionWebService/V2/closeWatchList
				//http://developer.yahoo.co.jp/webapi/auctions/auction/v2/closewatchlist.html
				//
				class close_watchlist : public yahoo_base{
				public:
					close_watchlist(const string_type start="")
						: start_(start), yahoo_base("GET","http","auctions.yahooapis.jp","/AuctionWebService/V2/closeWatchList"){}
					param_type sort() const{
						param_type sort;
						if(!start_.empty()) sort["start"]=start_;
						return sort;
					}
				private:
					const string_type start_;
				};

				//
				//GET AuctionWebService/V2/myBidList
				//http://developer.yahoo.co.jp/webapi/auctions/auction/v2/mybidlist.html
				//
				class my_bidlist : public yahoo_base{
				public:
					my_bidlist(const string_type start="")
						: start_(start), yahoo_base("GET","http","auctions.yahooapis.jp","/AuctionWebService/V2/myBidList"){}
					param_type sort() const{
						param_type sort;
						if(!start_.empty()) sort["start"]=start_;
						return sort;
					}
				private:
					const string_type start_;
				};

				//
				//GET AuctionWebService/V2/myWonList
				//http://developer.yahoo.co.jp/webapi/auctions/auction/v2/mywonlist.html
				//
				class my_wonlist : public yahoo_base{
				public:
					my_wonlist(const string_type start="")
						: start_(start), yahoo_base("GET","http","auctions.yahooapis.jp","/AuctionWebService/V2/myWonList"){}
					param_type sort() const{
						param_type sort;
						if(!start_.empty()) sort["start"]=start_;
						return sort;
					}
				private:
					const string_type start_;
				};

				//
				//GET AuctionWebService/V2/mySellingList
				//http://developer.yahoo.co.jp/webapi/auctions/auction/v2/mysellinglist.html
				//
				class my_sellinglist : public yahoo_base{
				public:
					my_sellinglist(const string_type start="")
						: start_(start), yahoo_base("GET","http","auctions.yahooapis.jp","/AuctionWebService/V2/mySellingList"){}
					param_type sort() const{
						param_type sort;
						if(!start_.empty()) sort["start"]=start_;
						return sort;
					}
				private:
					const string_type start_;
				};

				//
				//GET AuctionWebService/V2/myCloseList
				//http://developer.yahoo.co.jp/webapi/auctions/auction/v2/mycloselist.html
				//
				class my_closelist : public yahoo_base{
				public:
					my_closelist(const string_type start="",const string_type list="")
						: start_(start), list_(list), yahoo_base("GET","http","auctions.yahooapis.jp","/AuctionWebService/V2/myCloseList"){}
					param_type sort() const{
						param_type sort;
						if(!start_.empty()) sort["start"]=start_;
						if(!list_.empty()) sort["list"]=list_;
						return sort;
					}
				private:
					const string_type start_;
					const string_type list_;
				};

				//
				//GET AuctionWebService/V1/myWinnerList
				//http://developer.yahoo.co.jp/webapi/auctions/auction/v1/mywinnerlist.html
				//
				class my_winnerlist : public yahoo_base{
				public:
					my_winnerlist(const string_type auctionID)
						: auctionID_(auctionID), yahoo_base("GET","http","auctions.yahooapis.jp","/AuctionWebService/V1/myWinnerList"){}
					param_type sort() const{
						param_type sort;
						sort["auctionID"]=auctionID_;
						return sort;
					}
				private:
					const string_type auctionID_;
				};

				//
				//GET AuctionWebService/V1/deleteMyWonList
				//http://developer.yahoo.co.jp/webapi/auctions/auction/v1/deletemywonlist.html
				//
				class delete_my_winnerlist : public yahoo_base{
				public:
					delete_my_winnerlist(const string_type auctionID)
						: auctionID_(auctionID), yahoo_base("GET","http","auctions.yahooapis.jp","/AuctionWebService/V1/deleteMyWonList"){}
					param_type sort() const{
						param_type sort;
						sort["auctionID"]=auctionID_;
						return sort;
					}
				private:
					const string_type auctionID_;
				};

				//
				//GET AuctionWebService/V1/deleteMyCloseList
				//http://developer.yahoo.co.jp/webapi/auctions/auction/v1/deletemycloselist.html
				//
				class delete_my_closelist : public yahoo_base{
				public:
					delete_my_closelist(const string_type auctionID)
						: auctionID_(auctionID), yahoo_base("GET","http","auctions.yahooapis.jp","/AuctionWebService/V1/deleteMyCloseList"){}
					param_type sort() const{
						param_type sort;
						sort["auctionID"]=auctionID_;
						return sort;
					}
				private:
					const string_type auctionID_;
				};

				//
				//GET AuctionWebService/V1/myOfferList
				//http://developer.yahoo.co.jp/webapi/auctions/auction/v1/myofferlist.html
				//
				class my_offerlist : public yahoo_base{
				public:
					my_offerlist(const string_type start="",const string_type list="",const string_type sort="")
						: start_(start), list_(list), sort_(sort), yahoo_base("GET","http","auctions.yahooapis.jp","/AuctionWebService/V1/myOfferList"){}
					param_type sort() const{
						param_type sort;
						if(!start_.empty()) sort["start"]=start_;
						if(!list_.empty()) sort["list"]=list_;
						if(!sort_.empty()) sort["sort"]=sort_;
						return sort;
					}
				private:
					const string_type start_;
					const string_type list_;
					const string_type sort_;
				};

				//
				//GET AuctionWebService/V1/deleteMyOfferList
				//http://developer.yahoo.co.jp/webapi/auctions/auction/v1/deletemyofferlist.html
				//
				class delete_my_offerlist : public yahoo_base{
				public:
					delete_my_offerlist(const string_type auction_id="")
						: auction_id_(auction_id), yahoo_base("GET","http","auctions.yahooapis.jp","/AuctionWebService/V1/deleteMyOfferList"){}
					param_type sort() const{
						param_type sort;
						if(!auction_id_.empty()) sort["auction_id"]=auction_id_;
						return sort;
					}
				private:
					const string_type auction_id_;
				};

				//
				//GET AuctionWebService/V1/reminder
				//http://developer.yahoo.co.jp/webapi/auctions/auction/v1/reminder.html
				//
				class reminder : public yahoo_base{
				public:
					reminder(const string_type auctionID)
						: auctionID_(auctionID), yahoo_base("GET","http","auctions.yahooapis.jp","/AuctionWebService/V1/reminder"){}
					param_type sort() const{
						param_type sort;
						sort["auctionID"]=auctionID_;
						return sort;
					}
				private:
					const string_type auctionID_;
				};

				//
				//GET AuctionWebService/V1/deleteReminder
				//http://developer.yahoo.co.jp/webapi/auctions/auction/v1/deletereminder.html
				//
				class delete_reminder : public yahoo_base{
				public:
					delete_reminder(const string_type auctionID)
						: auctionID_(auctionID), yahoo_base("GET","http","auctions.yahooapis.jp","/AuctionWebService/V1/deleteReminder"){}
					param_type sort() const{
						param_type sort;
						sort["auctionID"]=auctionID_;
						return sort;
					}
				private:
					const string_type auctionID_;
				};

				//
				//GET AuctionWebService/V1/watchList
				//http://developer.yahoo.co.jp/webapi/auctions/auction/v1/watchlist.html
				//
				class watchlist : public yahoo_base{
				public:
					watchlist(const string_type auctionID)
						: auctionID_(auctionID), yahoo_base("GET","http","auctions.yahooapis.jp","/AuctionWebService/V1/watchList"){}
					param_type sort() const{
						param_type sort;
						sort["auctionID"]=auctionID_;
						return sort;
					}
				private:
					const string_type auctionID_;
				};

				//
				//GET AuctionWebService/V1/deleteWatchList
				//http://developer.yahoo.co.jp/webapi/auctions/auction/v1/deletewatchlist.html
				//
				class delete_watchlist : public yahoo_base{
				public:
					delete_watchlist(const string_type auctionID)
						: auctionID_(auctionID), yahoo_base("GET","http","auctions.yahooapis.jp","/AuctionWebService/V1/deleteWatchList"){}
					param_type sort() const{
						param_type sort;
						sort["auctionID"]=auctionID_;
						return sort;
					}
				private:
					const string_type auctionID_;
				};

				//
				//GET AuctionWebService/V1/contentsMatchItem
				//http://developer.yahoo.co.jp/webapi/auctions/auction/v1/contentsmatchitem.html
				//
				class contents_match_item : public yahoo_base{
				public:
					contents_match_item(const string_type appid,const string_type type,const string_type url="",const string_type sentence="",const string_type category="",const string_type results="",const string_type output="")
						: appid_(appid), type_(type), url_(url), sentence_(sentence), category_(category), results_(results), output_(output), yahoo_base("GET","http","auctions.yahooapis.jp","/AuctionWebService/V1/contentsMatchItem"){}
					param_type sort() const{
						param_type sort;
						sort["appid"]=appid_;
						sort["type"]=type_;
						if(!url_.empty()) sort["url"]=url_;
						if(!sentence_.empty()) sort["sentence"]=sentence_;
						if(!category_.empty()) sort["category"]=category_;
						if(!results_.empty()) sort["results"]=results_;
						if(!output_.empty()) sort["output"]=output_;
						return sort;
					}
				private:
					const string_type appid_;
					const string_type type_;
					const string_type url_;
					const string_type sentence_;
					const string_type category_;
					const string_type results_;
					const string_type output_;
				};
			}//End auctions namespace
		}//End yahoo namespace
	}//End api namespace
}//End oauth namespace

#endif
