#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void caesar(char *string, int shift) {
    for (int i = 0; i < strlen(string); i++) {
        if ((string[i] + shift) > 'Z') {
            int numPastZ = (string[i] + shift) - 90;
            string[i] = 'A' + numPastZ - 1;
        }
        else {
            string[i] = string[i] + shift;
        }
    }
    printf("%s ", string);
}

int main(int argc, char *argv[]) {
int shift;
   if (argc < 3) {
       printf("Usage: ./a.out SHIFT TEXT\n");
       return 1;
   }
shift = atoi(argv[1]);

    for (int i = 2; i < argc; i++) {
        caesar(argv[i], shift);
    }

   return 0;
}