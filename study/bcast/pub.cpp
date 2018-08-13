#include <iostream>
#include <gen/bcast_DCPS.hpp>

int main(int argc,char* argv[])
{
	if(argc<2) {
		std::cout<<"usage: pub <message>"<<std::endl;
		return -1;
	}

	dds::domain::DomainParticipant dp(0);
	dds::topic::Topic<bcast::Data> topic(dp,"bCast");
	dds::pub::Publisher pub(dp);
	dds::pub::DataWriter<bcast::Data> dw(pub,topic);

	std::cout<<"pub end"<<std::endl;
	return 0;
}
