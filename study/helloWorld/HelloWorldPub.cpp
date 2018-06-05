#include <iostream>
#include <gen/HelloWorldData_DCPS.hpp>
#include <util.h>

int main(int argc,char* argv[])
{
  dds::domain::DomainParticipant dp(0);
  dds::topic::Topic<HelloWorldData::Msg> topic(dp,"Message");
  dds::pub::Publisher pub(dp);
  dds::pub::DataWriter<HelloWorldData::Msg> dw(pub,topic);

  HelloWorldData::Msg message(1,"Publisher's message");
  dw.write(message);
  std::cout<<"DW: "<<message<<std::endl;

  std::cout<<"end of main"<<std::endl;
  return 0;
}
