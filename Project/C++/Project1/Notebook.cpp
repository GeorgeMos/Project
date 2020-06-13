#include "Notebook.h"
int Notebook::ammount = 0;
Notebook::Notebook(std::string name, int price, std::string description, int stock, int id, int sections)
{
	setName(name);
	setPrice(price);
	setDescription(description);
	setStock(stock);
	setId(id);
	setObjType("notebook");
	this->sections = sections;
	this->ammount++;
}

std::string Notebook::getDetails()
{
	return "Sections: " + std::to_string(sections) + ".";
}
