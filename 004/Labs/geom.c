#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef
struct _point {
    int x;
    int y;
}
Point;

typedef
struct _line {
    Point *p1;
    Point p2;
}
Line;

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

void printPoint(Point *pPoint) {
    printf("The point is located at (%d, %d)",
        pPoint)
}
Line *getLine(char prompt[]) {
    printf("%s", prompt);
    Line *pLine = malloc(sizeof(Line));
    pLine->p1 = getPoint("Enter x and y for the first point: ");
    Point *temp = getPoint("Enter x and y for the second point: ");
    pLine->p2 = *temp;
    return pLine;
}

void printLine(Line *pLine) {
    printf("The line runs from (%d, %d) to (%d, %d)\n",
        pLine->p1->x, pLine->p1->y,
        pLine->p2.x,pLine->p2.y);
}

double length(Line *pLine) {
    return distance(pLine->p1, &pLine->p2);
}

Point *getMidPoint(Line *pLine) {
    Point *pMid = malloc(sizeof(Point));
    pMid->x = (pLine->p1->x + pLine->p2.x) / 2;
    pMid->y = (pLine->p1->y + pLine->p2.y) / 2;
    return pMid;
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