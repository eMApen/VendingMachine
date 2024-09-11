#include "vending_machine.h"
#include <iostream>  // 需要包含这个头文件来使用std::cout
#include <string>  // 引入string头文件
#include <map>

Product::Product():name("Null"),price(0.0),stock(0){}
Product::Product(const std::string& name,double price,int stock)
: name(name),price(price),stock(stock){}

std::string Product::getName() const
{
    return name;
}

double Product::getPrice()const{
    return price;
}

int Product::getStock()const
{
    return stock;
}

void Product::dispense()
{
    std::cout << "Select Product: "<< getName() << ", Stock: " << getStock() << '.' << std::endl;
    if(stock > 0)
    {
        std::cout << "Successful dispense "<< getName() << '.' << std::endl;
        stock --;
    }
    else
    {
        std::cout << "Failed to dispense "<< getName() << '.'  << std::endl;
    }
    
}


VendingMachine::VendingMachine(const std::string& location)
: location(location){}

std::string VendingMachine::getLocation() const
{
    return location;
}

double VendingMachine::getTotalSales() const
{
    return totalSales;
}

double VendingMachine::getCurrentBalance() const
{
    return currentBalance;
}

std::map<int, Product> VendingMachine::getProductMap() const
{
    return products;
}

void VendingMachine::addProduct(const Product& addedProduct,uint productID)
{
    // 检查是否已经存在 productID，避免覆盖
    if(products.find(productID)!=products.end()){
        std::cout << "Product ID " << productID << " is already exsists. Cannot add product.";

    }
    else{
        // 使用 insert 方法显式插入产品
    products.insert(std::make_pair(productID, addedProduct));
    std::cout << "Product added: " << addedProduct.getName() << " with ID: " << productID << std::endl;
    }
    
}

void VendingMachine::sellProduct(uint productID)
{

    // 选择产品
    Product& selectedProduct = products[productID];
    // Check if stock 
    if(selectedProduct.getStock() == 0)
    {
        std::cout << "Insufficient stock!" << std::endl;
    }
    
    // 查询价格并查询用户投入的钱
    if(currentBalance >= selectedProduct.getPrice())
    {
        currentBalance -= selectedProduct.getPrice();
        totalSales += selectedProduct.getPrice();
        selectedProduct.dispense();
    }
    else
    {
        std::cout << "Insufficient balance!" << std::endl;
    }
        //Waiting for machine to return change
        returnChange();
    
}

void VendingMachine::depositMoney(double amount)
{
    currentBalance = amount;
}

double VendingMachine::returnChange()
{
    std::cout << "Return changes "<<  currentBalance<<"$"<<std::endl;
    double change = currentBalance;
    currentBalance = 0;
    return change;
}

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
