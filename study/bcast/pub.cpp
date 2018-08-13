#include <iostream>
#include <gen/bcast_DCPS.hpp>
#include <util.h>

int main(int argc,char* argv[])
{
	if(argc<2) {
		std::cout<<"usage: pub <payloadSize>"<<std::endl;
		return -1;
	}

	dds::domain::DomainParticipant dp(0);
	dds::topic::Topic<bcast::Data> topic(dp,"bCast");
	dds::pub::Publisher pub(dp);
	dds::pub::DataWriter<bcast::Data> dw(pub,topic);

	unsigned long payloadSize = atoi(argv[1]);
	std::cout<<"given payloadSize="<<payloadSize<<std::endl;
	bcast::Data sample;
	for(unsigned long i=0;i<payloadSize;i++) sample.payload().push_back(0x0);
	std::cout<<"sample payload size="<<sample.payload().size()<<std::endl;

	unsigned long long id=0;
	std::string msg;
	while(true){
		std::cout<<"(q to quit) message=?";
		std::cin>>msg;

		if("q"==msg) break;

		sample.id(id++);
		sample.message(msg);
		dw.write(sample);
		std::cout<<"DW:"<<sample<<" done"<<std::endl;
	}

	std::cout<<"pub end"<<std::endl;
	return 0;
}
