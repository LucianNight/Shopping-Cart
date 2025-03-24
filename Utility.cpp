#include "Utility.h"

#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

/*Function to get the input for the customer name and current date
and update the varibles in main */
void GetCustNameAndDate(string& name, string& currDate) {
	string custName;
	string currDay;
	cout << "Enter customer's name:" << endl;
	getline(cin, custName);
	name = custName;
	cout << "Enter today's date:" << endl;
	getline(cin, currDay);
	currDate = currDay;
}

//Function to print the updated customer name a date variables to the screen
void PrintCustNameAndDate(string name, string currDate) {
	cout << endl;
	cout << "Customer name: " << name << endl;
	cout << "Today's date: " << currDate << endl;
	cout << endl; 
}

//Function to display the menu option to the end user
void PrintMenu() {
	cout << "MENU" << endl;
	cout << "a - Add item to cart" << endl;
	cout << "d - Remove item from cart" << endl;
	cout << "c - Change item quantity" << endl;
	cout << "i - Output items' descriptions" << endl;
	cout << "o - Output shopping cart" << endl;
	cout << "q - Quit"; 
}

//Prints the menu and returns the menu choice
char GetMenuChoice() {
	char choice;
	PrintMenu();
	cout << endl;
	cout << "\nChoose an option:\n";
	cin >> choice; 

	return choice;
}

/*Function to operate the menu option(it passes the char choice and the list
and updates the cart by passing it by reference)*/
void ExecuteMenu(char choice, ShoppingCart& shoppingCart) {
	ItemToPurchase cartItem;

	//The main
	while (choice != 'q') {	
		//This is an input validation loop so if they do not input one of the valid options it will continue to ask for input
		while ((choice != 'a') && (choice != 'd') && (choice != 'c') && (choice != 'i') && (choice != 'o') && (choice != 'q')) {
			cout << "Choose an option:" << endl;
			cin >> choice;
		}
		switch (choice) {
		case 'a':
			//passes the item and the cart down the line to the helper function add the item
			addItem(cartItem, shoppingCart);
			break;
		case 'd':
			//passes the item and the cart down the line to the helper function remove the item
			removeItem(shoppingCart, cartItem);
			break;
		case 'c':
			//passes the item and the cart down the line to the helper function change the quantity
			changeQuantity(shoppingCart, cartItem);
			break;
		case 'i':
			//passes the cart down the line to the helper function print the descriptions
			printCartDescriptions(shoppingCart);
			break;
		case 'o':
			//passes the cart down the line to the helper function print the total of the items in the cart
			printCartTotal(shoppingCart);
			break;
		default:
			break;
		}
		/*This extra check is because once it breaks out of the switch
		we need to reprint the menu only if they do not enter 'q'*/
		if (choice == 'q') {
			break;
		}
		else {
			//reprints menu and gets the choice
			choice = GetMenuChoice();
		}
	}
}

//Function to aid in the call the ShoppingCart.AddItem() function
void addItem(ItemToPurchase& item, ShoppingCart& cart_item) {
	string item_name; 
	string description;
	float price; 
	int quantity; 

	/*All of these inputs prompts and inputs are for the initalization of each item added to the cart*/
	cout << "ADD ITEM TO CART" << endl;
	cout << "Enter the item name:" << endl;
	cin.ignore();
	getline(cin, item_name); 
	
	cout << "Enter the item description:" << endl;
	getline(cin, description);
	
	cout << "Enter the item price:" << endl;
	cin >> price;
	
	cout << "Enter the item quantity:" << endl;
	cin >> quantity;
	item = ItemToPurchase(item_name, description, price, quantity);

	/*After setting the ItemToPurchase object up we send it over 
	to the AddItem function in the ShoppingCart class*/
	cart_item.AddItem(item);	
}

//Function to aid in the call the ShoppingCart.RemoveItem() function
void removeItem(ShoppingCart& cart, ItemToPurchase& item) {
	string item_name;
	
	/*All this does is prompt for input and send the name of the item 
	you wish to remove over to the RemoveItem function*/
	cout << "REMOVE ITEM FROM CART" << endl;
	cout << "Enter name of item to remove: " << endl;
	cin.ignore();
	getline(cin, item_name);
	cart.RemoveItem(item_name);
}

//Function to aid in the call the ShoppingCart.ChangeQuantityItem() function
void changeQuantity(ShoppingCart& cart, ItemToPurchase& item) {
	ItemToPurchase newItem  = ItemToPurchase();
	string item_name;
	int newQuantity;
	
	/*This gets the name of the item you wish to change and the new quantity and 
	then sets the new quantity and name to a new item and 
	passes the new item and new quantity to the ModifyItem function*/
	cout << "CHANGE ITEM QUANTITY" << endl;
	cout << "Enter the item name:" << endl;
	cin.ignore(); 
	getline(cin, item_name);
	newItem.SetName(item_name);
	cout << "Enter the new quantity:" << endl;
	cin >> newQuantity;
	newItem.SetQuantity(newQuantity); 
	cart.ModifyItem(newItem, newQuantity);
}

//Function to aid in the call the ShoppingCart.StringOfTotal() function
void printCartTotal(ShoppingCart& cart) {
	//This was just for solidarity just cout's the returned string from the function below
	cout << cart.StringOfTotal();
}

//Function to aid in the call the ShoppingCart.StringOfDescriptions() function
void printCartDescriptions(ShoppingCart& cart) {
	//This was just for solidarity just cout's the returned string from the function below
	cout << cart.StringOfDescriptions();
}

