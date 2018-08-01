#include <iostream>
#include <gen/HelloWorldData_DCPS.hpp>

int main(int argc,char* argv[])
{
  if(argc<2) {
    std::cout<<"usage: HelloWorldPub <message>"<<std::endl;
    return -1;
  }

  std::cout<<"pub end"<<std::endl;
  return 0;
}
