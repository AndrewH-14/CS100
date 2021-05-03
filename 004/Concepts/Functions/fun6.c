#include <stdio.h>
#include <limits.h>

int max(int arr[], int size);

int main() {
    int size;
    while (1) {
        printf("Enter how many numbers:\n");
        scanf("%d", &size);

        if (size <= 0) {
            printf("Invalid size\n");
        }
        else {
            break;
        }
    }

    printf("Enter %d numbers:\n", size);
    int arr[size];
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int m = max(arr, size);

    printf("The max is %d\n", m);

    return 0;
}

int max(int *arr, int size) {
    int m = INT_MIN; // int m = arr[0];
    for (int i = 0; i < size; i++) {
        if (arr[i] > m) {
            m = arr[i];
        }
    }
    return m;
}