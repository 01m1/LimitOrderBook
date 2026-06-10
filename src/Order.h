#pragma once
#include <cstdint>
#include <stdexcept>

using OrderId = uint64_t;
using Price = int32_t;
using Quantity = uint32_t;

enum class OrderType
{
    GoodTillCancel,
    FillAndKill
};

enum class Side
{
    Buy,
    Sell
};

class Order
{
public:
    Order(OrderId orderId, Side side, Price price, OrderType orderType, Quantity quantity)
        : orderId(orderId), side(side), price(price), orderType(orderType), initialQuantity(quantity), remainingQuantity(quantity)
    {
    }

    OrderId GetOrderId() const { return orderId; }
    Side GetSide() const { return side; }
    Price GetPrice() const { return price; }
    OrderType GetOrderType() const { return orderType; }
    Quantity GetInitialQuantity() const { return initialQuantity; }
    Quantity GetRemainingQuantity() const { return remainingQuantity; }
    Quantity GetFilledQuantity() const { return initialQuantity - remainingQuantity; }

    void Fill(Quantity quantity)
    {
        if (quantity > remainingQuantity)
            throw std::logic_error("Cannot fill more than remaining quantity");
        remainingQuantity -= quantity;
    }

private:
    OrderId orderId;
    Side side;
    Price price;
    OrderType orderType;
    Quantity initialQuantity;
    Quantity remainingQuantity;
};