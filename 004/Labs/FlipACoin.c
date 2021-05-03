#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void HeadsOrTails(char *decisionString) {
    int flip = rand() % 2;

    if (flip == 1) {
        strcpy(decisionString, "tails");
    }
    else {
        strcpy(decisionString, "heads");
    }
    printf("%s\n", decisionString);
}

int main(void) {
   /* Add more variables as needed */
   char decisionString[10];
   int numDecisions;

   srand(2);  /* Unique seed */

   scanf("%d", &numDecisions);

   for (int i = 0; i < numDecisions; i++) {
       HeadsOrTails(decisionString);
   }
   
   return 0;
}
