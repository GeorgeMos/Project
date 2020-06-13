#include "Eshop.h"
#include<iostream>
#include"Pen.h"
#include"Paper.h"
#include"Notebook.h"
#include"Pencil.h"
Eshop::Eshop()
{
}
Eshop::Eshop(std::string name, Owner* owner)
{
	this->name = name;
	this->owner = owner;
	
}

void Eshop::addItem(Item* item)
{
	//---Duplicate check---
	bool itemExists = false;
	for (int i = 0; i < itemsList.size(); i++) {
		if (itemsList[i]->equals(*item)) {
			itemExists = true;
		}
	}
	//---------------------
	if (!itemExists) {
		itemsList.push_back(item);
	}
	else {
		throw(std::invalid_argument("Item already exists"));
	}
}

void Eshop::addBuyer(Buyer* buyer)
{
	//---Duplicate check---
	bool buyerExists = false;
	for (int i = 0; i < buyersList.size(); i++) {
		if (buyersList[i]->equals(*buyer)) {
			buyerExists = true;
		}
	}
	//---------------------
	if (!buyerExists) {
		buyersList.push_back(buyer);
		
	}
	else {
		throw(std::invalid_argument("Buyer already exists"));
	}
}

void Eshop::removeItem(Item* item)
{
	//---Existance check---
	bool itemExists = false;
	for (int i = 0; i < itemsList.size(); i++) {
		if (itemsList[i]->equals(*item)) {
			itemExists = true;
		}
	}
	//---------------------
	if (itemExists) {
		int j = 0;
		for (int i = 0; i < itemsList.size(); i++) {
			if (itemsList[i]->equals(*item)) {
				itemsList.erase(itemsList.begin()+i);
			}
		}
	}
	else {
		throw(std::invalid_argument("Item does not exist"));
	}
}

void Eshop::removeBuyer(Buyer* buyer)
{
	//---Existance check---
	bool buyerExists = false;
	for (int i = 0; i < buyersList.size(); i++) {
		if (buyersList[i]->equals(*buyer)) {
			buyerExists = true;
		}
	}
	//---------------------
	if (buyerExists) {
		buyer->cart.clearCart();
		for (int i = 0; i < buyersList.size(); i++) {
			if (buyersList[i]->equals(*buyer)) {
				buyersList.erase(buyersList.begin() + i);
			}
		}
	}
	else {
		throw(std::invalid_argument("Buyer does not exist"));
	}
}

Item* Eshop::getItemByld(int id)
{
	bool itemExists = false;
	for (int i = 0; i < itemsList.size(); i++) {
		if (id == itemsList[i]->getId()) {
			itemExists = true;
			return itemsList[i];
		}
	}
	if (!itemExists) {
		throw(std::invalid_argument("Item does not exist"));
	}
}

Buyer* Eshop::getBuyerByEmail(std::string email)
{
	bool buyerExists = false;
	for (int i = 0; i < buyersList.size(); i++) {
		if (email.compare(buyersList[i]->getEmail()) == 0) {
			buyerExists = true;
			return buyersList[i];
		}
	}
	if (!buyerExists) {
		throw(std::invalid_argument("Buyer does not exist"));
	}
}

void Eshop::updateItemStock(Item* item, int stock)
{
	bool itemExists = false;
	for (int i = 0; i < itemsList.size(); i++) {
		if (itemsList[i]->equals(*item)) {
			itemExists = true;
			itemsList[i]->setStock(stock);
		}
	}
	if (!itemExists) {
		throw(std::invalid_argument("Item does not exist"));
	}
}

void Eshop::showCategories()
{
	std::cout << "1:Pen(" << Pen::ammount << ")" << "\n2:Notebook(" << Notebook::ammount << ")" << "\n3:Paper("<< Paper::ammount << ")" <<"\n4:Pencil(" << Pencil::ammount << ")";
}

void Eshop::showProductsInCategory(std::string cat)
{
	for (int i = 0; i < itemsList.size(); i++) {
		if (cat.compare(itemsList[i]->getObjType()) == 0) {
			std::cout << itemsList[i]->getBasicInfo() << "\n";
		}
	}
}

void Eshop::showProduct(Item item)
{
	item.toString();
}

void Eshop::checkStatus()
{
	for (int i = 0; i < buyersList.size(); i++) {
		std::cout << i+1 << ":Name: " << buyersList[i]->getName() << ". Email: " << buyersList[i]->getEmail() << ". Points: " << buyersList[i]->getBuyerPts() << ". Category: ";
		if (buyersList[i]->getBuyerCategory() == 0) {
			std::cout << "Bronze.\n";
		}
		else if (buyersList[i]->getBuyerCategory() == 1) {
			std::cout << "Silver.\n";
		}
		else {
			std::cout << "Gold.\n";
		}
	}
}

User* Eshop::checkBuyer(std::string email)
{
	bool buyerExists = false;
	for (int i = 0; i < buyersList.size(); i++) {
		if (buyersList[i]->getEmail().compare(email) == 0) {
			return buyersList[i];
			buyerExists = true;
			break;
		}
	}
	if (!buyerExists) {
		if (owner->getEmail().compare(email) == 0) {
			return owner;
		}
		else {
			throw(std::invalid_argument("Buyer does not exist"));
		}
	}
}

