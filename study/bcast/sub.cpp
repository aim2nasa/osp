#include <iostream>
#include <gen/bcast_DCPS.hpp>
#include <util.h>

int main(int argc,char* argv[])
{
	dds::domain::DomainParticipant dp(0);
	dds::topic::Topic<bcast::Data> topic(dp,"bCast");
	dds::sub::Subscriber sub(dp);
	dds::sub::DataReader<bcast::Data> dr(sub,topic);

	dds::core::cond::WaitSet ws;
	dds::sub::cond::ReadCondition rc(dr,dds::sub::status::DataState::new_data());
	ws += rc;

	while(true){
		std::cout<<"waiting..."<<std::endl;
		ws.wait();

		auto samples = dr.take();
		std::for_each(samples.begin(),samples.end(),[](const dds::sub::Sample<bcast::Data>& s) {
			std::cout<<"DR: "<< s.data() <<std::endl;
		});
	}

	std::cout<<"sub end"<<std::endl;
	return 0;
}
