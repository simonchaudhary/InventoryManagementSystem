#ifndef MENU_H
#define MENU_H

#include <vector>

#include "../product/Product.cpp"
#include "../supplier/LocalSupplier.cpp"
#include "../supplier/GlobalSupplier.cpp"
#include "../organization/Organization.cpp"

class Menu
{
private:
    Organization organization;

    std::vector<LocalSupplier *> localSuppliers;
    std::vector<GlobalSupplier *> globalSuppliers;

    void displayMenu() const;
    void handleViewProducts();
    void handleAddProduct();
    void handleRemoveProduct();
    void handleSearchProduct();
    void handleUpdateStock();
    void handleCreateSupplier();
    void handleSubscribeSupplier();
    void handleGenerateReport();

public:
    Menu(Organization &org);

    void run();
};

#endif // MENU_H
