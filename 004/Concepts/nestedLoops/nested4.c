#include <stdio.h>

int main() {

    printf("Enter a number:\n");
    int num;
    scanf("%d", &num);
    int needX = 1;
    for (int a = 0; a < num; a++) {
        for (int b = 0; b < num; b++) {
            if ((a + b) % 2 == 0) {
                printf("X");

        }
            else {
            printf("O");

            }
        }
        printf("\n");
    }
    return 0;
}