
#include <cmath>
#include <iostream>

#include "../include/AssetPriceGenerator.h"

AssetPriceGenerator::AssetPriceGenerator(float price, float drift, float volatility) 
    : price(price), drift(drift), volatility(volatility){}

void AssetPriceGenerator::setNextPrice() {
    float yi = distribution(generator);
    price += (drift * TIME_STEP * price) + (volatility * sqrtf(drift) * yi * price);
}