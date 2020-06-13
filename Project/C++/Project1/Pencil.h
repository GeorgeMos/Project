#pragma once
#include "Item.h"
class Pencil :public Item
{
private:
	int type;
	double tipSize;

public:
	static int ammount;
	static const int HB = 0;
	static const int H = 1;
	static const int B = 2;
	Pencil(std::string name, double price, std::string description, int stock, int id, double tipSize, int type);
	std::string getDetails();
};

