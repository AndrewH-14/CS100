#include <stdio.h> //printf

int main() { //starting point
   printf("Enter 3 integers to average:\n") ; // prompt
   int x, y, z ;
   scanf("%d %d %d", &x, &y, &z) ;

   double avg = (x + y + z) / (double)3 ;

    printf("The average is %lf\n", avg) ; // outout to the terminal

    return 0 ; // end point
}