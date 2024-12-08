#include "Supplier.h"
#include "../organization/Organization.h"
#include <iostream>

LocalSupplier::LocalSupplier(const std::string &name) : Supplier(name) {}

void LocalSupplier::notifyRestock(int productID, int quantity)
{
    std::cout << "LocalSupplier " << name << " notified to restock Product " << productID
              << " with quantity " << quantity << ".\n";
}

void LocalSupplier::subscribeToOrganization(Organization *organization)
{
    organization->addSupplier(this);
}

GlobalSupplier::GlobalSupplier(const std::string &name) : Supplier(name) {}

void GlobalSupplier::notifyRestock(int productID, int quantity)
{
    std::cout << "GlobalSupplier " << name << " notified to restock Product " << productID
              << " with quantity " << quantity << ".\n";
}

void GlobalSupplier::subscribeToOrganization(Organization *organization)
{
    organization->addSupplier(this);
}
