#include "ItemToPurchase.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
using namespace std;

//Constructors

/*Intilizes the object with default values*/
ItemToPurchase::ItemToPurchase() {
	/*Default values for the class*/
	itemName = "none";
	itemDescription = "none";
	itemPrice = 0.0;
	itemQuantity = 0;

}
/*Intilizes the object with values as arguements*/
ItemToPurchase::ItemToPurchase(string item_name, string item_description, float item_price, int item_quantity) {
	/*Sets the values to whatever is passed to this constructor with the given parameters*/
	itemName = item_name;
	itemDescription = item_description;
	itemPrice = item_price;
	itemQuantity = item_quantity;
}

//Mutators(Setters)

//Sets the name of the item with the arguement passed
void ItemToPurchase::SetName(string item_Name) { itemName = item_Name; }

//Sets the description of the item with the arguement passed
void ItemToPurchase::SetDescription(string item_description) { itemDescription = item_description; }

//Sets the price of the item with the arguement passed
void ItemToPurchase::SetPrice(float item_price) { itemPrice = item_price;	}

//Sets the quantity of the item with the arguement passed
void ItemToPurchase::SetQuantity(int item_quantity) { itemQuantity = item_quantity; }

//Accessors (Getters)

//Returns the name of the item
string ItemToPurchase::GetName() { return itemName;	}

//Returns the description of the item
string ItemToPurchase::GetDescription()  { return itemDescription; }

//Returns the price of the item
float ItemToPurchase::GetPrice() const { return itemPrice; }

//Returns the quantity of the item
int ItemToPurchase::GetQuantity() const { return itemQuantity; }

//Returns a string of the item price and quantity multiplied
string ItemToPurchase::StringOfItemCost(){
	ostringstream cost;
	string fullCost;

	/*Gets the item cost and quantity and pushes them into ostream variable
	then multiplies them(within the same line), then converts it to a string 
	while assigning that to the
	string variable and returning the string*/
	cost << setprecision(2) << fixed <<  GetName() << " " << GetQuantity() << " @ $" << GetPrice() << " = $" << (GetPrice() * GetQuantity());
		
	fullCost = cost.str();

	return fullCost;
}

//Returns a string of the item name and description displayed for end user
string ItemToPurchase::StringOfItemDescription(){
	ostringstream description;
	string fullDescription;

	/*Gets the item name and descriptions and pushes them into ostream variable
	then converts it to a string while assigning that to the 
	string variable and returning the string*/
	description << GetName() << ": " << GetDescription();

	fullDescription = description.str();

	return fullDescription;

}


