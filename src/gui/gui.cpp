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

Preferences preferences;
#define FADEMODE LV_SCR_LOAD_ANIM_FADE_ON
LGFX gfx;

void PreIngredientsLoaded();
void IngredientsLoaded();
void TimeLineLoaded();

lv_obj_t *addTimeline(const char *text)
{
  lv_obj_t *ui_TimelineCnt = lv_obj_create(ui_PanelTimeline);
  lv_obj_remove_style_all(ui_TimelineCnt);
  lv_obj_set_height(ui_TimelineCnt, 40);
  lv_obj_set_width(ui_TimelineCnt, lv_pct(100));
  lv_obj_set_align(ui_TimelineCnt, LV_ALIGN_CENTER);
  lv_obj_set_flex_flow(ui_TimelineCnt, LV_FLEX_FLOW_ROW);
  lv_obj_set_flex_align(ui_TimelineCnt, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
  lv_obj_clear_flag(ui_TimelineCnt, LV_OBJ_FLAG_SCROLLABLE); /// Flags
  lv_obj_set_style_pad_left(ui_TimelineCnt, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_right(ui_TimelineCnt, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_top(ui_TimelineCnt, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_pad_bottom(ui_TimelineCnt, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

  lv_obj_t *ui_TimelineCbx = lv_checkbox_create(ui_TimelineCnt);
  lv_checkbox_set_text(ui_TimelineCbx, "");
  lv_obj_set_width(ui_TimelineCbx, LV_SIZE_CONTENT);  /// 670
  lv_obj_set_height(ui_TimelineCbx, LV_SIZE_CONTENT); /// 1
  lv_obj_set_align(ui_TimelineCbx, LV_ALIGN_CENTER);
  lv_obj_add_flag(ui_TimelineCbx, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags

  lv_obj_t *ui_TimelineTxt = lv_label_create(ui_TimelineCnt);
  lv_obj_set_width(ui_TimelineTxt, lv_pct(95));
  lv_obj_set_height(ui_TimelineTxt, LV_SIZE_CONTENT); /// 1
  lv_obj_set_align(ui_TimelineTxt, LV_ALIGN_CENTER);
  lv_label_set_text(ui_TimelineTxt, text);

  return ui_TimelineCnt;
}

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

  recipe.SetSelectedType(String((char *)lv_event_get_user_data(e)));
  if (event_code == LV_EVENT_CLICKED)
  {
    _ui_screen_change(&ui_Method, FADEMODE, 200, 0, &ui_Method_screen_init);
  }
}

void ui_event_PizzaMethod(lv_event_t *e)
{
  lv_event_code_t event_code = lv_event_get_code(e);
  lv_obj_t *target = lv_event_get_target(e);

  recipe.SetSelectedMethod(String((char *)lv_event_get_user_data(e)));

  Serial.print("Selected method: ");
  Serial.println(recipe.GetSelectedMethod());

  if (recipe.GetSelectedMethod() == "Direct")
  {
    lv_obj_add_flag(ui_PrefPnl, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui_IngrStarterLbl, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(ui_LeaveningCmp, LV_OBJ_FLAG_HIDDEN);
  }
  else
  {
    lv_obj_clear_flag(ui_PrefPnl, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(ui_IngrStarterLbl, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui_LeaveningCmp, LV_OBJ_FLAG_HIDDEN);
  }

  if (recipe.GetSelectedMethod() == "Poolish")
  {
    lv_obj_add_flag(ui_PrefWaterCmp, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(ui_PrefPercCmp, LV_OBJ_FLAG_HIDDEN);
  }
  else if (recipe.GetSelectedMethod() == "Biga" || recipe.GetSelectedMethod() == "BigaPoolish")
  {
    lv_obj_clear_flag(ui_PrefWaterCmp, LV_OBJ_FLAG_HIDDEN);
    lv_obj_clear_flag(ui_PrefPercCmp, LV_OBJ_FLAG_HIDDEN);
  }
  else // Direct
  {
    lv_obj_add_flag(ui_PrefWaterCmp, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(ui_PrefPercCmp, LV_OBJ_FLAG_HIDDEN);
  }

  if (event_code == LV_EVENT_CLICKED)
  {
    _ui_screen_change(&ui_Yeast, FADEMODE, 200, 0, &ui_Yeast_screen_init);
  }
}

void ui_event_Next(lv_event_t *e)
{
  _ui_screen_change(&ui_Ingredients, FADEMODE, 200, 0, &ui_Ingredients_screen_init);
}

void ui_event_Prev(lv_event_t *e)
{
  _ui_screen_change(&ui_Yeast, FADEMODE, 200, 0, &ui_Yeast_screen_init);
}

void ui_event_Prev2(lv_event_t *e)
{
  _ui_screen_change(&ui_PreIngredients, FADEMODE, 200, 0, &ui_PreIngredients_screen_init);
}

void ui_event_PowerOff(lv_event_t *e)
{
  esp_deep_sleep_start();
}

void ui_event_BtnNextIngredients(lv_event_t *e)
{
  _ui_screen_change(&ui_Timeline, FADEMODE, 200, 0, &ui_Timeline_screen_init);
}

void ui_event_UseFridge(lv_event_t *e)
{
  recipe.UseTheFridge = lv_obj_has_state(ui_UseTheFridgeSw, LV_STATE_CHECKED);
}

void ui_event_DoughMachine(lv_event_t *e)
{
  recipe.SetUseDoughMachine(lv_obj_has_state(ui_DoughMachine, LV_STATE_CHECKED));
}

void ui_event_PizzaYeast(lv_event_t *e)
{
  lv_event_code_t event_code = lv_event_get_code(e);
  lv_obj_t *target = lv_event_get_target(e);

  recipe.SetSelectedYeast(String((char *)lv_event_get_user_data(e)));

  if (event_code == LV_EVENT_CLICKED)
  {
    _ui_screen_change(&ui_PreIngredients, FADEMODE, 200, 0, &ui_PreIngredients_screen_init);
  }
}

void ui_event_SliderChanged(lv_event_t *e)
{
  lv_obj_t *component = (lv_obj_t *)lv_event_get_user_data(e);
  lv_obj_t *target = lv_event_get_target(e);

  int value = lv_slider_get_value(target);

  if (component == ui_WaterCmp)
  {
    recipe.WaterPerc = value;
    lv_label_set_text(ui_comp_get_child(component, UI_COMP_INGREDIENTCMP_MIDDLECONTAINER_CONTAINER13_INGREDIENTCMPVALUE), (String(value) + "%").c_str());
  }
  else if (component == ui_LeaveningCmp)
  {
    recipe.TotalLeavening = value;
    recipe.UpdateReadyToBakeTime();
    lv_label_set_text(ui_comp_get_child(component, UI_COMP_INGREDIENTCMP_MIDDLECONTAINER_CONTAINER13_INGREDIENTCMPVALUE), (String(value) + "hrs").c_str());
  }
  else if (component == ui_RoomTempCmp)
  {
    recipe.RoomTemperature = value;
    recipe.UpdateReadyToBakeTime();
    lv_label_set_text(ui_comp_get_child(component, UI_COMP_INGREDIENTCMP_MIDDLECONTAINER_CONTAINER13_INGREDIENTCMPVALUE), (String(value) + "C").c_str());
  }
  else if (component == ui_DoughballWeightCmp)
  {
    recipe.BallWeight = value;
    lv_label_set_text(ui_comp_get_child(component, UI_COMP_INGREDIENTCMP_MIDDLECONTAINER_CONTAINER13_INGREDIENTCMPVALUE), (String(value) + "gr").c_str());
  }
  else if (component == ui_DoughballQtyCmp)
  {
    recipe.DoughBalls = value;
    lv_label_set_text(ui_comp_get_child(component, UI_COMP_INGREDIENTCMP_MIDDLECONTAINER_CONTAINER13_INGREDIENTCMPVALUE), String(value).c_str());
  }
  else if (component == ui_PrefWaterCmp)
  {
    recipe.SetPrefWaterPercentage(value);
    lv_label_set_text(ui_comp_get_child(component, UI_COMP_INGREDIENTCMP_MIDDLECONTAINER_CONTAINER13_INGREDIENTCMPVALUE), (String(value) + "%").c_str());
  }
  else if (component == ui_PrefPercCmp)
  {
    recipe.SetPrefPercentage(value);
    lv_label_set_text(ui_comp_get_child(component, UI_COMP_INGREDIENTCMP_MIDDLECONTAINER_CONTAINER13_INGREDIENTCMPVALUE), (String(value) + "%").c_str());
  }

  recipe.Recalculate();
}

void ui_event_TimelineScreenLoaded(lv_event_t *e)
{
  recipe.AddTimeline();
  TimeLineLoaded();
  recipe.SetScreen("Timeline");
}

void ui_event_PizzaTypeScreenLoaded(lv_event_t *e)
{
  recipe.SetScreen("PizzaType");
}

void ui_event_HomeScreenLoaded(lv_event_t *e)
{
  recipe.SetScreen("Home");
}

void ui_event_MethodScreenLoaded(lv_event_t *e)
{
  recipe.SetScreen("Method");
}

void ui_event_YeastScreenLoaded(lv_event_t *e)
{
  recipe.SetScreen("Yeast");
}

void ui_event_PreIngredientsScreenLoaded(lv_event_t *e)
{
  recipe.UpdateReadyToBakeTime();
  recipe.IntializeIngredients();
  PreIngredientsLoaded();

  recipe.SetScreen("PreIngredients");
}

void ui_event_IngredientsScreenLoaded(lv_event_t *e)
{
  IngredientsLoaded();
  recipe.SetScreen("Ingredients");
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
  gfx.setBrightness(200);

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

  lv_obj_add_event_cb(ui_RoundPnl, ui_event_PizzaType, LV_EVENT_CLICKED, (void *)"Round");
  lv_obj_add_event_cb(ui_GrandmaPnl, ui_event_PizzaType, LV_EVENT_CLICKED, (void *)"Grandma");
  lv_obj_add_event_cb(ui_DetroitPnl, ui_event_PizzaType, LV_EVENT_CLICKED, (void *)"Detroit");
  lv_obj_add_event_cb(ui_BreadPnl, ui_event_PizzaType, LV_EVENT_CLICKED, (void *)"Bread");
  lv_obj_add_event_cb(ui_FocacciaPnl, ui_event_PizzaType, LV_EVENT_CLICKED, (void *)"Focaccia");

  lv_obj_add_event_cb(ui_DirectPnl, ui_event_PizzaMethod, LV_EVENT_CLICKED, (void *)"Direct");
  lv_obj_add_event_cb(ui_BigaPnl, ui_event_PizzaMethod, LV_EVENT_CLICKED, (void *)"Biga");
  lv_obj_add_event_cb(ui_PoolishPnl, ui_event_PizzaMethod, LV_EVENT_CLICKED, (void *)"Poolish");
  lv_obj_add_event_cb(ui_BigaPolishPnl, ui_event_PizzaMethod, LV_EVENT_CLICKED, (void *)"BigaPoolish");

  lv_obj_add_event_cb(ui_YeastFreshPnl, ui_event_PizzaYeast, LV_EVENT_CLICKED, (void *)"Fresh");
  lv_obj_add_event_cb(ui_YeastDryPnl, ui_event_PizzaYeast, LV_EVENT_CLICKED, (void *)"Dry");
  lv_obj_add_event_cb(ui_YeastSourdoughPnl, ui_event_PizzaYeast, LV_EVENT_CLICKED, (void *)"Sourdough");

  lv_obj_add_event_cb(ui_BtnNext, ui_event_Next, LV_EVENT_CLICKED, NULL);
  lv_obj_add_event_cb(ui_BtnPrev, ui_event_Prev, LV_EVENT_CLICKED, NULL);
  lv_obj_add_event_cb(ui_BtnPrev2, ui_event_Prev2, LV_EVENT_CLICKED, NULL);
  lv_obj_add_event_cb(ui_BtnNextIngredients, ui_event_BtnNextIngredients, LV_EVENT_CLICKED, NULL);
  // lv_obj_add_event_cb(ui_PowerOff, ui_event_PowerOff, LV_EVENT_CLICKED, NULL);

  lv_obj_add_event_cb(ui_UseTheFridgeSw, ui_event_UseFridge, LV_EVENT_CLICKED, NULL);

  lv_obj_add_event_cb(ui_DoughMachine, ui_event_DoughMachine, LV_EVENT_CLICKED, NULL);

  lv_obj_add_event_cb(ui_HomeImg, ui_event_HomeBtn, LV_EVENT_CLICKED, NULL);
  lv_obj_add_event_cb(ui_HomeImg2, ui_event_HomeBtn, LV_EVENT_CLICKED, NULL);

  // screen loaded
  lv_obj_add_event_cb(ui_Home, ui_event_HomeScreenLoaded, LV_EVENT_SCREEN_LOADED, NULL);
  lv_obj_add_event_cb(ui_Timeline, ui_event_TimelineScreenLoaded, LV_EVENT_SCREEN_LOADED, NULL);
  lv_obj_add_event_cb(ui_PizzaType, ui_event_PizzaTypeScreenLoaded, LV_EVENT_SCREEN_LOADED, NULL);
  lv_obj_add_event_cb(ui_Method, ui_event_MethodScreenLoaded, LV_EVENT_SCREEN_LOADED, NULL);
  lv_obj_add_event_cb(ui_Yeast, ui_event_YeastScreenLoaded, LV_EVENT_SCREEN_LOADED, NULL);
  lv_obj_add_event_cb(ui_PreIngredients, ui_event_PreIngredientsScreenLoaded, LV_EVENT_SCREEN_LOADED, NULL);
  lv_obj_add_event_cb(ui_Ingredients, ui_event_IngredientsScreenLoaded, LV_EVENT_SCREEN_LOADED, NULL);

  lv_obj_add_event_cb(ui_comp_get_child(ui_WaterCmp, UI_COMP_INGREDIENTCMP_MIDDLECONTAINER_INGREDIENTCMPCONTAINER_INGREDIENTCMPSLI), ui_event_SliderChanged, LV_EVENT_VALUE_CHANGED, ui_WaterCmp);
  lv_obj_add_event_cb(ui_comp_get_child(ui_LeaveningCmp, UI_COMP_INGREDIENTCMP_MIDDLECONTAINER_INGREDIENTCMPCONTAINER_INGREDIENTCMPSLI), ui_event_SliderChanged, LV_EVENT_VALUE_CHANGED, ui_LeaveningCmp);
  lv_obj_add_event_cb(ui_comp_get_child(ui_RoomTempCmp, UI_COMP_INGREDIENTCMP_MIDDLECONTAINER_INGREDIENTCMPCONTAINER_INGREDIENTCMPSLI), ui_event_SliderChanged, LV_EVENT_VALUE_CHANGED, ui_RoomTempCmp);
  lv_obj_add_event_cb(ui_comp_get_child(ui_DoughballWeightCmp, UI_COMP_INGREDIENTCMP_MIDDLECONTAINER_INGREDIENTCMPCONTAINER_INGREDIENTCMPSLI), ui_event_SliderChanged, LV_EVENT_VALUE_CHANGED, ui_DoughballWeightCmp);
  lv_obj_add_event_cb(ui_comp_get_child(ui_DoughballQtyCmp, UI_COMP_INGREDIENTCMP_MIDDLECONTAINER_INGREDIENTCMPCONTAINER_INGREDIENTCMPSLI), ui_event_SliderChanged, LV_EVENT_VALUE_CHANGED, ui_DoughballQtyCmp);
  lv_obj_add_event_cb(ui_comp_get_child(ui_PrefWaterCmp, UI_COMP_INGREDIENTCMP_MIDDLECONTAINER_INGREDIENTCMPCONTAINER_INGREDIENTCMPSLI), ui_event_SliderChanged, LV_EVENT_VALUE_CHANGED, ui_PrefWaterCmp);
  lv_obj_add_event_cb(ui_comp_get_child(ui_PrefPercCmp, UI_COMP_INGREDIENTCMP_MIDDLECONTAINER_INGREDIENTCMPCONTAINER_INGREDIENTCMPSLI), ui_event_SliderChanged, LV_EVENT_VALUE_CHANGED, ui_PrefPercCmp);

  recipe.GoToScreen();
}

void PreIngredientsLoaded()
{
  lv_slider_set_value(ui_comp_get_child(ui_WaterCmp, UI_COMP_INGREDIENTCMP_MIDDLECONTAINER_INGREDIENTCMPCONTAINER_INGREDIENTCMPSLI), recipe.WaterPerc, LV_ANIM_ON);
  lv_event_send(ui_comp_get_child(ui_WaterCmp, UI_COMP_INGREDIENTCMP_MIDDLECONTAINER_INGREDIENTCMPCONTAINER_INGREDIENTCMPSLI), LV_EVENT_VALUE_CHANGED, ui_WaterCmp);

  lv_slider_set_value(ui_comp_get_child(ui_LeaveningCmp, UI_COMP_INGREDIENTCMP_MIDDLECONTAINER_INGREDIENTCMPCONTAINER_INGREDIENTCMPSLI), recipe.TotalLeavening, LV_ANIM_ON);
  lv_event_send(ui_comp_get_child(ui_LeaveningCmp, UI_COMP_INGREDIENTCMP_MIDDLECONTAINER_INGREDIENTCMPCONTAINER_INGREDIENTCMPSLI), LV_EVENT_VALUE_CHANGED, ui_LeaveningCmp);

  lv_slider_set_value(ui_comp_get_child(ui_RoomTempCmp, UI_COMP_INGREDIENTCMP_MIDDLECONTAINER_INGREDIENTCMPCONTAINER_INGREDIENTCMPSLI), recipe.RoomTemperature, LV_ANIM_ON);
  lv_event_send(ui_comp_get_child(ui_RoomTempCmp, UI_COMP_INGREDIENTCMP_MIDDLECONTAINER_INGREDIENTCMPCONTAINER_INGREDIENTCMPSLI), LV_EVENT_VALUE_CHANGED, ui_RoomTempCmp);
}

void IngredientsLoaded()
{
  lv_slider_set_value(ui_comp_get_child(ui_DoughballWeightCmp, UI_COMP_INGREDIENTCMP_MIDDLECONTAINER_INGREDIENTCMPCONTAINER_INGREDIENTCMPSLI), recipe.BallWeight, LV_ANIM_ON);
  lv_event_send(ui_comp_get_child(ui_DoughballWeightCmp, UI_COMP_INGREDIENTCMP_MIDDLECONTAINER_INGREDIENTCMPCONTAINER_INGREDIENTCMPSLI), LV_EVENT_VALUE_CHANGED, ui_DoughballWeightCmp);

  lv_slider_set_value(ui_comp_get_child(ui_DoughballQtyCmp, UI_COMP_INGREDIENTCMP_MIDDLECONTAINER_INGREDIENTCMPCONTAINER_INGREDIENTCMPSLI), recipe.DoughBalls, LV_ANIM_ON);
  lv_event_send(ui_comp_get_child(ui_DoughballQtyCmp, UI_COMP_INGREDIENTCMP_MIDDLECONTAINER_INGREDIENTCMPCONTAINER_INGREDIENTCMPSLI), LV_EVENT_VALUE_CHANGED, ui_DoughballQtyCmp);

  lv_slider_set_value(ui_comp_get_child(ui_PrefWaterCmp, UI_COMP_INGREDIENTCMP_MIDDLECONTAINER_INGREDIENTCMPCONTAINER_INGREDIENTCMPSLI), recipe.GetPrefWaterPercentage(), LV_ANIM_ON);
  lv_event_send(ui_comp_get_child(ui_PrefWaterCmp, UI_COMP_INGREDIENTCMP_MIDDLECONTAINER_INGREDIENTCMPCONTAINER_INGREDIENTCMPSLI), LV_EVENT_VALUE_CHANGED, ui_PrefWaterCmp);

  lv_slider_set_value(ui_comp_get_child(ui_PrefPercCmp, UI_COMP_INGREDIENTCMP_MIDDLECONTAINER_INGREDIENTCMPCONTAINER_INGREDIENTCMPSLI), recipe.GetPrefPercentage(), LV_ANIM_ON);
  lv_event_send(ui_comp_get_child(ui_PrefPercCmp, UI_COMP_INGREDIENTCMP_MIDDLECONTAINER_INGREDIENTCMPCONTAINER_INGREDIENTCMPSLI), LV_EVENT_VALUE_CHANGED, ui_PrefPercCmp);

  if (recipe.UseTheFridge)
  {
    lv_obj_add_state(ui_UseTheFridgeSw, LV_STATE_CHECKED);
  }
  else
  {
    lv_obj_clear_state(ui_UseTheFridgeSw, LV_STATE_CHECKED);
  }
}

void TimeLineLoaded()
{

  if (recipe.UseDoughMachine)
  {
    lv_obj_add_state(ui_DoughMachine, LV_STATE_CHECKED);
  }
  else
  {
    lv_obj_clear_state(ui_DoughMachine, LV_STATE_CHECKED);
  }
}