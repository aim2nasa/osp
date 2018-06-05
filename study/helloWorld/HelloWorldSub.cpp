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

  std::cout<<"sleeping..."<<std::endl;
  std::this_thread::sleep_for(std::chrono::seconds(10));
  
  std::cout<<"reading..."<<std::endl;
  auto samples = dr.read();
  std::for_each(samples.begin(),samples.end(),[](const dds::sub::Sample<HelloWorldData::Msg>& s) {
    std::cout<<"message received"<<std::endl;
  });
  std::cout<<"reading done"<<std::endl;

  std::cout<<"end of main"<<std::endl;
  return 0;
}
