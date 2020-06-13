#include "Pencil.h"
int Pencil::ammount = 0;
Pencil::Pencil(std::string name, double price, std::string description, int stock, int id, double tipSize, int type)
{
	setName(name);
	setDescription(description);
	setPrice(price);
	setStock(stock);
	setId(id);
	setObjType("pencil");
	this->tipSize = tipSize;
	this->type = type;
	this->ammount++;
}

std::string Pencil::getDetails()
{
	std::string det = "Tip Size: " + std::to_string(tipSize) + ". Type: ";
	if (type == 0) {
		det += "HB.";
	}
	else if (type == 1) {
		det += "H.";
	}
	else {
		det += "B.";
	}
	return det;
}
