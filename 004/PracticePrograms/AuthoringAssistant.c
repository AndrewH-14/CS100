#include <stdio.h>
#include <string.h>
#include <ctype.h>

int GetNumOfNonWSCharacters(char* userStr) {
    int count = 0;
    for (int i = 0; i < strlen(userStr); i++) {
        if ((userStr[i] != ' ') && (userStr[i] != '\n')) {
            count++;
        }
    }
    return count;
}

int GetNumOfWords(char* userStr) {
    int count = 0;
    for (int i = 0; i < strlen(userStr); i++) {
        if ((userStr[i] == ' ') && (isalpha(userStr[i + 1]) || (userStr[i] == '.'))) {
            count++;
        }
    }
    return count;
}

char* FixCapatilization(char* userStr) {

    if (islower(userStr[1])) {
        userStr[1] = toupper(userStr[1]);
    }

    for (int i = 0; i < strlen(userStr); i++) {
        if ((userStr[i - 2] == '.') && (islower(userStr[i]))) {
            userStr[i] = toupper(userStr[i]);
        }
    }
    return userStr;
}

char* ReplaceExclamation(char* userStr) {
    for (int i = 0; i < strlen(userStr); i++) {
        if (userStr[i] == '!') {
            userStr[i] = '.';
        }
    }
    return userStr;
}

char* ShortenSpace(char* userStr) {
    for (int i = 0; i < strlen(userStr); i++) {
        if ((userStr[i] == ' ') && (userStr[i + 1] == ' ')) {
            for (int j = (i + 1); j < strlen(userStr - 1); j++) {
                userStr[j] = userStr[j + 1];
            }
        }
    }
    return userStr;
}

int PrintMenu(char* userStr) {
    char userInput = ' ';
    while (userInput != 'q') {
        printf("\nMENU\n");
        printf("c - Number of non-whitespace characters\n");
        printf("w - Number of words\n");
        printf("f - Fix capitalization\n");
        printf("r - Replace all !'s\n");
        printf("s - Shorten spaces\n");
        printf("q - Quit\n\n");

        printf("Choose an option:\n");
        scanf(" %c", & userInput);

        if (userInput == 'c') {
            printf("Number of non-whitespace characters: %d\n", GetNumOfNonWSCharacters(userStr));
            userInput = ' ';
        }
        else if (userInput == 'w') {
            printf("Number of words: %d\n", GetNumOfWords(userStr));
            userInput = ' ';
        }
        else if (userInput == 'f') {
            FixCapatilization(userStr);
            printf("Edited text: %s\n", userStr);
            userInput = ' ';
        }
        else if (userInput == 'r') {
            ReplaceExclamation(userStr);
            printf("Edited text: %s\n", userStr);
            userInput = ' ';
        }
        else if (userInput == 's') {
            ShortenSpace(userStr);
            printf("Edited text: %s\n", userStr);
            userInput = ' ';
        }
    }
    return 0;
}

int main() {

    char userStr[400];
    printf("Enter a sample text:\n\n");
    scanf(" %[^\n]s", userStr);
    printf("You entered: %s\n", userStr);

    PrintMenu(userStr);

    return 0;
}