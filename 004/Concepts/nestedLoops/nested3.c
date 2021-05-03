#include <stdio.h>

int main() {

    printf("Enter a number:\n");
    int num;
    scanf("%d", &num);
    for (int a = num; a > 0; a--) {
        for (int b = 0; b < a; b++) {
            printf("X");
        }
         printf("\n");
    }
    return 0;
}