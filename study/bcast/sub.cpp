#include <iostream>
#include <gen/bcast_DCPS.hpp>
#include <util.h>

int main(int argc,char* argv[])
{
	dds::domain::DomainParticipant dp(0);
	dds::topic::qos::TopicQos topicQos = dp.default_topic_qos()
		<< dds::core::policy::Durability::Transient()
		<< dds::core::policy::Reliability::Reliable();
	dds::topic::Topic<bcast::Data> topic(dp,"bCast",topicQos);
	dds::sub::Subscriber sub(dp);
	dds::sub::qos::DataReaderQos drQos = topic.qos();
	dds::sub::DataReader<bcast::Data> dr(sub,topic,drQos);

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
