#include <iostream>
#include "yaca_client.h"

int main (void)
{
  std::cout << "yaca_client_executable started" << std::endl;
  
  yaca::YacaClient yacaClient {"127.0.0.1", 8080};
  
  yacaClient.connect();


  int inputInt {-1};
  
  /*  while(true)
    {
      std::cout << "press 1 to send message, 0 to quit" <<std::endl;
      std::cin >> inputInt;

      if (inputInt == 0)
	break;
      else if (inputInt == 1)
	{
	  std::string s;
	  std::cin >> s;

	  yacaClient.send(s);
	}
	}*/
  
  yacaClient.send("123456789012");
  std::cin >> inputInt;
  
  return 0;
}
