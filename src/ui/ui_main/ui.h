// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.4
// LVGL version: 8.2.0
// Project name: PizzaHelper

#ifndef _PIZZAHELPER_UI_H
#define _PIZZAHELPER_UI_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined __has_include
#if __has_include("lvgl.h")
#include "lvgl.h"
#elif __has_include("lvgl/lvgl.h")
#include "lvgl/lvgl.h"
#else
#include "lvgl.h"
#endif
#else
#include "lvgl.h"
#endif

#include "ui_helpers.h"
#include "ui_events.h"
// SCREEN: ui_PizzaType
void ui_PizzaType_screen_init(void);
extern lv_obj_t * ui_PizzaType;
extern lv_obj_t * ui_MainContainer;
extern lv_obj_t * ui_RoundPnl;
extern lv_obj_t * ui_PizzaTypeImg;
extern lv_obj_t * ui_PizzaTypeLbl;
extern lv_obj_t * ui_GrandmaPnl;
extern lv_obj_t * ui_PizzaTypeImg1;
extern lv_obj_t * ui_PizzaTypeLbl1;
extern lv_obj_t * ui_FocacciaPnl;
extern lv_obj_t * ui_PizzaTypeImg2;
extern lv_obj_t * ui_PizzaTypeLbl2;
extern lv_obj_t * ui_DetroitPnl;
extern lv_obj_t * ui_PizzaTypeImg3;
extern lv_obj_t * ui_PizzaTypeLbl3;
extern lv_obj_t * ui_BreadPnl;
extern lv_obj_t * ui_PizzaTypeImg4;
extern lv_obj_t * ui_PizzaTypeLbl4;
extern lv_obj_t * ui_PowerOff;
// SCREEN: ui_Method
void ui_Method_screen_init(void);
extern lv_obj_t * ui_Method;
extern lv_obj_t * ui_Container5;
extern lv_obj_t * ui_DirectPnl;
extern lv_obj_t * ui_PizzaTypeImg6;
extern lv_obj_t * ui_PizzaTypeLbl6;
extern lv_obj_t * ui_BigaPnl;
extern lv_obj_t * ui_PizzaTypeImg5;
extern lv_obj_t * ui_PizzaTypeLbl5;
extern lv_obj_t * ui_PoolishPnl;
extern lv_obj_t * ui_PizzaTypeImg7;
extern lv_obj_t * ui_PizzaTypeLbl7;
extern lv_obj_t * ui_BigaPolishPnl;
extern lv_obj_t * ui_PizzaTypeImg8;
extern lv_obj_t * ui_PizzaTypeLbl8;
void ui_event_BtnPrev(lv_event_t * e);
extern lv_obj_t * ui_BtnPrev;
extern lv_obj_t * ui_PrevLbl;
// SCREEN: ui_Yeast
void ui_Yeast_screen_init(void);
extern lv_obj_t * ui_Yeast;
extern lv_obj_t * ui_Container1;
extern lv_obj_t * ui_YeastFreshPnl;
extern lv_obj_t * ui_YeastImg;
extern lv_obj_t * ui_YeastLbl;
extern lv_obj_t * ui_YeastDryPnl;
extern lv_obj_t * ui_YeastImg1;
extern lv_obj_t * ui_YeastLbl1;
extern lv_obj_t * ui_YeastSourdoughPnl;
extern lv_obj_t * ui_YeastImg2;
extern lv_obj_t * ui_YeastLbl2;
void ui_event_BtnPrev2(lv_event_t * e);
extern lv_obj_t * ui_BtnPrev2;
extern lv_obj_t * ui_PrevLbl2;
// SCREEN: ui_PreIngredients
void ui_PreIngredients_screen_init(void);
extern lv_obj_t * ui_PreIngredients;
// SCREEN: ui_Ingredients
void ui_Ingredients_screen_init(void);
extern lv_obj_t * ui_Ingredients;
// SCREEN: ui_Timeline
void ui_Timeline_screen_init(void);
extern lv_obj_t * ui_Timeline;
void ui_event_BtnPrev3(lv_event_t * e);
extern lv_obj_t * ui_BtnPrev3;
extern lv_obj_t * ui_PrevLbl3;
extern lv_obj_t * ui_PanelTimeline;
extern lv_obj_t * ui_DoughMachine;
extern lv_obj_t * ui_Label1;
// SCREEN: ui_Components
void ui_Components_screen_init(void);
extern lv_obj_t * ui_Components;
extern lv_obj_t * ui_PanelTimeline2;
extern lv_obj_t * ui_TimelineCnt;
extern lv_obj_t * ui_TimelineCbx;
extern lv_obj_t * ui_TimelineTxt;
extern lv_obj_t * ui_TabView1;
extern lv_obj_t * ui_TabPage1;
extern lv_obj_t * ui_Button1;
extern lv_obj_t * ui_TabPage2;
// SCREEN: ui_Oven
void ui_Oven_screen_init(void);
extern lv_obj_t * ui_Oven;
extern lv_obj_t * ui_Arc1;
extern lv_obj_t * ui_Slider1;
extern lv_obj_t * ui____initial_actions0;

LV_IMG_DECLARE(ui_img_pizza_back01_png);    // assets\pizza_back01.png
LV_IMG_DECLARE(ui_img_pizza_png);    // assets\pizza.png
LV_IMG_DECLARE(ui_img_grandma_png);    // assets\grandma.png
LV_IMG_DECLARE(ui_img_focaccia_png);    // assets\focaccia.png
LV_IMG_DECLARE(ui_img_detroit_png);    // assets\detroit.png
LV_IMG_DECLARE(ui_img_bread_png);    // assets\bread.png
LV_IMG_DECLARE(ui_img_9054774_bx_power_off_icon_png);    // assets\9054774_bx_power_off_icon.png
LV_IMG_DECLARE(ui_img_direct_png);    // assets\direct.png
LV_IMG_DECLARE(ui_img_biga_png);    // assets\biga.png
LV_IMG_DECLARE(ui_img_poolish_png);    // assets\poolish.png
LV_IMG_DECLARE(ui_img_bigapool_png);    // assets\bigapool.png
LV_IMG_DECLARE(ui_img_fresh_png);    // assets\fresh.png
LV_IMG_DECLARE(ui_img_dry_png);    // assets\dry.png
LV_IMG_DECLARE(ui_img_sourdough_png);    // assets\sourdough.png



void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
