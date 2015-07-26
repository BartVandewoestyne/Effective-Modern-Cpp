#include "alarm.h"

// setSoundL ("L" for "lambda") is a function object allowing a
// sound to be specified for a 30-sec alarm to go off an hour
// after it's set
auto setSoundL =
  [](Sound s)
  {
    // make std::chrono components available w/o qualification
    using namespace std::chrono;

    setAlarm(steady_clock::now() + hours(1),  // alarm to go off
             s,                               // in an hour for
	     seconds(30));                    // 30 seconds
  };


int main()
{
    setSoundL(Sound::Siren);  // body of setAlarm may
                              // well be inlined here
}
