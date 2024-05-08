#include "recipes_screen.hpp"
#include "chatgpt.hpp"
#include "../ingredients.hpp"
#include <Arduino.h>
#include "models/recipe.hpp"
// #include "stepbystep_screen.hpp"

void RecipesScreenLoaded(lv_event_t *e);
void loadRecipes();
RecipesScreen recipesScreen;

void init_recipes()
{
    lv_obj_add_event_cb(ui_Recipes, RecipesScreenLoaded, LV_EVENT_SCREEN_LOADED, NULL);
}

void RecipesScreenLoaded(lv_event_t *e)
{
    recipesScreen.LoadRecipes();
}

void RecipesScreen::LoadRecipes()
{
    SetRecipe(recipes[0], ui_Ingredients1, ui_Title1);
    SetRecipe(recipes[1], ui_Ingredients2, ui_Title2);
    SetRecipe(recipes[2], ui_Ingredients3, ui_Title3);
}

void RecipesScreen::SetRecipe(Recipe recipe, lv_obj_t *ingredients, lv_obj_t *title)
{
    String allIngredients = recipe.GetIngredients();

    allIngredients += "\n\nMethod:\n\n";

    for (int i = 0; i < recipe.method.size(); i++)
    {
        allIngredients = allIngredients + recipe.method[i] + String("\n");
    }

    lv_label_set_text(title, recipe.title.c_str());
    lv_label_set_text(ingredients, allIngredients.c_str());
}