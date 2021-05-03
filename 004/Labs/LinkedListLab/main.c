#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ContactNode.h"

int main(void) {

   char name[50];
   char number[50];
   char c = ' ';

   ContactNode* head = NULL;
   ContactNode* tail = NULL;
   ContactNode* c1 = (ContactNode*)malloc(sizeof(ContactNode));
   ContactNode* c2 = (ContactNode*)malloc(sizeof(ContactNode));
   ContactNode* c3 = (ContactNode*)malloc(sizeof(ContactNode));

   printf("Person 1\n");
   printf("Enter name:\n");
   scanf(" %[^\n]s", c1->contactName);
   printf("Enter phone number:\n");
   scanf(" %s", c1->contactPhoneNum);
   printf("You entered: %s, %s\n\n", c1->contactName, c1->contactPhoneNum);

   c1 = CreateContactNode(c1, c1->contactName, c1->contactPhoneNum, NULL);

   while ((c = getchar()) != EOF && c != '\n');

   printf("Person 2\n");
   printf("Enter name:\n");
   scanf(" %[^\n]s", c2->contactName);
   printf("Enter phone number:\n");
   scanf(" %s", c2->contactPhoneNum);
   printf("You entered: %s, %s\n\n", c1->contactName, c1->contactPhoneNum);

   c2 = CreateContactNode(c2, c2->contactName, c2->contactPhoneNum, NULL);

   printf("Person 3\n");
   printf("Enter name:\n");
   scanf(" %[^\n]s", c3->contactName);
   printf("Enter phone number:\n");
   scanf(" %s", c3->contactPhoneNum);
   printf("You entered: %s, %s\n\n", c3->contactName, c3->contactPhoneNum);

   c3 = CreateContactNode(c3, c3->contactName, c3->contactPhoneNum, NULL);

   while ((c = getchar()) != EOF && c != '\n');

   head = c1;
   InsertContactAfter(head, c2);
   InsertContactAfter(c2, c3);

   printf("CONTACT LIST\n");
   PrintContactNode(c1);
   PrintContactNode(c2);
   PrintContactNode(c3);

   return 0;
}