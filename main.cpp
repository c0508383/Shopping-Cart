#include <iostream>
using namespace std;

#include "ItemToPurchase.h"
#include "ShoppingCart.h"

void PrintMenu(ShoppingCart &cart);
int main() {
   std::string name,date;
   
   std::cout << "Enter customer's name:" << std::endl;
   std::getline(std::cin, name);
   std::cout << "Enter today's date:" << std::endl;
   std::getline(std::cin, date);

   ShoppingCart cart(name,date);
   
   std::cout << std::endl;
   std::cout << "Customer name: " << name << std::endl;
   std::cout << "Today's date: " << date << std::endl;
   
   std::cout << std::endl;
   PrintMenu(cart);
   
   return 1;
}

void PrintMenu(ShoppingCart &cart){
   std::cout << "MENU" << std::endl;
   std::cout << "a - Add item to cart" << std::endl;
   std::cout << "d - Remove item from cart" << std::endl;
   std::cout << "c - Change item quantity" << std::endl;
   std::cout << "i - Output items' descriptions" << std::endl;
   std::cout << "o - Output shopping cart" << std::endl;
   std::cout << "q - Quit" << std::endl;
   std::cout << std::endl;
   
   std::istream input;
   float inF = 0;
   int inI = 0;
   std::string inS = "";
   char inC = 'q';

   std::cin.clear();

   std::cout << "Choose an option:" << std::endl;
   input >> inC;
   
   while(inC != 'a' && inC != 'd' && inC != 'c' && inC != 'i' && inC != 'o' && inC != 'q'){
      std::cout << "Choose an option:" << std::endl;
      std::cin >> inC;
   }
   
   std::getline(std::cin,inS);
   
   ItemToPurchase newItem;
   switch(inC){
      case 'a':
         std::cout << "ADD ITEM TO CART" << std::endl;
         std::cout << "Enter the item name:" << std::endl;
         std::getline(std::cin, inS);
         newItem.SetName(inS);
         std::cout << "Enter the item description:" << std::endl;
         std::getline(std::cin, inS);
         newItem.SetDescription(inS);
         std::cout << "Enter the item price:" << std::endl;
         
         while((std::cin >> inF) && (std::cin.bad()) && (std::cin.eof())){
            std::cin >> inF;
            newItem.SetPrice(inF);
         }
         std::cin.clear();

         std::cout << "Enter the item quantity:" << std::endl;
         std::cin >> inI;
         newItem.SetQuantity(inI);
         
         cart.AddItem(newItem);

         std::cout << endl;
         break;
      case 'd':
         std::cout << "REMOVE ITEM FROM CART" << std::endl;
         std::cout << "Enter name of item to remove:" << std::endl;
         std::getline(std::cin, inS);
         cart.RemoveItem(inS);
         std::cout << std::endl;
         break;
      case 'c':
         std::cout << "CHANGE ITEM QUANTITY" << std::endl;
         std::cout << "Enter the item name:" << std::endl;
         std::getline(std::cin, inS);
         newItem.SetName(inS);
         cart.ModifyItem(newItem);
         std::cout << std::endl;
         break;
      case 'i':
         std::cout << "OUTPUT ITEMS' DESCRIPTIONS" << std::endl;
         cart.PrintDescriptions();
         std::cout << std::endl;
         break;
      case 'o':
         std::cout << "OUTPUT SHOPPING CART" << std::endl;
         cart.PrintTotal();
         std::cout << std::endl;
         break;
      case 'q':
         break;
      default:
         break;
   }

   if(inC != 'q')
      PrintMenu(cart);
}