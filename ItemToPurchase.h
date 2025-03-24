#ifndef ITEMTOPURCHASEH
#define ITEMTOPURCHASEH 

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
using namespace std;


class ItemToPurchase{
	public:
		//constructors

		/*Intilizes the object with default values*/
		ItemToPurchase();
		/*Intilizes the object with values as arguements*/
		ItemToPurchase(string item_name, string item_description, float item_price, int item_quantity);

		//Mutators (setters)

		//Sets the name of the item with the arguement passed
		void SetName(string item_Name);
		//Sets the description of the item with the arguement passed
		void SetDescription(string item_description);
		//Sets the price of the item with the arguement passed
		void SetPrice(float item_price);
		//Sets the quantity of the item with the arguement passed
		void SetQuantity(int item_quantity);

		//Accessors (Getters)

		//Returns the name of the item
		string GetName();
		//Returns the description of the item
		string GetDescription();
		//Returns the price of the item
		float GetPrice() const;
		//Returns the quantity of the item
		int GetQuantity() const;
		//Returns a string of the item price and quantity multiplied
		string StringOfItemCost();
		//Returns a string of the item name and description displayed for end user
		string StringOfItemDescription();



	private:
		string itemName;
		string itemDescription;
		double itemPrice;
		int itemQuantity;

};

#endif