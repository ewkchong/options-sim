#include <vector>
#include <string>

#ifndef MATCHINGENGINE_H
#define MATCHINGENGINE_H

// typedef std::pair<std::string, float> order_t;
typedef struct order_struct {
	char trader_id[64];
	char order_id[64];
	float price;
	int order_quantity;
	int rolling_quantity;
} order_t;

class MatchingEngine {
public:
	std::string symbol;
	float price;

	std::vector<order_t> buy_orders;
	std::vector<order_t> sell_orders;

	MatchingEngine(std::string symbol, float price);

	void process_trades();
	void match_orders();
	float get_price() { return price; }
	int get_breakeven_index();

	void place_buy_order(std::string, float, int);
	void place_sell_order(std::string, float, int);

	void run();
	void run_iterations(int);
};

#endif
