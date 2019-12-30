#include <iostream>
using namespace std;
#include "ShoppingCart.h"

ShoppingCart::ShoppingCart(){
   customerName = "none";
   currentDate = "January 1, 2016";
}
ShoppingCart::ShoppingCart(string customerName, string currentDate){
   this->customerName = customerName;
   this->currentDate = currentDate;
}
string ShoppingCart::GetCustomerName() const{
   return customerName;
}
string ShoppingCart::GetDate() const{
   return currentDate;
}

void ShoppingCart::AddItem(ItemToPurchase item){
   cartItems.push_back(item);
}

void ShoppingCart::RemoveItem(string name){
   bool found = false;
   for(unsigned int a = 0 ; a < cartItems.size() ; a++){
      if(cartItems.at(a).GetName() == name){
         found = true;
         cartItems.erase(cartItems.begin()+a);
      }
   }

   if(!found)
      cout << "Item not found in cart. Nothing removed." << endl;
}
int ShoppingCart::GetNumItemsInCart() const{
   int num = 0;

   for(unsigned int a = 0 ; a < cartItems.size() ; a++){
      num += cartItems.at(a).GetQuantity();
   }
   
   return num;
}
float ShoppingCart::GetCostOfCart() const{
   float cost = 0;
   
   for(unsigned int a = 0 ; a < cartItems.size() ; a++){
      cost += cartItems.at(a).GetPrice() * cartItems.at(a).GetQuantity();
   }
   
   return cost;
}
void ShoppingCart::PrintTotal(){
   cout << customerName << "'s Shopping Cart - " << currentDate << endl;
   cout << "Number of Items: " << GetNumItemsInCart() << endl;
   
   if(GetNumItemsInCart() == 0){
      cout << endl;
      cout << "SHOPPING CART IS EMPTY" << endl;
      cout << endl << "Total: $0" << endl;
   }
   else{
      cout << endl;
      for(unsigned int a = 0 ; a < cartItems.size() ; a++){
         cartItems.at(a).PrintItemCost();
         cout << endl;
      }
      
      cout << endl << "Total: $" << GetCostOfCart() << endl;
   }
}
void ShoppingCart::PrintDescriptions(){
   cout << customerName << "'s Shopping Cart - " << currentDate << endl << endl;

   cout << "Item Descriptions" << endl;
   
   for(unsigned int a = 0 ; a < cartItems.size() ; a++){
      cartItems.at(a).PrintItemDescription();
      cout << endl;
   }
}
void ShoppingCart::ModifyItem(ItemToPurchase item){
   int inI, index;
   bool found = false;
   
   for(unsigned int a = 0 ; a < cartItems.size() ; a++){
      if(cartItems.at(a).GetName() == item.GetName()){
         found = true;
         
         if(cartItems.at(a).GetDescription() != "none" && cartItems.at(a).GetPrice() != 0 && cartItems.at(a).GetQuantity() != 0){
            index = a;
         }
      }
   }
   
   cout << "Enter the new quantity:" << endl;
   cin >> inI;
   
   if(!found){
      cout << "Item not found in cart. Nothing modified." << endl;
   }
   else cartItems.at(index).SetQuantity(inI);
}