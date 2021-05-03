#include <stdio.h>
#include <string.h>

int main() {

char userInput[50];
printf("Enter a string: ");
fgets(userInput, 50, stdin);
int unique[50] = { 0 };
for(int i = 0; i < strlen(userInput); i++) {
    for(int j = 0; j < strlen(userInput); j++){
        if (i != j) {
            if (userInput[i] == userInput[j]) {
                unique[i]++;
            }
        }
    }
}

int noUnique = 1;
printf("Unique charcters include: ");
for (int i = 0; i < strlen(userInput) - 1; i++) {
    if (unique[i] == 0) {
        printf("%c ", userInput[i]);
        noUnique = 0;
    }
}


if (noUnique == 1) {
    printf("NONE");
}

printf("\n");
    return 0;
}