#ifndef YACA_CLIENT_H
#define YACA_CLIENT_H

#include <string>
#include "connection.h"

namespace yaca
{
  class YacaClient
  {
  public:
    YacaClient(std::string ip, int port);

    void connect();
    void send(std::string content);
  private:
    Connection connection;
  };
}

#endif 
