#pragma once
#include<string>
#include<list>
#include<iostream>
class Item
{
private:
	std::string name;
	double price;
	std::string description;
	int stock;
	int id;
	std::string objType;
public:
	std::string getBasicInfo();
	//setters:
	void setName(std::string name);
	void setPrice(double price);
	void setDescription(std::string description);
	void setStock(int stock);
	void setId(int id);
	void setObjType(std::string objType);
	//getters:
	std::string getName();
	double getPrice();
	std::string getDescription();
	int getStock();
	int getId();
	std::string getObjType();
	//methods:
	std::string toString();
	//Equals method for object comparison:
	bool equals(Item item);
	std::string getDetails();

};

