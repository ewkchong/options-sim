#include <random>

#ifndef ASSET_PRICE_GENERATOR_H
#define ASSET_PRICE_GENERATOR_H

#define TIME_STEP 0.05f

static unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
static std::default_random_engine generator(seed);
static std::normal_distribution<float> distribution(0, 1);

class AssetPriceGenerator {
private:
    float price;
    float drift;
    float volatility;

public:
    AssetPriceGenerator(float price, float drift, float volatility);
    float getPrice() { return price; }
    void setNextPrice();
};

#endif