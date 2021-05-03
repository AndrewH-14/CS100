#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* flatten(char* log[], int length) {

    int numChars = 0;

    for (int i = 0; i < length; i++) {
        numChars = numChars + strlen(log[i]);
        //printf("%d\n", strlen(log[i]));
    }
    numChars = numChars + length + 1;
    //printf("%d\n", numChars);

    char* flattenStr = malloc(sizeof(char) * numChars);

    //char *flattenStr[100];


    strcpy(flattenStr, log[0]);
    strcat(flattenStr, "\n");

    //printf("%s", flattenStr);

    for (int i = 1; i < length; i++) {
        strcat(flattenStr, log[i]);
        strcat(flattenStr, "\n");
        //printf("%s", flattenStr);
    }
    // printf("%d\n", count);
    //printf("%s", flattenStr);
    return flattenStr;
}

// Example main. You only need to write 'flatten', but this is here to help you test.
int main() {
    char *log[] = {"This is line one","I am line two","A third line is here"};
    char* str = flatten(log, 3);

    printf("%s", str); // No need for \n in printf as the returned string should already have a trailing \n

    // Expected output (note the three "\n"s at the end of each line):
    /*
    This is line one
    I am line two
    A third line is here
    */
}