#include "Paper.h"
int Paper::ammount = 0;
Paper::Paper(std::string name, int price, std::string description, int stock, int id, int weight, int pages)
{
	setName(name);
	setPrice(price);
	setDescription(description);
	setStock(stock);
	setId(id);
	setObjType("paper");
	this->weight = weight;
	this->pages = pages;
	this->ammount++;
}

std::string Paper::getDetails()
{
	return "Weight: " + std::to_string(weight) + ". Pages: " + std::to_string(pages) + ".";
}
