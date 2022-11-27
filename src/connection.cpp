#include "connection.h"

yaca::Connection::Connection(std::string ip, int port): ip{ip}, port{port}
{  
}

void yaca::Connection::connect()
{
  boost::asio::io_context io_context;

  //boost::asio::ip::tcp::socket socket {io_context};
  socket = std::make_unique<boost::asio::ip::tcp::socket>(io_context);
  
  boost::asio::ip::address address = boost::asio::ip::make_address(ip);
  
  boost::asio::ip::tcp::endpoint endpoint {address, port};

  socket->connect(endpoint);

  t1= std::thread {&yaca::Connection::receive, this};

 //  t1.join();

}

void yaca::Connection::send(std::string content)
{

  int length {content.size()};
  std::string lengthAsStr {std::to_string(length)};

  //  boost::asio::
  
  size_t numBytesWritten = boost::asio::write(*socket, boost::asio::buffer(lengthAsStr));

  std::cout << "numBytesWritten => " << numBytesWritten << std::endl;

  numBytesWritten = boost::asio::write(*socket, boost::asio::buffer(content));
  
  std::cout << "numBytesWritten => " << numBytesWritten << std::endl;
}

void yaca::Connection::receive()
{
  //  boost::array<char, 128> buf;
  std::array<char, 2> charBuf;
  boost::asio::read(*socket, boost::asio::buffer(charBuf));
  
  std::cout << charBuf[0] << charBuf[1] << std::endl;
}
  
