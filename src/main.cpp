#include <Arduino.h>
#include <lv_conf.h>
#include <lvgl.h>
#include <WiFi.h>
#include "gui/gui.h"
#include <Preferences.h>
#include <Timezone.h>
#include "time.h"

const char *ssid = "TP-Link_8724";
const char *password = "40950211";

const char *ntpServer = "uk.pool.ntp.org";
const long gmtOffset_sec = 0;
const int daylightOffset_sec = 3600;

void printLocalTime()
{
  // Timezone rules for United Kingdom (London, Belfast)
  TimeChangeRule BST = {"BST", Last, Sun, Mar, 1, 60}; // British Summer Time
  TimeChangeRule GMT = {"GMT", Last, Sun, Oct, 2, 0};  // Standard Time
  Timezone UK(BST, GMT);

  struct tm timeinfo;
  if (!getLocalTime(&timeinfo))
  {
    Serial.println("Failed to obtain time");
    return;
  }

  Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
  Serial.print("Day of week: ");
  Serial.println(&timeinfo, "%A");
  Serial.print("Month: ");
  Serial.println(&timeinfo, "%B");
  Serial.print("Day of Month: ");
  Serial.println(&timeinfo, "%d");
  Serial.print("Year: ");
  Serial.println(&timeinfo, "%Y");
  Serial.print("Hour: ");
  Serial.println(&timeinfo, "%H");
  Serial.print("Hour (12 hour format): ");
  Serial.println(&timeinfo, "%I");
  Serial.print("Minute: ");
  Serial.println(&timeinfo, "%M");
  Serial.print("Second: ");
  Serial.println(&timeinfo, "%S");

  Serial.println("Time variables");
  char timeHour[3];
  strftime(timeHour, 3, "%H", &timeinfo);
  Serial.println(timeHour);
  char timeWeekDay[10];
  strftime(timeWeekDay, 10, "%A", &timeinfo);
  Serial.println(timeWeekDay);
  Serial.println();
}

void setup()
{
  Serial.begin(115200);
  Serial.println();

  Serial.println(F("Tft starting"));

  preferences.begin("pizza-helper");
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  esp_sleep_enable_ext0_wakeup(GPIO_NUM_19, 1);

  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
  printLocalTime();

  gui_start();
}

void loop()
{
  lv_timer_handler();

  delay(5);
}
