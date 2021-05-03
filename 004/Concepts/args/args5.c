#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    if (argc != 3) {
        printf("Incorrect number of arguments\n");
        return 1;
    }

    FILE *src = fopen(argv[1], "r");
    FILE *dest = fopen(argv[2], "w");

    if (!src) {
        printf("Could not open src file\n");
        return 2;
    }

    if (!dest) {
        printf("Could not open dest file\n");
        return 3;
    }

    char ch;
    while (1) {
        fscanf(src, "%c", &ch);
        if (feof(src)) break;
        fprintf(dest, "%c", ch);
    }

    fclose(src);
    fclose(dest);

    return 0;
}