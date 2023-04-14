#include <cmath>
#include <stdio.h>
#include <algorithm>

#include "../include/OptionsPricer.h"

using namespace optP;

float optionsPricer::call_price(float s,
		float ex,
		float r,
		float sig,
		float tte) {
	if (tte <= 0)
		return std::fmax(s-ex, 0);
	float d1 = (log(s/ex) + ((r + 0.5*sig*sig)*tte))/(sig*sqrt(tte));
	float d2 = d1-sig*sqrt(tte);
	float n1 = 0.5*(1+erf(d1/sqrt(2)));						
	float n2 = 0.5*(1+erf(d2/sqrt(2)));						

	return s*n1-ex*exp(-r*(tte))*n2;
}

float optionsPricer::put_price(float s,
		float ex,
		float r,
		float sig,
		float tte) {
	if (tte <= 0)
		return std::fmax(ex-s, 0);
	float d1 = (log(s/ex) + ((r + 0.5*sig*sig)*tte))/(sig*sqrt(tte));
	float d2 = d1-sig*sqrt(tte);
	float n1 = 0.5*(1+erf(d1/sqrt(2)));						
	float n2 = 0.5*(1+erf(d2/sqrt(2)));						

	float C = s*n1-ex*exp(-r*(tte))*n2;

	return C + ex*exp(-r*tte) - s;
}

std::pair<float, float> optionsPricer::call_price_delta(float s,
		float ex,
		float r,
		float sig,
		float tte) {
	if (tte <= 0)
		return {std::fmax(s-ex, 0), 0.5 * ((s-ex == 0 ? 0 : s-ex < 0 ? -1 : 1) + 1) };
	float d1 = (log(s/ex) + ((r + 0.5*sig*sig)*tte))/(sig*sqrt(tte));
	float d2 = d1-sig*sqrt(tte);
	float n1 = 0.5*(1+erf(d1/sqrt(2)));						
	float n2 = 0.5*(1+erf(d2/sqrt(2)));						

	return {s*n1-ex*exp(-r*(tte))*n2, n1};
}
