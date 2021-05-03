#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int h = atoi(argv[1]);
    int w = atoi(argv[2]);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            printf("(%d,%d)", i, j);
        }
        printf("\n");
    }

    return 0;
}