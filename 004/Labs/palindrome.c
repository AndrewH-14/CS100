#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {

    char userInput[100];
    //scanf("%s", userI
    fgets(userInput, 100, stdin);
    int len = strlen(userInput);
    int j = len - 2;
    for (int i = 0; i < (len) / 2; i++, --j) {
        if (userInput[i] == ' ') {
            ++i;
        }
        if (userInput[j] == ' ') {
            --j;
        }
        // printf("%c %c\n", userInput[i], userInput[j]);
        if (tolower(userInput[i]) == tolower(userInput[j])) {
            continue;
        }
        else {
            printf("%s is not a palindrome.", userInput);
            return 1;
        }
    }
    printf("%s is a palindrome.", userInput);


    return 0;
}