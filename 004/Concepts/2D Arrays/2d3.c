#include <stdio.h>

int main() {

    int rows = 3;
    int cols = 4;
    int **arr = malloc(sizeof(int *) * rows);
    for (int i = 0; i < rows; i++) {
        arr[i] = malloc(sizeof(int) * cols);
    }

    return 0;
}