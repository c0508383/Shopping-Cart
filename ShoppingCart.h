#ifndef SHOPPING_CART_H
#define SHOPPING_CART_H
#include <vector>
#include <string>
#include "ItemToPurchase.h"
using namespace std;


class ShoppingCart{
   public:
      ShoppingCart();
      ShoppingCart(string customerName, string currentDate);
      string GetCustomerName() const;
      string GetDate() const;
      void AddItem(ItemToPurchase item);
      void RemoveItem(string name);
      int GetNumItemsInCart() const;
      float GetCostOfCart() const;
      void PrintTotal();
      void PrintDescriptions();
      void ModifyItem(ItemToPurchase item);
   private:
      string customerName;
      string currentDate;
      vector<ItemToPurchase> cartItems;
};

#endif