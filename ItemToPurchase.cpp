#include <iostream>
using namespace std;
#include "ItemToPurchase.h"

ItemToPurchase::ItemToPurchase(){
   itemDescription = "none";
   itemName = "none";
   itemPrice= 0;
   itemQuantity = 0;
}

ItemToPurchase::ItemToPurchase(string itemName, string itemDescription, float itemPrice, int itemQuantity){
   this->itemDescription = itemDescription;
   this->itemName = itemName;
   this->itemPrice = itemPrice;
   this->itemQuantity = itemQuantity;
}

void ItemToPurchase::SetName(string itemName){
   this->itemName = itemName;
}
void ItemToPurchase::SetPrice(float itemPrice){
   this->itemPrice = itemPrice;
}
void ItemToPurchase::SetQuantity(int itemQuantity){
   this->itemQuantity = itemQuantity;
}

string ItemToPurchase::GetName() const{
   return itemName;
}
float ItemToPurchase::GetPrice() const{
   return itemPrice;
}
int ItemToPurchase::GetQuantity() const{
   return itemQuantity;
}

void ItemToPurchase::SetDescription(string itemDescription){
   this->itemDescription = itemDescription;
}
string ItemToPurchase::GetDescription() const{
   return itemDescription;
}
void ItemToPurchase::PrintItemCost(){
   cout << itemName << " " << itemQuantity << " @ $" << itemPrice << " = $" << itemPrice*itemQuantity;
   //Bottled Water 10 @ $1 = $10
}
void ItemToPurchase::PrintItemDescription(){
   cout << itemName << ": " << itemDescription;
}