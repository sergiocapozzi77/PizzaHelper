
#ifndef RECIPESSCREEN_H
#define RECIPESSCREEN_H

#include "gui/gui.h"
#include "ui/ui.h"
#include <vector>
#include <Arduino.h>
#include "models/recipe.hpp"

void init_recipes();

class RecipesScreen
{
public:
    Recipe *recipes;
    void SetRecipe(Recipe recipe, lv_obj_t *recipePanel, lv_obj_t *title);
};

extern RecipesScreen recipesScreen;

#endif