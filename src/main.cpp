#include <iostream>
#include <cmath>

#include "../include/OptionsPricer.h"

// call_price(s, ex, r, sig, tte)
// put_price(s, ex, r, sig, tte)

using namespace optP;

int main () {
	optionsPricer options_pricer;
	for (float tte = 1; tte >= 0; tte = std::round((tte-0.05) * 1e2) / 1e2) {
		std::pair<double, double> c = options_pricer.call_price_delta(2, 2.5, 0.03, 0.25, tte);
		std::cout << "tte: " << tte << ", " << c.first << " " << c.second <<  std::endl;
	}
	return 0;
}
