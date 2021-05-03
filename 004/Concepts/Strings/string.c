#include <stdio.h>

int main() {

    char str[] = "L25";

    char ch; 
    int num;
    sscanf(str, "%c%d", &ch, &num);

    printf("The char is %c and the number is %d\n", ch, num);

    char pStr[100];
    sprintf(pStr, "%d-%c", num, ch);
    printf("%s\n", pStr);

    return 0;
}