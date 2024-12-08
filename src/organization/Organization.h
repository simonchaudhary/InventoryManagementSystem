#ifndef ORGANIZATION_H
#define ORGANIZATION_H

#include <vector>

#include "../product/Product.h"
#include "../supplier/Supplier.h"

class Organization
{
private:
    std::vector<Product> products;
    std::vector<Supplier *> suppliers;

public:
    void getAllProduct() const;
    void addProduct(const Product &product);
    void removeProduct(int productID);
    Product *searchProduct(int productID);
    void generateReport() const;

    void addSupplier(Supplier *supplier);
    void notifySuppliers(int productID, int restockQuantity);
};

#endif // ORGANIZATION_H
