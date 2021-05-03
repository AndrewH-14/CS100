#include <stdio.h>
#include <string.h>

int main() {

    char str[] = "Roll";
    char str2[10];
    char str3[100] = "Roll";

    printf("%s\n", str);
    scanf("%s", str2); // no &
    printf("You entered '%s'\n", str2);

    if (strcmp("Hello", "Hello") == 0) {
        printf("They are the same\n");
    } 

    return 0;
}