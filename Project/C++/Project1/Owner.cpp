#include "Owner.h"

Owner::Owner(){}

Owner::Owner(std::string name, std::string email, std::string address, int postalCode)
{
	setName(name);
	setEmail(email);
	setAddress(address);
	setPostalCode(postalCode);
}
