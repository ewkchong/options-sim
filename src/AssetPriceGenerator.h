#include <random>

#ifndef ASSET_PRICE_GENERATOR_H
#define ASSET_PRICE_GENERATOR_H

#define TIME_STEP 0.01f // Measured in years

// static unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
static std::random_device rd;
static std::mt19937 generator(rd());
static std::normal_distribution<float> distribution(0, 1);

class AssetPriceGenerator {
private:
    float price;
    float drift;
    float volatility;

public:
    AssetPriceGenerator(float price, float drift, float volatility);
    float get_price() { return price; }
    void set_next_price();
};

#endif
