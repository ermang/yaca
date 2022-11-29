#ifndef YACA_SERVER_H
#define YACA_SERVER_H

#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <exception>
#include <functional>
#include <boost/asio.hpp>

namespace yaca
{
  class YacaServer
  {
  public:
    YacaServer(int port);
    void start();

  private:
    int port;
    std::thread t8;
    boost::asio::io_context io_context;
    std::vector<boost::asio::ip::tcp::socket> socketVector;
    std::vector<std::thread> threadVector;

    void receive(boost::asio::ip::tcp::socket& socket);
  };
}

#endif 
