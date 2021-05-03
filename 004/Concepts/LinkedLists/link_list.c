#include <stdio.h>
#include <stdlib.h>

typedef struct _letter {
    char ch;
    struct _letter *next;
} Letter;

void printList(Letter* head) {
    while(head != NULL) {
        printf("%c", head->ch);
        head = head->next;
    }
    printf("\n");   
}

Letter* createLetter(char myChar) {
    Letter* tempLetter = (Letter*)malloc(sizeof(Letter));
    tempLetter->ch = myChar;
    tempLetter->next = NULL;
    return tempLetter;
}

int main() {

    Letter* letterT = createLetter('T');
    Letter* letterI = createLetter('I');
    Letter* letterD = createLetter('D');
    Letter* letterE = createLetter('E');

    letterT->next = letterI;
    letterI->next = letterD;
    letterD->next = letterE;

    printList(letterT);

    letterE->next = letterD;
    letterD->next = letterI;
    letterI->next = letterT;
    letterT->next = NULL;

    printList(letterE);


    return 0;
}