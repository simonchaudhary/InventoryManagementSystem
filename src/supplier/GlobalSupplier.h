#ifndef GLOBAL_SUPPLIER_H
#define GLOBAL_SUPPLIER_H

#include "Supplier.h"

class GlobalSupplier : public Supplier
{
public:
    GlobalSupplier(const std::string &name);

    std::string getName() const;

    void notifyRestock(int productID, int quantity) override;

    void subscribeToOrganization(Organization *organization) override;
};

#endif // GLOBAL_SUPPLIER_H
