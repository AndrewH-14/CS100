#include <stdio.h>

int main() {

    int val;
    int sum = 0;
    scanf("%d", &val); // init
    while (val != 0) { // test
        sum += val; // process
        scanf("%d", &val); // update

    }

    printf("The sum is %d\n", sum);

    return 0;
}