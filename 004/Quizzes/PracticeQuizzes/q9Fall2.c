#include <stdio.h>
int main(void) {
    int data[4][4] = { {6,7,8,9}, {9,8,7,6},
    {2,3,4,5}, {5,4,3,2} };
    int x = 0, y = 0;
    for (int a=0; a<4; a++) {
        for (int b=0; b<4; b++) {
            if ( a+b == 3 )
                x = x + data[a][b];
            else if ( a == b)
                y = y + data[a][b];
        }
    }
    printf("%d and %d\n", x, y);
    return 0;
}