#include <stdio.h>

int main() {

    int val;
    int largest = 0;
    scanf("%d", &val); // init
    largest = val; // init
    while (val != 0) { // test
        if (val > largest) { // process
            largest = val;
        }
        scanf("%d", &val); // update
    }

    printf("The largest is %d\n", largest);

    return 0;
}