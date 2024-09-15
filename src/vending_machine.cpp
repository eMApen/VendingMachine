#include <iostream>  // 需要包含这个头文件来使用std::cout
#include <string>  // 引入string头文件
#include <map>

#include "product.h"
#include "vending_machine.h"

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
