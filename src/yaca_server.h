#ifndef YACA_SERVER_H
#define YACA_SERVER_H

#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <memory>
#include <exception>
#include <functional>
#include <boost/asio.hpp>
#include "server_connection.h"

namespace yaca
{
  class YacaServer
  {
  public:
    YacaServer(int port);
    void start();

  private:
    int port;
    boost::asio::io_context io_context;
    std::vector<std::unique_ptr<yaca::ServerConnection>> serverConnectionVector;

    //void receive(boost::asio::ip::tcp::socket& socket);
  };
}

#endif 
