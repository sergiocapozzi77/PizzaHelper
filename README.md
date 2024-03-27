# Getting started with the Sunton ESP32-S3 7 inch display, LovyanGFX and LVGL

Simple demo application how to use this display with LovyanGFX and LVGL.

Some more explanation you can find on https://www.haraldkreuzer.net/en/news/getting-started-makerfabs-esp32-s3-7-inch-display-lovyangfx-and-lvgl

del .\src\ui\ui_main\screens\ui_Ingredients.c
del .\src\ui\ui_main\screens\ui_PreIngredients.c
del .\src\ui\ui_ingr\ui_helpers.c
del .\src\ui\ui_ingr\images\ui_img_pizza_back01_png.c

uint32_t LV_EVENT_GET_COMP_CHILD;
void ui_init(void)
{
LV_EVENT_GET_COMP_CHILD = lv_event_register_id();
