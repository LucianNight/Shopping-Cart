#include "ShoppingCart.h"

#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

//Constructors

/*Intilizes the object with default values*/
ShoppingCart::ShoppingCart(){
	/*Default values for the class*/
	customerName = "none";
	currentDate = "January 1, 2016";
}
/*Intilizes the object with values as arguements*/
ShoppingCart::ShoppingCart(string customer_name, string date) {
	/*Sets the values to whatever is passed to this constructor with the given parameters*/
	this->customerName = customer_name;
	this->currentDate = date;
}

//Mutators(Setters)

//Adds an item to the shopping cart vector
void ShoppingCart::AddItem(ItemToPurchase& item) {
	/*This just appends what ever item is passes to the cartItems vector
	effectively added it to the online shopping cart*/
	ShoppingCart::cartItems.push_back(item);

}

//Removes an item from the shopping cart vector
void ShoppingCart::RemoveItem(string item_name) {
	//create a new vector, you'll see why
	vector <ItemToPurchase> newCart;
	unsigned int i;

	/*We're gonna step through the original vector comparing every name and if it is NOT
	equal to the one we want to remove, we append it to the new vector*/
	for (i = 0; i < ShoppingCart::cartItems.size(); ++i) {
		if (item_name != ShoppingCart::cartItems.at(i).GetName()) {
			newCart.push_back(ShoppingCart::cartItems.at(i));
		
		}
	}
	/*This check is to see if the new vector is smaller, meaning if the the item was found, 
	without having to use a bool variable, if it is: we reassign the value of the original vector to the new one.
	It will resize itself and remove the item*/
	if (newCart.size() < ShoppingCart::cartItems.size()) {
		ShoppingCart::cartItems = newCart;
	}
	else {
		/*If the new vector is not smaller, then nothing was found to be removed*/
		cout << "Item not found in cart. Nothing removed.\n\n";
	}
	
}

//Modifies an item within vector, when found, Specifically the quantity
void ShoppingCart::ModifyItem(ItemToPurchase& item, int new_quantity) {
	unsigned int i;
	bool found = false;
	string description;
	float price;

	/*We're gonna step through the vector again to look for the name of the item 
	we have passed over within the shopping cart. When found, we flip the found variable and break the loop,
	setting i to the desired value*/
	for (i = 0; i < ShoppingCart::cartItems.size(); ++i) {
		if (ShoppingCart::cartItems.at(i).GetName() == item.GetName()) {
			found = true;
			break;
		}
	}
	if (found) {
		/*one thing to note about these is they are all if's on the same level 
		so whether they are all true or al false they will checked equally*/
		/*If it is not equal to the defualt value we will reset (but it is since it's a new item)*/
		if (item.GetDescription() != "none") {
			cout << "Enter the new description:" << endl;
			cin >> description;
			item.SetDescription(description);
		}
		/*If it is not equal to the defualt value we will reset (but it is since it's a new item)*/
		if (item.GetPrice() != 0.0) {
			cout << "Enter the new price:" << endl;
			cin >> price;
			item.SetPrice(price);
		}
		/*This is really what we are looking for. If the new quantity (the one entered)
		is not equal to what is already store in the item's attribute, we will reset*/
		if (new_quantity != ShoppingCart::cartItems.at(i).GetQuantity()) {
			ShoppingCart::cartItems.at(i).SetQuantity(new_quantity);
		}
	}
	/*And of course if found is false we say that, in so many words*/
	else {
		cout << "Item not found in cart. Nothing modified.\n\n";
	}
}

//Accessor(Getters)

/*Simply returns the customer name*/
string ShoppingCart::GetCustomerName() { return customerName; }

/*Simply returns the current date*/
string ShoppingCart::GetDate() { return currentDate;}

//Returns how many items total are in the cart
int ShoppingCart::GetNumItemsInCart() { 
	unsigned int i;
	int total_items = 0;

	/*Using an accumulator, we step through the vector and add the quantity of each item to it
	reurtning the final value*/
	for (i = 0; i < ShoppingCart::cartItems.size(); ++i) {
		total_items += ShoppingCart::cartItems.at(i).GetQuantity();
	}
	return total_items;
}

//Returns the total cost of the cart
float ShoppingCart::GetCostOfCart() {
	float total = 0.0;
	unsigned int i;

	/*Using another accumulator, but this time we step through 
	and multiply the price by the quantity of each item and then
	add it all to the total and return that value*/
	for (i = 0; i < ShoppingCart::cartItems.size(); ++i) {
		total += (ShoppingCart::cartItems.at(i).GetPrice() * ShoppingCart::cartItems.at(i).GetQuantity());
	}

	return total;
}

//Returns the total cost of the cart, but as a string for easier printing
string ShoppingCart::StringOfTotal() {
	ostringstream printCartTotal;
	string cartTotal;
	unsigned int i;

	printCartTotal << "OUTPUT SHOPPING CART\n\n" << customerName << "'s Shopping Cart - " << currentDate << "\n";
	printCartTotal << "Number of Items: " << GetNumItemsInCart() << "\n\n";
	/*intially we check if there is anything in the cart if there is we grab the 
	StringOfItemCost to display the cost of each item individually
	and then the total from GetCostOfCart. Notice we ostream to get a perfect display and then use .str()
	to convert it to a string*/
	if (GetNumItemsInCart() > 0) {
		for (i = 0; i < ShoppingCart::cartItems.size(); ++i) {
			printCartTotal << ShoppingCart::cartItems.at(i).StringOfItemCost() << "\n";
		}
		printCartTotal << setprecision(2) << fixed << "\n" << "Total: $" << GetCostOfCart() << "\n";
		cartTotal = printCartTotal.str() + "\n";
	}
	else {
		/*if the check we made if false, the cart is empty and we ostream, convert, and return that instead*/
		printCartTotal << setprecision(2) << fixed << "SHOPPING CART IS EMPTY\n\nTotal: $" << GetCostOfCart() << "\n";
		cartTotal = printCartTotal.str() + "\n";
	}

	return cartTotal;
}

//Returns the item names and descriptions of the entire cart
string ShoppingCart::StringOfDescriptions() {
	ostringstream cartDescriptions;
	string fullCartDescriptions;
	unsigned int i;

	cartDescriptions << "OUTPUT ITEMS' DESCRIPTIONS\n\n" <<  customerName << "'s Shopping Cart - " << currentDate << "\n\n";
	cartDescriptions << "Item Descriptions\n";

	/*Similar to above, we step through and call the StringOfItemDescription() on each of the items in the vector
	and push them into the ostream and them convert, set it to the string variable and return it*/
	for (i = 0; i < ShoppingCart::cartItems.size(); ++i) {
		cartDescriptions << ShoppingCart::cartItems.at(i).StringOfItemDescription() + "\n"; 
	}
	fullCartDescriptions = cartDescriptions.str() + "\n";

	return fullCartDescriptions;
}