#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct words {
    char *name;
    struct words *next;
} Words;

void print(Words *);
Words *add(Words *, char *);
int countSame(Words *);

int main(void) {
    char input[100];
    Words *myList = NULL;
    printf("Enter a word : ");
    scanf("%s", input);
    while (strcmp(input, "xxx") != 0) {
        myList = add (myList, input);
        printf("Enter a word or 'xxx' to exit : ");
        scanf("%s", input);
    }
    printf("\n\nThe list is ");  print(myList); printf("\n");
    printf("\n\ncountSame returns %d\n", countSame(myList) );
    return 0;
}
void print(Words *ptr) {
    while (ptr) { printf("%s ", ptr->name); ptr = ptr->next; }
    return;
}

Words *add(Words *ptr, char *name) {
    Words *newNode = malloc( sizeof(Words) );
    newNode->name = malloc( strlen(name) + 1 );
    strcpy(newNode->name, name);
    newNode->next = ptr;
    return newNode;
}

int countSame(Words* head) {
    int count = 0;
    for (Words* cur = head; cur != NULL; cur = cur->next) {
        int isSame = 1;
        if (isupper(cur->name[0])) {
            for (int i = 0; i < (strlen(cur->name)); i++) {
                if (!isupper(cur->name[i])) {
                    isSame = 0;
                }
            }
            //printf("...\n");
            if (isSame == 1)  {
                count++;
                printf("%s\n", cur->name);
            }
        }
        else if (islower(cur->name[0])) {
            for (int i = 0; i < strlen(cur->name); i++) {
                if (!islower(cur->name[i])) {
                    isSame = 0;
                }
            }
            if (isSame == 1) {
                count++;
                printf("%s\n", cur->name);
            }
        }
    }
    return count;
}

