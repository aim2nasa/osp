#include <iostream>
#include <gen/HelloWorldData_DCPS.hpp>

int main(int argc,char* argv[])
{
  dds::domain::DomainParticipant dp(0);
  dds::topic::Topic<HelloWorldData::Msg> topic(dp,"Message");

  std::cout<<"end of main"<<std::endl;
  return 0;
}
