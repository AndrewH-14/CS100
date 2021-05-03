#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef
struct _point {
    int x;
    int y;
}
Point;

Point *getPoint(char prompt[])
{
    printf("%s", prompt);
    Point *p=malloc(sizeof(Point));
    scanf("%d", &p->x);
    scanf("%d", &p->y);
    return p;
}

double distance(Point *p1, Point *p2)
{
    int dx=p2->x-p1->x;
    int dy=p2->y-p1->y;
    double dist=sqrt(dx*dx+dy*dy);
    return dist;
}

int main()
{
    Point *p1;
    Point *p2;
    p1=getPoint("Enter the first point: ");
    p2=getPoint("Enter the second point: ");

    double d=distance(p1, p2);

    printf("The distance from (%d, %d) to (%d, %d) is %lf\n", p1->x, p1->y, p2->x, p2->y, d);

    free(p1);
    free(p2);
    
    return 0;
}
