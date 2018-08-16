#include <iostream>
#include <gen/bcast_DCPS.hpp>
#include <util.h>
#include <thread>

void exitHandler(int s)
{
	std::cout<<"Signal:"<<s<<std::endl;
	exit(1);
}

int main(int argc,char* argv[])
{
	if(argc<3) {
		std::cout<<"usage: pub <payloadSize> <loop>"<<std::endl;
		return -1;
	}

	dds::domain::DomainParticipant dp(0);
	dds::topic::Topic<bcast::Data> topic(dp,"bCast");
	dds::pub::Publisher pub(dp);
	dds::pub::qos::DataWriterQos dwQos = topic.qos();
	dwQos	<< dds::core::policy::Reliability::Reliable(dds::core::Duration(100,0))
			<< dds::core::policy::History::KeepAll()
			<< dds::core::policy::ResourceLimits(1000);
	dds::pub::DataWriter<bcast::Data> dw(pub,topic,dwQos);

	unsigned long payloadSize = atoi(argv[1]);
	std::cout<<"given payloadSize="<<payloadSize<<std::endl;
	bcast::Data sample;
	for(unsigned long i=0;i<payloadSize;i++) sample.payload().push_back(0x0);
	std::cout<<"sample payload size="<<sample.payload().size()<<std::endl;
	unsigned long loop = atoi(argv[2]);
	std::cout<<"loop="<<loop<<std::endl;

	struct sigaction sigIntHandler;
	sigIntHandler.sa_handler = exitHandler;
	sigemptyset(&sigIntHandler.sa_mask);
	sigIntHandler.sa_flags = 0;
	sigaction(SIGINT,&sigIntHandler,NULL);

	unsigned long long id=0;
	std::string msg="test";
	for(unsigned long i=0;i<loop;i++){
		sample.id(id++);
		sample.message(msg);
		dw.write(sample);
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
		std::cout<<".";
	}
	std::cout<<std::endl<<loop<<" samples sent"<<std::endl;

	std::this_thread::sleep_for(std::chrono::seconds(600));
	std::cout<<"pub end"<<std::endl;
	return 0;
}
