#include <utility>

#ifndef OPTIONS_PRICER_H
#define OPTIONS_PRICER_H

namespace optP {
	class optionsPricer {
		public:
			float call_price(float s, float ex, float r, float sig, float tte);

			std::pair<float, float> call_price_delta(float s, float ex, float r, float sig, float tte);

			float put_price(float s, float ex, float r, float sig, float tte);

			void call_put_mem(float * call_p, float * put_p, float s, float ex, float r, float sig, float tte);
	};

}

#endif // !OPTIONS_PRICER_H
