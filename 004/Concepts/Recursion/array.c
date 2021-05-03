#include <stdio.h>
/*
int max(int x[], int n)
{
    if (n == 1) return x[0];

    int m1 = max(x+1, n-1);
    if (x[0] > m1) {
        return x[0];
    }
    else {
        return m1;
    }
}
*/

int max(int x[], int n)
{
    if (n == 1) return x[0];
    
    int m1 = max(x, n-1);
    if (x[n - 1] > m1) {
        return x[n - 1];
    }
    else {
        return m1;
    }
}

int main()
{
	int a[8]={5, 2, 3, 7, 8, 13, 25, 6};

	int result=max(a, 8);

	printf("Max is %d\n", result);

	return 0;
}