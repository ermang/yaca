#ifndef YACA_SERVER_H
#define YACA_SERVER_H

#include <vector>
#include <boost/asio.hpp>

namespace yaca
{
  class Server
  {
  public:
    Server(int port);
    void start();

  private:
    int port;
    std::vector<std::unique_ptr<boost::asio::ip::tcp::socket>> socketVector;
  };
}

#endif 
