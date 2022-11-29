#include <iostream>
#include "yaca_server.h"

int main (void)
{
  std::cout << "yaca_server_executable started" << std::endl;
  
  yaca::YacaServer yacaServer {8080};
  
  yacaServer.start();

  int x = 5;
  
  std::cin >> x;
  
  return 0;
}
