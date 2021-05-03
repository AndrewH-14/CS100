#include <stdio.h>

int sum(int arr[], int len);

int main() {
    int arr[] = { 1, 2, 3, 4, 5 };
    int len = 5;
    int s = sum(arr, len);
    printf("The sum is %d\n", s);

    return 0;
}

int sum(int arr[], int len) {
    int s = 0;
    for (int i = 0; i < len; i++) {
        s += arr[i];
    }

    return s;
}