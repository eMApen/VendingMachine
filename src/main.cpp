#include "vending_machine.h"
#include "product.h"
#include "user.h"
#include "discount_vm.h"

#include <iostream>


int main()
{
    // Create a vending machine
    VendingMachine VM1("First Veding Machine Ever");

    Product cola("Cola", 3.5, 10);
    Product chip("Chip",5.8,8);
    Product gum("Gum",4,10);

    // Adding products to the machine 
    VM1.addProduct(cola,1);
    VM1.addProduct(chip,0);
    VM1.addProduct(gum,2);
    
    // Create an User
    User ruby("Ruby",100);

    ruby.depositMoney(VM1,20);
    ruby.purchaseProduct(VM1,1);
    std::cout<<std::endl;

    // Create a vending machine
    DiscountVM VM2("Veding Machine Outlets");

    VM2.applyDiscount(0.5);
    // Adding products to the machine 
    VM2.addProduct(cola,1);
    VM2.addProduct(chip,0);
    VM2.addProduct(gum,2);
    
    // Create an User
    User bill("Bill",100);

    bill.depositMoney(VM2,10);
    bill.purchaseProduct(VM2,1);

}