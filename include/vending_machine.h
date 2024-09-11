#ifndef VENDINGMACHINE_H
#define VENDINGMACHINE_H

#include <string>  // 引入string头文件
#include <map>

class Product{
  public:
	Product();
	Product(const std::string& name, double price, int stock);

    std::string getName() const;
    double getPrice() const;
    int getStock() const; //

    void dispense(); //send

  private:
	std::string name;
    double price;
    int stock;

};

class VendingMachine {
  public:
    VendingMachine(const std::string& location);  // 使用std::string标识位置
    
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

class User {
  public:
	User(const std::string& name, double balance);

    std::string name;
    double balance;
	
	std::string getName() const;
	double getBalance() const;

	void depositMoney(VendingMachine& machine, double amount);
	void purchaseProduct(VendingMachine& machine, uint productId);
	void addBalance(double amount);
};

#endif