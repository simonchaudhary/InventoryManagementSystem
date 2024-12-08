#include <iostream>
#include <algorithm>

#include "Organization.h"

// Add a product to the inventory
void Organization::addProduct(const Product &product)
{
    products.push_back(product);
}

// Remove a product from the inventory
void Organization::removeProduct(int productID)
{
    products.erase(std::remove_if(products.begin(), products.end(),
                                  [productID](const Product &p)
                                  { return p.getID() == productID; }),
                   products.end());
}

// Search for a product in the inventory
Product *Organization::searchProduct(int productID)
{
    std::cout << "\nSearching for product with ID: " << productID << '\n';

    for (auto &product : products)
    {
        if (product.getID() == productID)
        {
            return &product;
        }
    }

    return nullptr;
}

// Get all Product
void Organization::getAllProduct() const
{
    std::cout << "\nViewing All Products:\n";

    for (const auto &product : products)
    {
        std::cout << "Product ID: " << product.getID()
                  << ", Name: " << product.getName()
                  << ", Category: " << product.getCategory()
                  << ", Price: " << product.getPrice()
                  << ", Stock Level: " << product.getStockLevel()
                  << ", Threshold: " << product.getReorderThreshold()
                  << '\n';
    }
}

void Organization::generateReport() const
{
    std::cout << "\nInventory Report:\n";

    for (const auto &product : products)
    {
        std::cout << "Product ID: " << product.getID()
                  << ", Name: " << product.getName()
                  << ", Category: " << product.getCategory()
                  << ", Price: " << product.getPrice()
                  << ", Stock Level: " << product.getStockLevel()
                  << ", Threshold: " << product.getReorderThreshold()
                  << '\n';
    }

    std::cout << "\nProducts needing restock:\n";

    for (const auto &product : products)
    {
        if (product.needsRestock())
        {
            std::cout << "Product ID: " << product.getID()
                      << ", Name: " << product.getName()
                      << ", Restock Quantity: " << product.getReorderThreshold() - product.getStockLevel() << '\n';
        }
    }
}

// Add a supplier to the subscription list
void Organization::addSupplier(Supplier *supplier)
{
    suppliers.push_back(supplier);
}

// Notify suppliers to restock a product
void Organization::notifySuppliers(int productID, int restockQuantity)
{
    std::cout << "\n!!! Notify Restock !!!\n";

    for (auto *supplier : suppliers)
    {
        supplier->notifyRestock(productID, restockQuantity);
    }
}
