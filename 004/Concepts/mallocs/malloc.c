#include <stdio.h>
#include <string.h>
#include <stdlib.h> // malloc, free

char *combineNames(char first[], char last[]) {
    char *full = malloc(sizeof(char)*42);
    strcpy(full, first);
    strcat(full, " ");
    strcat(full, last);

    return full;
}

int main() {
    char first[21];
    char last[21];

    printf("Enter the first name:\n");
    scanf("%s", first);
    printf("Enter the last name:\n");
    scanf("%s", last);

    char *full = combineNames(first, last);
    printf("The full name is '%s' with length %lu\n", full, strlen(full));

    free(full);

    return 0;
}