#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char **argv) {
    FILE* f1;
    FILE* f2;
    FILE* f3;
    f1 = fopen(argv[1], "r");
    f2 = fopen("integers", "w");
    f3 = fopen("others", "w");

    char str[50];
    int isInt = 1;
    while (!feof(f1)) {
        fscanf(f1, "%s", str);
        printf("%s\n", str);
        for (int i = 0; i < strlen(str); i++) {
            if (!isdigit(str[i])) {
                isInt = 0;
            }
            if ((str[i] == '-') || (str[i] == '+')) {
                if (isdigit(str[i + 1])) {
                    isInt = 1;
                }
            }
        }
        if (isInt == 1) {
            fprintf(f2, "%s\n", str);
        }
        else {
            fprintf(f3, "%s\n", str);
        }
        isInt = 1;
    }
    fclose(f1);
    fclose(f2);
    fclose(f3);
    return 0;
}