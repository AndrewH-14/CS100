#include <stdio.h>

int main() {

    int val;
    int largest = 0;
    for ( int i = 0; i < 5; i++) { // init; test; update
        scanf("%d", &val);
        if (i == 0 || val > largest) {
            largest = val;
        }
        else if (val > largest) {
            largest = val;
        }
    }

    printf("The largest is %d\n", largest);

    return 0;
}