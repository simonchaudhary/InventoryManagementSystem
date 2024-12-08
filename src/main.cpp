
#include <iostream>
#include <string>
#include <limits>

#include "product/Product.cpp"
#include "supplier/LocalSupplier.cpp"
#include "supplier/GlobalSupplier.cpp"
#include "organization/Organization.cpp"

void clearInputStream()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void displayMenu()
{
    std::cout << "\n--- Inventory Management System ---\n";
    std::cout << "1. View Products\n";
    std::cout << "2. Add Product\n";
    std::cout << "3. Remove Product\n";
    std::cout << "4. Search Product\n";
    std::cout << "5. Update Product Stock\n";
    std::cout << "6. Create Supplier\n";
    std::cout << "7. Subscribe Supplier\n";
    std::cout << "8. Generate Report\n";
    std::cout << "0. Exit\n";
    std::cout << "------------------------------------\n";
    std::cout << "Enter your choice: ";
}

int main()
{
    Organization organization;
    std::vector<LocalSupplier *> localSuppliers;
    std::vector<GlobalSupplier *> globalSuppliers;

    while (true)
    {
        displayMenu();

        int choice;

        std::cin >> choice;

        if (std::cin.fail())
        {
            clearInputStream();

            std::cout << "Invalid input. Please enter a number.\n";

            continue;
        }

        switch (choice)
        {
        case 1:
        { // View Products
            organization.getAllProduct();
            break;
        }
        case 2:
        { // Add Product
            int id, stock, threshold;
            std::string name, category;
            double price;

            std::cout << "Enter Product ID: ";
            std::cin >> id;
            std::cout << "Enter Product Name: ";
            clearInputStream();
            std::getline(std::cin, name);
            std::cout << "Enter Product Category: ";
            std::getline(std::cin, category);
            std::cout << "Enter Product Price: ";
            std::cin >> price;
            std::cout << "Enter Stock Level: ";
            std::cin >> stock;
            std::cout << "Enter Reorder Threshold: ";
            std::cin >> threshold;

            organization.addProduct(Product(id, name, category, price, stock, threshold));
            std::cout << "Product added successfully.\n";
            break;
        }
        case 3:
        { // Remove Product
            int id;
            std::cout << "Enter Product ID to remove: ";
            std::cin >> id;

            Product *product = organization.searchProduct(id);

            if (product)
            {
                organization.removeProduct(id);

                std::cout
                    << "Product removed successfully.\n";
            }
            else
            {
                std::cout << "Product not found.\n";
            }
            break;
        }
        case 4:
        { // Search Product
            int id;
            std::cout << "Enter Product ID to search: ";
            std::cin >> id;

            Product *product = organization.searchProduct(id);
            if (product)
            {
                std::cout << "Product Found:\n";
                std::cout << "ID: " << product->getID() << '\n';
                std::cout << "Name: " << product->getName() << '\n';
                std::cout << "Category: " << product->getCategory() << '\n';
                std::cout << "Price: " << product->getPrice() << '\n';
                std::cout << "Stock Level: " << product->getStockLevel() << '\n';
                std::cout << "Reorder Threshold: " << product->getReorderThreshold() << '\n';
            }
            else
            {
                std::cout << "Product not found.\n";
            }
            break;
        }
        case 5:
        { // Update Product Stock
            int id, change;
            std::cout << "Enter Product ID to update stock: ";
            std::cin >> id;

            Product *product = organization.searchProduct(id);
            if (product)
            {
                std::cout << "Enter stock change (positive to increase, negative to decrease): ";
                std::cin >> change;
                product->updateStockLevel(change);

                std::cout << "Stock updated successfully.\n";

                if (product->needsRestock())
                {
                    int restockQuantity = product->getReorderThreshold() - product->getStockLevel();

                    organization.notifySuppliers(product->getID(), restockQuantity);
                }
            }
            else
            {
                std::cout << "Product not found.\n";
            }
            break;
        }
        case 6:
        { // Create Supplier
            std::string name, type;
            std::cout << "Enter Supplier Name: ";
            clearInputStream();
            std::getline(std::cin, name);
            std::cout << "Enter Supplier Type (local/global): ";
            std::getline(std::cin, type);

            if (type == "local")
            {
                localSuppliers.push_back(new LocalSupplier(name));
                std::cout << "Local Supplier created successfully.\n";
            }
            else if (type == "global")
            {
                globalSuppliers.push_back(new GlobalSupplier(name));
                std::cout << "Global Supplier created successfully.\n";
            }
            else
            {
                std::cout << "Invalid supplier type.\n";
            }
            break;
        }

        case 7:
        { // Subscribe Supplier
            std::cout << "Available Suppliers:\n";

            // Display Local Suppliers
            std::cout << "Local Suppliers:\n";
            for (size_t i = 0; i < localSuppliers.size(); ++i)
            {
                std::cout << i + 1 << ". " << localSuppliers[i]->getName() << " [Local]\n";
            }

            // Display Global Suppliers
            std::cout << "Global Suppliers:\n";
            for (size_t i = 0; i < globalSuppliers.size(); ++i)
            {
                std::cout << localSuppliers.size() + i + 1 << ". " << globalSuppliers[i]->getName() << " [Global]\n";
            }

            int index;
            std::cout << "Enter Supplier number to subscribe: ";
            std::cin >> index;

            // Check if the index falls within local supplier range
            if (index > 0 && static_cast<size_t>(index) <= localSuppliers.size())
            {
                localSuppliers[index - 1]->subscribeToOrganization(&organization);
                std::cout << "Local Supplier subscribed successfully.\n";
            }
            // Check if the index falls within global supplier range
            else if (index > static_cast<int>(localSuppliers.size()) &&
                     index <= static_cast<int>(localSuppliers.size() + globalSuppliers.size()))
            {
                globalSuppliers[index - localSuppliers.size() - 1]->subscribeToOrganization(&organization);
                std::cout << "Global Supplier subscribed successfully.\n";
            }
            else
            {
                std::cout << "Invalid selection.\n";
            }
            break;
        }

        // case 7:
        // { // Subscribe Supplier
        //     std::cout << "Available Suppliers:\n";
        //     for (size_t i = 0; i < localSuppliers.size(); ++i)
        //     {
        //         std::cout << i + 1 << ". " << localSuppliers[i]->getName() << '\n';
        //     }

        //     int index;
        //     std::cout << "Enter Supplier number to subscribe: ";
        //     std::cin >> index;

        //     if (index > 0 && static_cast<size_t>(index) <= localSuppliers.size())
        //     {
        //         localSuppliers[index - 1]->subscribeToOrganization(&organization);
        //         std::cout << "Supplier subscribed successfully.\n";
        //     }
        //     else
        //     {
        //         std::cout << "Invalid selection.\n";
        //     }
        //     break;
        // }
        case 8:
        { // Generate Report
            organization.generateReport();
            break;
        }
        case 0:
        { // Exit
            std::cout << "Exiting the program.\n";
            return 0;
        }
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
