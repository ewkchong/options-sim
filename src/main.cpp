#include <iostream>
#include <cmath>

#include "../include/OptionsPricer.h"
#include "../include/AssetPriceGenerator.h"

int main () {
	for (float tte = 1; tte >= 0; tte = std::round((tte-0.05) * 1e2) / 1e2) {
		std::pair<double, double> c = optionsPricer::call_price_delta(2, 2.5, 0.03, 0.25, tte);
		std::cout << "tte: " << tte << ", " << c.first << " " << c.second <<  "\n";
	}
	AssetPriceGenerator asset_price_generator(10,0.03,0.3);
	// asset_price_generator.exampleMethod();
	for (int i = 0; i < 10000; i++) {
		asset_price_generator.setNextPrice();
	}

	std::cout << asset_price_generator.getPrice() << std::endl;
	return 0;
}
