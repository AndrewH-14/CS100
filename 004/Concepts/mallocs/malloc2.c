#include <stdio.h>
#include <stdlib.h>

void minMax(int *arr, int size, int *min, int *max);

int main() {

    int n;
    printf("How many numbers?\n");
    scanf("%d", &n);

    int *arr = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int min, max;
    minMax(arr, n, &min, &max);

    printf("min=%d, max=%d\n", min, max);

    return 0;
}

void minMax(int *arr, int size, int *refMin, int *refMax) {
    int min = *arr;
    int max = *(arr + 0);

    for (int i = 1; i < size; i++) {
        if (*(arr + i) < min) {
            min = *(arr + i);
        }
        if (*(arr + i) > max) {
            max = *(arr + i);
        }
    }

    *refMin = min;
    *refMax = max;
}