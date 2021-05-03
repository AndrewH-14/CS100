#include <stdio.h>

int main() {
    int x, y, z, k;
    printf("Enter an interger\n");
    scanf("%d %d %d %d", &x, &y, &z, &k);
    double average = (x + y + z + k) / 4.0;
    printf("The average is %lf\n", average);
    return 0;
}