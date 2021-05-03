#include <stdio.h>

int getElement(int x[][6], int r, int c) {
  return x[r][c];
}

int getElementContinuous(int x[], int pos) {
  return x[pos];
}

int main(void) {
  int array[6][4] = { // stack
    {  0,  1,  2,  3 },
    {  4,  5,  6,  7 },
    {  8,  9, 10, 11 },
    { 12, 13, 14, 15 },
    { 16, 17, 18, 19 },
    { 20, 21, 22, 23 }
  };

  while (1) {
    printf("Enter two subscripts or CTRL-D to exit: ");

    int a, b;
    scanf("%d%d", &a, &b);
    if (feof(stdin)) break;

    printf("array[%d][%d] is %d\n", a, b, array[a][b]);

    int idx = 4 * a + b;
    int val = getElementContinuous(array, idx);
    printf("array[%d] is %d\n", idx, val);

    int pos = 4*a + b;
    int r = pos / 6;
    int c = pos % 6;
    int ele = getElement(array, r, c);
    printf("array[%d][%d] is %d\n", r, c, ele);
  }

  return 0;
}