#include "Organization.h"
#include <iostream>
#include <algorithm>

void Organization::addProduct(const Product &product)
{
    products.push_back(product);
}

void Organization::removeProduct(int productID)
{
    products.erase(std::remove_if(products.begin(), products.end(),
                                  [productID](const Product &p)
                                  { return p.getID() == productID; }),
                   products.end());
}

Product *Organization::searchProduct(int productID)
{
    for (auto &product : products)
    {
        if (product.getID() == productID)
        {
            return &product;
        }
    }

    return nullptr;
}

void Organization::generateReport() const
{
    std::cout << "Inventory Report:\n";

    for (const auto &product : products)
    {
        std::cout << "Product ID: " << product.getID()
                  << ", Name: " << product.getName()
                  << ", Category: " << product.getCategory()
                  << ", Price: " << product.getPrice()
                  << ", Threshold: " << product.getReorderThreshold()
                  << ", Stock Level: " << product.getStockLevel() << '\n';
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

void Organization::addSupplier(Supplier *supplier)
{
    suppliers.push_back(supplier);
}

void Organization::notifySuppliers(int productID, int restockQuantity)
{
    for (auto *supplier : suppliers)
    {
        supplier->notifyRestock(productID, restockQuantity);
    }
}
