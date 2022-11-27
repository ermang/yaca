#include <iostream>
#include "yaca_server.h"

int main (void)
{
  std::cout << "hoppa" ;
  
  yaca::YacaServer yacaServer {8080};
  
  yacaServer.start();
  
  return 0;
}
