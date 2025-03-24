#ifndef SHOPPINGCARTH
#define SHOPPINGCARTH

#include "ItemToPurchase.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

class ShoppingCart{
	public:
		//Constructors

		/*Intilizes the object with default values*/
		ShoppingCart();
		/*Intilizes the object with values as arguements*/
		ShoppingCart(string customer_name, string date);

		//Mutators(Setters)

		//Adds an item to the shopping cart vector
		void AddItem(ItemToPurchase& item);
		//Removes an item from the shopping cart vector
		void RemoveItem(string item_name);
		//Modifies an item within vector, when found, Specifically the quantity
		void ModifyItem(ItemToPurchase& item, int new_quantity);

		
		//Accessor(Getters)

		//Returns the customer name
		string GetCustomerName();
		//Retursn the date
		string GetDate();
		//Returns how many items total are in the cart
		int GetNumItemsInCart();
		//Returns the total cost of the cart
		float GetCostOfCart();
		//Returns the total cost of the cart, but as a string for easier printing
		string StringOfTotal();
		//Returns the item names and descriptions of the entire cart
		string StringOfDescriptions();

	private:
		string customerName;
		string currentDate;
		vector <ItemToPurchase> cartItems;

};




#endif
