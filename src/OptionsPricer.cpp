#include <cmath>
#include <stdio.h>
#include <algorithm>

#include "../include/OptionsPricer.h"

// Returns call price given:
//		s = asset price
// 		ex = strike price
//		r = interest rate
// 		sig = volatility
//		tte = time to expfiry (years)
float optionsPricer::call_price(float s,
		float ex,
		float r,
		float sig,
		float tte) {
	if (tte <= 0)
		return std::fmaxf(s-ex, 0);
	float d1 = (logf(s/ex) + ((r + 0.5*sig*sig)*tte))/(sig*sqrtf(tte));
	float d2 = d1-sig*sqrtf(tte);
	float n1 = 0.5*(1+erf(d1/sqrtf(2)));						
	float n2 = 0.5*(1+erf(d2/sqrtf(2)));						

	return s*n1-ex*expf(-r*(tte))*n2;
}

// Returns put price given:
//		s = asset price
// 		ex = strike price
//		r = interest rate
// 		sig = volatility
//		tte = time to expiry (years)
float optionsPricer::put_price(float s,
		float ex,
		float r,
		float sig,
		float tte) {
	if (tte <= 0)
		return std::fmaxf(ex-s, 0);
	float d1 = (logf(s/ex) + ((r + 0.5*sig*sig)*tte))/(sig*sqrtf(tte));
	float d2 = d1-sig*sqrtf(tte);
	float n1 = 0.5*(1+erf(d1/sqrtf(2)));						
	float n2 = 0.5*(1+erf(d2/sqrtf(2)));						

	float C = s*n1-ex*expf(-r*(tte))*n2;

	return C + ex*expf(-r*tte) - s;
}

// Returns (call_price, delta) given:
//		s = asset price
// 		ex = strike price
//		r = interest rate
// 		sig = volatility
//		tte = time to expiry (years)
std::pair<float, float> optionsPricer::call_price_delta(float s,
		float ex,
		float r,
		float sig,
		float tte) {
	if (tte <= 0)
		return {std::fmax(s-ex, 0), 0.5 * ((s-ex == 0 ? 0 : s-ex < 0 ? -1 : 1) + 1) };
	float d1 = (log(s/ex) + ((r + 0.5*sig*sig)*tte))/(sig*sqrtf(tte));
	float d2 = d1-sig*sqrtf(tte);
	float n1 = 0.5*(1+erf(d1/sqrtf(2)));						
	float n2 = 0.5*(1+erf(d2/sqrtf(2)));						

	return {s*n1-ex*expf(-r*(tte))*n2, n1};
}

/*
* Takes two pointers to floats, call_p and put_p,
* calculates the call and put price for a given strike s
* and places the prices in those two memory locations
*/
void call_put_mem(float * call_p, float * put_p, float s, float ex, float r, float sig, float tte) {
	if (tte <= 0) {
		*call_p = std::fmax(s-ex, 0);
		*put_p = std::fmax(ex-s, 0);
		return;
	}
		 
	float d1 = (logf(s/ex) + ((r + 0.5*sig*sig)*tte))/(sig*sqrtf(tte));
	float d2 = d1-sig*sqrtf(tte);
	float n1 = 0.5*(1+erf(d1/sqrtf(2)));						
	float n2 = 0.5*(1+erf(d2/sqrtf(2)));						

	float C = s*n1-ex*expf(-r*(tte))*n2;
	*call_p = C;
	*put_p = C + ex*expf(-r*tte) - s;
}
