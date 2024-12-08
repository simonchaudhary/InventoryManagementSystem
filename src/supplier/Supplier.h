#ifndef SUPPLIER_H
#define SUPPLIER_H

#include <string>

class Organization; // Forward declaration

class Supplier
{
protected:
    std::string name;

public:
    Supplier(const std::string &supplierName) : name(supplierName) {}
    virtual ~Supplier() {}

    virtual void notifyRestock(int productID, int quantity) = 0;
    virtual void subscribeToOrganization(Organization *organization) = 0;
};

class LocalSupplier : public Supplier
{
public:
    LocalSupplier(const std::string &name);
    void notifyRestock(int productID, int quantity) override;
    void subscribeToOrganization(Organization *organization) override;
};

class GlobalSupplier : public Supplier
{
public:
    GlobalSupplier(const std::string &name);
    void notifyRestock(int productID, int quantity) override;
    void subscribeToOrganization(Organization *organization) override;
};

#endif // SUPPLIER_H
