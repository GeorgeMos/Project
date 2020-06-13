#include "Buyer.h"

//Buyer::Buyer(){}
Buyer::Buyer(std::string name, std::string email, std::string address, int postalCode){
	setName(name);
	setAddress(address);
	setEmail(email);
	setPostalCode(postalCode);
	buyerCategory = BRONZE;
	cart = ShoppingCart(buyerCategory);
	cart.setBuyerCategory(buyerCategory);

}

int Buyer::getBuyerCategory()
{
	return buyerCategory;
}

void Buyer::setBuyerCategory()
{
	if (buyerPts >= 100) {
		buyerCategory = SILVER;
	}
	else if (buyerPts >= 200) {
		buyerCategory = GOLD;
	}
	cart.setBuyerCategory(buyerCategory);
}

int Buyer::getBuyerPts()
{
	return buyerPts;
}

void Buyer::setBuyerPts(int buyerPts)
{
	this->buyerPts = buyerPts;
}

void Buyer::awardBonus(int pts)
{
	setBuyerPts(buyerPts + pts);
	setBuyerCategory();
}

void Buyer::placeOrder(Item* item, int quantity)
{
	cart.addItemOrdered(item, quantity);
}

