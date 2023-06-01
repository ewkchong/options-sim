#include <algorithm>
#include <iostream>

#include "../include/MatchingEngine.h"

MatchingEngine::MatchingEngine(std::string symbol, float price) : 
	symbol(symbol), price(price)
{}

int MatchingEngine::get_breakeven_index() {
	unsigned long k = 0;
	while (k < std::min(buy_orders.size(), sell_orders.size())) {
		if (sell_orders[k].price > buy_orders[k].price) {
			return k;
		}
	}
	return -1;
}

bool compareOrders(const order_t &a, const order_t &b) {
	return (a.price < b.price);
}

void MatchingEngine::process_trades() {
	// provide natural ordering of orders
	sort(buy_orders.rbegin(), buy_orders.rend(), &compareOrders);
	sort(sell_orders.begin(), sell_orders.end(), &compareOrders);
	
	// let k be breakeven index
	int k = get_breakeven_index();

	if (k < 0) return;
	// The first k-1 sellers give the item and receive sk
	sell_orders.erase(sell_orders.begin(), sell_orders.begin()+(k-1));

	// The first k-1 buyers receive the item and pay bk
	buy_orders.erase(buy_orders.begin(), buy_orders.begin()+(k-1));
}

void MatchingEngine::place_buy_order(float price) {
	order_t order = { "abc", price, 1 };
	buy_orders.push_back(order);
}

void MatchingEngine::place_sell_order(float price) {
	order_t order = { "abc", price, 1 };
	sell_orders.push_back(order);
}

void MatchingEngine::run() {
	std::cout << "running MatchingEngine for " << symbol << "\n";
}
