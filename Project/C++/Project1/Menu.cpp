#include "Menu.h"
#include<iostream>
#include<stdlib.h>

Menu::Menu(Eshop* shop, Owner* owner)
{
	this->shop = shop;
	this->owner = owner;
}

void Menu::login()
{
	//Not the best option but there is no problen here.
	system("cls");
	std::string email = "";
	std::cout << "\tWelcome to PaperWorks!\n";
	do {
		std::cout << "Enter your email: ";
		std::cin >> email;
		try {
			loggedUser = shop->checkBuyer(email);
		}
		catch (std::invalid_argument& e) {
			std::string choice;
			std::cout << e.what() << ". Would you like to Sign Up? (yes/no):";
			std::cin >> choice;
			std::cin.ignore();
			if (choice.compare("yes") == 0) {
				std::string name, address;
				int postalCode;
				std::cout << "Enter your Name: ";
				std::getline(std::cin, name);
				std::cout << "Enter your Address: ";
				std::getline(std::cin, address);
				std::cout << "Enter your Postal Code: ";
				std::cin >> postalCode;
				loggedUser = new Buyer(name, email, address, postalCode);
				shop->addBuyer(new Buyer(name, email, address, postalCode));
			}
			else if (choice.compare("no") == 0) {
				email = "";
			}
			else {
				std::cout << "Invalid option. Please enter yes/no\n";
				email = "";
			}
		}
	} while (email.compare("") == 0);
	mainMenu();
}

void Menu::mainMenu()
{
	int choice;
	do {
		//Not the best option but there is no problen here.
		system("cls");
		std::cout << "\tPaperWorks\n\n";
		if (loggedUser->getEmail().compare(owner->getEmail()) == 0) {
			//Owner's Menu
			choice = 0;
			std::cout << "\tWelcome " << owner->getName() << "  (Owner menu mode)\n\n";
			std::cout << "Name: " << loggedUser->getName() << "\nEmail: " << loggedUser->getEmail() << "\nAddress: " << loggedUser->getAddress() << "\n\n";
			std::cout << "1:Browse store\n" << "2:Check status\n" << "3:Log out\n" << "4:Quit\n";
			std::cout << "=>";
			std::cin >> choice;
			if (choice == 1) {
				browseStore(true);

			}
			else if (choice == 2) {
				//buyer modify choice
				int bMod_choice;
				std::string email;
				do {
					system("cls");
					shop->checkStatus();
					std::cout << "\n1:View buyers cart\n2:Delete buyer\n3:Back\n=>";
					std::cin >> bMod_choice;
					if (bMod_choice == 1) {
						std::cout << "Enter buyers email\n=>";
						std::cin >> email;
						shop->getBuyerByEmail(email)->cart.showCart();
						std::cin.ignore(2);
					}
					else if (bMod_choice == 2) {
						std::cout << "Enter buyers email\n=>";
						std::cin >> email;
						shop->removeBuyer(shop->getBuyerByEmail(email));
					}
				} while (bMod_choice != 3);
			}
			else if (choice == 3) {
				login();
				break;
				
			}
			else if (choice == 4) {
				//Proper object cleanup and program termination
				exit(0);
			}
			//f (choice <= 3) {
				//std::cin.ignore();
			//}
			
		}
		else {
			//Buyer's Menu
			choice = 0;
			std::cout << "\tWelcome " << loggedUser->getName() << "\n\n";
			std::cout << "Name: " << loggedUser->getName() << "\nEmail: " << loggedUser->getEmail() << "\nAddress: " << loggedUser->getAddress() << "\nPoints: " << ((Buyer*)loggedUser)->getBuyerPts() << "\nCategory: ";
			if (((Buyer*)loggedUser)->getBuyerCategory() == 0) {
				std::cout << "Bronze\n\n";
			}
			else if (((Buyer*)loggedUser)->getBuyerCategory() == 1) {
				std::cout << "Silver\n\n";
			}
			else {
				std::cout << "Gold\n\n";
			}
			std::cout << "1:Browse store\n2:View cart contents\n3:Checkout\n4:Log out\n5:Quit\n";
			std::cout << "=>";
			std::cin >> choice;
			if (choice == 1) {
				browseStore(false);

			}
			else if (choice == 2) {
				//checkout choice
				int ch_choice;
				do {
					//Not the best option but there is no problen here.
					system("cls");
					//Casting loggedUser from User* to Buyer* to gain access to his cart.
					((Buyer*)loggedUser)->cart.showCart();
					std::cout << "\n1:Continue to checkout\n2:Change item quantity\n3:Remove Item\n4:Clear cart\n5:Back\n=>";
					std::cin >> ch_choice;
					if (ch_choice == 1) {
						//Not the best option but there is no problen here.
						system("cls");
						try {
							std::string confirmation;
							((Buyer*)loggedUser)->cart.showCart();
							std::cout << "\nContinue to checkout? (yes/no): ";
							std::cin >> confirmation;
							if (confirmation.compare("yes") == 0) {
								((Buyer*)loggedUser)->awardBonus(((Buyer*)loggedUser)->cart.calculateNet() * 0.1);
								((Buyer*)loggedUser)->cart.checkout(true);
							}
							else {
								((Buyer*)loggedUser)->cart.checkout(false);
							}
						}
						catch (std::invalid_argument& e) {
							std::cout << e.what();
							std::cin.ignore();
						}
					}
					else if (ch_choice == 2) {
						int id;
						int quantity;
						std::cout << "Enter item id\n=>";
						std::cin >> id;
						std::cout << "Enter new quantity\n=>";
						std::cin >> quantity;
						try {
							((Buyer*)loggedUser)->cart.changeItemOrderedQuantity(shop->getItemByld(id), quantity);
						}
						catch (std::invalid_argument& e) {
							std::cout << e.what();
							std::cin.ignore();
						}
					}
					else if (ch_choice == 3) {
						int id;
						std::cout << "Enter item id\n=>";
						std::cin >> id;
						try {
							((Buyer*)loggedUser)->cart.removeItemOrdered(shop->getItemByld(id));
						}
						catch (std::invalid_argument& e) {
							std::cout << e.what();
							std::cin.ignore();
						}
					}
					else if (ch_choice == 4) {
						((Buyer*)loggedUser)->cart.clearCart();
					}
				} while (ch_choice > 5); 

			}
			else if (choice == 4) {
				login();
				break;

			}
			else if (choice == 5) {
				//Proper object cleanup and program termination
				exit(0);
			}
			else if (choice == 3) {
				std::string confirmation;
				((Buyer*)loggedUser)->cart.showCart();
				std::cout << "\nContinue to checkout? (yes/no): ";
				std::cin >> confirmation;
				if (confirmation.compare("yes") == 0) {
					((Buyer*)loggedUser)->awardBonus(((Buyer*)loggedUser)->cart.calculateNet() * 0.1);
					((Buyer*)loggedUser)->cart.checkout(true);
				}
				else {
					((Buyer*)loggedUser)->cart.checkout(false);
				}
			}
		}
		std::cin.get();
	} while (choice != 4);
}

