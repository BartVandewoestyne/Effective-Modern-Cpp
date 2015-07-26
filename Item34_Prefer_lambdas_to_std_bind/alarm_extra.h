#ifndef ALARM_EXTRA_H
#define ALARM_EXTRA_H

enum class Volume { Normal, Loud, LoudPlusPlus };

void setAlarm(Time t, Sound s, Duration d, Volume v);

#endif
