#include "yaca_server.h"

yaca::YacaServer::YacaServer(int port): port{port}
{
}

void yaca::YacaServer::start()
{

  boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::tcp::v4(), port);    
  boost::asio::ip::tcp::acceptor acceptor(io_context, endpoint);

  while(true)
  {
    std::cout << "accepting socket" << std::endl;
    boost::asio::ip::tcp::socket socket(io_context);
    socketVector.push_back(std::move(socket));
    boost::asio::ip::tcp::socket& socketRef = socketVector.back();
    acceptor.accept(socketRef);
    std::cout << "accepted socket" << std::endl << std::flush;
    
    std::cout << "YacaServer.start() -> socketRef.is_open() => " << socketRef.is_open() << std::endl;
    boost::asio::ip::tcp::endpoint endpointy = socketRef.remote_endpoint();
    std::cout << "YacaServer.start() -> endpointy is " << endpointy << std::endl;
    
    std::thread t9 {&yaca::YacaServer::receive, this, std::ref(socketRef)};
    threadVector.push_back(std::move(t9));

    //threadVector.back().join(); //bu olmadan mort
    
    std::cout <<  "YacaServer.start() -> socketRef.is_open() => " << socketRef.is_open() << std::endl;
    std::cout << "YacaServer.start() -> start() endpointy is " << endpointy << std::endl;
  }  
  
}

void yaca::YacaServer::receive(boost::asio::ip::tcp::socket& sockety)
{
  
  std::cout << "YacaServer.receive() -> socket.is_open() => " << sockety.is_open() << std::endl;
  std::cout << "YacaServer.receive() sleeping for 5sec" << std::endl;
  std::this_thread::sleep_for(std::chrono::milliseconds(5000));  
  std::cout << "YacaServer.receive() -> socket.is_open() => " << sockety.is_open() << std::endl;
  
  std::array<char, 2> charBuf;
  
  while (true)
    {
      try
	{	  
	  boost::asio::ip::tcp::endpoint endpointy = sockety.remote_endpoint();
	  std::cout << "YacaServer.receive() -> endpointy is " << endpointy << std::endl;
	  
	  std::cout << "YacaServer.receive() -> waiting to read" << std::endl;
	  boost::asio::read(sockety, boost::asio::buffer(charBuf));
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

