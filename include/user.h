#ifndef USER_H
#define USER_H

#include <string>  // 引入string头文件
#include <map>

class VendingMachine;

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