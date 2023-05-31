#include <vector>
#include <string>

#ifndef MATCHINGENGINE_H
#define MATCHINGENGINE_H

// typedef std::pair<std::string, float> order_t;
typedef struct order_struct {
	std::string trader_id;
	float price;
	int quantity;
} order_t;

class MatchingEngine {
public:
	std::string symbol;
	float price;

	std::vector<order_t> buy_orders;
	std::vector<order_t> sell_orders;

	void process_trades();
	float get_price() { return price; }
	int get_breakeven_index();

	void place_buy_order(float);
	void place_sell_order(float);
};

#endif
