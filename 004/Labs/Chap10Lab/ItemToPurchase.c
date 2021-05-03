#include<stdio.h>
#include<string.h>

#include "ItemToPurchase.h"

void MakeItemBlank(itemToPurchase* item) {
    strcpy(item->itemName, "none");
    item->itemPrice = 0;
    item->itemQuantity = 0;
}

void PrintItemCost(itemToPurchase* item) {
    printf("%s %d @ $%d = %d\n", item->itemName, item->itemQuantity, item->itemPrice, item->itemPrice * item->itemQuantity);
}