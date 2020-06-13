#pragma once
#include<string>
#include<stdexcept>
#include<vector>
#include"Owner.h"
#include"Item.h"
#include"Buyer.h"
class Eshop{
private:
	std::string name;
	std::vector<Item*> itemsList;
	std::vector<Buyer*> buyersList;
	Owner* owner;
public:
	Eshop();
	Eshop(std::string name, Owner* owner);
	void addItem(Item* item);
	void addBuyer(Buyer* buyer);
	void removeItem(Item* item);
	void removeBuyer(Buyer* buyer);
	Item* getItemByld(int id);
	Buyer* getBuyerByEmail(std::string email);
	void updateItemStock(Item* item, int stock);
	void showCategories();
	void showProductsInCategory(std::string cat);
	void showProduct(Item item);
	void checkStatus();
	User* checkBuyer(std::string email);
	


};

