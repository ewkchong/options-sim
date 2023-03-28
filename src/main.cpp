#include <stdio.h>
#include <iostream>

#include "OptionsPricer.cpp"
//#include "../include/OptionsPricer.h"

// call_price(s, ex, r, sig, tte)
// put_price(s, ex, r, sig, tte)

int main () {
	Options_Pricer options_pricer;
	for (double tte = 1; tte > -0.05; tte-=0.05) {
		double c = options_pricer.call_price(2, 2.5, 0.03, 0.25, tte);
		std::cout << "tte: " << tte << ", " << c << std::endl;
	}
	return 0;
}
