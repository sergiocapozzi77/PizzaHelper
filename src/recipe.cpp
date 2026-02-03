
#include "recipe.hpp"

#include "ui/ui.h"
#include "gui/gui.h"

#include "timehelper.hpp"
#include <Arduino.h>

Recipe recipe;

#define WATERPERCMACHINE 0.63F

int Recipe::GetPrefWaterPercentage()
{
    if (this->selectedMethod == "Direct")
    {
        return 0;
    }
    else if (this->selectedMethod == "Biga" || this->selectedMethod == "BigaPoolish")
    {
        return this->BigaWaterPerc;
    }
    else if (this->selectedMethod == "Poolish")
    {
        return 50;
    }

    return 0;
}

void Recipe::SetPrefWaterPercentage(int value)
{
    if (this->selectedMethod == "Direct")
    {
        return;
    }
    else if (this->selectedMethod || this->selectedMethod == "BigaPoolish")
    {
        this->BigaWaterPerc = value;
    }
    else if (this->selectedMethod == "Poolish")
    {
        return;
    }
}

int Recipe::GetPrefPercentage()
{
    if (this->selectedMethod == "Direct")
    {
        return 0;
    }
    else if (this->selectedMethod == "Biga" || this->selectedMethod == "BigaPoolish")
    {
        return this->BigaPercentage;
    }
    else if (this->selectedMethod == "Poolish")
    {
        return this->PoolPercentage;
    }
    return 0;
}

void Recipe::SetPrefPercentage(int value)
{
    if (this->selectedMethod == "Direct")
    {
        return;
    }
    else if (this->selectedMethod == "Biga" || this->selectedMethod == "BigaPoolish")
    {
        this->BigaPercentage = value;
    }
    else if (this->selectedMethod == "Poolish")
    {
        this->PoolPercentage = value;
    }
}

void Recipe::SetUseDoughMachine(boolean value)
{
    UseDoughMachine = value;
    preferences.putBool("UseMachine", UseDoughMachine);
    AddTimeline();
}

void Recipe::SaveToPreferences()
{
    preferences.putInt(GetPreferenceKey("WaterPerc").c_str(), WaterPerc);
    preferences.putInt(GetPreferenceKey("TotalLeave").c_str(), TotalLeavening);
    preferences.putInt(GetPreferenceKey("FridgeLeave").c_str(), FridgeLeavening);

    preferences.putFloat(GetPreferenceKey("SaltPerc").c_str(), SaltPerc);
    preferences.putFloat(GetPreferenceKey("FatPerc").c_str(), FatPerc);

    preferences.putInt(GetPreferenceKey("DoughBalls").c_str(), DoughBalls);
    Serial.print("Set DoughBalls key: ");
    Serial.println(GetPreferenceKey("DoughBalls"));

    preferences.putInt(GetPreferenceKey("BallWeight").c_str(), BallWeight);
    preferences.putInt(GetPreferenceKey("RoomTemp").c_str(), RoomTemperature);

    preferences.putBool(GetPreferenceKey("IsTray").c_str(), IsTray);
    preferences.putBool(GetPreferenceKey("UseTheFridge").c_str(), UseTheFridge);
    preferences.putBool("UseMachine", UseDoughMachine);

    preferences.putInt(GetPreferenceKey("BigaPerc").c_str(), BigaPercentage);
    preferences.putInt(GetPreferenceKey("BigaWtrPrc").c_str(), BigaWaterPerc);
    preferences.putInt(GetPreferenceKey("PoolPerc").c_str(), PoolPercentage);
}

void Recipe::SetScreen(const char *screen)
{
    preferences.putString("ActiveScreen", screen);
}

void Recipe::SetSelectedType(String type)
{
    this->selectedType = type;
    preferences.putString("selType", type);
}

void Recipe::SetSelectedMethod(String method)
{
    this->selectedMethod = method;
    preferences.putString(GetPreferenceKey("selMethod").c_str(), method);
}

