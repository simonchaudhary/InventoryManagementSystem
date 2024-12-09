
#include "Menu.h"

#include "../utils/Input.cpp"

Menu::Menu(Organization &org) : organization(org) {}

void Menu::displayMenu() const
{
    std::cout << "\n--- Inventory Management System ---\n"
              << "1. View Products\n"
              << "2. Add Product\n"
              << "3. Remove Product\n"
              << "4. Search Product\n"
              << "5. Update Product Stock\n"
              << "6. Create Supplier\n"
              << "7. Subscribe Supplier\n"
              << "8. Generate Report\n"
              << "0. Exit\n"
              << "------------------------------------\n"
              << "Enter your choice: ";
}

void Menu::handleViewProducts()
{
    organization.getAllProduct();
}

void Menu::handleAddProduct()
{
    int id, stock, threshold;
    std::string name, category;
    double price;

    std::cout << "Enter Product ID: ";
    std::cin >> id;
    std::cout << "Enter Product Name: ";

    Input::clearInputStream();

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
}

void Menu::handleRemoveProduct()
{
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
}

void Menu::handleSearchProduct()
{
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
}

void Menu::handleUpdateStock()
{
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
}

void Menu::handleCreateSupplier()
{
    std::string name, type;
    std::cout << "Enter Supplier Name: ";
    Input::clearInputStream();
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
}

void Menu::handleSubscribeSupplier()
{
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
}

void Menu::handleGenerateReport()
{
    organization.generateReport();
}

void Menu::run()
{
    while (true)
    {
        displayMenu();

        int choice;
        std::cin >> choice;

        if (std::cin.fail())
        {
            Input::clearInputStream();
            std::cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        switch (choice)
        {
        case 1:
            handleViewProducts();
            break;
        case 2:
            handleAddProduct();
            break;
        case 3:
            handleRemoveProduct();
            break;
        case 4:
            handleSearchProduct();
            break;
        case 5:
            handleUpdateStock();
            break;
        case 6:
            handleCreateSupplier();
            break;
        case 7:
            handleSubscribeSupplier();
            break;
        case 8:
            handleGenerateReport();
            break;
        case 0:
            std::cout << "Exiting the program.\n";
            return;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    }
}
