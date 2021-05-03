#include <stdio.h>
#include <stdlib.h>

typedef struct _box {
    int length;
    int width;
    int height;
} Box;

int volumeBox(Box b) {
    return b.length * b.width * b.height;
}

int surfaceAreaBox(Box b) {
    return 2 * (b.length * b.width + b.length * b.height + b.height * b.width);
}

int main() {
    Box b;
    printf("Enter length, width, then height:\n");
    scanf("%d%d%d", &b.length, &b.width, &b.height);

    int volume, sa;
    volume = volumeBox(b);
    sa = surfaceAreaBox(b);
    
    printf("Volume=%d, Surface Area = %d\n", volume, sa);

    return 0;
}