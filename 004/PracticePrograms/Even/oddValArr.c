#include <stdio.h>
#include <stdbool.h>

bool IsArrayEven(int inputVals[], int numVals) {
    for (int i = 0; i < numVals; i++) {
        if (inputVals[i] % 2 == 1) {
            return false;
        }
    }
    return true;
}
bool IsArrayOdd(int inputVals[], int numVals) {
    for (int i = 0; i < numVals; i++) {
        if (inputVals[i] % 2 == 0) {
            return false;
        }
    }
    return true;
}

int main() {

    int size;
    int numbers[20];
    scanf("%d", &size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &numbers[i]);
    }
    if (IsArrayOdd(numbers, size)) {
        printf("all odd\n");
    }
    else if (IsArrayEven(numbers, size)) {
        printf("all even\n");
    }
    else {
        printf("not even or odd\n");
    }

    return 0;
}