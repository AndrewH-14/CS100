#include <stdio.h>

int main () {

    int arr[5];
    int a, b, c, d, e;

    arr[0] = 1;
    a = 1;

    scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
    scanf("%d%d%d%d%d", &arr[0], &arr[1], &arr[2], &arr[3], &arr[4]);

    printf("%d, %d, %d, %d, %d\n", a, b, c, d, e);
    printf("%d, %d, %d, %d, %d\n", arr[0], arr[1], arr[2], arr[3], arr[4]);

    int len = 5;
    for (int i = 0; i < len; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < len; i++) {
        printf("%d\n", arr[i]);
    }

    int g = arr[1] + arr[2];
    
    return 0;
}