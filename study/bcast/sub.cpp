#include <iostream>
#include <gen/bcast_DCPS.hpp>
#include <util.h>

int main(int argc,char* argv[])
{
	dds::domain::DomainParticipant dp(0);
	dds::topic::Topic<bcast::Data> topic(dp,"bCast");
	dds::sub::Subscriber sub(dp);
	dds::sub::qos::DataReaderQos drQos = topic.qos();
	drQos	<< dds::core::policy::Reliability::Reliable(dds::core::Duration(100,0))
			<< dds::core::policy::History::KeepAll() 
			<< dds::core::policy::ResourceLimits(1000);
	dds::sub::DataReader<bcast::Data> dr(sub,topic,drQos);

	dds::core::cond::WaitSet ws;
	dds::sub::cond::ReadCondition rc(dr,dds::sub::status::DataState::new_data());
	ws += rc;

	static unsigned long long prevId=0;
	static bool bRun = true;
	static unsigned long long errCount=0;
	while(bRun){
		std::cout<<"-"<<std::flush;
		ws.wait();

		auto samples = dr.take();
		std::for_each(samples.begin(),samples.end(),[](const dds::sub::Sample<bcast::Data>& s) {
			unsigned long long id = s.data().id();
			if(id == (prevId+1)) {
				std::cout<<"."<<std::flush;
			}else{
				errCount++;
				std::cout<<"x("<<prevId<<","<<id<<")"<<std::flush;
			}
			prevId = id;
			if(s.data().message()=="end") {
				std::cout<<"E"<<std::flush;
			   bRun = false;
				return;
			}
		});
	}
	std::cout<<std::endl<<"Last sample id="<<prevId<<std::endl;
	std::cout<<"Error count="<<errCount<<std::endl;

	std::cout<<"sub end"<<std::endl;
	return 0;
}