void Recipe::SetSelectedYeast(String yeast)
{
    this->selectedYeast = yeast;
    preferences.putString(GetPreferenceKey("selYeast").c_str(), yeast);
}

void Recipe::GoToScreen()
{
    String activeScreen = preferences.getString("ActiveScreen", "");
    if (activeScreen == "")
    {
        return;
    }

    this->selectedType = preferences.getString("selType");
    this->selectedMethod = preferences.getString(GetPreferenceKey("selMethod").c_str(), "");
    this->selectedYeast = preferences.getString(GetPreferenceKey("selYeast").c_str(), "");

    recipe.IntializeIngredients();
    if (activeScreen == "Home")
    {
        _ui_screen_change(&ui_Home, LV_SCR_LOAD_ANIM_NONE, 0, 0, &ui_Home_screen_init);
    }
    else if (activeScreen == "Timeline")
    {
        _ui_screen_change(&ui_Timeline, LV_SCR_LOAD_ANIM_NONE, 0, 0, &ui_Timeline_screen_init);
    }
    else if (activeScreen == "PizzaType")
    {
        _ui_screen_change(&ui_PizzaType, LV_SCR_LOAD_ANIM_NONE, 0, 0, &ui_PizzaType_screen_init);
    }
    else if (activeScreen == "Method")
    {
        _ui_screen_change(&ui_Method, LV_SCR_LOAD_ANIM_NONE, 0, 0, &ui_Method_screen_init);
    }
    else if (activeScreen == "Yeast")
    {
        _ui_screen_change(&ui_Yeast, LV_SCR_LOAD_ANIM_NONE, 0, 0, &ui_Yeast_screen_init);
    }
    else if (activeScreen == "PreIngredients")
    {
        _ui_screen_change(&ui_PreIngredients, LV_SCR_LOAD_ANIM_NONE, 0, 0, &ui_PreIngredients_screen_init);
    }
    else if (activeScreen == "Ingredients")
    {
        _ui_screen_change(&ui_Ingredients, LV_SCR_LOAD_ANIM_NONE, 0, 0, &ui_Ingredients_screen_init);
    }
}

