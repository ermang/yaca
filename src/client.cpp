#include "client.h"

yaca::Client::Client()
  {
    
  }

void yaca::Client::connect()
{
  boost::asio::io_context io_context;

  boost::asio::ip::tcp::socket socket {io_context};


  boost::asio::ip::address address = boost::asio::ip::make_address("127.0.0.1");
  
  boost::asio::ip::tcp::endpoint endpoint {address, 8080};
  
  // boost::asio::connect(socket, endpoint);

  socket.connect(endpoint);
}
