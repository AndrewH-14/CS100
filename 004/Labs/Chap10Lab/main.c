#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "ItemToPurchase.h"

int main(void) {
 
   itemToPurchase* item1 = malloc(sizeof(itemToPurchase));
   itemToPurchase* item2 = malloc(sizeof(itemToPurchase));

   printf("Item 1\n");
   printf("Enter the item name:\n");
   scanf("%[^\n]s", item1->itemName);
   printf("Enter the item price:\n");
   scanf("%d", &item1->itemPrice);
   printf("Enter the item quantity:\n");
   scanf("%d", &item1->itemQuantity);

   char c = getchar();
   while(c != '\n' && c != EOF) {
        c = getchar();
    }

    printf("\n");

   printf("Item 2\n");
   printf("Enter the item name:\n");
   scanf("%[^\n]s", item2->itemName);
   printf("Enter the item price:\n");
   scanf("%d", &item2->itemPrice);
   printf("Enter the item quantity:\n");
   scanf("%d", &item2->itemQuantity);

    printf("\nTOTAL COST\n");
    PrintItemCost(item1);
    PrintItemCost(item2);
    printf("\nTotal: $%d\n", (item1->itemPrice * item1->itemQuantity) + (item2->itemPrice * item2->itemQuantity));

    MakeItemBlank(item1);
    MakeItemBlank(item2);

   return 0;
}