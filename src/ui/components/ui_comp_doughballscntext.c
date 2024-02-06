// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.4
// LVGL version: 8.2.0
// Project name: PizzaHelper

#include "../ui.h"


// COMPONENT DoughballsCntExt

lv_obj_t * ui_DoughballsCntExt_create(lv_obj_t * comp_parent)
{

    lv_obj_t * cui_DoughballsCntExt;
    cui_DoughballsCntExt = lv_obj_create(comp_parent);
    lv_obj_remove_style_all(cui_DoughballsCntExt);
    lv_obj_set_height(cui_DoughballsCntExt, 82);
    lv_obj_set_width(cui_DoughballsCntExt, LV_SIZE_CONTENT);   /// 226
    lv_obj_set_x(cui_DoughballsCntExt, -182);
    lv_obj_set_y(cui_DoughballsCntExt, -181);
    lv_obj_set_align(cui_DoughballsCntExt, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(cui_DoughballsCntExt, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(cui_DoughballsCntExt, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_START);
    lv_obj_clear_flag(cui_DoughballsCntExt, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    lv_obj_t * cui_DoughBallsQtyImg;
    cui_DoughBallsQtyImg = lv_img_create(cui_DoughballsCntExt);
    lv_img_set_src(cui_DoughBallsQtyImg, &ui_img_3558094_bake_bread_fast_food_pizza_icon_png);
    lv_obj_set_width(cui_DoughBallsQtyImg, 48);
    lv_obj_set_height(cui_DoughBallsQtyImg, 48);
    lv_obj_set_x(cui_DoughBallsQtyImg, -345);
    lv_obj_set_y(cui_DoughBallsQtyImg, -189);
    lv_obj_set_align(cui_DoughBallsQtyImg, LV_ALIGN_CENTER);
    lv_obj_add_flag(cui_DoughBallsQtyImg, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(cui_DoughBallsQtyImg, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    lv_obj_t * cui_MiddleContainer;
    cui_MiddleContainer = lv_obj_create(cui_DoughballsCntExt);
    lv_obj_remove_style_all(cui_MiddleContainer);
    lv_obj_set_width(cui_MiddleContainer, 333);
    lv_obj_set_height(cui_MiddleContainer, lv_pct(100));
    lv_obj_set_x(cui_MiddleContainer, 1);
    lv_obj_set_y(cui_MiddleContainer, -22);
    lv_obj_set_align(cui_MiddleContainer, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(cui_MiddleContainer, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(cui_MiddleContainer, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_obj_clear_flag(cui_MiddleContainer, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_pad_left(cui_MiddleContainer, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(cui_MiddleContainer, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(cui_MiddleContainer, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(cui_MiddleContainer, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_Label1;
    cui_Label1 = lv_label_create(cui_MiddleContainer);
    lv_obj_set_width(cui_Label1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(cui_Label1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(cui_Label1, -256);
    lv_obj_set_y(cui_Label1, -218);
    lv_obj_set_align(cui_Label1, LV_ALIGN_CENTER);
    lv_label_set_text(cui_Label1, "Dough balls");

    lv_obj_t * cui_DoughballsQtyCnt;
    cui_DoughballsQtyCnt = lv_obj_create(cui_MiddleContainer);
    lv_obj_remove_style_all(cui_DoughballsQtyCnt);
    lv_obj_set_height(cui_DoughballsQtyCnt, 50);
    lv_obj_set_width(cui_DoughballsQtyCnt, lv_pct(100));
    lv_obj_set_x(cui_DoughballsQtyCnt, -194);
    lv_obj_set_y(cui_DoughballsQtyCnt, -184);
    lv_obj_set_align(cui_DoughballsQtyCnt, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(cui_DoughballsQtyCnt, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(cui_DoughballsQtyCnt, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(cui_DoughballsQtyCnt, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_pad_left(cui_DoughballsQtyCnt, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(cui_DoughballsQtyCnt, 15, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(cui_DoughballsQtyCnt, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(cui_DoughballsQtyCnt, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_DoughballsQtyLbl;
    cui_DoughballsQtyLbl = lv_label_create(cui_DoughballsQtyCnt);
    lv_obj_set_width(cui_DoughballsQtyLbl, 50);
    lv_obj_set_height(cui_DoughballsQtyLbl, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(cui_DoughballsQtyLbl, -287);
    lv_obj_set_y(cui_DoughballsQtyLbl, -36);
    lv_obj_set_align(cui_DoughballsQtyLbl, LV_ALIGN_CENTER);
    lv_label_set_text(cui_DoughballsQtyLbl, "");
    lv_obj_set_style_pad_left(cui_DoughballsQtyLbl, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(cui_DoughballsQtyLbl, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(cui_DoughballsQtyLbl, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(cui_DoughballsQtyLbl, 10, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t * cui_DoughballsQtySli;
    cui_DoughballsQtySli = lv_slider_create(cui_DoughballsQtyCnt);
    lv_slider_set_range(cui_DoughballsQtySli, 100, 1000);
    lv_slider_set_value(cui_DoughballsQtySli, 1000, LV_ANIM_OFF);
    if(lv_slider_get_mode(cui_DoughballsQtySli) == LV_SLIDER_MODE_RANGE) lv_slider_set_left_value(cui_DoughballsQtySli, 0,
                                                                                                      LV_ANIM_OFF);
    lv_obj_set_height(cui_DoughballsQtySli, 15);
    lv_obj_set_width(cui_DoughballsQtySli, lv_pct(100));
    lv_obj_set_x(cui_DoughballsQtySli, -242);
    lv_obj_set_y(cui_DoughballsQtySli, -41);
    lv_obj_set_align(cui_DoughballsQtySli, LV_ALIGN_CENTER);

    lv_obj_t ** children = lv_mem_alloc(sizeof(lv_obj_t *) * _UI_COMP_DOUGHBALLSCNTEXT_NUM);
    children[UI_COMP_DOUGHBALLSCNTEXT_DOUGHBALLSCNTEXT] = cui_DoughballsCntExt;
    children[UI_COMP_DOUGHBALLSCNTEXT_DOUGHBALLSQTYIMG] = cui_DoughBallsQtyImg;
    children[UI_COMP_DOUGHBALLSCNTEXT_MIDDLECONTAINER] = cui_MiddleContainer;
    children[UI_COMP_DOUGHBALLSCNTEXT_MIDDLECONTAINER_LABEL1] = cui_Label1;
    children[UI_COMP_DOUGHBALLSCNTEXT_MIDDLECONTAINER_DOUGHBALLSQTYCNT] = cui_DoughballsQtyCnt;
    children[UI_COMP_DOUGHBALLSCNTEXT_MIDDLECONTAINER_DOUGHBALLSQTYCNT_DOUGHBALLSQTYLBL] = cui_DoughballsQtyLbl;
    children[UI_COMP_DOUGHBALLSCNTEXT_MIDDLECONTAINER_DOUGHBALLSQTYCNT_DOUGHBALLSQTYSLI] = cui_DoughballsQtySli;
    lv_obj_add_event_cb(cui_DoughballsCntExt, get_component_child_event_cb, LV_EVENT_GET_COMP_CHILD, children);
    lv_obj_add_event_cb(cui_DoughballsCntExt, del_component_child_event_cb, LV_EVENT_DELETE, children);
    ui_comp_DoughballsCntExt_create_hook(cui_DoughballsCntExt);
    return cui_DoughballsCntExt;
}
