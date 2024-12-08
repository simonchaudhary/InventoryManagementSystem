#ifndef LOCAL_SUPPLIER_H
#define LOCAL_SUPPLIER_H

#include "Supplier.h"

class LocalSupplier : public Supplier
{
public:
    LocalSupplier(const std::string &name);

    std::string getName() const;

    void notifyRestock(int productID, int quantity) override;

    void subscribeToOrganization(Organization *organization) override;
};

#endif // LOCAL_SUPPLIER_H
