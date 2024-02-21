#include <Preferences.h>
#include "ui/ui.h"

#ifndef GUI_H
#define GUI_H

void gui_start();
lv_obj_t *addTimeline(const char *text);

extern Preferences preferences;

#endif