#include <iostream>
#include "server.h"

int main (void)
{
  std::cout << "hoppa" ;
  
  yaca::Server server {8080};
  
  server.start();
  
  return 0;
}
