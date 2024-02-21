#include <Arduino.h>

#ifndef RECIPE_H
#define RECIPE_H

class Recipe
{
private:
    double AdjustYeast(double yeast);

public:
    String selectedType;
    String selectedMethod;
    String selectedYeast;

    int WaterPerc;
    int TotalLeavening;
    int FridgeLeavening;
    float SaltPerc;
    float FatPerc;
    int DoughBalls;
    int BallWeight;
    int RoomTemperature;
    bool IsTray;
    bool UseTheFridge;
    int BigaPercentage;
    int BigaWaterPerc;
    int PoolPercentage;

    int Flour;
    int Water;
    float Yeast;
    int Salt;
    int Fat;

    int FlourBiga;
    int WaterBiga;
    float YeastBiga;

    int FlourPool;
    int WaterPool;
    float YeastPool;

    void IntializeIngredients();
    void Recalculate();

    int GetPrefWaterPercentage();
    int GetPrefPercentage();

    void SetPrefPercentage(int value);
    void SetPrefWaterPercentage(int value);

    void SaveToPreferences();
    void AddTimeline();
};

extern Recipe recipe;

#endif