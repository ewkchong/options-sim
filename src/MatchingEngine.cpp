#include <algorithm>
#include <iostream>

#include "../include/MatchingEngine.h"

MatchingEngine::MatchingEngine(std::string symbol, float price)
    : symbol(symbol), price(price) {}

int MatchingEngine::get_breakeven_index() {
    unsigned long k = 0;
    while (k < std::min(buy_orders.size(), sell_orders.size())) {
        if (sell_orders[k].price >= buy_orders[k].price) {
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

    while ((buy_orders.size() > 0 && sell_orders.size() > 0) &&
           sell_orders[0].price <= buy_orders[0].price) {
        order_t *top_sell = &sell_orders[0];
        order_t *top_buy = &buy_orders[0];

        int matchedQuantity =
            std::min(top_sell->rolling_quantity, top_buy->rolling_quantity);

        top_sell->rolling_quantity -= matchedQuantity;
        top_buy->rolling_quantity -= matchedQuantity;

        if (top_sell->rolling_quantity == 0) {
            sell_orders.erase(sell_orders.begin());
            std::cout << "Trader " << top_sell->trader_id << " sold "
                      << top_sell->order_quantity << " at " << top_sell->price
                      << std::endl;
        }
        if (top_buy->rolling_quantity == 0) {
            buy_orders.erase(buy_orders.begin());
            std::cout << "Trader " << top_buy->trader_id << " bought "
                      << top_buy->order_quantity << " at " << top_sell->price
                      << std::endl;
        }
    }
}

void MatchingEngine::place_buy_order(std::string id, float price,
                                     int quantity) {
    order_t order = {"buyer_10123", "AAPL", price, quantity, quantity};
    std::cout << "Buy order placed for " << quantity << " at $" << price
              << std::endl;
    buy_orders.push_back(order);
}

void MatchingEngine::place_sell_order(std::string id, float price,
                                      int quantity) {
    order_t order = {"seller_04192", "AAPL", price, quantity, quantity};
    std::cout << "Sell order placed for " << quantity << " at $" << price
              << std::endl;
    sell_orders.push_back(order);
}

void MatchingEngine::run() {
    std::cout << "Running matching engine for " << symbol << "\n";
    place_buy_order("buyer", 102, 2);
    place_sell_order("seller1", 100, 1);
    place_sell_order("seller2", 101, 1);
    process_trades();
}

void MatchingEngine::run_iterations(int i) {
    std::cout << "Running matching engine for " << symbol << "\n";
    for (int j = 0; j < i; j++) {
        process_trades();
        // sleep for some indefinite amount of time
    }
}
