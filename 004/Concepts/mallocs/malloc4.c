#include <stdio.h>
#include <stdlib.h>

int *getData(char filename[], int size) {
    FILE *fp = fopen(filename, "r");
    int *arr = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        fscanf(fp, "%d", arr + i);
    }
    fclose(fp);
    return arr;
}

void displayArray(int arr[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf(" %d", arr[i]);
    }
    printf(" ]\n");
}

int main(int argc, char **argv) {
    char *filename = argv[1];
    int n = atoi(argv[2]);

    int *arr = getData(filename, n);
    displayArray(arr, n);

    return 0;
}