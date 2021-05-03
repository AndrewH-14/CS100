#include <stdio.h>
#include <string.h>

int main() {
char userInput[50];
int sameLetter;
    while (1) {
        scanf("%s", userInput);

        if (strcmp(userInput, "xxx") == 0) {
            break;
        }
        else {
            int len = strlen(userInput);
            if (userInput[0] == userInput[len - 1])  {
                sameLetter = sameLetter + 1;
            }
        }
    }
    printf("%d have same first and last character", sameLetter);


    return 0;
}