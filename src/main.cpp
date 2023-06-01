#include <iostream>
#include <cmath>
#include <thread>
#include <string>

#include "../include/OptionsPricer.h"
#include "../include/AssetPriceGenerator.h"
#include "../include/MatchingEngine.h"

using std::vector;
using std::thread;
using std::string;

void print_sample() {
	for (float tte = 1; tte >= 0; tte = std::round((tte-0.05) * 1e2) / 1e2) {
		std::pair<double, double> c = optionsPricer::call_price_delta(2, 2.5, 0.03, 0.25, tte);
		std::cout << "tte: " << tte << ", " << c.first << " " << c.second <<  "\n";
	}
}

void testPricing() {
	float final_time = 1;
	AssetPriceGenerator asset_price_generator(10,0.03f,0.3f);
	float prices[100];
	for (int i = 0; i < 100; i++) {
		prices[i] = asset_price_generator.get_price();
		asset_price_generator.set_next_price();
		float call_price = optionsPricer::call_price(prices[i], 10, 0.03f, 0.3f, final_time - (i * 0.01));
		std::cout << "Asset Price: " << prices[i] << ", Call Price: " << call_price << "\n";
	}

	std::cout << asset_price_generator.get_price() << std::endl;
}

void startMatchingEngine(string symbol) {
	// stack allocated MatchingEngine
	MatchingEngine m(symbol, 1);
	std::cout << "creating matching engine for " << symbol << std::endl;

	m.run();
}


int main () {
	vector<string> symbols = {"AAPL", "TSLA", "NVDA"};
	vector<thread> engine_threads;

	for (string sym : symbols) {
		thread t(startMatchingEngine, sym);
		engine_threads.push_back(std::move(t));
	}

	for (thread & t : engine_threads) {
		if (t.joinable()) t.join();
	}
	return 0;
}