void Recipe::AddTimeline()
{
    lv_obj_clean(ui_PanelTimeline);

    time_t localTimeNow = getTime();
    if (localTimeNow == NULL)
    {
        Serial.println("Failed to obtain time");
    }

    tm *localTmNow = gmtime(&localTimeNow);

    char buf[100];

    Serial.println("Add timeline");
    if (this->selectedMethod == "Direct")
    {
        strftime(buf, 100, "%A, %H:%M Start kneading the dough", localTmNow);
        addTimeline(buf);
        int doughPrepTimeMinutes;

        time_t lastFold;
        if (this->UseDoughMachine)
        {

            int water = this->Flour * WATERPERCMACHINE;
            if (water > this->Water)
            {
                addTimeline(String("Add all flour and all water in the machine and knead until the \"pumpkin\" is formed").c_str());
            }
            else
            {
                addTimeline((String("Add all flour and ") + String(water) + "gr of water and start the machine").c_str());
                addTimeline((String("When the \"pumpkin\" is formed, add the remaining ") + String(Water - water) + "gr of water slowly").c_str());
            }

            lastFold = AddMinutes(localTimeNow, 15);

            doughPrepTimeMinutes - 15;
        }
        else
        {

            time_t firstFold = AddMinutes(localTimeNow, 45);
            strftime(buf, 100, "%A, %H:%M First fold", gmtime(&firstFold));
            addTimeline(buf);

            time_t secondFold = AddMinutes(firstFold, 25);
            strftime(buf, 100, "%A, %H:%M Second fold", gmtime(&secondFold));
            addTimeline(buf);

            lastFold = AddMinutes(secondFold, 25);
            strftime(buf, 100, "%A, %H:%M Third fold", gmtime(&lastFold));
            addTimeline(buf);

            doughPrepTimeMinutes = 45 + 25 + 25;
        }

        time_t puntataStart = AddMinutes(lastFold, 5);
        strftime(buf, 100, "%A, %H:%M Leave the mass to rest", gmtime(&puntataStart));
        addTimeline(buf);

        time_t puntataEnd = AddMinutes(puntataStart, 60);

        time_t split = puntataEnd;
        if (UseTheFridge)
        {
            strftime(buf, 100, "%A, %H:%M Put the mass in the fridge", gmtime(&puntataEnd));
            addTimeline(buf);

            time_t fridgeEnd = AddHours(TotalLeavening - 4, puntataStart);
            strftime(buf, 100, "%A, %H:%M Remove from the fridge", gmtime(&fridgeEnd));
            addTimeline(buf);
            split = AddMinutes(fridgeEnd, 5);
        }

        strftime(buf, 100, "%A, %H:%M Split the dough", gmtime(&split));
        addTimeline(buf);

        time_t ready = AddHours(localTimeNow, recipe.TotalLeavening);
        strftime(buf, 100, "%A, %H:%M Ready to bake!", gmtime(&ready));
        addTimeline(buf);
    }
    else if (this->selectedMethod == "Biga")
    {
        strftime(buf, 100, "%A, %H:%M Start making the biga", localTmNow);
        addTimeline(buf);

        int minutesBiga = CalculateBigaTimeMinutes();
        time_t bigaReady = AddMinutes(localTimeNow, minutesBiga);
        if (this->UseDoughMachine)
        {
            strftime(buf, 100, "%A, %H:%M Start kneading the dough", gmtime(&bigaReady));
            addTimeline(buf);

            int allFlour = this->Flour + this->FlourBiga;
            int allWater = this->Water + this->WaterBiga;
            int waterForZucca = allFlour * WATERPERCMACHINE;

            if (waterForZucca < this->WaterBiga)
            {
                addTimeline((String("Add all the biga and all the flour in the machine and knead until the \"pumpkin\" is formed").c_str()));
            }
            else
            {
                addTimeline((String("Add all the biga, all the flour and ") + String(waterForZucca - this->WaterBiga) + "gr of water and start the machine").c_str());
            }

            int remainingWater = allWater - waterForZucca;
            if (remainingWater > 0)
            {
                addTimeline((String("When the \"pumpkin\" is formed, add the remaining ") + String(remainingWater) + "gr of water slowly").c_str());
            }
        }
        else
        {
            strftime(buf, 100, "%A, %H:%M Biga is ready, add the other ingredients and make the dough", gmtime(&bigaReady));
            addTimeline(buf);
        }

        time_t ready = AddHours(bigaReady, 4);
        strftime(buf, 50, "Pizza ready to bake on: %A, %H:%M", gmtime(&ready));
    }
    else if (this->selectedMethod == "Poolish")
    {
        strftime(buf, 100, "%A, %H:%M Start making the biga", localTmNow);
        addTimeline(buf);

        int minutesBiga = CalculateBigaTimeMinutes();
        time_t poolReady = AddMinutes(localTimeNow, minutesBiga);
        if (this->UseDoughMachine)
        {
            strftime(buf, 100, "%A, %H:%M Start kneading the dough", gmtime(&poolReady));
            addTimeline(buf);

            int allFlour = this->Flour + this->FlourPool;
            int allWater = this->Water + this->WaterPool;
            int waterForZucca = allFlour * WATERPERCMACHINE;

            if (waterForZucca < this->WaterPool)
            {
                addTimeline((String("Add all the poolish and all the flour in the machine and knead until the \"pumpkin\" is formed").c_str()));
            }
            else
            {
                addTimeline((String("Add all the poolish, all the flour and ") + String(waterForZucca - this->WaterPool) + "gr of water and start the machine").c_str());
            }

            int remainingWater = allWater - waterForZucca;
            if (remainingWater > 0)
            {
                addTimeline((String("When the \"pumpkin\" is formed, add the remaining ") + String(remainingWater) + "gr of water slowly").c_str());
            }
        }
        else
        {
            strftime(buf, 100, "%A, %H:%M Poolish is ready, add the other ingredients and make the dough", gmtime(&poolReady));
            addTimeline(buf);
        }

        time_t ready = AddHours(poolReady, 4);
        strftime(buf, 50, "Pizza ready to bake on: %A, %H:%M", gmtime(&ready));
    }
    else if (this->selectedMethod == "BigaPoolish")
    {
        strftime(buf, 100, "%A, %H:%M Start making the biga and the poolish", localTmNow);
        addTimeline(buf);

        int minutesBiga = CalculateBigaTimeMinutes();
        time_t poolReady = AddMinutes(localTimeNow, minutesBiga);
        if (this->UseDoughMachine)
        {
            strftime(buf, 100, "%A, %H:%M Start kneading the dough", gmtime(&poolReady));
            addTimeline(buf);

            int allFlour = this->Flour + this->FlourPool + this->FlourBiga;
            int allWater = this->Water + this->WaterPool + this->WaterBiga;
            int waterForZucca = allFlour * WATERPERCMACHINE;

            if (waterForZucca < (this->WaterPool + this->WaterBiga))
            {
                addTimeline((String("Add all the poolish and biga and all the flour in the machine and knead until the \"pumpkin\" is formed").c_str()));
            }
            else
            {
                addTimeline((String("Add all the poolish and biga, all the flour and ") + String(waterForZucca - this->WaterPool - this->WaterBiga) + "gr of water and start the machine").c_str());
            }

            int remainingWater = allWater - waterForZucca;
            if (remainingWater > 0)
            {
                addTimeline((String("When the \"pumpkin\" is formed, add the remaining ") + String(min(this->Water, remainingWater)) + "gr of water slowly").c_str());
            }
        }
        else
        {
            strftime(buf, 100, "%A, %H:%M Poolish and Biga is ready, add the other ingredients and make the dough", gmtime(&poolReady));
            addTimeline(buf);
        }

        time_t ready = AddHours(poolReady, 4);
        strftime(buf, 50, "Pizza ready to bake on: %A, %H:%M", gmtime(&ready));
    }
}

