#include <stdio.h>
#include <string.h>

int main() {

    char str[] = "Roll";
    char str2[] = {'R','o','l','l','\0'};

    char ch = str[0]; // access 'R'
    str[0] = 'r'; // modify 'R' to 'r'

    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        char ch = str[i];
        printf("'%c'\n", ch);
    }


    return 0;
}