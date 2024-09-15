#include <iostream>  // 需要包含这个头文件来使用std::cout
#include <string>  // 引入string头文件
#include <map>

#include "user.h"
#include "vending_machine.h"
#include "product.h"

User::User(const std::string& name, double balance)
: name(name),balance(balance){}

std::string User::getName() const
{
    return name;
}

double User::getBalance() const
{
    return balance;
}

void User::depositMoney(VendingMachine& machine, double amount)
{
    if(balance >= amount)
    {
        balance -= amount;// Deduct user's balance
        machine.depositMoney(amount); // Deposit money in machine
        std::cout << name << " deposited "<< amount <<
                             " into the vending machine." << std::endl;
    }
    else
    {
        std::cout << "Insufficient balance." << std::endl;
    }
    
}

void User::purchaseProduct(VendingMachine& machine, uint productId)
{
    //Viewing and Selecting Products
    Product& wantedproduct = machine.getProductMap()[productId];
    std::cout << "At " << machine.getLocation() <<", "
            << name << " want to buy " << wantedproduct.getName()<<std::endl;
    // Check if stock 
    if(wantedproduct.getStock() > 0)
    {
        //Waiting for machine to push out product
        machine.sellProduct(productId);
    }
    else
    {
        std::cout << "Insufficient stock!" << std::endl;
    }
    
}

void User::addBalance(double amount)
{
    balance += amount;
}
