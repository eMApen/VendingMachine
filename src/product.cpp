#include <iostream>  // 需要包含这个头文件来使用std::cout
#include <string>  // 引入string头文件
#include <map>

#include "vending_machine.h"
#include "product.h"


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