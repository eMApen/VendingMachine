#include "vending_machine.h"

int main()
{
    // Create a vending machine
    VendingMachine machine("First Veding Machine Ever");

    
    Product cola("Cola", 3.5, 10);
    Product chip("Chip",5.8,8);
    Product gum("Gum",4,10);

    // Adding products to the machine 
    machine.addProduct(cola,1);
    machine.addProduct(chip,0);
    machine.addProduct(gum,4);
    
    // Create an User
    User ruby("Ruby",100);

    ruby.depositMoney(machine,20);
    ruby.purchaseProduct(machine,0);


}