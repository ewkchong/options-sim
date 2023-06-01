#include "MatchingEngine.h"

#ifndef TRADER_H
#define TRADER_H

class Trader {
private:
	std::string id;
	MatchingEngine me; // matching engine for the trader's asset
	float funds;
	std::vector<order_t> executed_orders;
};

#endif
