#pragma once
#include "Order.h"
#include <vector>

struct LevelInfo
{
    Price price;
    Quantity quantity;
}; // Represents a price level in the book#

struct OrderBookLevelInfos
{
    std::vector<LevelInfo> bids;
    std::vector<LevelInfo> asks;
};