#pragma once
#include "User.h"
#include"ShoppingCart.h"
#include<string>
class Buyer :public User{
private:
	int buyerCategory;
	int buyerPts = 0;
public:
	ShoppingCart cart;
	static const int BRONZE = 0;
	static const int SILVER = 1;
	static const int GOLD = 2;
	Buyer();
	Buyer(std::string name, std::string email, std::string address, int postalCode);
	int getBuyerCategory();
	void setBuyerCategory();
	int getBuyerPts();
	void setBuyerPts(int buyerPts);
	void awardBonus(int pts);
	void placeOrder(Item* item, int quantity);
};

