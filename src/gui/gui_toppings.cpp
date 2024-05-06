#include "gui_toppings.h"
// #include "chatgpt.hpp"
#include "../ingredients.hpp"
#include <Arduino.h>
#include "models/recipe.hpp"
#include "uicomponents.h"

Toppings toppings;

void IngredientsTextReady(lv_event_t *e)
{
    lv_obj_t *ta = lv_event_get_target(e);
    if (e->code == LV_EVENT_READY)
    {
        lv_indev_reset(NULL, ta);
    }
}

void GetRecipeButtonClicked(lv_event_t *e)
{
    Serial.println("Getting recipe button click");
}

void IngredientsTextValueChanged(lv_event_t *e)
{
    toppings.IngredientsTextValueChanged(e);
}

void GetRecipesClicked(lv_event_t *e)
{
}

void init_toppings()
{
    lv_obj_add_event_cb(ui_IngredientText, IngredientsTextValueChanged, LV_EVENT_VALUE_CHANGED, NULL);
    lv_obj_add_event_cb(ui_BtnRecipes, GetRecipesClicked, LV_EVENT_CLICKED, NULL);
}

void suggestedIngredientClicked(lv_event_t *e)
{
    toppings.SuggestedIngredientClicked(e);
}

void Toppings::SuggestedIngredientClicked(lv_event_t *e)
{
    lv_obj_t *target = lv_event_get_target(e);
    const char *ingredient = lv_label_get_text(lv_obj_get_child(target, 0));
    createChip(ui_AvailableIngredientsPanel, ingredient);
    lv_obj_add_flag(ui_IngredientsSuggestionPanel, LV_OBJ_FLAG_HIDDEN); /// Flags
    lv_textarea_set_text(ui_IngredientText, "");

    this->availableIngredients.push_back(String(ingredient));
}

void Toppings::IngredientsTextValueChanged(lv_event_t *e)
{
    Serial.println("IngredientsTextValueChanged");
    lv_obj_t *ta = lv_event_get_target(e);
    const char *text = lv_textarea_get_text(ta);
    if (strlen(text) > 1)
    {
        std::vector<String> list = ingredients.GetIngredientsStartingWith(text);
        if (list.size() > 0)
        {
            lv_obj_clean(ui_IngredientsSuggestionPanel);
            for (int i = 0; i < list.size(); i++)
            {
                createButtonWithText(ui_IngredientsSuggestionPanel, list[i].c_str(), suggestedIngredientClicked);
            }
            lv_obj_clear_flag(ui_IngredientsSuggestionPanel, LV_OBJ_FLAG_HIDDEN); /// Flags
        }
        else
        {
            lv_obj_add_flag(ui_IngredientsSuggestionPanel, LV_OBJ_FLAG_HIDDEN); /// Flags
        }
    }
    else
    {
        lv_obj_add_flag(ui_IngredientsSuggestionPanel, LV_OBJ_FLAG_HIDDEN); /// Flags
    }
}
