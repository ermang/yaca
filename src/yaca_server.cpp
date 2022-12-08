#include "yaca_server.h"

yaca::YacaServer::YacaServer(int port): port{port}
{
  serverConnectionVector.reserve(5);
}

void yaca::YacaServer::start()
{

  boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::tcp::v4(), port);    
  boost::asio::ip::tcp::acceptor acceptor(io_context, endpoint);

  while(true)
  {
    std::cout << "thread_id=" << std::this_thread::get_id() << " accepting socket" << std::endl;

    std::unique_ptr<boost::asio::ip::tcp::socket> socket = std::make_unique<boost::asio::ip::tcp::socket>(io_context);
      //    boost::asio::ip::tcp::socket socket {io_context};
    
    acceptor.accept(*socket);
    std::cout << "thread_id=" << std::this_thread::get_id() <<  " accepted socket" << std::endl << std::flush;

    std::cout << "vec.size=" <<serverConnectionVector.size() << " vec.capacity="
	      << serverConnectionVector.capacity() << std::endl;
    serverConnectionVector.emplace_back(yaca::ServerConnection {std::move(socket)});
    std::cout << "Vec.size" << serverConnectionVector.size() <<   " vec.capacity="
	      << serverConnectionVector.capacity() << std::endl;
    serverConnectionVector.back().doIt();
  }  
  
}


/*
void yaca::YacaServer::receive(boost::asio::ip::tcp::socket& sockety)
{
  int x = 0;
  
  std::cout << "YacaServer.receive() -> socket.is_open() => " << sockety.is_open() << std::endl;
  
  std::cin >> x;
 
  std::cout << "YacaServer.receive() sleeping for 5sec" << std::endl;
  std::this_thread::sleep_for(std::chrono::milliseconds(5000));  
  std::cout << "YacaServer.receive() -> socket.is_open() => " << sockety.is_open() << std::endl;
  
  std::array<char, 2> charBuf;
  
  while (true)
    {
      try
	{	  
	  boost::asio::ip::tcp::endpoint endpointy = sockety.remote_endpoint();//works if sockety replaced with socketVector[0]
	  std::cout << "YacaServer.receive() -> endpointy is " << endpointy << std::endl;
	  
	  std::cout << "YacaServer.receive() -> waiting to read" << std::endl;
	  boost::asio::read(sockety, boost::asio::buffer(charBuf));//works if sockety replaced with socketVector[0]
	  std::cout << "YacaServer.receive() -> read something" << std::endl;
	}
      catch(const boost::system::system_error& e)
	{
	  std::cout << "e is " << e.code() << " " << e.what() << std::endl;
	  std::terminate();
	}
      
      std::cout << charBuf[0] << charBuf[1] << std::endl;
    }
  
}
*/

