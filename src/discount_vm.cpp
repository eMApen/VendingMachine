#include <iostream>  // 需要包含这个头文件来使用std::cout
#include <string>    // 引入string头文件
#include <map>

#include "discount_vm.h"
#include "product.h"

DiscountVM::DiscountVM(const std::string& location)
: VendingMachine(location){}

void DiscountVM::applyDiscount(double inputdiscountRate)
{
    if (discountRate <= 0 || discountRate > 1) 
    {
        std::cout << "Invalid discount rate!" << std::endl;
        return;
    }
    else
    {
        discountRate = inputdiscountRate;
        std::cout << "Apply discount rate: " << discountRate << std::endl;
    }
    
}
void DiscountVM::sellProduct(uint productID)
{
    // 选择产品
    Product& selectedProduct = products[productID];
    // Check if stock 
    if(selectedProduct.getStock() == 0)
    {
        std::cout << "Insufficient stock!" << std::endl;
    }
    
    // 查询价格并查询用户投入的钱，这里加上打折
    double discountPrice = selectedProduct.getPrice()*discountRate;
    if(currentBalance >= discountPrice)
    {
        std::cout << "After discount: " << discountPrice << std::endl;
        currentBalance -= discountPrice;
        totalSales += discountPrice;
        selectedProduct.dispense();
    }
    else
    {
        std::cout << "Insufficient balance!" << std::endl;
    }
        //Waiting for machine to return change
        returnChange();
}