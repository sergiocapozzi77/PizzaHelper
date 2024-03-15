#include "time.h"

#ifndef TIMEHELPER_H
#define TIMEHELPER_H

time_t getTime();
time_t AddMinutes(time_t time, int minutes);
time_t AddHours(time_t time, int hours);

#endif
