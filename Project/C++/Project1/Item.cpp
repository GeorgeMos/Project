#include "Item.h"

std::string Item::getBasicInfo()
{
	return "Name: " + name + ". Price: " + std::to_string(price) + ". Description: " + description + ". Stock: " + std::to_string(stock) + ". Id: " + std::to_string(id)+". ";
}

void Item::setName(std::string name)
{
	this->name = name;
}

void Item::setPrice(double price)
{
	this->price = price;
}

void Item::setDescription(std::string description)
{
	this->description = description;
}

void Item::setStock(int stock)
{
	this->stock = stock;
}

void Item::setId(int id)
{
	this->id = id;
}

void Item::setObjType(std::string objType)
{
	this->objType = objType;
}

std::string Item::getName()
{
	return name;
}

double Item::getPrice()
{
	return price;
}

std::string Item::getDescription()
{
	return description;
}

int Item::getStock()
{
	return stock;
}

int Item::getId()
{
	return id;
}

std::string Item::getObjType()
{
	return objType;
}


std::string Item::toString()
{
	return getBasicInfo() + getDetails();
}

bool Item::equals(Item item)
{
	if (item.getName() == name && item.getPrice() == price && item.getDescription() == description && item.getId() == id && item.getStock() == stock || item.getId() == id) {
		return true;
	}
	else {
		return false;
	}
}

std::string Item::getDetails()
{
	return std::string();
}

