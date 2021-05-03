#include <stdio.h>
#include <string.h>

int main() {
char name[50], number[50];

//ContactNode* head;
//ContactNode* temp;

for (int i = 1; i <=3; i++) {

    printf("Person %d\n", i);
    printf("Enter name:\n");
    scanf(" %[^\n]s", name);
    printf("Enter phone number\n");
    scanf(" %s", number);

    if (i == 1) {
        //head = CreateContactNode(name, number);
    }


    return 0;
}