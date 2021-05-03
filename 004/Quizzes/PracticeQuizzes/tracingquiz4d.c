#include <stdio.h>
int main(void) {
     for (int a=0; a<4; a++) {
        for (int b=0; b<4; b++) {
            if ( (a+b) %2 == 0 )
                printf("X");
            else
                printf("O");
         }
         printf("\n");
    }
 return 0;
}