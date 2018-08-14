#ifndef __UTIL_H__
#define __UTIL_H__

#include <iostream>
#include <gen/bcast_DCPS.hpp>

std::ostream& operator<< (std::ostream& os, const bcast::Data& d);

#endif
