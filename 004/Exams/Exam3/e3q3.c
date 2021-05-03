#include <stdio.h>
#include <stdlib.h>

int multiplySums(int** matrix, int rows, int cols) {
   int sum = 0;
   int ms = 1;

   for (int i = 0; i < rows; i++) {
       sum = 0;
       for (int j = 0; j < cols; j++) {
           sum = sum + matrix[i][j];
       }
       //printf("%d\n", sum);
       ms = ms * sum;
       //printf("%d\n", ms);
   }
   return ms;
}

// Example main. You only need to write 'multiplySums', but this is here to help you test.
int main() {
    // Generate matrix with values:
    /*
    1 2 3
    4 5 6
    */
    int row1[] = {1, 2, 3};
    int row2[] = {4, 5, 6};
    int* M[] = {&row1[0], &row2[0]};
    
    // Call multiplySums
    int ms = multiplySums(M, 2, 3);
    //printf("%d\n", ms);

    // Show result (expected output: 90.000000)
    printf("%d\n", ms);

    return 0;
}
