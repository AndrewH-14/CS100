#include <stdio.h>
#include <string.h>
#include <ctype.h> 

int main(int argc, char **argv) {
 
    int len = strlen(argv[1]);
    char *str = argv[1];
    int numUppers = 0;
    int numLowers = 0;
    int numDigits = 0;

    for (int i = 0; i < len; i++) {
        if (isupper(*(str + i))) {
            numUppers++;
        }
        else if (islower(*(str + i))) {
            numLowers++;
        }
        else if (isdigit(*(str + i))) {
            numDigits++;
        }
    }

    printf("Uppers = %d\n", numUppers);
    printf("Lowers = %d\n", numLowers);
    printf("Digits = %d\n", numDigits);

    return 0;
}