#include "server_connection.h"


yaca::ServerConnection::ServerConnection(std::unique_ptr<boost::asio::ip::tcp::socket> sockety): socket{std::move(sockety)}
{

  std::cout << "ServerConnection() -> socket.is_open() => " << socket->is_open() << std::endl;  
  std::cout << "ServerConnection() -> endpointy is " << socket->remote_endpoint() << std::endl;    
}

yaca::ServerConnection::ServerConnection(ServerConnection&& other): socket{std::move(other.socket)}
{
  std::cout << "move constructor " << std::endl;
  thread = std::move(other.thread);
}

yaca::ServerConnection::~ServerConnection() 
{
  std::cout << "thread_id=" << std::this_thread::get_id() << " ~ServerConnection()" << std::endl;
}

void yaca::ServerConnection::doIt() 
{
  thread = std::thread {&yaca::ServerConnection::receive, this};
}

void yaca::ServerConnection::receive()
{
  std::this_thread::sleep_for(std::chrono::milliseconds(5000));  
  
  while (true)
    {            
      std::array<char, 2> charBuf;
      
      try
	{	  
	  //	  std::cout << "thread_id=" << std::this_thread::get_id() << " ServerConnection.receive() -> socket.is_open() => " << socket->is_open() << std::endl << std::flush;	  
	  // std::cout << "ServerConnection.receive() -> endpointy is " << socket->remote_endpoint() << std::endl << std::flush;    

	  std::size_t read = boost::asio::read(*socket, boost::asio::buffer(charBuf));
	  std::cout << "read -> " << read << std::endl;
	}
      catch(const boost::system::system_error& e)
	{
	  std::cout << "e.code=" << e.code() << " e.what=" << e.what() << std::endl << std::flush;
	  std::terminate();
	}
      
      std::cout << charBuf[0] << charBuf[1] << std::endl;
    }
}

/*

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

*/

  

