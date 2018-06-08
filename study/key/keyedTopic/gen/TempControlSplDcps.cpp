#include "TempControlSplDcps.h"
#include "TempControl_DCPS.hpp"

#include <v_copyIn.h>
#include <v_topic.h>
#include <os_stdlib.h>
#include <string.h>
#include <os_report.h>

v_copyin_result
__tutorial_TempSensorType__copyIn(
    c_base base,
    const class ::tutorial::TempSensorType *from,
    struct _tutorial_TempSensorType *to)
{
    v_copyin_result result = V_COPYIN_RESULT_OK;
    (void) base;

    to->id = (c_short)from->id_;
    to->temp = (c_float)from->temp_;
    to->hum = (c_float)from->hum_;
#ifdef OSPL_BOUNDS_CHECK
    if((((c_long)from->scale_) >= 0) && (((c_long)from->scale_) < 3) ){
        to->scale = (enum _tutorial_TemperatureScale)from->scale_;
    } else {
        OS_REPORT (OS_ERROR, "copyIn", 0,"Member 'tutorial::TempSensorType.scale' of type 'TemperatureScale' is out of range.");
        result = V_COPYIN_RESULT_INVALID;
    }
#else
    to->scale = (enum _tutorial_TemperatureScale)from->scale_;
#endif
    return result;
}

void
__tutorial_TempSensorType__copyOut(
    const void *_from,
    void *_to)
{
    const struct _tutorial_TempSensorType *from = (const struct _tutorial_TempSensorType *)_from;
    class ::tutorial::TempSensorType *to = (class ::tutorial::TempSensorType *)_to;
    to->id_ = (::DDS::Short)from->id;
    to->temp_ = (::DDS::Float)from->temp;
    to->hum_ = (::DDS::Float)from->hum;
    to->scale_ = (::tutorial::TemperatureScale)from->scale;
}

