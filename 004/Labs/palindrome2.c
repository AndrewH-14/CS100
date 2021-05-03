#include <stdio.h>
#include <string.h>

int main() {

    char userInput[50];
    //scanf("%s", userInput);
    fgets(userInput, 50, stdin);
    int len = strlen(userInput);
    if (userInput[len - 1] == '\n') {
        userInput[len - 1] = '\0';
    }
    int j = len - 1;
    //printf("%s", userInput);

    for (int i = 0; i < (len / 2); i++, j--) {
        if (userInput[i] == ' ') {
            i = i + 1;
        }
        if (userInput[j] == ' ') {
            j = j - 1;;
        }
        if (userInput[i] == userInput[j]) {
            continue;
        }
        else if (userInput[i] != userInput[j]) {
            printf("%s is not a palindrome\n", userInput);
            return 1;
        }
    }
    printf("%s is a palindrome\n", userInput); 
    return 0;
}