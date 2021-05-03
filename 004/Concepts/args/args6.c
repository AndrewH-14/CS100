#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Incorrect number of arguments\n");
        return 1;
    }

    FILE *src = fopen(argv[1], "r");

    if (!src) {
        printf("Could not open src file\n");
        return 2;
    }

    int chCount = 0;
    int nlCount = 0;
    char ch;
    while (1) {
        fscanf(src, "%c", &ch);
        if (feof(src)) break;
        
        if (isalpha(ch)) {
            chCount++;
        }
        else if (ch == '\n') {
            nlCount++;
        }
    }

    fclose(src);

    printf("char count = %d, newline count = %d\n", chCount, nlCount);

    return 0;
}