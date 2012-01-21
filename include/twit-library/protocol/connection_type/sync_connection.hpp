//
// async_connection.hpp
// ~~~~~~~~~~
//
// 非同期のためのクラス群
//

#ifndef TWIT_LIB_PROTOCOL_CONNECTTYPE_SYNC_CONNECTION
#define TWIT_LIB_PROTOCOL_CONNECTTYPE_SYNC_CONNECTION

#include <memory>
#include <boost/asio.hpp>
#include "connection_base.hpp"
#include "../application_layer/layer_base.hpp"

namespace oauth{
namespace protocol{
namespace connection_type{

class sync_connection : public connection_base{
public:
	sync_connection(std::shared_ptr<application_layer::layer_base>& socket_layer)
	{
		socket_layer_ = socket_layer;
	}
	virtual ~sync_connection(){}
	
	//追加	
	error_code& operator() (
		const std::string& host,
		boost::asio::streambuf& buf,
		error_code& ec
		)
	{
		boost::asio::ip::tcp::resolver resolver(socket_layer_->get_io_service());
		boost::asio::ip::tcp::resolver::query query(host,socket_layer_->service_protocol());
		boost::asio::ip::tcp::resolver::iterator ep_iterator = resolver.resolve(query,ec);
		if(ec) return ec;

		socket_layer_->connect(ep_iterator,ec);
		if(ec) return ec;

		socket_layer_->write(buf,ec);
		if(ec) return ec;

		socket_layer_->read(ec);

		return ec;
	}

	//追加	
	error_code& operator() (
		boost::asio::ip::tcp::resolver::iterator ep_iterator,
		boost::asio::streambuf& buf,
		error_code& ec
		)
	{
		
		//非同期実装
		return ec;
	}
};

} // namespace connection_type
} // namespace protocol
} // namespace oauth

#endif
