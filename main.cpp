#include "Utility.h"
#include "ShoppingCart.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

int main() {
	string customer_Name;
	string current_Date;
	ItemToPurchase item;
	char menu_choice;

	//Gets the input for the customer name and current date, and updates variables
	GetCustNameAndDate(customer_Name, current_Date);
	//Prints them to the screen
	PrintCustNameAndDate(customer_Name, current_Date);
	
	//Intitlizes the shoppingCart object with those inputs
	ShoppingCart myCart = ShoppingCart(customer_Name, current_Date); 
	
	//Prints the menu options and gets the first choice
	menu_choice = GetMenuChoice();

	//Calls the menu execution loop
	ExecuteMenu(menu_choice, myCart);
	
   
   return 0;
}