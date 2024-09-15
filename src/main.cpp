#include "vending_machine.h"
#include "product.h"
#include "user.h"

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


}