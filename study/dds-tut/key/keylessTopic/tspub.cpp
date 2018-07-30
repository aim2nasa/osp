// -- Std C/C++ Include
#include <iostream>
#include <gen/TempControl_DCPS.hpp>
#include <thread>         // std::thread, std::this_thread::sleep_for
#include <chrono> 
#include "util.hpp"

float
randomValue(float avg,float delta)
{
  return avg + ((random()*delta)/RAND_MAX);
}

int
main(int argc, char* argv[])
{
  dds::domain::DomainParticipant dp(0);
  dds::topic::Topic<tutorial::TempSensorType> topic(dp, "KeylessTTempSensor");
  dds::pub::Publisher pub(dp);
  dds::pub::DataWriter<tutorial::TempSensorType> dw(pub, topic);
    
  const float avgT = 25;
  const float avgH = 0.6;
  const float deltaT = 5;
  const float deltaH = 0.15;

  // Initialize random number generation with a seed
  srandom(clock());
    
  while(1) {
    tutorial::TempSensorType sensor1(1,randomValue(avgT,deltaT),randomValue(avgH,deltaH),tutorial::CELSIUS);
    tutorial::TempSensorType sensor2(2,randomValue(avgT,deltaT),randomValue(avgH,deltaH),tutorial::CELSIUS);

    dw.write(sensor1); 
    std::cout << "DW << " << sensor1 << std::endl;

    dw.write(sensor2); 
    std::cout << "DW << " << sensor2 << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
  return 0;
}
