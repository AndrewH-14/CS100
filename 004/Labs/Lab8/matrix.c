#include <stdio.h>
#include <stdlib.h>

int **allocateMatrix(int numRows, int numCols)
{
   int** matrix = (int**)malloc(sizeof(int *) * numRows);
   for (int i = 0; i < numRows; i++) {
      matrix[i] = (int*)malloc(sizeof(int) * numCols);
   }
   return matrix;
}

void freeMatrix(int **matrix, int numRows, int numCols)
{
   for (int i = 0; i < numRows; i++) {
      free(matrix[i]);
   }
   free(matrix);
}

void readMatrix(FILE *fp, int **matrix, int numRows, int numCols)
{
   for (int i = 0; i < numRows; i++) {
      for (int j = 0; j < numCols; j++) {
         fscanf(fp, "%d", &matrix[i][j]);
      }
   }
}

void printMatrix(int **matrix, int numRows, int numCols)
{
   for (int i = 0; i < numRows; i++) {
      for (int j = 0; j < numCols; j++) {
         printf(" %d ", matrix[i][j]);
      }
      printf("\n");
   }
}

int rangeRow(int **matrix, int numRows, int numCols, int r)
{
   int max, min;
   max = matrix[0][0];
   min = matrix[0][0];
   for (int i = 0; i < numCols; i++) {
      if (matrix[r][i] > max) {
         max = matrix[r][i];
      }
      else if (matrix[r][i] < min) {
         min = matrix[r][i];
      }
   }
   return max  - min;
}

double avgCol(int **matrix, int numRows, int numCols, int c)
{
   double avg = 0;
   int sum = 0;
   for (int i = 0; i < numRows; i++) {
      sum = sum + matrix[i][c]; 
   }
   avg = (double)sum / numRows;
   return avg;
}

void printCorners(int **matrix, int numRows, int numCols)
{
   printf("%d %d\n", matrix[0][0], matrix[0][numCols - 1]);
   printf("%d %d\n", matrix[numRows - 1][0], matrix[numRows - 1][numCols - 1]);
}
