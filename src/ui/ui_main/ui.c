// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.4
// LVGL version: 8.2.0
// Project name: PizzaHelper

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////


// SCREEN: ui_Home
void ui_Home_screen_init(void);
lv_obj_t * ui_Home;
lv_obj_t * ui_HomeCont;
void ui_event_RoundPnl2(lv_event_t * e);
lv_obj_t * ui_RoundPnl2;
lv_obj_t * ui_PizzaTypeImg10;
lv_obj_t * ui_PizzaTypeLbl10;
lv_obj_t * ui_RoundPnl3;
lv_obj_t * ui_PizzaTypeImg11;
lv_obj_t * ui_PizzaTypeLbl11;


// SCREEN: ui_PizzaType
void ui_PizzaType_screen_init(void);
lv_obj_t * ui_PizzaType;
lv_obj_t * ui_MainContainer;
lv_obj_t * ui_RoundPnl;
lv_obj_t * ui_PizzaTypeImg;
lv_obj_t * ui_PizzaTypeLbl;
lv_obj_t * ui_GrandmaPnl;
lv_obj_t * ui_PizzaTypeImg1;
lv_obj_t * ui_PizzaTypeLbl1;
lv_obj_t * ui_FocacciaPnl;
lv_obj_t * ui_PizzaTypeImg2;
lv_obj_t * ui_PizzaTypeLbl2;
lv_obj_t * ui_DetroitPnl;
lv_obj_t * ui_PizzaTypeImg3;
lv_obj_t * ui_PizzaTypeLbl3;
lv_obj_t * ui_BreadPnl;
lv_obj_t * ui_PizzaTypeImg4;
lv_obj_t * ui_PizzaTypeLbl4;
lv_obj_t * ui_TopBar;
void ui_event_HomeBtn(lv_event_t * e);
lv_obj_t * ui_HomeBtn;
lv_obj_t * ui_TopBar5;
void ui_event_HomeBtn5(lv_event_t * e);
lv_obj_t * ui_HomeBtn5;


// SCREEN: ui_Method
void ui_Method_screen_init(void);
lv_obj_t * ui_Method;
lv_obj_t * ui_Container5;
lv_obj_t * ui_DirectPnl;
lv_obj_t * ui_PizzaTypeImg6;
lv_obj_t * ui_PizzaTypeLbl6;
lv_obj_t * ui_BigaPnl;
lv_obj_t * ui_PizzaTypeImg5;
lv_obj_t * ui_PizzaTypeLbl5;
lv_obj_t * ui_PoolishPnl;
lv_obj_t * ui_PizzaTypeImg7;
lv_obj_t * ui_PizzaTypeLbl7;
lv_obj_t * ui_BigaPolishPnl;
lv_obj_t * ui_PizzaTypeImg8;
lv_obj_t * ui_PizzaTypeLbl8;
void ui_event_BtnPrev(lv_event_t * e);
lv_obj_t * ui_BtnPrev;
lv_obj_t * ui_PrevLbl;
lv_obj_t * ui_TopBar2;
void ui_event_HomeBtn2(lv_event_t * e);
lv_obj_t * ui_HomeBtn2;


// SCREEN: ui_Yeast
void ui_Yeast_screen_init(void);
lv_obj_t * ui_Yeast;
lv_obj_t * ui_Container1;
lv_obj_t * ui_YeastFreshPnl;
lv_obj_t * ui_YeastImg;
lv_obj_t * ui_YeastLbl;
lv_obj_t * ui_YeastDryPnl;
lv_obj_t * ui_YeastImg1;
lv_obj_t * ui_YeastLbl1;
lv_obj_t * ui_YeastSourdoughPnl;
lv_obj_t * ui_YeastImg2;
lv_obj_t * ui_YeastLbl2;
void ui_event_BtnPrev2(lv_event_t * e);
lv_obj_t * ui_BtnPrev2;
lv_obj_t * ui_PrevLbl2;
lv_obj_t * ui_TopBar3;
void ui_event_HomeBtn3(lv_event_t * e);
lv_obj_t * ui_HomeBtn3;


// SCREEN: ui_PreIngredients
void ui_PreIngredients_screen_init(void);
lv_obj_t * ui_PreIngredients;


// SCREEN: ui_Ingredients
void ui_Ingredients_screen_init(void);
lv_obj_t * ui_Ingredients;


// SCREEN: ui_Timeline
void ui_Timeline_screen_init(void);
lv_obj_t * ui_Timeline;
void ui_event_BtnPrev3(lv_event_t * e);
lv_obj_t * ui_BtnPrev3;
lv_obj_t * ui_PrevLbl3;
lv_obj_t * ui_PanelTimeline;
lv_obj_t * ui_DoughMachine;
lv_obj_t * ui_Label1;
lv_obj_t * ui_TopBar4;
void ui_event_HomeBtn4(lv_event_t * e);
lv_obj_t * ui_HomeBtn4;


// SCREEN: ui_Components
void ui_Components_screen_init(void);
lv_obj_t * ui_Components;
lv_obj_t * ui_PanelTimeline2;
lv_obj_t * ui_TimelineCnt;
lv_obj_t * ui_TimelineCbx;
lv_obj_t * ui_TimelineTxt;
lv_obj_t * ui_TabView1;
lv_obj_t * ui_TabPage1;
lv_obj_t * ui_Button1;
lv_obj_t * ui_TabPage2;
lv_obj_t * ui____initial_actions0;
const lv_img_dsc_t * ui_imgset_pizza_back[1] = {&ui_img_pizza_back01_png};

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////
void ui_event_RoundPnl2(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_PizzaType, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, &ui_PizzaType_screen_init);
    }
}
void ui_event_HomeBtn(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_Home, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, &ui_Home_screen_init);
    }
}
void ui_event_HomeBtn5(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_Home, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, &ui_Home_screen_init);
    }
}
void ui_event_BtnPrev(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_PizzaType, LV_SCR_LOAD_ANIM_FADE_ON, 300, 0, &ui_PizzaType_screen_init);
    }
}
void ui_event_HomeBtn2(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_Home, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, &ui_Home_screen_init);
    }
}
void ui_event_BtnPrev2(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_Method, LV_SCR_LOAD_ANIM_FADE_ON, 300, 0, &ui_Method_screen_init);
    }
}
void ui_event_HomeBtn3(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_Home, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, &ui_Home_screen_init);
    }
}
void ui_event_BtnPrev3(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_Ingredients, LV_SCR_LOAD_ANIM_FADE_ON, 300, 0, &ui_Ingredients_screen_init);
    }
}
void ui_event_HomeBtn4(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_Home, LV_SCR_LOAD_ANIM_FADE_ON, 100, 0, &ui_Home_screen_init);
    }
}

///////////////////// SCREENS ////////////////////


uint32_t LV_EVENT_GET_COMP_CHILD;
void ui_init(void)
{
LV_EVENT_GET_COMP_CHILD = lv_event_register_id();
    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_Home_screen_init();
    ui_PizzaType_screen_init();
    ui_Method_screen_init();
    ui_Yeast_screen_init();
    ui_PreIngredients_screen_init();
    ui_Ingredients_screen_init();
    ui_Timeline_screen_init();
    ui_Components_screen_init();
    ui____initial_actions0 = lv_obj_create(NULL);
    lv_disp_load_scr(ui_Home);
}
