#include <Arduino.h>
#include <Wire.h>
#include <lv_conf.h>
#include <lvgl.h>
#include "gui.h"

#include "../ui/ui.h"
#include "../gfx/LGFX_ESP32S3_RGB_MakerfabsParallelTFTwithTouch70.h"
#include "recipe.hpp"

static const char *TAG = "gui";

static const uint16_t screenWidth = 800;
static const uint16_t screenHeight = 480;

static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf[2][screenWidth * 10];

LGFX gfx;

/* Display flushing */
void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p)
{
  if (gfx.getStartCount() == 0)
  { // Processing if not yet started
    gfx.startWrite();
  }
  gfx.pushImageDMA(area->x1, area->y1, area->x2 - area->x1 + 1, area->y2 - area->y1 + 1, (lgfx::rgb565_t *)&color_p->full);
  lv_disp_flush_ready(disp);
}

/*Read the touchpad*/
void my_touchpad_read(lv_indev_drv_t *indev_driver, lv_indev_data_t *data)
{
  uint16_t touchX, touchY;

  data->state = LV_INDEV_STATE_REL;

  if (gfx.getTouch(&touchX, &touchY))
  {
    data->state = LV_INDEV_STATE_PR;

    /*Set the coordinates*/
    data->point.x = touchX;
    data->point.y = touchY;
  }
}

// static void ta_event_cb(lv_event_t *e)
// {
//   lv_event_code_t code = lv_event_get_code(e);
//   lv_obj_t *ta = lv_event_get_target(e);
//   if (code == LV_EVENT_CLICKED || code == LV_EVENT_FOCUSED)
//   {
//     /*Focus on the clicked text area*/
//     if (ui_Keyboard1 != NULL)
//       lv_keyboard_set_textarea(ui_Keyboard1, ta);
//   }
// }

void ui_event_PizzaType(lv_event_t *e)
{
  lv_event_code_t event_code = lv_event_get_code(e);
  lv_obj_t *target = lv_event_get_target(e);

  recipe.selectedType = String((char *)lv_event_get_user_data(e));
  if (event_code == LV_EVENT_CLICKED)
  {
    _ui_screen_change(&ui_Method, LV_SCR_LOAD_ANIM_OVER_LEFT, 500, 0, &ui_Method_screen_init);
  }
}

void ui_event_PizzaMethod(lv_event_t *e)
{
  lv_event_code_t event_code = lv_event_get_code(e);
  lv_obj_t *target = lv_event_get_target(e);

  recipe.selectedMethod = String((char *)lv_event_get_user_data(e));
  if (event_code == LV_EVENT_CLICKED)
  {
    _ui_screen_change(&ui_Ingredients, LV_SCR_LOAD_ANIM_OVER_LEFT, 500, 0, &ui_Ingredients_screen_init);
  }
}

/**
 * @brief
 *
 */
void gui_start()
{

  // ----------- GFX -------------
  gfx.begin();
  //  gfx.setColorDepth(16);
  gfx.setBrightness(127);

  lv_init();
  lv_disp_draw_buf_init(&draw_buf, buf[0], buf[1], screenWidth * 10);

  /*Initialize the display*/
  static lv_disp_drv_t disp_drv;
  lv_disp_drv_init(&disp_drv);
  disp_drv.hor_res = screenWidth;
  disp_drv.ver_res = screenHeight;
  disp_drv.flush_cb = my_disp_flush;
  disp_drv.draw_buf = &draw_buf;
  lv_disp_drv_register(&disp_drv);

  /*Initialize the input device driver*/
  static lv_indev_drv_t indev_drv;
  lv_indev_drv_init(&indev_drv);
  indev_drv.type = LV_INDEV_TYPE_POINTER;
  indev_drv.read_cb = my_touchpad_read;
  lv_indev_drv_register(&indev_drv);

  ui_init();

  // lv_obj_add_event_cb(ui_DoughBallsTa, ta_event_cb, LV_EVENT_ALL, NULL);
  // lv_obj_add_event_cb(ui_BallWieghtTa, ta_event_cb, LV_EVENT_ALL, NULL);
  // lv_obj_add_event_cb(ui_LeaveningTimeTa, ta_event_cb, LV_EVENT_ALL, NULL);
  // lv_obj_add_event_cb(ui_RoomTemperatureTa, ta_event_cb, LV_EVENT_ALL, NULL);

  lv_obj_add_event_cb(ui_RoundPnl, ui_event_PizzaType, LV_EVENT_CLICKED, (void *)"Round");
  lv_obj_add_event_cb(ui_GrandmaPnl, ui_event_PizzaType, LV_EVENT_CLICKED, (void *)"Grandma");
  lv_obj_add_event_cb(ui_DetroitPnl, ui_event_PizzaType, LV_EVENT_CLICKED, (void *)"Detroit");
  lv_obj_add_event_cb(ui_BreadPnl, ui_event_PizzaType, LV_EVENT_CLICKED, (void *)"Bread");
  lv_obj_add_event_cb(ui_FocacciaPnl, ui_event_PizzaType, LV_EVENT_CLICKED, (void *)"Focaccia");

  lv_obj_add_event_cb(ui_DirectPnl, ui_event_PizzaMethod, LV_EVENT_CLICKED, (void *)"Direct");
  lv_obj_add_event_cb(ui_BigaPnl, ui_event_PizzaMethod, LV_EVENT_CLICKED, (void *)"Biga");
  lv_obj_add_event_cb(ui_PoolishPnl, ui_event_PizzaMethod, LV_EVENT_CLICKED, (void *)"Poolish");
  lv_obj_add_event_cb(ui_BigaPolishPnl, ui_event_PizzaMethod, LV_EVENT_CLICKED, (void *)"BigaPoolish");
}
