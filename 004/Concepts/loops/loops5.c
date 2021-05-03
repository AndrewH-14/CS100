#include <stdio.h>

int main() {

    int val;
    int sum = 0;
    for ( int i = 0; i < 5; i++) { // init; test; update
        scanf("%d", &val);
        sum += val;
    }

    printf("The sum is %d\n", sum);

    return 0;
}