#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    FILE *f1 = fopen(argv[1], "r");
    FILE *f2 = fopen(argv[2], "r");

    int num1;
    int num2;

    fscanf(f1, "%d", &num1);
    fscanf(f2, "%d", &num2);

    while(!feof(f1) && !feof(f2)) {
        if(num1 < num2) {
            printf("%d ", num1);
            fscanf(f1, "%d", &num1);
        }
        else if(num1 > num2) {
            printf("%d ", num2);
            fscanf(f2, "%d", &num2);
        }
        else {
            printf("%d ", num1);
            fscanf(f1, "%d", &num1);
            fscanf(f2, "%d", &num2);
        }
    }
    while(!feof(f1)) {
        printf("%d ", num1);
        fscanf(f1, "%d", &num1);
    }
    while(!feof(f2)) {
        printf("%d ", num2);
        fscanf(f2, "%d", &num2);
    }
    return 0;
}