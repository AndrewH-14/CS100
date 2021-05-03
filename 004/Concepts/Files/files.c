#include <stdio.h>

int main() {
    FILE *fp; // variable
    fp = fopen("sample.txt", "w"); // open

    int i = 1;
    //printf("Hello there %d\n", i);
    //fprintf(stdout, "Hello there %d\n", i); // same as printf()
    fprintf(fp, "Hello there %d\n", i); // writing

    fclose(fp); // closing

    return 0;
}