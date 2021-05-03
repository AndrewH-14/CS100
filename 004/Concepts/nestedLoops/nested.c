#include <stdio.h>

int main() {

    printf("Enter a number:\n");
    int num;
    scanf("%d", &num);
    for (int a = 0; a < num; a++) {
        for (int b = 0; b <= num; b++) {
            printf("(%d,%d) ", a, b);
        }
         printf("\n");
    }
    return 0;
}