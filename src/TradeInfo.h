#pragma once
#include "Order.h"
#include <vector>

struct OrderTradeInfo
{
    OrderId orderId;
    Quantity quantity;
}; // Trade info about an order

struct Trade
{
    OrderTradeInfo bidTrade;
    OrderTradeInfo askTrade;
};