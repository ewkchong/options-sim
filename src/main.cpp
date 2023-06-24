#include <cmath>
#include <iostream>
#include <string>
#include <thread>

#include "AssetPriceGenerator.h"
#include "MatchingEngine.h"
#include "OptionsPricer.h"
#include "Server.h"

using std::string;

void print_sample() {
    for (float tte = 1; tte >= 0; tte = std::round((tte - 0.05) * 1e2) / 1e2) {
        std::pair<double, double> c =
            optionsPricer::call_price_delta(2, 2.5, 0.03, 0.25, tte);
        std::cout << "tte: " << tte << ", " << c.first << " " << c.second
                  << "\n";
    }
}

void testPricing() {
    float final_time = 1;
    AssetPriceGenerator asset_price_generator(10, 0.03f, 0.3f);
    float prices[100];
    for (int i = 0; i < 100; i++) {
        prices[i] = asset_price_generator.get_price();
        asset_price_generator.set_next_price();
        float call_price = optionsPricer::call_price(prices[i], 10, 0.03f, 0.3f,
                                                     final_time - (i * 0.01));
        std::cout << "Asset Price: " << prices[i]
                  << ", Call Price: " << call_price << "\n";
    }

    std::cout << asset_price_generator.get_price() << std::endl;
}

void startMatchingEngine(string symbol) {
    // stack allocated MatchingEngines
    MatchingEngine m(symbol, 1);
    printf("Starting MatchingEngine for %s\n", symbol.c_str());

    m.run();
}

int main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cerr << "usage: options-sim <symbol>" << std::endl;
		return 1;
	}

    // vector<string> symbols = {"AAPL", "TSLA", "NVDA", "SPY"};
	
	Server s;

	s.start();

    return 0;
}
