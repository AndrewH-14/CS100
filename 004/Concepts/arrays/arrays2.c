#include <stdio.h>

int main() {

int len = 5;
int arr1[5]; // { ?, ?, ?, ?, ?}
int arr2[5] = { 10, 20, 30, 40, 50 };
int arr3[] = { 100, 200, 300, 400, 500 }; // infer size
int arr4[5] = { 1000 }; // { 1000, 0, 0, 0, 0 }
int arr5[5] = { 0 }; // { 0, 0, 0, 0, 0 }

for ( int i = 0; i < len; i++) {
    printf("%d\n", arr4[i]);
}

arr5[10000] = 1;

    return 0;
}