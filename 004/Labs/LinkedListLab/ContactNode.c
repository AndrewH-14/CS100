#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ContactNode.h"

ContactNode* CreateContactNode(ContactNode* contact, char name[50], char number[50], ContactNode* address) {
    strcpy(contact->contactName, name);
    strcpy(contact->contactPhoneNum, number);
    contact->nextNodePtr = address;

    return contact;
}

void InsertContactAfter(ContactNode* first, ContactNode* second) {
    first->nextNodePtr = second;
}

ContactNode* GetNextContact(ContactNode* temp) {
    return temp->nextNodePtr;
}

void PrintContactNode(ContactNode* current) {
    printf("Name: %s\n", current->contactName);
    printf("Phone number: %s\n\n", current->contactPhoneNum);
}

