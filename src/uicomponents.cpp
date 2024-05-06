#include "ui/ui.h"

lv_obj_t *createButtonWithText(lv_obj_t *parent, const char *text, void (*ui_event_click)(lv_event_t *e))
{
    lv_obj_t *ui_SuggestionButton = lv_btn_create(parent);
    lv_obj_set_width(ui_SuggestionButton, 168);
    lv_obj_set_height(ui_SuggestionButton, 30);
    lv_obj_set_x(ui_SuggestionButton, -177);
    lv_obj_set_y(ui_SuggestionButton, 64);
    lv_obj_set_align(ui_SuggestionButton, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_SuggestionButton, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_SuggestionButton, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_add_flag(ui_SuggestionButton, LV_OBJ_FLAG_SCROLL_ON_FOCUS); /// Flags
    lv_obj_clear_flag(ui_SuggestionButton, LV_OBJ_FLAG_SCROLLABLE);    /// Flags
    lv_obj_set_style_bg_color(ui_SuggestionButton, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_SuggestionButton, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_SuggestionButton, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_SuggestionButton, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t *ui_SuggestionText = lv_label_create(ui_SuggestionButton);
    lv_obj_set_width(ui_SuggestionText, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(ui_SuggestionText, LV_SIZE_CONTENT); /// 1
    lv_obj_set_align(ui_SuggestionText, LV_ALIGN_CENTER);
    lv_label_set_text(ui_SuggestionText, text);
    lv_obj_set_style_text_color(ui_SuggestionText, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_SuggestionText, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_add_event_cb(ui_SuggestionButton, ui_event_click, LV_EVENT_CLICKED, NULL);
    return ui_SuggestionButton;
}

lv_obj_t *createChip(lv_obj_t *parent, const char *text)
{
    lv_obj_t *chip = lv_obj_create(parent);
    lv_obj_set_width(chip, LV_SIZE_CONTENT); /// 100
    lv_obj_set_height(chip, 35);
    lv_obj_set_align(chip, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(chip, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(chip, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_clear_flag(chip, LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_radius(chip, 30, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(chip, lv_color_hex(0xEEEEEE), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(chip, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(chip, lv_color_hex(0x848484), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(chip, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(chip, 1, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t *close = lv_label_create(chip);
    lv_obj_set_width(close, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(close, LV_SIZE_CONTENT); /// 1
    lv_obj_set_align(close, LV_ALIGN_CENTER);
    lv_label_set_text(close, "x");

    lv_obj_t *chiptext = lv_label_create(chip);
    lv_obj_set_width(chiptext, LV_SIZE_CONTENT);  /// 1
    lv_obj_set_height(chiptext, LV_SIZE_CONTENT); /// 1
    lv_obj_set_align(chiptext, LV_ALIGN_CENTER);
    lv_label_set_text(chiptext, text);

    return chip;
}