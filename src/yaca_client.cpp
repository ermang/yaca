#include "yaca_client.h"

yaca::YacaClient::YacaClient(std::string ip, int port): connection{ip, port}
{
}

void yaca::YacaClient::connect()
{
  connection.connect();
}

void yaca::YacaClient::send(std::string content)
{
  connection.send(content);
}
