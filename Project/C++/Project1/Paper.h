#pragma once
#include "Item.h"
class Paper :public Item
{
private:
	int weight;
	int pages;
public:
	static int ammount;
	Paper(std::string name, int price, std::string description, int stock, int id, int weight, int pages);
	std::string getDetails();
};

