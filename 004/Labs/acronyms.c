#include <stdio.h>
#include <string.h>
#include <ctype.h>

void CreateAcronym(char userPhrase[], char userAcronym[]) {
    int count = 0;
    for(int i = 0; i < strlen(userPhrase); ++i) {
        if(i == 0 || userPhrase[i-1] == ' ') {
            if(isupper(userPhrase[i])) {
                userAcronym[count++] = userPhrase[i];
            }
        }
    }
    userAcronym[count] = '\0';
}

int main() {
    char inputPhrase[1000], userAcronym[20];
    fgets(inputPhrase, 1000, stdin);
    CreateAcronym(inputPhrase, userAcronym);
    printf("%s\n", userAcronym);
    return 0;
}