#include "alarm.h"

auto setSoundL =
  [](Sound s)
  {
    using namespace std::chrono;
    using namespace std::literals;      // for C++14 suffixes

    setAlarm(steady_clock::now() + 1h,  // C++14, but     // fine, calls
             s,                         // same meaning   // 3-arg version
	     30s);                      // as above       // of setAlarm
  };


int main()
{
    setSoundL(Sound::Siren);  // body of setAlarm may
                              // well be inlined here
}
