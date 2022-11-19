#include <iostream>
#include "user.h"

int main (void)
{
  std::cout << "user started" ;
  
  yaca::User user;
  
  user.connect();
  
  return 0;
}
