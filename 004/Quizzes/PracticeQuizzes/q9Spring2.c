#include <stdio.h>
typedef struct point {
 int x; int y;
} Point;

double f(Point a, Point b) {
    if (a.x == b.x) return -999999999;
    return (double)(b.y-a.y) / (double)(b.x-a.x);
}

int main(void) {
    Point data[5];
    for (int a=0; a<4; a++) {
        scanf("%d", &data[a].x);
        scanf("%d", &data[a].y);
    }
    printf("%lf\n", f(data[1], data[3]) );
    printf("%lf\n", f(data[0], data[2]) );
    return 0;
}