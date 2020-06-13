#include "ShoppingCart.h"

ShoppingCart::ShoppingCart()
{
}

ShoppingCart::ShoppingCart(int buyerCategory) { this->buyerCategory = buyerCategory; }

void ShoppingCart::setBuyerCategory(int buyerCategory)
{
	this->buyerCategory = buyerCategory;
}

void ShoppingCart::addItemOrdered(Item* item, int quantity)
{
	if (orderList.find(item) == orderList.end() && item->getStock() >= quantity) {
		item->setStock(item->getStock() - quantity);
		orderList.insert(std::make_pair(item, quantity));
	}
	else if(orderList.find(item) != orderList.end() && item->getStock() >= quantity){
		//Removing the diference or the old with the new quantity
		item->setStock(item->getStock() - quantity + orderList.find(item)->second);
		changeItemOrderedQuantity(item, quantity);
	}
	else {
		throw(std::invalid_argument("Not enough items in stock"));
	}
}

void ShoppingCart::removeItemOrdered(Item* item)
{
	item->setStock(orderList.find(item)->second + item->getStock());
	orderList.erase(item);
}

void ShoppingCart::changeItemOrderedQuantity(Item* item, int quantity)
{
	removeItemOrdered(item);
	addItemOrdered(item, quantity);
}

void ShoppingCart::showCart()
{
	std::map<Item*, int>::iterator it = orderList.begin();
	int i = 0;
	while (it != orderList.end()) {
		std::cout << i + 1 << ":Name: " << it->first->getName() << ". Id: " << it->first->getId() << ". Quantity: " << it->second << ". Price: " << it->first->getPrice() << ".\n";
		it++;
		i++;
	}
	if (i == 0) {
		std::cout << "The cart is empty\n";
	}
	std::cout << "Price: " << calculateNet() << " $\n";
	std::cout <<  "Courier cost " <<calculateCourierCost(calculateNet()) << " $\n";
}

void ShoppingCart::clearCart()
{
	std::map<Item*, int>::iterator it = orderList.begin();
	while (it != orderList.end()) {
		it->first->setStock(it->first->getStock() + it->second);
		it++;
	}
	orderList.clear();
}

void ShoppingCart::checkout(bool confirmation)
{
	if (confirmation) {
		orderList.clear();
	}
	else {
		throw std::invalid_argument("Checkout canceled\n");
	}
	//Buyer points are added in the menu class by passing the 10% of calculateNet() to awardBonus() (ex. awardBonus(buyer::cart::calculateNet*0.1))
}

double ShoppingCart::calculateNet()
{
	double net = 0.0;
	std::map<Item*, int>::iterator it = orderList.begin();
	while (it != orderList.end()) {
		net += it->second*it->first->getPrice();
		it++;
	}
	return net;
}

double ShoppingCart::calculateCourierCost(int net)
{
	if (buyerCategory == 0) {
		if (net * 0.02 >= 3) {
			return net * 0.02;
		}
		else {
			return 3;
		}
	}
	else if (buyerCategory == 1) {
		return net * 0.01;
	}
	else {
		return 0;
	}
}
