#pragma once
#include<string>
class User {
private:
	std::string name;
	std::string email;
	std::string address;
	int postalCode;
public:
	void setName(std::string name);
	void setEmail(std::string email);
	void setAddress(std::string address);
	void setPostalCode(int postalCode);
	std::string getName();
	std::string getEmail();
	std::string getAddress();
	int getPostalCode();
	//Equals method for object comparison:
	bool equals(User user);
};

