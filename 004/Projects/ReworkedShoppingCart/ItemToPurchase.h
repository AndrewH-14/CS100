#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct itemtopurchase {
    char itemName[50];
    char itemDescription[50];
    int itemPrice;
    int itemQuantity;
} ItemToPurchase;

void MakeItemBlank(ItemToPurchase* item);

void PrintItemCost(ItemToPurchase item);

void PrintItemDescription(ItemToPurchase item);