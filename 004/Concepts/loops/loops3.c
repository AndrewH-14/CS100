#include <stdio.h> 

int main() {

    printf("Enter 10 ints:\n");

    int sum = 0;
    for (int i = 0; i < 10; i++) {
        int num;
        scanf("%d", &num);
        sum += num;
    }

    double avg = sum / 10.0;
    printf("The average is %lf\n", avg);

    return 0;
}