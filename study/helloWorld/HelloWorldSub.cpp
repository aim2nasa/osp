#include <iostream>
#include <gen/HelloWorldData_DCPS.hpp>
#include <thread>
#include <chrono>

int main(int argc,char* argv[])
{
  dds::domain::DomainParticipant dp(0);
  dds::topic::Topic<HelloWorldData::Msg> topic(dp,"Message");
  dds::sub::Subscriber sub(dp);
  dds::sub::DataReader<HelloWorldData::Msg> dr(sub,topic);

  dds::core::cond::WaitSet ws;
  dds::sub::cond::ReadCondition rc(dr,dds::sub::status::DataState::new_data());
  ws += rc;

  while(true) {
    std::cout<<"waiting..."<<std::endl;
    ws.wait();
    auto samples = dr.read();
    std::for_each(samples.begin(),samples.end(),[](const dds::sub::Sample<HelloWorldData::Msg>& s) {
      std::cout<<"message received"<<std::endl;
    });
    std::cout<<"reading done"<<std::endl;
  }

  std::cout<<"end of main"<<std::endl;
  return 0;
}
