#include<iostream>
#include<string>
#include"Buyer.h"
#include"Owner.h"
#include"Pen.h"
#include"Pencil.h"
#include"Notebook.h"
#include"Paper.h"
#include"Eshop.h"
#include"Menu.h"



int main() {
	Owner bob = Owner("Bob", "owner@gmail.com", "denSouLew", 123456);
	Buyer john = Buyer("John", "JohnJohn@gmail.com", "otinane", 1234);
	Buyer nick = Buyer("Nick", "NickNick@gmail.com", "otinane", 56789);
	Pen pen1 = Pen("Black pen", 1, "A pen 1", 100, 1, "Black", 0.5);
	Pen pen2 = Pen("Blue pen", 1, "A pen 2", 100, 2, "Blue", 0.7);
	Pen pen3 = Pen("Red pen", 1, "A pen 3", 100, 3, "Red", 0.7);
	Pencil pencil1 = Pencil("HB pencil", 0.5, "A pencil 1", 340, 4, 0.7, Pencil::HB);
	Pencil pencil2 = Pencil("B pencil", 0.5, "A pencil 1", 340, 5, 0.5, Pencil::B);
	Pencil pencil3 = Pencil("H pencil", 0.5, "A pencil 1", 340, 6, 0.5, Pencil::H);
	Notebook book1 = Notebook("3 Section Notebook", 5, "book1", 50, 7, 3);
	Notebook book2 = Notebook("2 Section Notebook", 3.5, "book1", 50, 8, 2);
	Notebook book3 = Notebook("1 Section Notebook", 2.5, "book1", 50, 9, 1);
	Paper paper1 = Paper("Very Thicc Paper", 8, "paper1", 5, 10, 500, 300);
	Paper paper2 = Paper("Medium Thicc Paper", 7, "paper1", 5, 11, 350, 200);
	Paper paper3 = Paper("Little Thicc Paper", 6, "paper1", 5, 12, 250, 100);
	Eshop shop = Eshop("PapperWorks", &bob);
	Menu menu = Menu(&shop, &bob);
	shop.addBuyer(&john);
	shop.addItem(&pen1);
	shop.addItem(&pen2);
	shop.addItem(&pen3);
	shop.addItem(&pencil1);
	shop.addItem(&pencil2);
	shop.addItem(&pencil3);
	shop.addItem(&book1);
	shop.addItem(&book2);
	shop.addItem(&book3);
	shop.addItem(&paper1);
	shop.addItem(&paper2);
	shop.addItem(&paper3);
	menu.login();

	return 0;
}