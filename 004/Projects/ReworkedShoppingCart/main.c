#include <stdio.h>
#include "ShoppingCart.h"

void PrintMenu(ShoppingCart cart) {
    char userInput = ' ';
    char c = ' ';
    while (userInput != 'q') {
        printf("\nMENU\n");
        printf("a - Add item to cart\n");
        printf("r - Remove item from cart\n");
        printf("c - Change item quantity\n");
        printf("i - Output items' descriptions\n");
        printf("o - Output shopping cart\n");
        printf("q - Quit\n\n");

        while (userInput != 'a' && userInput != 'r' && userInput != 'c' && userInput != 'i' && userInput != 'o' && userInput != 'q') {
            printf("Choose an option:\n");
            scanf(" %c", &userInput);
        } 

        if (userInput == 'a') {
            while ((c = getchar()) != EOF && c != '\n');
            char name[50];
            char description[50];
            ItemToPurchase item;
            printf("\nADD ITEM TO CART\n");
            printf("Enter the item name:\n");
            scanf(" %[^\n]s", name);
            strcpy(item.itemName, name);
            printf("Enter the item description:\n");
            scanf(" %[^\n]s", description);
            strcpy(item.itemDescription, description);
            printf("Enter the item price:\n");
            scanf("%d", &item.itemPrice);
            printf("Enter the item quantity:\n");
            scanf("%d", &item.itemQuantity);
            cart = AddItem(item, cart);
            //printf("\n");
            userInput = ' ';
        }
        else if (userInput == 'r') {
            while ((c = getchar()) != EOF && c != '\n');
            char itemToRemove[50];
            printf("REMOVE ITEM FROM CART\n");
            printf("Enter name of item to remove:\n");
            scanf(" %[^\n]s", itemToRemove);
            cart = RemoveItem(itemToRemove, cart);
            userInput = ' ';
        }
        else if (userInput == 'c') {
            while ((c = getchar()) != EOF && c != '\n');
            char name[50];
            printf("CHANGE ITEM QUANTITY\n");
            printf("Enter the item name:\n");
            scanf(" %[^\n]s", name);
            cart = ModifyItem(name, cart);
            userInput = ' ';
        }
        else if (userInput == 'i') {
            printf("OUTPUT ITEMS' DESCRIPTIONS\n");
            PrintDescriptions(cart);
            userInput = ' ';
        }
        else if (userInput == 'o') {
            printf("OUTPUT SHOPPING CART\n");
            PrintTotal(cart);
            userInput = ' ';
        }
    }
}

int main() {
    ShoppingCart cart;
    cart.cartSize = 0;
    printf("Enter Customer's Name:\n");
    scanf(" %[^\n]s", cart.customerName);
    printf("Enter Today's Date:\n");
    scanf(" %[^\n]s", cart.currentDate);
    printf("\nCustomer Name: %s\n", cart.customerName);
    printf("Today's Date: %s\n", cart.currentDate);
    PrintMenu(cart);
    return 0;
}
