#ifndef YACA_SERVER_CONNECTION_H
#define YACA_SERVER_CONNECTION_H

#include <iostream>
#include <string>
#include <thread>
#include <memory>
#include <chrono>
#include <boost/asio.hpp>
#include <boost/array.hpp>

namespace yaca
{
  class ServerConnection
  {
  public:
    ServerConnection(std::unique_ptr<boost::asio::ip::tcp::socket> sockety);
    ServerConnection(const ServerConnection&) = delete;
    ServerConnection operator=(const ServerConnection&) = delete;
    ServerConnection(ServerConnection&& other);
    ServerConnection& operator=(ServerConnection&& other) = delete;
    ~ServerConnection();
    void doIt();
    //    void send(std::string content);
    void receive();
  private:
    std::thread thread;
    std::unique_ptr<boost::asio::ip::tcp::socket> socket;
    
  };
}

#endif 
