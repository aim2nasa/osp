#include <iostream>
#include <gen/bcast_DCPS.hpp>
#include <util.h>

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

	unsigned long payloadSize = 4096;
	bcast::Data sample;
	sample.id(0);
	for(unsigned long i=0;i<payloadSize;i++) sample.payload().push_back(0x0);
	std::cout<<"sample payload size="<<sample.payload().size()<<std::endl;

	dw.write(sample);
	std::cout<<"DW:"<<sample<<" done"<<std::endl;

	std::cout<<"pub end"<<std::endl;
	return 0;
}
