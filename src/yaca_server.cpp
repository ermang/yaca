#include "yaca_server.h"

yaca::YacaServer::YacaServer(int port): port{port}
{
}

void yaca::YacaServer::start()
{
  // boost::asio::io_context io_context;

  boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::tcp::v4(), port);
    
  boost::asio::ip::tcp::acceptor acceptor(io_context, endpoint);

  while(true)
  {
    std::unique_ptr<boost::asio::ip::tcp::socket> socket = std::make_unique<boost::asio::ip::tcp::socket>(io_context);
    
    acceptor.accept(*socket);

    socketVector.push_back(std::move(socket));
  }

  
  
}

