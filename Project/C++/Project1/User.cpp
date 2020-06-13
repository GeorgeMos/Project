#include "User.h"

void User::setName(std::string name)
{
	this->name = name;
}

void User::setEmail(std::string email)
{
	this->email = email;
}

void User::setAddress(std::string address)
{
	this->address = address;
}

void User::setPostalCode(int postalCode)
{
	this->postalCode = postalCode;
}

std::string User::getName()
{
	return name;
}

std::string User::getEmail()
{
	return email;
}

std::string User::getAddress()
{
	return address;
}

int User::getPostalCode()
{
	return postalCode;
}

bool User::equals(User user)
{
	if (user.getName().compare(name) == 0 && user.getEmail().compare(email) == 0 && user.getAddress().compare(address) == 0 && user.getPostalCode() == postalCode || user.getEmail().compare(email) == 0) {
		return true;
	}
	else {
		return false;
	}
}
