#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product
{
private:
    int productID;
    std::string productName;
    std::string category;
    double price;
    int stockLevel;
    int reorderThreshold;

public:
    Product(int id, const std::string &name, const std::string &category, double price, int stock, int threshold);

    // Getters
    int getID() const;
    std::string getName() const;
    std::string getCategory() const;
    double getPrice() const;
    int getStockLevel() const;
    int getReorderThreshold() const;

    // Methods
    void updateStockLevel(int amount);
    bool needsRestock() const;
};

#endif // PRODUCT_H
