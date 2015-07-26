#include "alarm.h"

using namespace std::chrono;           // as above
using namespace std::literals;

using namespace std::placeholders;     // needed for use of "_1"

auto setSoundB =                       // "B" for "bind"
  std::bind(setAlarm,
            steady_clock::now() + 1h,  // incorrect! see below
	    _1,
	    30s);
