#pragma once
#include "Item.h"
class Notebook :public Item
{
private:
	int sections;
public:
	static int ammount;
	Notebook(std::string name, int price, std::string description, int stock, int id, int sections);
	std::string getDetails();
};

