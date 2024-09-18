#ifndef DISCOUNT_VENDING_MACHINE_H
#define DISCOUNT_VENDING_MACHINE_H

#include <string>
#include "vending_machine.h"

class DiscountVM :public VendingMachine {
  public:
    DiscountVM(const std::string& location);
    void applyDiscount(double inputDiscountRate);
    void sellProduct(uint productID);
  private:
    double discountRate;
};

#endif