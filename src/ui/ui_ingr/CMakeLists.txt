SET(SOURCES components/ui_comp_ingredientcmp.c
    components/ui_comp.c
    screens/ui_PreIngredients.c
    screens/ui_Ingredients.c
    ui.c
    components/ui_comp_hook.c
    ui_helpers.c
    ui_events.c
    images/ui_img_pizza_back01_png.c
    images/ui_img_3558094_bake_bread_fast_food_pizza_icon_png.c
    images/ui_img_2995004_rain_water_drop_weather_cloud_icon_png.c
    images/ui_img_3856401_celsius_degrees_temperature_thermometer_weather_icon_png.c
    images/ui_img_2824441_clock_stopwatch_time_timer_icon_png.c
    images/ui_img_10673486_fridge_kitchen_refrigerator_food_and_icon_png.c
    images/ui_img_8726048_home_icon_png.c
    images/ui_img_7450398_kitchen_utensils_scale_appliance_weight_icon_png.c)

add_library(ui ${SOURCES})
