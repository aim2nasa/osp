#ifndef OPENSPLICE_ISOCXX_PSM
#define OPENSPLICE_ISOCXX_PSM
#endif
#ifndef CCPP_TEMPCONTROL_H
#define CCPP_TEMPCONTROL_H

#include "TempControl.h"
#undef OS_API
#include "TempControlDcps.h"
#undef OS_API

#include <orb_abstraction.h>
#include "TempControlDcps_impl.h"

#endif /* CCPP_TEMPCONTROL_H */

#ifdef TEMPCONTROL_DCPS_TYPESUPPORT_DEFINED
#ifndef TEMPCONTROL_DCPS_HPP_
#define TEMPCONTROL_DCPS_HPP_
#include "dds/dds.hpp"

REGISTER_TOPIC_TRAITS(::tutorial::TempSensorType)

#endif
#endif