void Recipe::UpdateReadyToBakeTime()
{
    time_t localTimeNow = getTime();
    char buf[50];

    if (this->selectedMethod == "Direct")
    {
        time_t ready = AddHours(localTimeNow, recipe.TotalLeavening);
        strftime(buf, 50, "Pizza ready to bake on: %A, %H:%M", gmtime(&ready));
        lv_label_set_text(ui_PizzaReadyLbl, buf);
        lv_obj_add_flag(ui_StarterReadyLbl, LV_OBJ_FLAG_HIDDEN);
    }
    else if (this->selectedMethod == "Biga")
    {
        int minutesBiga = CalculateBigaTimeMinutes();
        time_t bigaReady = AddMinutes(localTimeNow, minutesBiga);
        strftime(buf, 50, "Biga ready on: %A, %H:%M", gmtime(&bigaReady));
        lv_label_set_text(ui_StarterReadyLbl, buf);

        time_t ready = AddHours(bigaReady, 4);
        strftime(buf, 50, "Pizza ready to bake on: %A, %H:%M", gmtime(&ready));
        lv_label_set_text(ui_PizzaReadyLbl, buf);
        lv_obj_clear_flag(ui_StarterReadyLbl, LV_OBJ_FLAG_HIDDEN);
    }
    else if (this->selectedMethod == "Poolish")
    {
    }
}

String Recipe::GetPreferenceKey(const char *key)
{
    return this->selectedType.substring(0, 1) + String(".") + String(key);
}

int Recipe::CalculateBigaTimeMinutes()
{
    return 18 * 60 + (18 - RoomTemperature) * 35;
}

