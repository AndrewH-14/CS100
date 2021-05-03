#include "ShoppingCart.h"
#include <string.h>
#include <stdio.h>

ShoppingCart AddItem(ItemToPurchase item, ShoppingCart cart) {
    cart.cartItems[cart.cartSize] = item;
    cart.cartSize++;

    return cart;
}

ShoppingCart RemoveItem(char* name, ShoppingCart cart) {
    int i = 0;

    for (i = 0; i < cart.cartSize; i++) {
        if (strcmp(name, cart.cartItems[i].itemName) == 0) {
            for (int j = i; j < cart.cartSize; j++) {
                cart.cartItems[j] = cart.cartItems[j + 1];
            }
            cart.cartSize--;
            return cart;
        }
    }
    printf("Item not found in cart. Nothing removed.\n");
    return cart;
}

ShoppingCart ModifyItem(char item[50], ShoppingCart cart) {
    int quantity;

    printf("Enter the new quantity:\n");
    scanf("%d", &quantity);

    for (int i = 0; i < cart.cartSize; i++) {
        if (strcmp(item, cart.cartItems[i].itemName) == 0) {
            cart.cartItems[i].itemQuantity = quantity;
            return cart;
        }
    }
    printf("Item not found in cart. Nothing modified.\n");
    return cart;
}

int GetNumItemsInCart(ShoppingCart cart) {
    return cart.cartSize;
}

int GetCostOfCart(ShoppingCart cart) {
    int totalCost = 0;
    
    for (int i = 0; i < cart.cartSize; i++) {
        totalCost = totalCost + (cart.cartItems[i].itemQuantity * cart.cartItems[i].itemPrice);
    }
    return totalCost;
}

void PrintTotal(ShoppingCart cart) {
    int totalCost = 0;
    int numItems = 0;

    for (int i = 0; i < cart.cartSize; i++) {
        numItems = numItems + cart.cartItems[i].itemQuantity;
    }

    printf("%s\'s Shopping Cart - %s\n", cart.customerName, cart.currentDate);
    printf("Number of Items: %d\n\n", numItems);

    if (cart.cartSize == 0) {
        printf("SHOPPING CART IS EMPTY\n\n");
        printf("Total: $0\n");
        return;
    }
    else {
        for (int i = 0; i < cart.cartSize; ++i) {
            printf("%s %d @ $%d = $%d\n", cart.cartItems[i].itemName, cart.cartItems[i].itemQuantity,
            cart.cartItems[i].itemPrice, ((cart.cartItems[i].itemQuantity) * (cart.cartItems[i].itemPrice)));
            totalCost = totalCost + ((cart.cartItems[i].itemQuantity) * (cart.cartItems[i].itemPrice));

        }
        printf("\nTotal: $%d\n", totalCost);
    }
}

void PrintDescriptions(ShoppingCart cart) {
    printf("%s's Shopping Cart - %s\n\n", cart.customerName, cart.currentDate);
    printf("Item Descriptions\n");
    for (int i = 0; i < cart.cartSize; ++i) {
    printf("%s: %s\n", cart.cartItems[i].itemName, cart.cartItems[i].itemDescription);
    } 
}
