#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv[]) {

    for (int i = 0; i < argc; i++) {
        printf("argv[%d]=%s\n", i, argv[i]);
    }

    int i = atoi(argv[1]);
    float f = atof(argv[2]);

    printf("i=%d, f=%f\n", i, f);

    return 0;
}