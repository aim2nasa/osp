#include "util.h"

std::ostream& operator<< (std::ostream& os, const bcast::Data& d)
{
  os << "[ id=" << d.id()
     << ",message=" << d.message()
     << ",payloadSize=" << d.payload().size() 
     << "]";
  return os;
}

