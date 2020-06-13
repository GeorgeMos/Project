#pragma once
#include "User.h"
#include<string>
class Owner :public User
{
private:
	bool isOwner = true;
public:
	Owner();
	Owner(std::string name, std::string email, std::string address, int postalCode);
};

