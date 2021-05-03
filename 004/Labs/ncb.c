#include <stdio.h>
#include <string.h>

int main() {

    char str1[10];
    char str2[10];

    scanf("%s %s", &str1, &str2);

    if ((strcmp(str1, "ninja") == 0) && (strcmp(str2, "cowboy") == 0)) {
        printf("Player one wins");
    }
    else if ((strcmp(str1, "cowboy") == 0) && (strcmp(str2, "ninja") == 0)) {
        printf("Player two wins");
    }
    else if ((strcmp(str1, "ninja") == 0) && (strcmp(str2, "ninja") == 0)) {
        printf("The game is a tie");
    }
    else if ((strcmp(str1, "cowboy") == 0) && (strcmp(str2, "cowboy") == 0)) {
        printf("The game is a tie");
    }
    else if ((strcmp(str1, "ninja") == 0) && (strcmp(str2, "bear") == 0)) {
        printf("Player two wins");
    }
    else if ((strcmp(str1, "bear") == 0) && (strcmp(str2, "ninja") == 0)) {
        printf("Player one wins");
    }
    else if ((strcmp(str1, "bear") == 0) && (strcmp(str2, "bear") == 0)) {
        printf("The game is a tie");
    }
    else if ((strcmp(str1, "cowboy") == 0) && (strcmp(str2, "bear") == 0)) {
        printf("Player one wins");
    }
    else if ((strcmp(str1, "bear") == 0) && (strcmp(str2, "cowboy") == 0)) {
        printf("Player two wins");
    }

return 0;
}