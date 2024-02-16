// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.4
// LVGL version: 8.2.0
// Project name: PizzaHelper1

#include "../ui.h"

void ui_Ingredients_screen_init(void)
{
    ui_Ingredients = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Ingredients, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Container4 = lv_obj_create(ui_Ingredients);
    lv_obj_remove_style_all(ui_Container4);
    lv_obj_set_width(ui_Container4, lv_pct(100));
    lv_obj_set_height(ui_Container4, lv_pct(100));
    lv_obj_set_align(ui_Container4, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Container4, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_Container4, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_obj_clear_flag(ui_Container4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_pad_left(ui_Container4, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Container4, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Container4, 20, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Container4, 20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PrefWaterCmp = ui_IngredientCmp_create(ui_Container4);
    lv_obj_set_x(ui_PrefWaterCmp, -183);
    lv_obj_set_y(ui_PrefWaterCmp, -92);

    lv_img_set_src(ui_comp_get_child(ui_PrefWaterCmp, UI_COMP_INGREDIENTCMP_DOUGHBALLSQTYIMG),
                   &ui_img_2995004_rain_water_drop_weather_cloud_icon_png);



    lv_label_set_text(ui_comp_get_child(ui_PrefWaterCmp,
                                        UI_COMP_INGREDIENTCMP_MIDDLECONTAINER_CONTAINER13_INGREDIENTNAMECMP), "Biga water percentage");

    lv_obj_set_style_pad_left(ui_comp_get_child(ui_PrefWaterCmp,
                                                UI_COMP_INGREDIENTCMP_MIDDLECONTAINER_INGREDIENTCMPCONTAINER), 15, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_comp_get_child(ui_PrefWaterCmp,
                                                 UI_COMP_INGREDIENTCMP_MIDDLECONTAINER_INGREDIENTCMPCONTAINER), 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_comp_get_child(ui_PrefWaterCmp,
                                               UI_COMP_INGREDIENTCMP_MIDDLECONTAINER_INGREDIENTCMPCONTAINER), 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_comp_get_child(ui_PrefWaterCmp,
                                                  UI_COMP_INGREDIENTCMP_MIDDLECONTAINER_INGREDIENTCMPCONTAINER), 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_slider_set_range(ui_comp_get_child(ui_PrefWaterCmp,
                                          UI_COMP_INGREDIENTCMP_MIDDLECONTAINER_INGREDIENTCMPCONTAINER_INGREDIENTCMPSLI), 45, 60);






    ui_PrefPercCmp = ui_IngredientCmp_create(ui_Container4);
    lv_obj_set_x(ui_PrefPercCmp, -183);
    lv_obj_set_y(ui_PrefPercCmp, -92);

    lv_img_set_src(ui_comp_get_child(ui_PrefPercCmp, UI_COMP_INGREDIENTCMP_DOUGHBALLSQTYIMG),
                   &ui_img_2824441_clock_stopwatch_time_timer_icon_png);



    lv_label_set_text(ui_comp_get_child(ui_PrefPercCmp,
                                        UI_COMP_INGREDIENTCMP_MIDDLECONTAINER_CONTAINER13_INGREDIENTNAMECMP), "Biga percentage in dough");



    lv_slider_set_range(ui_comp_get_child(ui_PrefPercCmp,
                                          UI_COMP_INGREDIENTCMP_MIDDLECONTAINER_INGREDIENTCMPCONTAINER_INGREDIENTCMPSLI), 50, 100);






    ui_DoughballWeightCmp = ui_IngredientCmp_create(ui_Container4);
    lv_obj_set_x(ui_DoughballWeightCmp, -183);
    lv_obj_set_y(ui_DoughballWeightCmp, -92);

    lv_img_set_src(ui_comp_get_child(ui_DoughballWeightCmp, UI_COMP_INGREDIENTCMP_DOUGHBALLSQTYIMG),
                   &ui_img_7450398_kitchen_utensils_scale_appliance_weight_icon_png);



    lv_label_set_text(ui_comp_get_child(ui_DoughballWeightCmp,
                                        UI_COMP_INGREDIENTCMP_MIDDLECONTAINER_CONTAINER13_INGREDIENTNAMECMP), "Dough balls weight");



    lv_slider_set_range(ui_comp_get_child(ui_DoughballWeightCmp,
                                          UI_COMP_INGREDIENTCMP_MIDDLECONTAINER_INGREDIENTCMPCONTAINER_INGREDIENTCMPSLI), 100, 1000);






    ui_DoughballQtyCmp = ui_IngredientCmp_create(ui_Container4);
    lv_obj_set_x(ui_DoughballQtyCmp, -182);
    lv_obj_set_y(ui_DoughballQtyCmp, -181);







    lv_slider_set_range(ui_comp_get_child(ui_DoughballQtyCmp,
                                          UI_COMP_INGREDIENTCMP_MIDDLECONTAINER_INGREDIENTCMPCONTAINER_INGREDIENTCMPSLI), 1, 20);






    ui_PanelIngredients = lv_obj_create(ui_Ingredients);
    lv_obj_set_width(ui_PanelIngredients, 357);
    lv_obj_set_height(ui_PanelIngredients, 447);
    lv_obj_set_x(ui_PanelIngredients, 206);
    lv_obj_set_y(ui_PanelIngredients, -1);
    lv_obj_set_align(ui_PanelIngredients, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_PanelIngredients, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_PanelIngredients, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_obj_clear_flag(ui_PanelIngredients, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_pad_left(ui_PanelIngredients, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_PanelIngredients, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_PanelIngredients, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_PanelIngredients, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_PanelIngredients, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_PrefPnl = lv_obj_create(ui_PanelIngredients);
    lv_obj_remove_style_all(ui_PrefPnl);
    lv_obj_set_height(ui_PrefPnl, 202);
    lv_obj_set_width(ui_PrefPnl, lv_pct(100));
    lv_obj_set_align(ui_PrefPnl, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_PrefPnl, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_PrefPnl, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_obj_clear_flag(ui_PrefPnl, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_IngrLbl1 = lv_label_create(ui_PrefPnl);
    lv_obj_set_width(ui_IngrLbl1, lv_pct(100));
    lv_obj_set_height(ui_IngrLbl1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_IngrLbl1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_IngrLbl1, "INGREDIENTS FOR BIGA");
    lv_obj_set_style_text_align(ui_IngrLbl1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_IngrLbl1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_IngrLbl1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_IngrLbl1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_IngrLbl1, 20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Container10 = lv_obj_create(ui_PrefPnl);
    lv_obj_remove_style_all(ui_Container10);
    lv_obj_set_width(ui_Container10, lv_pct(100));
    lv_obj_set_height(ui_Container10, LV_SIZE_CONTENT);    /// 50
    lv_obj_set_align(ui_Container10, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Container10, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Container10, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_obj_clear_flag(ui_Container10, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_pad_left(ui_Container10, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Container10, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Container10, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Container10, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label17 = lv_label_create(ui_Container10);
    lv_obj_set_width(ui_Label17, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label17, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label17, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label17, "Flour:");

    ui_FlourB = lv_label_create(ui_Container10);
    lv_obj_set_width(ui_FlourB, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_FlourB, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_FlourB, LV_ALIGN_CENTER);
    lv_label_set_text(ui_FlourB, "100");
    lv_obj_set_style_pad_left(ui_FlourB, 40, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_FlourB, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_FlourB, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_FlourB, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label15 = lv_label_create(ui_Container10);
    lv_obj_set_width(ui_Label15, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label15, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label15, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label15, "grams");
    lv_obj_set_style_pad_left(ui_Label15, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Label15, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Label15, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Label15, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Container1 = lv_obj_create(ui_PrefPnl);
    lv_obj_remove_style_all(ui_Container1);
    lv_obj_set_width(ui_Container1, lv_pct(100));
    lv_obj_set_height(ui_Container1, LV_SIZE_CONTENT);    /// 50
    lv_obj_set_align(ui_Container1, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Container1, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Container1, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_obj_clear_flag(ui_Container1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_pad_left(ui_Container1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Container1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Container1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Container1, 5, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label16 = lv_label_create(ui_Container1);
    lv_obj_set_width(ui_Label16, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label16, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label16, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label16, "Water:");

    ui_WaterB = lv_label_create(ui_Container1);
    lv_obj_set_width(ui_WaterB, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_WaterB, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_WaterB, LV_ALIGN_CENTER);
    lv_label_set_text(ui_WaterB, "100");
    lv_obj_set_style_pad_left(ui_WaterB, 40, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_WaterB, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_WaterB, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_WaterB, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label18 = lv_label_create(ui_Container1);
    lv_obj_set_width(ui_Label18, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label18, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label18, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label18, "grams");
    lv_obj_set_style_pad_left(ui_Label18, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Label18, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Label18, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Label18, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Container11 = lv_obj_create(ui_PrefPnl);
    lv_obj_remove_style_all(ui_Container11);
    lv_obj_set_width(ui_Container11, lv_pct(100));
    lv_obj_set_height(ui_Container11, LV_SIZE_CONTENT);    /// 50
    lv_obj_set_align(ui_Container11, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Container11, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Container11, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_obj_clear_flag(ui_Container11, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Label19 = lv_label_create(ui_Container11);
    lv_obj_set_width(ui_Label19, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label19, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label19, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label19, "Yeast:");

    ui_YeastB = lv_label_create(ui_Container11);
    lv_obj_set_width(ui_YeastB, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_YeastB, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_YeastB, LV_ALIGN_CENTER);
    lv_label_set_text(ui_YeastB, "100");
    lv_obj_set_style_pad_left(ui_YeastB, 40, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_YeastB, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_YeastB, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_YeastB, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label20 = lv_label_create(ui_Container11);
    lv_obj_set_width(ui_Label20, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label20, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label20, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label20, "grams");
    lv_obj_set_style_pad_left(ui_Label20, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Label20, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Label20, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Label20, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_IngrLbl = lv_label_create(ui_PanelIngredients);
    lv_obj_set_width(ui_IngrLbl, lv_pct(100));
    lv_obj_set_height(ui_IngrLbl, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_IngrLbl, LV_ALIGN_CENTER);
    lv_label_set_text(ui_IngrLbl, "INGREDIENTS");
    lv_obj_set_style_text_align(ui_IngrLbl, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_IngrLbl, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_IngrLbl, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_IngrLbl, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_IngrLbl, 20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Container2 = lv_obj_create(ui_PanelIngredients);
    lv_obj_remove_style_all(ui_Container2);
    lv_obj_set_height(ui_Container2, 21);
    lv_obj_set_width(ui_Container2, lv_pct(100));
    lv_obj_set_align(ui_Container2, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Container2, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Container2, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_obj_clear_flag(ui_Container2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Label2 = lv_label_create(ui_Container2);
    lv_obj_set_width(ui_Label2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label2, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label2, "Flour:");

    ui_FlourQ = lv_label_create(ui_Container2);
    lv_obj_set_width(ui_FlourQ, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_FlourQ, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_FlourQ, LV_ALIGN_CENTER);
    lv_label_set_text(ui_FlourQ, "100");
    lv_obj_set_style_pad_left(ui_FlourQ, 40, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_FlourQ, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_FlourQ, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_FlourQ, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label6 = lv_label_create(ui_Container2);
    lv_obj_set_width(ui_Label6, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label6, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label6, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label6, "grams");
    lv_obj_set_style_pad_left(ui_Label6, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Label6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Label6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Label6, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Container3 = lv_obj_create(ui_PanelIngredients);
    lv_obj_remove_style_all(ui_Container3);
    lv_obj_set_width(ui_Container3, lv_pct(100));
    lv_obj_set_height(ui_Container3, LV_SIZE_CONTENT);    /// 50
    lv_obj_set_align(ui_Container3, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Container3, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Container3, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_obj_clear_flag(ui_Container3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Label7 = lv_label_create(ui_Container3);
    lv_obj_set_width(ui_Label7, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label7, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label7, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label7, "Water:");

    ui_WaterQ = lv_label_create(ui_Container3);
    lv_obj_set_width(ui_WaterQ, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_WaterQ, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_WaterQ, LV_ALIGN_CENTER);
    lv_label_set_text(ui_WaterQ, "100");
    lv_obj_set_style_pad_left(ui_WaterQ, 40, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_WaterQ, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_WaterQ, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_WaterQ, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label8 = lv_label_create(ui_Container3);
    lv_obj_set_width(ui_Label8, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label8, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label8, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label8, "ml");
    lv_obj_set_style_pad_left(ui_Label8, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Label8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Label8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Label8, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Container8 = lv_obj_create(ui_PanelIngredients);
    lv_obj_remove_style_all(ui_Container8);
    lv_obj_set_width(ui_Container8, lv_pct(100));
    lv_obj_set_height(ui_Container8, LV_SIZE_CONTENT);    /// 50
    lv_obj_set_align(ui_Container8, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Container8, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Container8, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_obj_clear_flag(ui_Container8, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Label4 = lv_label_create(ui_Container8);
    lv_obj_set_width(ui_Label4, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label4, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label4, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label4, "Yeast:");

    ui_YeastQ = lv_label_create(ui_Container8);
    lv_obj_set_width(ui_YeastQ, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_YeastQ, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_YeastQ, LV_ALIGN_CENTER);
    lv_label_set_text(ui_YeastQ, "100");
    lv_obj_set_style_pad_left(ui_YeastQ, 40, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_YeastQ, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_YeastQ, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_YeastQ, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label5 = lv_label_create(ui_Container8);
    lv_obj_set_width(ui_Label5, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label5, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label5, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label5, "grams");
    lv_obj_set_style_pad_left(ui_Label5, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Label5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Label5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Label5, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Container6 = lv_obj_create(ui_PanelIngredients);
    lv_obj_remove_style_all(ui_Container6);
    lv_obj_set_width(ui_Container6, lv_pct(100));
    lv_obj_set_height(ui_Container6, LV_SIZE_CONTENT);    /// 50
    lv_obj_set_align(ui_Container6, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Container6, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Container6, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_obj_clear_flag(ui_Container6, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Label3 = lv_label_create(ui_Container6);
    lv_obj_set_width(ui_Label3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label3, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label3, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label3, "Salt:");

    ui_SaltQ = lv_label_create(ui_Container6);
    lv_obj_set_width(ui_SaltQ, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_SaltQ, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_SaltQ, LV_ALIGN_CENTER);
    lv_label_set_text(ui_SaltQ, "100");
    lv_obj_set_style_pad_left(ui_SaltQ, 40, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_SaltQ, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_SaltQ, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_SaltQ, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label9 = lv_label_create(ui_Container6);
    lv_obj_set_width(ui_Label9, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label9, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label9, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label9, "grams");
    lv_obj_set_style_pad_left(ui_Label9, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Label9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Label9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Label9, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Container7 = lv_obj_create(ui_PanelIngredients);
    lv_obj_remove_style_all(ui_Container7);
    lv_obj_set_width(ui_Container7, lv_pct(100));
    lv_obj_set_height(ui_Container7, LV_SIZE_CONTENT);    /// 50
    lv_obj_set_align(ui_Container7, LV_ALIGN_CENTER);
    lv_obj_set_flex_flow(ui_Container7, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(ui_Container7, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_obj_clear_flag(ui_Container7, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Label10 = lv_label_create(ui_Container7);
    lv_obj_set_width(ui_Label10, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label10, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label10, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label10, "Oil:");

    ui_OilQ = lv_label_create(ui_Container7);
    lv_obj_set_width(ui_OilQ, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_OilQ, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_OilQ, LV_ALIGN_CENTER);
    lv_label_set_text(ui_OilQ, "100");
    lv_obj_set_style_pad_left(ui_OilQ, 40, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_OilQ, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_OilQ, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_OilQ, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label11 = lv_label_create(ui_Container7);
    lv_obj_set_width(ui_Label11, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label11, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label11, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label11, "ml");
    lv_obj_set_style_pad_left(ui_Label11, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Label11, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Label11, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Label11, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_BtnPrev2 = lv_btn_create(ui_Ingredients);
    lv_obj_set_width(ui_BtnPrev2, 100);
    lv_obj_set_height(ui_BtnPrev2, 50);
    lv_obj_set_x(ui_BtnPrev2, -333);
    lv_obj_set_y(ui_BtnPrev2, 199);
    lv_obj_set_align(ui_BtnPrev2, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_BtnPrev2, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_BtnPrev2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Label22 = lv_label_create(ui_BtnPrev2);
    lv_obj_set_width(ui_Label22, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label22, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Label22, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label22, "PREV");

}
