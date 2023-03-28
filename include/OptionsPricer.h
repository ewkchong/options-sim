#ifndef OPTIONS_PRICER_H
#define OPTIONS_PRICER_H

namespace optP {

	class optionsPricer {
		public:
			double call_price(double s, double ex, double r, double sig, double tte);
			double put_price(double s, double ex, double r, double sig, double tte);
	};

}

#endif // !OPTIONS_PRICER_H
