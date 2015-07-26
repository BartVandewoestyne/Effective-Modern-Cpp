#include "alarm.h"
#include "alarm_extra.h"

using namespace std::chrono;           // as above
using namespace std::literals;

using namespace std::placeholders;     // needed for use of "_1"


//auto setSoundB =                            // error! which
//  std::bind(setAlarm,                       // setAlarm?
//            std::bind(std::plus<>(),
//	              steady_clock::now(),
//		      1h),
//	    _1,
//	    30s);


using SetAlarm3ParamType = void(*)(Time t, Sound s, Duration d);

auto setSoundB =                                        // now
  std::bind(static_cast<SetAlarm3ParamType>(setAlarm),  // okay
            std::bind(std::plus<>(),
	              steady_clock::now(),
		      1h),
	    _1,
	    30s);


int main()
{
    setSoundB(Sound::Siren);   // body of setAlarm is less
                               // likely to be inlined here
}
