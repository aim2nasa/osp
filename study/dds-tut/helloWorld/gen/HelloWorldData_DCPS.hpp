#ifndef OPENSPLICE_ISOCXX_PSM
#define OPENSPLICE_ISOCXX_PSM
#endif
#ifndef CCPP_HELLOWORLDDATA_H
#define CCPP_HELLOWORLDDATA_H

#include "HelloWorldData.h"
#undef OS_API
#include "HelloWorldDataDcps.h"
#undef OS_API

#include <orb_abstraction.h>
#include "HelloWorldDataDcps_impl.h"

#endif /* CCPP_HELLOWORLDDATA_H */

#ifdef HELLOWORLDDATA_DCPS_TYPESUPPORT_DEFINED
#ifndef HELLOWORLDDATA_DCPS_HPP_
#define HELLOWORLDDATA_DCPS_HPP_
#include "dds/dds.hpp"

REGISTER_TOPIC_TRAITS(::HelloWorldData::Msg)

#endif
#endif
