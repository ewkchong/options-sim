#include <cmath>
#include <stdio.h>
#include <algorithm>

#include "../include/OptionsPricer.h"

using namespace optP;

double optionsPricer::call_price(double s,
		double ex,
		double r,
		double sig,
		double tte) {
	if (tte <= 0)
		return std::fmax(s-ex, 0);
	double d1 = (log(s/ex) + ((r + 0.5*sig*sig)*tte))/(sig*sqrt(tte));
	double d2 = d1-sig*sqrt(tte);
	double n1 = 0.5*(1+erf(d1/sqrt(2)));						
	double n2 = 0.5*(1+erf(d2/sqrt(2)));						

	return s*n1-ex*exp(-r*(tte))*n2;
}

double optionsPricer::put_price(double s,
		double ex,
		double r,
		double sig,
		double tte) {
	if (tte <= 0)
		return std::fmax(ex-s, 0);
	double d1 = (log(s/ex) + ((r + 0.5*sig*sig)*tte))/(sig*sqrt(tte));
	double d2 = d1-sig*sqrt(tte);
	double n1 = 0.5*(1+erf(d1/sqrt(2)));						
	double n2 = 0.5*(1+erf(d2/sqrt(2)));						

	double C = s*n1-ex*exp(-r*(tte))*n2;

	return C + ex*exp(-r*tte) - s;
}
		

