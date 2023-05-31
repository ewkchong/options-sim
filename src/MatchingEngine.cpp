#include <algorithm>
#include "../include/MatchingEngine.h"

int MatchingEngine::get_breakeven_index() {
	unsigned long k = 0;
	while (k < std::min(buy_orders.size(), sell_orders.size())) {
		if (sell_orders[k].price > buy_orders[k].price) {
			return k;
		}
	}
	return -1;
}

void MatchingEngine::process_trades() {
	// provide natural ordering of orders
	sort(buy_orders.rbegin(), buy_orders.rend());
	sort(sell_orders.begin(), sell_orders.end());
	
	// let k be breakeven index
	int k = get_breakeven_index();

	if (k < 0) return;
	// The first k-1 sellers give the item and receive sk
	for (int i = 0; i < k-1; i++) {

	}
	// The first k-1 buyers receive the item and pay bk
	for (int i = 0; i < k-1; i++) {

	}
}

void MatchingEngine::place_buy_order(float price) {
	 
}

void MatchingEngine::place_sell_order(float price) {
}
