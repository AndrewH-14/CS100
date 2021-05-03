#include <stdio.h>
#include <stdlib.h>

int **create2D(int rows, int cols) {
    int **twoD = (int **)malloc(sizeof(int *) * rows);
    for (int i = 0; i < rows; i++) {
        twoD[i] = (int *)malloc(sizeof(int) * cols);
    }

    return twoD;
}

void init2D(int **arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = i*cols + j;
        }
    }
}

void print2D(int **arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("arr[%d][%d]=%d\t", i, j, arr[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char **argv) {
    int rows = 5;
    int cols = 3;

    int **twoD = create2D(rows, cols);
    init2D(twoD, rows, cols);
    print2D(twoD, rows, cols);

    return 0;
}