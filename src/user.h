#ifndef YACA_USER_H
#define YACA_USER_H

#include <boost/asio.hpp>
#include "client.h"

namespace yaca
{
  class User
  {
  public:
    User();

    void connect();
  private:
    Client client;
  };
}

#endif 
