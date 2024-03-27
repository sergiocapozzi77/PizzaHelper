#include <Arduino.h>

#ifndef RECIPE_H
#define RECIPE_H

class Recipe
{
private:
    double AdjustYeast(double yeast);
    int CalculateBigaTimeMinutes();
    String GetPreferenceKey(const char *key);
    String selectedType;
    String selectedMethod;
    String selectedYeast;

public:
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
    bool UseDoughMachine;
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
    void UpdateReadyToBakeTime();
    void SetUseDoughMachine(boolean value);
    void SetScreen(const char *screen);
    void GoToScreen();

    void SetSelectedType(String type);

    String GetSelectedType()
    {
        return this->selectedType;
    }

    void SetSelectedMethod(String method);

    String GetSelectedMethod()
    {
        return this->selectedMethod;
    }

    void SetSelectedYeast(String yeast);

    String GetSelectedYeast()
    {
        return this->selectedYeast;
    }
};

extern Recipe recipe;

#endif