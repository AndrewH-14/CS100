#ifndef CONTACTNODE_H
#define CONTACTNODE_H

typedef struct contactnode_struct {
    char contactName[50];
    char contactPhoneNum[50];
    struct contactnode_struct* nextNodePtr;
} ContactNode;

//Creates Contact Node
ContactNode* CreateContactNode(ContactNode* contact,char* name, char* number, ContactNode* address);

//Inserts a contact node after another contact node
void InsertContactAfter(ContactNode* head, ContactNode* next);

//Returns pointer to next contact
ContactNode* GetNextContact(ContactNode* temp);

//Prints a specific contact node
void PrintContactNode(ContactNode* head);

#endif