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

int sum2D(int **arr, int rows, int cols) {
    int sum = 0;
    for (int r = 0; r < rows; r++) { // foreach row
        int *row = arr[r];
        for (int c = 0; c < cols; c++) { // foreach col
            int val = row[c];
            sum += val;
        }
    }
    return sum;
}

double avg2D(int **arr, int rows, int cols) {
    int sum = sum2D(arr, rows, cols);
    int numElements = rows * cols;
    return (double)sum / numElements;
}

void minMax2D(int **arr, int rows, int cols, int *refMin, int *refMax) {
    int min = arr[0][0];
    int max = arr[0][0];
    for (int r = 0; r < rows; r++) { // foreach row
        int *row = arr[r];
        for (int c = 0; c < cols; c++) { // foreach col
            int val = row[c];
            if (val < min) {
                min = val;
            }
            if (val > max) {
                max = val;
            }
        }
    }
    *refMin = min;
    *refMax = max;
}

int main(int argc, char **argv) {
    int rows = 3;
    int cols = 3;

    int **twoD = create2D(rows, cols);
    init2D(twoD, rows, cols);
    print2D(twoD, rows, cols);

    int sum = sum2D(twoD, rows, cols);
    printf("sum=%d\n", sum);

    double avg = avg2D(twoD, rows, cols);
    printf("avg=%lf\n", avg);

    int min, max;
    minMax2D(twoD, rows, cols, &min, &max);
    printf("min=%d, max=%d\n", min, max);

    return 0;
}