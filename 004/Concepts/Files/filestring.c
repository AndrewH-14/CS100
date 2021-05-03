#include <stdio.h>

int main() {
    char str[] = "L25";

    char ch;
    int num;
    sscanf(str, "%c%d", &ch, &num);
    printf("The char is %c, the num is %d\n", ch, num);

    char swapStr[100];
    sprintf(swapStr, "%d%c", num, ch);
    fprintf(stdout, "The string swapped is %s\n", swapStr);

    return 0;
}