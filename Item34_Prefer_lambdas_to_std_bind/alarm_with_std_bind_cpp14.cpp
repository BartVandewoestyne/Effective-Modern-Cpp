#include "alarm.h"

using namespace std::chrono;           // as above
using namespace std::literals;

using namespace std::placeholders;     // needed for use of "_1"

auto setSoundB =                       // "B" for "bind"
  std::bind(setAlarm,
            std::bind(std::plus<>(), steady_clock::now(), 1h),
	    _1,
	    30s);


int main()
{
    setSoundB(Sound::Siren);   // body of setAlarm is less
                               // likely to be inlined here
}
