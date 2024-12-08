#include <iostream>

#include "GlobalSupplier.h"

#include "../organization/Organization.h"

GlobalSupplier::GlobalSupplier(const std::string &name) : Supplier(name) {}

std::string GlobalSupplier::getName() const
{
    return name;
}

void GlobalSupplier::notifyRestock(int productID, int quantity)
{

    std::cout << "Global Supplier: \n"
              << name << " notified to restock Product " << productID
              << " with quantity " << quantity << ".\n";
}

void GlobalSupplier::subscribeToOrganization(Organization *organization)
{
    organization->addSupplier(this);
}
