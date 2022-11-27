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

    // socketVector.push_back(std::make_unique<boost::asio::ip::tcp::socket>(io_context));
    
    acceptor.accept(*socket);
    std::cout << "accepted socket" << std::endl;
    
    //  t1= std::thread {&yaca::Connection::receive, this};
    //    t8 = std::thread {&yaca::YacaServer::receive, this, std::ref(socket)};

    threadVector.push_back(std::thread {&yaca::YacaServer::receive, this, std::ref(socket)} );

        socketVector.push_back(std::move(socket));

    //    t8.join();
  }

  
  
}

void yaca::YacaServer::receive(std::unique_ptr<boost::asio::ip::tcp::socket>& socket)
{
    //  boost::array<char, 128> buf;
  
  std::array<char, 2> charBuf;
  
  while (true)
    {
      try
	{
	  std::cout << "waiting to read" << std::endl;
	  boost::asio::read(*socket, boost::asio::buffer(charBuf));
	  std::cout << "read something" << std::endl;
	}
      catch(const boost::system::system_error& e)
	{
	  std::cout << "e is " << e.code() << " " << e.what() << std::endl;
	  std::terminate();
	}
      
      std::cout << charBuf[0] << charBuf[1] << std::endl;
    }
  
}


