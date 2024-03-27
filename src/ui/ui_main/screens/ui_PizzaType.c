// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.4
// LVGL version: 8.2.0
// Project name: PizzaHelper

#include "../ui.h"

void ui_PizzaType_screen_init(void)
{
    ui_PizzaType = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_PizzaType, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_MainContainer = lv_obj_create(ui_PizzaType);
    lv_obj_remove_style_all(ui_MainContainer);
    lv_obj_set_width(ui_MainContainer, lv_pct(100));
    lv_obj_set_height(ui_MainContainer, lv_pct(100));
    lv_obj_set_align(ui_MainContainer, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_MainContainer, LV_FLEX_FLOW_ROW_WRAP);
    lv_obj_set_flex_align(ui_MainContainer, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_MainContainer, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_img_src(ui_MainContainer, &ui_img_pizza_back01_png, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_MainContainer, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_MainContainer, 10, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_RoundPnl = lv_obj_create(ui_MainContainer);
    lv_obj_set_width(ui_RoundPnl, 144);
    lv_obj_set_height(ui_RoundPnl, 149);
    lv_obj_set_x(ui_RoundPnl, -245);
    lv_obj_set_y(ui_RoundPnl, -157);
    lv_obj_set_align(ui_RoundPnl, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_RoundPnl, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_RoundPnl, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_RoundPnl, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_RoundPnl, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_RoundPnl, 180, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PizzaTypeImg = lv_img_create(ui_RoundPnl);
    lv_img_set_src(ui_PizzaTypeImg, &ui_img_pizza_png);
    lv_obj_set_width(ui_PizzaTypeImg, 100);
    lv_obj_set_height(ui_PizzaTypeImg, 98);
    lv_obj_set_align(ui_PizzaTypeImg, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_PizzaTypeImg, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_PizzaTypeImg, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_PizzaTypeLbl = lv_label_create(ui_RoundPnl);
    lv_obj_set_width(ui_PizzaTypeLbl, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_PizzaTypeLbl, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_PizzaTypeLbl, LV_ALIGN_CENTER);
    lv_label_set_text(ui_PizzaTypeLbl, "Round");

    ui_GrandmaPnl = lv_obj_create(ui_MainContainer);
    lv_obj_set_width(ui_GrandmaPnl, 144);
    lv_obj_set_height(ui_GrandmaPnl, 149);
    lv_obj_set_x(ui_GrandmaPnl, -245);
    lv_obj_set_y(ui_GrandmaPnl, -157);
    lv_obj_set_align(ui_GrandmaPnl, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_GrandmaPnl, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_GrandmaPnl, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_GrandmaPnl, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_GrandmaPnl, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_GrandmaPnl, 180, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PizzaTypeImg1 = lv_img_create(ui_GrandmaPnl);
    lv_img_set_src(ui_PizzaTypeImg1, &ui_img_grandma_png);
    lv_obj_set_width(ui_PizzaTypeImg1, 100);
    lv_obj_set_height(ui_PizzaTypeImg1, 98);
    lv_obj_set_align(ui_PizzaTypeImg1, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_PizzaTypeImg1, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_PizzaTypeImg1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_PizzaTypeLbl1 = lv_label_create(ui_GrandmaPnl);
    lv_obj_set_width(ui_PizzaTypeLbl1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_PizzaTypeLbl1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_PizzaTypeLbl1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_PizzaTypeLbl1, "Grandma");

    ui_FocacciaPnl = lv_obj_create(ui_MainContainer);
    lv_obj_set_width(ui_FocacciaPnl, 144);
    lv_obj_set_height(ui_FocacciaPnl, 149);
    lv_obj_set_x(ui_FocacciaPnl, -245);
    lv_obj_set_y(ui_FocacciaPnl, -157);
    lv_obj_set_align(ui_FocacciaPnl, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_FocacciaPnl, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_FocacciaPnl, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_FocacciaPnl, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_FocacciaPnl, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_FocacciaPnl, 180, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PizzaTypeImg2 = lv_img_create(ui_FocacciaPnl);
    lv_img_set_src(ui_PizzaTypeImg2, &ui_img_focaccia_png);
    lv_obj_set_width(ui_PizzaTypeImg2, 100);
    lv_obj_set_height(ui_PizzaTypeImg2, 98);
    lv_obj_set_align(ui_PizzaTypeImg2, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_PizzaTypeImg2, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_PizzaTypeImg2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_PizzaTypeLbl2 = lv_label_create(ui_FocacciaPnl);
    lv_obj_set_width(ui_PizzaTypeLbl2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_PizzaTypeLbl2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_PizzaTypeLbl2, LV_ALIGN_CENTER);
    lv_label_set_text(ui_PizzaTypeLbl2, "Focaccia");

    ui_DetroitPnl = lv_obj_create(ui_MainContainer);
    lv_obj_set_width(ui_DetroitPnl, 144);
    lv_obj_set_height(ui_DetroitPnl, 149);
    lv_obj_set_x(ui_DetroitPnl, -245);
    lv_obj_set_y(ui_DetroitPnl, -157);
    lv_obj_set_align(ui_DetroitPnl, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_DetroitPnl, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_DetroitPnl, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_DetroitPnl, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_DetroitPnl, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_DetroitPnl, 180, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PizzaTypeImg3 = lv_img_create(ui_DetroitPnl);
    lv_img_set_src(ui_PizzaTypeImg3, &ui_img_detroit_png);
    lv_obj_set_width(ui_PizzaTypeImg3, 100);
    lv_obj_set_height(ui_PizzaTypeImg3, 98);
    lv_obj_set_align(ui_PizzaTypeImg3, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_PizzaTypeImg3, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_PizzaTypeImg3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_PizzaTypeLbl3 = lv_label_create(ui_DetroitPnl);
    lv_obj_set_width(ui_PizzaTypeLbl3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_PizzaTypeLbl3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_PizzaTypeLbl3, LV_ALIGN_CENTER);
    lv_label_set_text(ui_PizzaTypeLbl3, "Detroit");

    ui_BreadPnl = lv_obj_create(ui_MainContainer);
    lv_obj_set_width(ui_BreadPnl, 144);
    lv_obj_set_height(ui_BreadPnl, 149);
    lv_obj_set_x(ui_BreadPnl, -245);
    lv_obj_set_y(ui_BreadPnl, -157);
    lv_obj_set_align(ui_BreadPnl, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_BreadPnl, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_BreadPnl, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_BreadPnl, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_BreadPnl, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_BreadPnl, 180, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PizzaTypeImg4 = lv_img_create(ui_BreadPnl);
    lv_img_set_src(ui_PizzaTypeImg4, &ui_img_bread_png);
    lv_obj_set_width(ui_PizzaTypeImg4, 100);
    lv_obj_set_height(ui_PizzaTypeImg4, 98);
    lv_obj_set_align(ui_PizzaTypeImg4, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_PizzaTypeImg4, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_PizzaTypeImg4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_PizzaTypeLbl4 = lv_label_create(ui_BreadPnl);
    lv_obj_set_width(ui_PizzaTypeLbl4, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_PizzaTypeLbl4, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_PizzaTypeLbl4, LV_ALIGN_CENTER);
    lv_label_set_text(ui_PizzaTypeLbl4, "Bread");

    ui_PowerOff = lv_img_create(ui_PizzaType);
    lv_img_set_src(ui_PowerOff, &ui_img_9054774_bx_power_off_icon_png);
    lv_obj_set_width(ui_PowerOff, 32);
    lv_obj_set_height(ui_PowerOff, 32);
    lv_obj_set_x(ui_PowerOff, 370);
    lv_obj_set_y(ui_PowerOff, -214);
    lv_obj_set_align(ui_PowerOff, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_PowerOff, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_PowerOff, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

}
