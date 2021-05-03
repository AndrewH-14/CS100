#ifndef ITEM_TO_PURCHASE_H
#define ITEM_TO_PURCHASE_H

typedef struct itemToPurchase_struct {
    char* itemName;
    int itemPrice;
    int itemQuantity;
} itemToPurchase;

void MakeItemBlank(itemToPurchase* item);

void PrintItemCost(itemToPurchase* item);

#endif