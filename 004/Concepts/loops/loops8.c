#include <stdio.h>

int main() {
    int val;
    int sum = 0;
    while (1) {
        scanf("%d", &val); // init & update
        if (val == 0) break; // sentinel value test
        // if (feof(stdin)) { // eof test
        //     break;
        // }
        sum += val; // process
    }

    printf("The sum is %d\n", sum);

    return 0;
}