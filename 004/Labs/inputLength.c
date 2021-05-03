#include <stdio.h>
#include <string.h>

int main() {

    char str[50];
    int numLetters = 0;
    fgets(str, 50, stdin);
    int len = strlen(str);
     for (int i = 0; i < len - 1; i++) {
        if ((str[i] != ' ') && (str[i] != '.') && (str[i] != ',')) {
            numLetters = numLetters + 1;
        }
    }
    printf("%d\n", numLetters); 
    return 0;
}