void Menu::browseStore(bool isOwner)
{
	//Browse store menu choice
	int bs_choice;
	if (isOwner) {
		//Owner browse store menu
		do {
			//Not the best option but there is no problen here.
			system("cls");
			std::cout << "1:Show product categories\n2:Back\n=>";
			std::cin >> bs_choice;
			if (bs_choice == 1) {
				//Category choice
				int cat_choice;
				do {
					//Not the best option but there is no problen here.
					system("cls");
					shop->showCategories();
					std::cout << "\nChoose a category to view the items in that category or enter 5 to go back\n =>";
					std::cin >> cat_choice;
					if (cat_choice == 1) {
						shop->showProductsInCategory("pen");
					}
					else if (cat_choice == 2) {
						shop->showProductsInCategory("notebook");
					}
					else if (cat_choice == 3) {
						shop->showProductsInCategory("paper");
					}
					else if (cat_choice == 4) {
						shop->showProductsInCategory("pencil");
					}
					else if (cat_choice == 5) {
						std::cout << "Press enter to go back\n";
					}
					if (cat_choice <= 4) {
						//Modify choice
						int m_choice;
						std::cout << "\n1:Modify item\n2:Back\n=>";
						std::cin >> m_choice;
						if (m_choice == 1) {
							int itemId;
							int quantity;
							std::cout << "Enter item id\n=>";
							std::cin >> itemId;
							std::cout << "Enter new quantity\n=>";
							std::cin >> quantity;
							try {
								shop->updateItemStock(shop->getItemByld(itemId), quantity);
							}
							catch (std::invalid_argument& e) {
								std::cout << e.what();
								std::cin.ignore();
							}
						}
					}
					std::cin.get();
				} while (cat_choice != 5);
			}
			else if (bs_choice == 2) {
				std::cout << "Press enter to go back\n";
			}
			std::cin.get();
		} while (bs_choice != 2);
	}
	else {
		//Buyer browse store menu
		do {
			//Not the best option but there is no problen here.
			system("cls");
			std::cout << "1:Show product categories\n2:Back\n=>";
			std::cin >> bs_choice;
			if (bs_choice == 1) {
				//Category choice
				int cat_choice;
				do {
					//Not the best option but there is no problen here.
					system("cls");
					shop->showCategories();
					std::cout << "\nChoose a category to view the items in that category or enter 5 to go back\n =>";
					std::cin >> cat_choice;
					if (cat_choice == 1) {
						shop->showProductsInCategory("pen");
					}
					else if (cat_choice == 2) {
						shop->showProductsInCategory("notebook");
					}
					else if (cat_choice == 3) {
						shop->showProductsInCategory("paper");
					}
					else if (cat_choice == 4) {
						shop->showProductsInCategory("pencil");
					}
					else if (cat_choice == 5) {
						std::cout << "Press enter to go back\n";
					}
					if (cat_choice <= 4) {
						try {
							addToCart();
						}
						catch (std::invalid_argument& e) {
							std::cout << e.what();
							std::cin.ignore();
						}
						
					}
					std::cin.get();
				} while (cat_choice != 5);
			}
			else if (bs_choice == 2) {
				std::cout << "Press enter to go back\n";
			}
			std::cin.get();
		} while (bs_choice != 2);

	}
}

void Menu::addToCart()
{
	std::cout << "\n1:Add item to cart\n2:Back\n=>";
	//Buy choice
	int b_choice;
	int item_id;
	int quantity;
	std::cin >> b_choice;
	if (b_choice == 1) {
		std::cout << "\nEnter item id\n=>";
		std::cin >> item_id;
		std::cout << "\nEnter quantity\n=>";
		std::cin >> quantity;
		((Buyer*)loggedUser)->placeOrder(shop->getItemByld(item_id), quantity);
		//Return back to store menu
		mainMenu();
	}
	
}


