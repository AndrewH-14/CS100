#include <stdio.h>
#include <stdlib.h>

typedef struct _point {
    int x;
    int y;
} Point;

typedef struct _box {
    int length;
    int width;
    int height;
} Box;

int main() {
    int *pInt = malloc(sizeof(int));
    *pInt = 1;

    Box *b = malloc(sizeof(Box));
    (*b).length = 1;
    b->width = 2;
    b->height = 3;

    Box *heapBoxes = malloc(sizeof(Box) * 10);
    Box stackBoxes[10];
    stackBoxes[0].length = 1;
    stackBoxes[0].width = 2;
    stackBoxes[0].height = 3;

    printf("(%d,%d,%d)\n", stackBoxes[0].length, stackBoxes[0].width, stackBoxes[0].height);

    return 0;
}