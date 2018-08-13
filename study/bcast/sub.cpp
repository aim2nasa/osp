#include <iostream>
#include <gen/bcast_DCPS.hpp>

int main(int argc,char* argv[])
{
	dds::domain::DomainParticipant dp(0);
	dds::topic::Topic<bcast::Data> topic(dp,"bCast");
	dds::sub::Subscriber sub(dp);
	dds::sub::DataReader<bcast::Data> dr(sub,topic);

	std::cout<<"sub end"<<std::endl;
	return 0;
}
