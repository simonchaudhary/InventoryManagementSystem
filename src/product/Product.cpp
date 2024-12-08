#include "Product.h"

Product::Product(int id, const std::string &name, const std::string &category, double price, int stock, int threshold)
    : productID(id), productName(name), category(category), price(price), stockLevel(stock), reorderThreshold(threshold) {}

int Product::getID() const
{
    return productID;
}

std::string Product::getName() const
{
    return productName;
}

std::string Product::getCategory() const
{
    return category;
}

double Product::getPrice() const
{
    return price;
}

int Product::getStockLevel() const
{
    return stockLevel;
}

int Product::getReorderThreshold() const
{
    return reorderThreshold;
}

void Product::updateStockLevel(int amount)
{
    stockLevel += amount;
}

bool Product::needsRestock() const
{
    return stockLevel < reorderThreshold;
}
