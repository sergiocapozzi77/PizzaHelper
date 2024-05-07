
#ifndef CHATGPT_H
#define CHATGPT_H

#include <Arduino.h>
#include "models/recipe.hpp"

class ChatGpt
{

public:
    Recipe *GetRecipes(std::vector<String> ingredients);
};

extern ChatGpt chatGpt;

#endif