#ifndef PRODUCT_H
#define PRODUCT_H
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
#endif