void Recipe::IntializeIngredients()
{
    Serial.println("Intialize Ingredients");

    UseTheFridge = preferences.getBool(GetPreferenceKey("UseTheFridge").c_str(), false);
    UseDoughMachine = preferences.getBool("UseMachine", false);
    TotalLeavening = preferences.getInt(GetPreferenceKey("TotalLeave").c_str(), 8);
    FridgeLeavening = preferences.getInt(GetPreferenceKey("FridgeLeave").c_str(), 0);
    SaltPerc = preferences.getFloat(GetPreferenceKey("SaltPerc").c_str(), 2.8);
    FatPerc = preferences.getFloat(GetPreferenceKey("FatPerc").c_str(), 2.7);
    DoughBalls = preferences.getInt(GetPreferenceKey("DoughBalls").c_str(), 1);
    Serial.print("DoughBalls key: ");
    Serial.println(GetPreferenceKey("DoughBalls"));
    Serial.println(DoughBalls);
    BallWeight = preferences.getInt(GetPreferenceKey("BallWeight").c_str(), 270);
    RoomTemperature = preferences.getInt(GetPreferenceKey("RoomTemp").c_str(), 21);

    BigaPercentage = preferences.getInt(GetPreferenceKey("BigaPerc").c_str(), 60);
    BigaWaterPerc = preferences.getInt(GetPreferenceKey("BigaWtrPrc").c_str(), 45);

    PoolPercentage = preferences.getInt(GetPreferenceKey("PoolPerc").c_str(), 60);

    if (this->selectedType == "Round")
    {
        this->IsTray = false;
    }
    else
    {
        this->IsTray = true;
    }

    if (this->selectedType == "Round")
    {
        WaterPerc = preferences.getInt(GetPreferenceKey("WaterPerc").c_str(), 65);
    }
    else if (this->selectedType == "Grandma")
    {
        WaterPerc = preferences.getInt(GetPreferenceKey("WaterPerc").c_str(), 75);
    }
    else if (this->selectedType == "Detroit")
    {
        WaterPerc = preferences.getInt(GetPreferenceKey("WaterPerc").c_str(), 75);
    }
    else if (this->selectedType == "Bread")
    {
        WaterPerc = preferences.getInt(GetPreferenceKey("WaterPerc").c_str(), 70);
    }
    else if (this->selectedType == "Focaccia")
    {
        WaterPerc = preferences.getInt(GetPreferenceKey("WaterPerc").c_str(), 75);
    }

    Recalculate();
}

