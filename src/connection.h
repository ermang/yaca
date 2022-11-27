#ifndef YACA_CONNECTION_H
#define YACA_CONNECTION_H

#include <iostream>
#include <string>
#include <thread>
#include <boost/asio.hpp>
#include <boost/array.hpp>

namespace yaca
{
  class Connection
  {
  public:
    Connection(std::string ip, int port);
	

    void connect();
    void send(std::string content);
    void receive();
  private:
    std::string ip;
    int port;
    std::thread t1;
    std::unique_ptr<boost::asio::ip::tcp::socket> socket;
  };
}

#endif 
