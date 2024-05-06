// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.4
// LVGL version: 8.2.0
// Project name: PizzaHelper

#include "../ui.h"

void ui_Home_screen_init(void)
{
    ui_Home = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Home, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_HomeCont = lv_obj_create(ui_Home);
    lv_obj_remove_style_all(ui_HomeCont);
    lv_obj_set_width(ui_HomeCont, lv_pct(100));
    lv_obj_set_height(ui_HomeCont, lv_pct(100));
    lv_obj_set_align(ui_HomeCont, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_HomeCont, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_HomeCont, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_HomeCont, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_img_src(ui_HomeCont, &ui_img_pizza_back01_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_HomeCont, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_HomeCont, 10, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_RoundPnl2 = lv_obj_create(ui_HomeCont);
    lv_obj_set_width(ui_RoundPnl2, 144);
    lv_obj_set_height(ui_RoundPnl2, 149);
    lv_obj_set_x(ui_RoundPnl2, -245);
    lv_obj_set_y(ui_RoundPnl2, -157);
    lv_obj_set_align(ui_RoundPnl2, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_RoundPnl2, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_RoundPnl2, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_RoundPnl2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_RoundPnl2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_RoundPnl2, 180, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PizzaTypeImg10 = lv_img_create(ui_RoundPnl2);
    lv_img_set_src(ui_PizzaTypeImg10, &ui_img_pizza_png);
    lv_obj_set_width(ui_PizzaTypeImg10, 100);
    lv_obj_set_height(ui_PizzaTypeImg10, 98);
    lv_obj_set_align(ui_PizzaTypeImg10, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_PizzaTypeImg10, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_PizzaTypeImg10, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_PizzaTypeLbl10 = lv_label_create(ui_RoundPnl2);
    lv_obj_set_width(ui_PizzaTypeLbl10, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_PizzaTypeLbl10, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_PizzaTypeLbl10, LV_ALIGN_CENTER);
    lv_label_set_text(ui_PizzaTypeLbl10, "Recipe Helper");

    ui_RoundPnl3 = lv_obj_create(ui_HomeCont);
    lv_obj_set_width(ui_RoundPnl3, 144);
    lv_obj_set_height(ui_RoundPnl3, 149);
    lv_obj_set_x(ui_RoundPnl3, -245);
    lv_obj_set_y(ui_RoundPnl3, -157);
    lv_obj_set_align(ui_RoundPnl3, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_RoundPnl3, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_RoundPnl3, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_RoundPnl3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_RoundPnl3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_RoundPnl3, 180, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PizzaTypeImg11 = lv_img_create(ui_RoundPnl3);
    lv_img_set_src(ui_PizzaTypeImg11, &ui_img_pizza_png);
    lv_obj_set_width(ui_PizzaTypeImg11, 100);
    lv_obj_set_height(ui_PizzaTypeImg11, 98);
    lv_obj_set_align(ui_PizzaTypeImg11, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_PizzaTypeImg11, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_PizzaTypeImg11, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_PizzaTypeLbl11 = lv_label_create(ui_RoundPnl3);
    lv_obj_set_width(ui_PizzaTypeLbl11, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_PizzaTypeLbl11, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_PizzaTypeLbl11, LV_ALIGN_CENTER);
    lv_label_set_text(ui_PizzaTypeLbl11, "Topping Helper");

    lv_obj_add_event_cb(ui_RoundPnl2, ui_event_RoundPnl2, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_RoundPnl3, ui_event_RoundPnl3, LV_EVENT_ALL, NULL);

}
