#pragma once
#include<iostream>
#include"User.h"
#include"Eshop.h"

class Menu
{
private:
	User* loggedUser;
	Eshop* shop;
	Owner* owner;

public:
	Menu(Eshop* shop, Owner* owner);
	void login();
	void mainMenu();
	void browseStore(bool isOwner);
	void addToCart();

};

