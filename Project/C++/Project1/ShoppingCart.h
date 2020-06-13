#pragma once
#include<map>
#include"Item.h"
class ShoppingCart
{
private:
	//Using map to store the items.
	std::map<Item*, int> orderList;
	int buyerCategory;
public:
	ShoppingCart();
	ShoppingCart(int buyerCategory);
	void setBuyerCategory(int buyerCategory);
	void addItemOrdered(Item* item, int quantity);
	void removeItemOrdered(Item* item);
	void changeItemOrderedQuantity(Item* item, int quantity);
	void showCart();
	void clearCart();
	void checkout(bool confirmation);
	double calculateNet();
	double calculateCourierCost(int net);
};

