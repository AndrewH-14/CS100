#include <stdio.h>

int main() {

    int x = 0; // init
    while (x <= 100) { // test
        printf("x=%d\n", x); // repeat
        x = x + 1; // update
    } // go back to test
    // after test fails

    // for (init; test; update) { repeat }
    for (int y = 0; y <= 100; y++) { // y += 1; y = y + 1;
        printf("y=%d\n", y); // repeat
    }

    return 0;
}