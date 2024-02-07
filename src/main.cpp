#include <Arduino.h>
#include <lv_conf.h>
#include <lvgl.h>

#include "gui/gui.h"

void setup()
{
  Serial.begin(115200);
  Serial.println();

  Serial.println(F("Tft starting"));

  gui_start();
}

void loop()
{
  lv_timer_handler();

  delay(5);
}
