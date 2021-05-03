#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {

    char userInput[1000];
    int columnWidth;
    char userAlignment[50];
    char autoCorrect[5];

    printf("Input: \n");
    fgets(userInput, 1000, stdin);

    printf("Column width: \n");
    scanf("%d", &columnWidth);

    printf("Alignment: \n");
    scanf("%s", userAlignment);

    printf("Autocorect: \n");
    scanf("%s", autoCorrect);

    int lenBeforePeriod = strlen(userInput);
    if (columnWidth < lenBeforePeriod) {
        printf("Invalid column width\n");
        return 1;
    }
    if (strcmp(autoCorrect, "yes") == 0) {
        if (userInput[lenBeforePeriod - 2] != '.') {
            userInput[lenBeforePeriod - 1] = '.';
            userInput[lenBeforePeriod] = '\n';
            userInput[lenBeforePeriod + 1] = '\0';
            columnWidth = columnWidth + 1;
        }
        //printf("\n");
    }
    // else {
    //     if (userInput[lenBeforePeriod - 1] == '\n') {
    //         userInput[lenBeforePeriod] = '\0';
    //     }
    // }

    int len = strlen(userInput);
    columnWidth = columnWidth;
    char hyphens[columnWidth];
    int numCenterSpaces = (columnWidth - len) / 2;
    int numRightSpaces = columnWidth - len;
    for (int i = 0; i < columnWidth; i++) {
        hyphens[i] = '-';
        printf("%c", hyphens[i]);
    }
    printf("\n");

    if (strcmp(autoCorrect, "yes") == 0) {
        for (int i = 0; i < len; i++) {
            if (islower(userInput[0])) {
                userInput[0] =toupper(userInput[0]);
            }
            if (userInput[i] == '.') {
                userInput[i + 2] = toupper(userInput[i + 2]);
            }
            if (userInput[i] == '3') {
                userInput[i] = 'e';
            }
            else if (userInput[i] == '1') {
                userInput[i] = 'l';
            }
            else if (userInput[i] == '0') {
                userInput[i] = 'o';
            }
            else if (userInput[i] == '7') {
                userInput[i] = 't';
            }
        }
    }

    if (strcmp(userAlignment,"center") == 0) {
        for (int i = 0; i <= numCenterSpaces; i++) {
        printf(" ");
        }
        printf("%s", userInput);
    }
    if (strcmp(userAlignment, "right") == 0) {
        for (int i = 0; i <= numRightSpaces; i++) {
            printf(" ");
        }
        printf("%s", userInput);
    }
    if (strcmp(userAlignment, "left") == 0) {
        printf("%s", userInput);
    }

    int numWords = 1;
    for (int i = 0; i < len; i++) {
        if (userInput[i] == ' ') {
        ++numWords;
        }
    }
    printf("Words: %d\n", numWords);

    int charCount = 0;
    for (int i = 0; i < len; i++) {
        if (userInput[i] > 96 && userInput[i] < 123) {
            ++charCount;
        }
        else if (userInput[i] > 64 && userInput[i] < 91) {
            ++charCount;
        }
    }

    double charCountDouble = charCount;
    double avgWordLength = charCountDouble / numWords;
    printf("Avg word length: %lf\n", avgWordLength);

    return 0;
}