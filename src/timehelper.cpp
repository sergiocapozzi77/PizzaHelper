#include "timehelper.hpp"
#include "time.h"
#include <Arduino.h>
#include <Timezone.h>

// Timezone rules for United Kingdom (London, Belfast)
TimeChangeRule BST = {"BST", Last, Sun, Mar, 1, 60}; // British Summer Time
TimeChangeRule GMT = {"GMT", Last, Sun, Oct, 2, 0};  // Standard Time
Timezone UK(BST, GMT);

time_t getTime()
{
    struct tm timeinfo;
    if (!getLocalTime(&timeinfo))
    {
        Serial.println("Failed to obtain time");
        return 0;
    }

    time_t epochNow = mktime(&timeinfo);
    epochNow = UK.toLocal(epochNow);
    return epochNow;
}

time_t AddMinutes(time_t time, int minutes)
{
    return time + minutes * 60;
}

time_t AddHours(time_t time, int hours)
{
    return time + hours * 60 * 60;
}