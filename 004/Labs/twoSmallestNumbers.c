#include <stdio.h>

int main() {

    int integers[20];
    int numInt;
    scanf("%d", &numInt);
    int min1, min2;

    for (int i = 0; i < numInt; i++) {
        scanf("%d", &integers[i]);
    }
    

    for (int i = 0; i < numInt; i++) {
        if (i == 0) {
            min1 = integers[i];
        }
        else if ((i == 1) && (integers[i] > min1)) {
            min2 = integers[i];
        }
        else if (integers[i] < min1) {
            min2 = min1;
            min1 = integers[i];
        }
        else if ((integers[i] < min2) && (integers[i] > min1)) {
            min2 = integers[i];
        }
    }
    printf("%d %d\n", min1, min2);

    return 0;
}