#pragma once
#include "Item.h"
class Pen :public Item
{
private:
	std::string color;
	double tipSize;

public:
	static int ammount;
	Pen(std::string name, double price, std::string description, int stock, int id, std::string color, double tipSize);
	std::string getDetails();


};

