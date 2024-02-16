// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.4
// LVGL version: 8.2.0
// Project name: PizzaHelper

#include "../ui.h"

void ui_Method_screen_init(void)
{
    ui_Method = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Method, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Container5 = lv_obj_create(ui_Method);
    lv_obj_remove_style_all(ui_Container5);
    lv_obj_set_width(ui_Container5, lv_pct(100));
    lv_obj_set_height(ui_Container5, lv_pct(100));
    lv_obj_set_align(ui_Container5, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Container5, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Container5, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Container5, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_DirectPnl = lv_obj_create(ui_Container5);
    lv_obj_set_width(ui_DirectPnl, 144);
    lv_obj_set_height(ui_DirectPnl, 149);
    lv_obj_set_x(ui_DirectPnl, -245);
    lv_obj_set_y(ui_DirectPnl, -157);
    lv_obj_set_align(ui_DirectPnl, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_DirectPnl, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_DirectPnl, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_DirectPnl, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_PizzaTypeImg6 = lv_img_create(ui_DirectPnl);
    lv_img_set_src(ui_PizzaTypeImg6, &ui_img_direct_png);
    lv_obj_set_width(ui_PizzaTypeImg6, 100);
    lv_obj_set_height(ui_PizzaTypeImg6, 98);
    lv_obj_set_align(ui_PizzaTypeImg6, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_PizzaTypeImg6, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_PizzaTypeImg6, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_PizzaTypeLbl6 = lv_label_create(ui_DirectPnl);
    lv_obj_set_width(ui_PizzaTypeLbl6, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_PizzaTypeLbl6, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_PizzaTypeLbl6, LV_ALIGN_CENTER);
    lv_label_set_text(ui_PizzaTypeLbl6, "Direct");

    ui_BigaPnl = lv_obj_create(ui_Container5);
    lv_obj_set_width(ui_BigaPnl, 144);
    lv_obj_set_height(ui_BigaPnl, 149);
    lv_obj_set_x(ui_BigaPnl, -245);
    lv_obj_set_y(ui_BigaPnl, -157);
    lv_obj_set_align(ui_BigaPnl, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_BigaPnl, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_BigaPnl, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_BigaPnl, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_PizzaTypeImg5 = lv_img_create(ui_BigaPnl);
    lv_img_set_src(ui_PizzaTypeImg5, &ui_img_biga_png);
    lv_obj_set_width(ui_PizzaTypeImg5, 100);
    lv_obj_set_height(ui_PizzaTypeImg5, 98);
    lv_obj_set_align(ui_PizzaTypeImg5, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_PizzaTypeImg5, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_PizzaTypeImg5, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_PizzaTypeLbl5 = lv_label_create(ui_BigaPnl);
    lv_obj_set_width(ui_PizzaTypeLbl5, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_PizzaTypeLbl5, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_PizzaTypeLbl5, LV_ALIGN_CENTER);
    lv_label_set_text(ui_PizzaTypeLbl5, "Biga");

    ui_PoolishPnl = lv_obj_create(ui_Container5);
    lv_obj_set_width(ui_PoolishPnl, 144);
    lv_obj_set_height(ui_PoolishPnl, 149);
    lv_obj_set_x(ui_PoolishPnl, -245);
    lv_obj_set_y(ui_PoolishPnl, -157);
    lv_obj_set_align(ui_PoolishPnl, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_PoolishPnl, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_PoolishPnl, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_PoolishPnl, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_PizzaTypeImg7 = lv_img_create(ui_PoolishPnl);
    lv_img_set_src(ui_PizzaTypeImg7, &ui_img_poolish_png);
    lv_obj_set_width(ui_PizzaTypeImg7, 100);
    lv_obj_set_height(ui_PizzaTypeImg7, 98);
    lv_obj_set_align(ui_PizzaTypeImg7, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_PizzaTypeImg7, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_PizzaTypeImg7, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_PizzaTypeLbl7 = lv_label_create(ui_PoolishPnl);
    lv_obj_set_width(ui_PizzaTypeLbl7, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_PizzaTypeLbl7, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_PizzaTypeLbl7, LV_ALIGN_CENTER);
    lv_label_set_text(ui_PizzaTypeLbl7, "Poolish");

    ui_BigaPolishPnl = lv_obj_create(ui_Container5);
    lv_obj_set_width(ui_BigaPolishPnl, 144);
    lv_obj_set_height(ui_BigaPolishPnl, 149);
    lv_obj_set_x(ui_BigaPolishPnl, -245);
    lv_obj_set_y(ui_BigaPolishPnl, -157);
    lv_obj_set_align(ui_BigaPolishPnl, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_BigaPolishPnl, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_BigaPolishPnl, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_BigaPolishPnl, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_PizzaTypeImg8 = lv_img_create(ui_BigaPolishPnl);
    lv_img_set_src(ui_PizzaTypeImg8, &ui_img_poolish_png);
    lv_obj_set_width(ui_PizzaTypeImg8, 100);
    lv_obj_set_height(ui_PizzaTypeImg8, 98);
    lv_obj_set_align(ui_PizzaTypeImg8, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_PizzaTypeImg8, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_PizzaTypeImg8, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_PizzaTypeLbl8 = lv_label_create(ui_BigaPolishPnl);
    lv_obj_set_width(ui_PizzaTypeLbl8, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_PizzaTypeLbl8, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_PizzaTypeLbl8, LV_ALIGN_CENTER);
    lv_label_set_text(ui_PizzaTypeLbl8, "Poolish+Biga");

}