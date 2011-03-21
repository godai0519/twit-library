#ifndef HTTP_HPP
#define HTTP_HPP

#include <string>
#include <map>

//Boost.Format用
#include <boost/format.hpp>

//Boost.Asio用ヘッダ
#include <boost/asio.hpp>
#include <boost/asio/ssl.hpp>

//Boost.AsioでSSLを使用するために必要(OpenSSL)
#pragma comment(lib, "libeay32MDd.lib")
#pragma comment(lib, "ssleay32MDd.lib")

namespace http{
	//リクエストヘッダ用
	typedef std::map<std::string,std::string> request_header;

	namespace status_code{
		//ステータスコード一覧
		enum status_code
		{
			Continue=100,
			SwitchingProtocols,
			OK=200,
			Created,
			Accepted,
			NonAuthoritativeInformation,
			NoContent,
			ResetContent,
			PartialContent,
			MultipleChoices=300,
			MovedPermanently,
			Found,
			SeeOther,
			NotModified,
			UseProxy,
			Unused,
			TemporaryRedirect,
			BadRequest=400,
			Unauthorized,
			PaymentRequired,
			Forbidden,
			NotFound,
			MethodNotAllowed,
			NotAcceptable,
			ProxyAuthenticationRequired,
			RequestTimeout,
			Conflict,
			Gone,
			LengthRequired,
			PreconditionFailed,
			RequestEntityTooLarge,
			RequestUriTooLong,
			UnsupportedMediaType,
			RequestedRangeNotSatisfiable,
			ExpectationFailed,
			InternalServerError=500,
			NotImplemented,
			BadGateway,
			ServiceUnavailable,
			GatewayTimeout,
			HttpVersionNotSupported
		};
	}//End status_code namespace

	class status_error
	{
	public:
		explicit status_error(const status_code::status_code& code_arg,const std::string& what_arg): what(what_arg),code(code_arg)
		{
		}
		virtual ~status_error(){}

		const std::string what;
		const status_code::status_code code;
	};

	//
	// basic_httpでtcpする際のテンプレート引数
	//
	namespace tcp{
		typedef boost::asio::ip::tcp::socket tcp_socket;
		class socket_type{
		public:
			socket_type() : socket_(io_service_){}
			~socket_type(){}

			//通信を開始する
			void start(const std::string& host,const std::string& port = "http"){
				boost::asio::ip::tcp::resolver resolver(io_service_);
				boost::asio::ip::tcp::resolver::query query(host,port);
				boost::asio::ip::tcp::resolver::iterator pos = resolver.resolve(query);
				boost::asio::ip::tcp::resolver::iterator last;

				boost::system::error_code error = boost::asio::error::host_not_found;
				while(error && pos != last){
					socket_.close();
					socket_.connect(*pos++,error);
				}
				if(error) throw boost::system::system_error(error);
			}

			tcp_socket& socket(){return socket_;}

		private:
			boost::asio::io_service io_service_;
			tcp_socket socket_;
		};
	}

	//
	// basic_httpでsslする際のテンプレート引数
	//
	namespace ssl{
		typedef boost::asio::ssl::stream<boost::asio::ip::tcp::socket> ssl_socket;
		class socket_type{
		public:
			socket_type() : ctx_(io_service_,boost::asio::ssl::context::sslv23) , socket_(io_service_,ctx_) {}
			~socket_type(){}

			//通信を開始する
			void start(const std::string& host,const std::string& port = "https"){
				boost::asio::ip::tcp::resolver resolver(io_service_);
				boost::asio::ip::tcp::resolver::query query(host,port);
				boost::asio::ip::tcp::resolver::iterator pos = resolver.resolve(query);
				boost::asio::ip::tcp::resolver::iterator last;

				boost::system::error_code error = boost::asio::error::host_not_found;
				while(error && pos != last){
					socket_.lowest_layer().close();
					socket_.lowest_layer().connect(*pos++,error);
					socket_.handshake(boost::asio::ssl::stream<boost::asio::ip::tcp::socket>::client); //ハンドシェイクする
				}
			}

			ssl_socket& socket(){return socket_;}

		private:
			boost::asio::io_service io_service_;
			boost::asio::ssl::context ctx_;
			ssl_socket socket_;
		};
	}
	//
	// 通信用クラス
	// tcp::http_wrapperかssl::http_wrapperをテンプレート引数にする
	//
	template<class socket_type>
	class basic_http{
	public:
		basic_http(): socket_(){}
		~basic_http(){}
				
		//
		// Requestの開始
		//
		virtual int request(const std::string& method,const std::string& host,const std::string& path,const request_header& head,const std::string& body)
		{
			boost::asio::streambuf buffer;
			std::ostream sbuf(&buffer);

			//リクエスト本文の作成
			sbuf << boost::format("%s %s HTTP/1.1\r\n") %method %path;
			sbuf << "Host: "+host+"\r\n";

			for(request_header::const_iterator it = head.begin();it != head.end();it++){
				sbuf << boost::format("%s: %s\r\n") %it->first %it->second;
			}

			if(!body.empty()){
				sbuf << "Content-Length: " << body.length() << "\r\n";
				sbuf << "\r\n";
				sbuf << body;
			}
			else sbuf << "\r\n";

			//ソケット準備
			socket_.start(host);

			//ソケット書き込み
			boost::asio::write(socket_.socket(), buffer);

			return 0;
		}

		//
		// Responseの受け取り
		//
		virtual std::string response(){
			boost::asio::streambuf buffer;
			std::string res;
			boost::system::error_code error;

			//レスポンスの読み取り
			while(boost::asio::read(socket_.socket(),buffer,boost::asio::transfer_at_least(1), error));
			res = static_cast<std::string>(boost::asio::buffer_cast<const char*>(buffer.data()));

			//レスポンスの一行目を解析
			std::string http_version;
			int status_code;
			std::string status_message;

			std::istringstream res_stream(res);
			res_stream >> http_version;
			res_stream >> status_code;
			res_stream >> status_message;

			if((status_code < 200) || (300 <= status_code))
			{
				throw http::status_error((http::status_code::status_code)status_code,res);
			}
		
			//レスポンス本文を取り出し
			res.erase(0,res.find("\r\n\r\n")+4);

			return res;
		}

	private:
		socket_type socket_;
	};

} //End http namespace

#endif