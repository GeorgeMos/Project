#include "Pen.h"
int Pen::ammount = 0;

Pen::Pen(std::string name, double price, std::string description, int stock, int id, std::string color, double tipSize)
{
	setName(name);
	setPrice(price);
	setDescription(description);
	setStock(stock);
	setId(id);
	setObjType("pen");
	this->color = color;
	this->tipSize = tipSize;
	this->ammount++;
}

std::string Pen::getDetails()
{
	return "Color: " + color + ". Tip Size: " + std::to_string(tipSize) + ".";
}

