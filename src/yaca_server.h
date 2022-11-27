#ifndef YACA_SERVER_H
#define YACA_SERVER_H

#include <vector>
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
    boost::asio::io_context io_context;
    std::vector<std::unique_ptr<boost::asio::ip::tcp::socket>> socketVector;
    std::vector<std::thread> threadVector;
  };
}

#endif 
