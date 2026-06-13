#pragma once
#include <list>
#include <map>
#include <memory>
#include <unordered_map>
#include <vector>
#include "Order.h"
#include "OrderBookLevelInfos.h"
#include "TradeInfo.h"

using OrderPointer = std::shared_ptr<Order>;
using OrderPointers = std::list<OrderPointer>;
using Trades = std::vector<Trade>;

class OrderBook
{
public:
    Trades AddOrder(OrderPointer order);
    void CancelOrder(OrderId orderId);
    Trades MatchOrders();
    OrderBookLevelInfos GetOrderInfos() const;

private:
    struct OrderEntry
    {
        OrderPointer order;
        OrderPointers::iterator location;
    };

    std::map<Price, OrderPointers, std::greater<Price>> bids;
    std::map<Price, OrderPointers> asks;
    std::unordered_map<OrderId, OrderEntry> orders;
};