void Recipe::Recalculate()
{
    Serial.print("Water: ");
    Serial.println(WaterPerc);

    Serial.print("TotalLeavening: ");
    Serial.println(TotalLeavening);

    Serial.print("FridgeLeavening: ");
    Serial.println(FridgeLeavening);

    Serial.print("Weight: ");
    Serial.println(BallWeight);

    Serial.print("Temperature: ");
    Serial.println(RoomTemperature);

    Serial.print("UseTheFridge: ");
    Serial.println(UseTheFridge);

    if (UseTheFridge == true && this->TotalLeavening > 4)
    {
        this->FridgeLeavening = this->TotalLeavening - 4;
    }

    int i = this->TotalLeavening;
    int s = this->FridgeLeavening;
    if (TotalLeavening > 8)
    {
        FridgeLeavening = TotalLeavening - 4;
    }
    else
    {
        FridgeLeavening = 0;
    }

    float l = this->SaltPerc * 10;
    float d = this->FatPerc * 10;
    int t = this->WaterPerc;
    int r = this->DoughBalls;
    int e = this->BallWeight;
    float g = 0.005;
    int v = 0;
    int p = this->RoomTemperature;
    int o = this->IsTray ? 1 : 0;
    float n = p * (1 - .25 * o);

    float c = i - 9 * s / 10.0;
    float N = 81.4206918743428 + 78.3939060802556 * log10(i);
    float m = 10 * round(N / 10.0);
    float h = 2250 * (1 + l / 200) * (1 + d / 300) / ((4.2 * t - 80 - .0305 * t * t) * pow(n, 2.5) * pow(c, 1.2));
    float u = r * e;
    float C = t * (l + d) + 1e3 * (t + 100);

    float f = u * v / 100;
    float flour = 1e5 * (u - f) / C;
    float water = (1e3 * t * (u - f) / C);
    float salt = (l * t * (u - f) / C);
    float fat = (d * t * (u - f) / C);
    float yeast = (flour * h - g * f);

    if (this->selectedMethod == "Direct")
    {
        this->Flour = flour;
        this->Water = water;
        this->Yeast = AdjustYeast(yeast);
        this->Salt = salt;
        this->Fat = fat;
    }
    else if (this->selectedMethod == "Biga")
    {
        this->FlourBiga = flour * (this->BigaPercentage / 100.0F);
        this->WaterBiga = this->FlourBiga * this->BigaWaterPerc / 100.0F;
        this->Water = water - this->WaterBiga;
        this->YeastBiga = AdjustYeast(this->FlourBiga * 0.01);
        this->Flour = flour - this->FlourBiga;
        this->Salt = salt;
        this->Fat = fat;
        this->Yeast = 0;

        lv_label_set_text(ui_WaterB, String(WaterBiga).c_str());
        lv_label_set_text(ui_FlourB, String(FlourBiga).c_str());
        lv_label_set_text(ui_YeastB, String(YeastBiga).c_str());
    }
    else if (this->selectedMethod == "Poolish")
    {
        this->WaterPool = water * (this->PoolPercentage / 100.0F);
        this->FlourPool = this->WaterPool;
        this->Water = water - this->WaterPool;
        this->YeastPool = AdjustYeast(this->FlourPool * 0.02);
        this->Flour = flour - this->FlourPool;
        this->Salt = salt;
        this->Fat = fat;
        this->Yeast = 0;

        lv_label_set_text(ui_WaterB, String(WaterPool).c_str());
        lv_label_set_text(ui_FlourB, String(FlourPool).c_str());
        lv_label_set_text(ui_YeastB, String(YeastPool).c_str());
    }
    else if (this->selectedMethod == "BigaPoolish")
    {
        float prefPerc = this->BigaPercentage / 2.0;

        this->FlourBiga = flour * (prefPerc / 100.0F);
        this->WaterBiga = this->FlourBiga * (this->BigaWaterPerc / 100.0F);
        this->YeastBiga = AdjustYeast(this->FlourBiga * 0.01);

        this->FlourPool = flour * (prefPerc / 100.0F);
        this->WaterPool = this->FlourPool;
        this->YeastPool = AdjustYeast(this->FlourPool * 0.02);

        this->Water = water - this->WaterBiga - this->WaterPool;
        this->Flour = flour - this->FlourBiga - this->FlourPool;
        this->Salt = salt;
        this->Fat = fat;
        this->Yeast = 0;

        lv_label_set_text(ui_WaterB, (String(WaterBiga) + " - " + String(WaterPool)).c_str());
        lv_label_set_text(ui_FlourB, (String(FlourBiga) + " - " + String(FlourPool)).c_str());
        lv_label_set_text(ui_YeastB, (String(YeastBiga) + " - " + String(YeastPool)).c_str());
    }

    SaveToPreferences();

    lv_label_set_text(ui_FlourQ, String(Flour).c_str());
    lv_label_set_text(ui_WaterQ, String(Water).c_str());
    lv_label_set_text(ui_SaltQ, String(Salt).c_str());
    lv_label_set_text(ui_OilQ, String(Fat).c_str());
    lv_label_set_text(ui_YeastQ, String(Yeast).c_str());
}

double Recipe::AdjustYeast(double yeast)
{
    if (selectedYeast == "Dry")
    {
        return yeast / 2;
    }
    else if (selectedYeast == "Sourdough")
    {
        return yeast * 120;
    }

    return yeast;
}