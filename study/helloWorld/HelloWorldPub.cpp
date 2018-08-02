#include <iostream>
#include <gen/HelloWorldData_DCPS.hpp>

int main(int argc,char* argv[])
{
  if(argc<2) {
    std::cout<<"usage: HelloWorldPub <message>"<<std::endl;
    return -1;
  }

  dds::domain::DomainParticipant dp(0);
  dds::topic::Topic<HelloWorldData::Msg> topic(dp,"Message");
  dds::pub::Publisher pub(dp);
  dds::pub::DataWriter<HelloWorldData::Msg> dw(pub,topic);

  HelloWorldData::Msg message(1,argv[1]);

  std::cout<<"pub end"<<std::endl;
  return 0;
}
