#ifndef ITEM_TO_PURCHASE_H
#define ITEM_TO_PURCHASE_H

#include <string>
using namespace std;

class ItemToPurchase{
   public:
      ItemToPurchase();
      ItemToPurchase(string itemName, string itemDescription, float itemPrice, int itemQuantity);
      void SetName(string itemName);
      void SetPrice(float itemPrice);
      void SetQuantity(int itemQuantity);
      string GetName() const;
      float GetPrice() const;
      int GetQuantity() const;
      void SetDescription(string itemDescription);
      string GetDescription() const;
      void PrintItemCost();
      void PrintItemDescription();
   private:
      string itemDescription;
      string itemName;
      float itemPrice;
      int itemQuantity;
};

#endif