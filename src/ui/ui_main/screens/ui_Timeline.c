// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.4
// LVGL version: 8.2.0
// Project name: PizzaHelper

#include "../ui.h"

void ui_Timeline_screen_init(void)
{
    ui_Timeline = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Timeline, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_img_src(ui_Timeline, &ui_img_pizza_back01_png, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_BtnPrev3 = lv_btn_create(ui_Timeline);
    lv_obj_set_width(ui_BtnPrev3, 100);
    lv_obj_set_height(ui_BtnPrev3, 50);
    lv_obj_set_x(ui_BtnPrev3, -340);
    lv_obj_set_y(ui_BtnPrev3, 204);
    lv_obj_set_align(ui_BtnPrev3, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_BtnPrev3, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_BtnPrev3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_PrevLbl3 = lv_label_create(ui_BtnPrev3);
    lv_obj_set_width(ui_PrevLbl3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_PrevLbl3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_PrevLbl3, LV_ALIGN_CENTER);
    lv_label_set_text(ui_PrevLbl3, "PREV");

    ui_PanelTimeline = lv_obj_create(ui_Timeline);
    lv_obj_set_width(ui_PanelTimeline, 714);
    lv_obj_set_height(ui_PanelTimeline, 368);
    lv_obj_set_x(ui_PanelTimeline, 0);
    lv_obj_set_y(ui_PanelTimeline, -18);
    lv_obj_set_align(ui_PanelTimeline, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_PanelTimeline, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_PanelTimeline, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_obj_set_style_bg_color(ui_PanelTimeline, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_PanelTimeline, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_PanelTimeline, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_DoughMachine = lv_switch_create(ui_Timeline);
    lv_obj_set_width(ui_DoughMachine, 50);
    lv_obj_set_height(ui_DoughMachine, 25);
    lv_obj_set_x(ui_DoughMachine, -219);
    lv_obj_set_y(ui_DoughMachine, 200);
    lv_obj_set_align(ui_DoughMachine, LV_ALIGN_CENTER);


    ui_Label1 = lv_label_create(ui_Timeline);
    lv_obj_set_width(ui_Label1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label1, -96);
    lv_obj_set_y(ui_Label1, 201);
    lv_obj_set_align(ui_Label1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label1, "I have a dough machine");
    lv_obj_set_style_text_color(ui_Label1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_TopBar4 = lv_obj_create(ui_Timeline);
    lv_obj_remove_style_all(ui_TopBar4);
    lv_obj_set_height(ui_TopBar4, 36);
    lv_obj_set_width(ui_TopBar4, lv_pct(100));
    lv_obj_set_align(ui_TopBar4, LV_ALIGN_TOP_MID);
    lv_obj_set_flex_flow(ui_TopBar4, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_TopBar4, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(ui_TopBar4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_TopBar4, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_TopBar4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_HomeBtn4 = lv_img_create(ui_TopBar4);
    lv_img_set_src(ui_HomeBtn4, &ui_img_8726048_home_icon_png);
    lv_obj_set_width(ui_HomeBtn4, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_HomeBtn4, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_HomeBtn4, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_HomeBtn4, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_HomeBtn4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    lv_obj_add_event_cb(ui_BtnPrev3, ui_event_BtnPrev3, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_HomeBtn4, ui_event_HomeBtn4, LV_EVENT_ALL, NULL);

}
