#ifndef VENDINGMACHINE_H
#define VENDINGMACHINE_H

#include <string>  // 引入string头文件
#include <map>
#include "machine.h"


class Product;
class VendingMachine : public Machine{
  public:
    VendingMachine(const std::string& location);  // 使用std::string标识位置
    
	void reset() override
	{
		// Throw away all products
		products.clear();
		// Clear all the money
		currentBalance = 0;
		// Clear all totalSales
		totalSales = 0;
	};

    std::string getLocation() const;
    double getTotalSales() const;
    double getCurrentBalance() const;
    std::map<int, Product> getProductMap() const;

    void addProduct(const Product& addedproduct,uint productID);
    void sellProduct(uint productID);
    void depositMoney(double amount);
    double returnChange();

  private:
    std::string location;
    double totalSales;
    double currentBalance;
    std::map<int, Product> products;
};


#endif