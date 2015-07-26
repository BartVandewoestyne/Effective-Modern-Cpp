#include "alarm.h"

using namespace std::chrono;           // as above
using namespace std::placeholders;

auto setSoundB =
  std::bind(setAlarm,
            std::bind(std::plus<steady_clock::time_point>(), steady_clock::now(), hours(1)),
	    _1,
	    seconds(30));


int main()
{
    setSoundB(Sound::Siren);   // body of setAlarm is less
                               // likely to be inlined here
}
