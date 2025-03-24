#ifndef UTILITYH
#define UTILITYH

#include "ShoppingCart.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream>
#include <string>

using namespace std;
/*Function to get the input for the customer name and current date 
and update the varibles in main */
void GetCustNameAndDate(string& name, string& currDate);

//Function to print the updated customer name a date variables to the screen
void PrintCustNameAndDate(string name, string currDate);

//Function to display the menu option to the end user
void PrintMenu();

//Prints the menu and returns the menu choice
char GetMenuChoice();

/*Function to operate the menu option(it passes the char choice and the list 
and updates the cart by passing it by reference)*/
void ExecuteMenu(char choice, ShoppingCart& shoppingCart);

//Function to aid in the call the ShoppingCart.AddItem() function
void addItem(ItemToPurchase& item, ShoppingCart& cart_item);

//Function to aid in the call the ShoppingCart.RemoveItem() function
void removeItem(ShoppingCart& cart, ItemToPurchase& item);

//Function to aid in the call the ShoppingCart.ChangeQuantityItem() function
void changeQuantity(ShoppingCart& cart, ItemToPurchase& item);

//Function to aid in the call the ShoppingCart.StringOfTotal() function
void printCartTotal(ShoppingCart& cart);

//Function to aid in the call the ShoppingCart.StringOfDescriptions() function
void printCartDescriptions(ShoppingCart& cart);
#endif
