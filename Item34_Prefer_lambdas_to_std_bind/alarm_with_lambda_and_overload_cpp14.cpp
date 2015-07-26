#include "alarm.h"
#include "alarm_extra.h"

auto setSoundL =
  [](Sound s)
  {
    using namespace std::chrono;
    using namespace std::literals;      // for C++14 suffixes

    setAlarm(steady_clock::now() + 1h,  // fine, calls
             s,                         // 3-arg version
	     30s);                      // of setAlarm
  };


int main()
{
    setSoundL(Sound::Siren);  // body of setAlarm may
                              // well be inlined here
}
