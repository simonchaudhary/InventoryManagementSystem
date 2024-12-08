#include <iostream>

#include "product/Product.cpp"
#include "supplier/LocalSupplier.cpp"
#include "supplier/GlobalSupplier.cpp"
#include "organization/Organization.cpp"

int main()
{
    // Create Products
    Product product1(101, "Laptop", "Electronics", 1000.0, 10, 5);
    Product product2(102, "Smartphone", "Electronics", 500.0, 3, 5);

    Organization organization;

    // Add Products
    organization.addProduct(product1);
    organization.addProduct(product2);

    organization.getAllProduct();

    organization.generateReport();

    Product *foundProduct = organization.searchProduct(101);

    if (foundProduct)
    {
        // Product found, display details
        std::cout << "Product Found:\n";
        std::cout << "ID: " << foundProduct->getID() << '\n';
        std::cout << "Name: " << foundProduct->getName() << '\n';
        std::cout << "Category: " << foundProduct->getCategory() << '\n';
        std::cout << "Price: " << foundProduct->getPrice() << '\n';
        std::cout << "Stock Level: " << foundProduct->getStockLevel() << '\n';
        std::cout << "Reorder Threshold: " << foundProduct->getReorderThreshold() << '\n';
    }
    else
    {
        // Product not found
        std::cout << "Product with ID " << 101 << " not found in inventory.\n";
    }

    // Create Suppliers
    LocalSupplier localSupplier("Mero Electronic");
    LocalSupplier localSupplier1("Aagan Computer and Electronic");
    GlobalSupplier globalSupplier("Malcom International Electronic");

    // Subscribe Suppliers
    localSupplier.subscribeToOrganization(&organization);
    localSupplier1.subscribeToOrganization(&organization);
    globalSupplier.subscribeToOrganization(&organization);

    // Simulate stock level change
    product1.updateStockLevel(-7); // Drop below threshold

    // If product1 needs restock, notify suppliers
    if (product1.needsRestock())
    {
        int restockQuantity = product1.getReorderThreshold() - product1.getStockLevel();

        organization.notifySuppliers(product1.getID(), restockQuantity);
    }

    // Generate Report
    organization.generateReport();

    return 0;
}
