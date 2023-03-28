#ifndef OPTIONS_PRICER_H
#define OPTIONS_PRICER_H

class Options_Pricer {
	public:
		double call_price(double s, double ex, double r, double sig, double tte);
};

#endif // !OPTIONS_PRICER_H
