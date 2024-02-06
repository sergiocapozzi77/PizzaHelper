#include <Arduino.h>

#ifndef RECIPE_H
#define RECIPE_H

class Recipe
{
public:
    String selectedType;
    String selectedMethod;

    int water;
    int leveningTime;
    int fridgeTime;
};

extern Recipe recipe;

#endif