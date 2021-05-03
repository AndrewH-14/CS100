#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include "ItemToPurchase.h"

typedef struct shoppingcart {
    char customerName[50];
    char currentDate[50];
    ItemToPurchase cartItems[10];
    int cartSize;
} ShoppingCart;

ShoppingCart AddItem(ItemToPurchase item, ShoppingCart cart);

ShoppingCart RemoveItem(char name[], ShoppingCart cart);

ShoppingCart ModifyItem(char item[50], ShoppingCart cart);

int GetNumItemsInCart(ShoppingCart cart);

int GetCostOfCart(ShoppingCart cart);

void PrintTotal(ShoppingCart cart);

void PrintDescriptions(ShoppingCart cart);

#endif