
#include "recipe.hpp"

#include "gui/gui.h"
#include "ui/ui.h"

Recipe recipe;

int Recipe::GetPrefWaterPercentage()
{
    if (this->selectedMethod == "Direct")
    {
        return 0;
    }
    else if (this->selectedMethod == "Biga")
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
    else if (this->selectedMethod == "Biga")
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
    else if (this->selectedMethod == "Biga")
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
    else if (this->selectedMethod == "Biga")
    {
        this->BigaPercentage = value;
    }
    else if (this->selectedMethod == "Poolish")
    {
        this->PoolPercentage = value;
    }
}

void Recipe::SaveToPreferences()
{
    preferences.putString("selectedType", selectedType.c_str());
    preferences.putString("selectedMethod", selectedMethod.c_str());
    preferences.putString("selectedYeast", selectedYeast.c_str());

    preferences.putInt("WaterPerc", WaterPerc);
    preferences.putInt("TotalLeavening", TotalLeavening);
    preferences.putInt("FridgeLeavening", FridgeLeavening);

    preferences.putFloat("SaltPerc", SaltPerc);
    preferences.putFloat("FatPerc", FatPerc);

    preferences.putInt("DoughBalls", DoughBalls);
    preferences.putInt("BallWeight", BallWeight);
    preferences.putInt("RoomTemperature", RoomTemperature);

    preferences.putBool("IsTray", IsTray);
    preferences.putBool("UseTheFridge", UseTheFridge);

    preferences.putInt("BigaPercentage", BigaPercentage);
    preferences.putInt("BigaWaterPerc", BigaWaterPerc);
    preferences.putInt("PoolPercentage", PoolPercentage);

    Serial.print("Save BigaWaterPerc: ");
    Serial.println(BigaWaterPerc);
}

void Recipe::IntializeIngredients()
{
    UseTheFridge = preferences.getBool("UseTheFridge", false);
    TotalLeavening = preferences.getInt("TotalLeavening", 8);
    FridgeLeavening = preferences.getInt("FridgeLeavening", 0);
    SaltPerc = preferences.getFloat("SaltPerc", 2.8);
    FatPerc = preferences.getFloat("FatPerc", 2.7);
    DoughBalls = preferences.getInt("DoughBalls", 1);
    BallWeight = preferences.getInt("BallWeight", 270);
    RoomTemperature = preferences.getInt("RoomTemperature", 21);

    BigaPercentage = preferences.getInt("BigaPercentage", 60);
    BigaWaterPerc = preferences.getInt("BigaWaterPerc", 45);
    Serial.print("Init BigaWaterPercentage: ");
    Serial.println(BigaWaterPerc);

    PoolPercentage = preferences.getInt("PoolPercentage", 60);

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
        WaterPerc = preferences.getInt("WaterPerc", 65);
    }
    else if (this->selectedType == "Grandma")
    {
        WaterPerc = preferences.getInt("WaterPerc", 75);
    }
    else if (this->selectedType == "Detroit")
    {
        WaterPerc = preferences.getInt("WaterPerc", 75);
    }
    else if (this->selectedType == "Bread")
    {
        WaterPerc = preferences.getInt("WaterPerc", 70);
    }
    else if (this->selectedType == "Focaccia")
    {
        WaterPerc = preferences.getInt("WaterPerc", 75);
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
    float k = 1e5 * (u - f) / C;
    float S = (1e3 * t * (u - f) / C);
    float x = (l * t * (u - f) / C);
    float w = (d * t * (u - f) / C);
    float b = (k * h - g * f);

    if (this->selectedMethod == "Direct")
    {
        this->Flour = k;
        this->Water = S;
        this->Yeast = AdjustYeast(b);
        this->Salt = x;
        this->Fat = w;
    }
    else if (this->selectedMethod == "Biga")
    {
        this->FlourBiga = k * (this->BigaPercentage / 100.0F);
        this->WaterBiga = this->FlourBiga * this->BigaWaterPerc / 100.0F;
        this->Water = S - this->WaterBiga;
        this->YeastBiga = AdjustYeast(this->FlourBiga * 0.01);
        this->Flour = k - this->FlourBiga;
        this->Salt = x;
        this->Fat = w;
        this->Yeast = 0;

        lv_label_set_text(ui_WaterB, String(WaterBiga).c_str());
        lv_label_set_text(ui_FlourB, String(FlourBiga).c_str());
        lv_label_set_text(ui_YeastB, String(YeastBiga).c_str());
    }
    else if (this->selectedMethod == "Poolish")
    {
        this->WaterPool = S * (this->PoolPercentage / 100.0F);
        this->FlourPool = this->WaterPool;
        this->Water = S - this->WaterPool;
        this->YeastPool = AdjustYeast(this->FlourPool * 0.02);
        this->Flour = k - this->FlourPool;
        this->Salt = x;
        this->Fat = w;
        this->Yeast = 0;

        lv_label_set_text(ui_WaterB, String(WaterPool).c_str());
        lv_label_set_text(ui_FlourB, String(FlourPool).c_str());
        lv_label_set_text(ui_YeastB, String(YeastPool).c_str());
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