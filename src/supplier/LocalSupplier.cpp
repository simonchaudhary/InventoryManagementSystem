#include <iostream>

#include "LocalSupplier.h"

#include "../organization/Organization.h"

LocalSupplier::LocalSupplier(const std::string &name) : Supplier(name) {}

void LocalSupplier::notifyRestock(int productID, int quantity)
{

    std::cout << "Local Suppliers: \n"
              << name << " notified to restock Product " << productID
              << " with quantity " << quantity << ".\n";
}

void LocalSupplier::subscribeToOrganization(Organization *organization)
{
    organization->addSupplier(this);
}
