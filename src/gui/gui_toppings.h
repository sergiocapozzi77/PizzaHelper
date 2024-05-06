#include "ui/ui.h"
#include "gui/gui.h"
#include "ui/ui.h"
#include <vector>
#include <Arduino.h>
#include "models/recipe.hpp"

#ifndef GUITOPPINGS_H
#define GUITOPPINGS_H

void init_toppings();

class Toppings
{
    void ui_event_click(lv_event_t *e);
    std::vector<String> availableIngredients;

public:
    std::vector<String> GetAvailableIngredients() { return availableIngredients; }
    void SuggestedIngredientClicked(lv_event_t *e);
    void IngredientsTextValueChanged(lv_event_t *e);
};

extern Toppings toppings;

#endif