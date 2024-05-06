#include "ui/ui.h"

#ifndef UICOMP_H
#define UICOMP_H

lv_obj_t *createButtonWithText(lv_obj_t *parent, const char *text, void (*ui_event_click)(lv_event_t *e));
lv_obj_t *createChip(lv_obj_t *parent, const char *text);

#endif