#include <stdio.h>

int main(void) {
   int numRows;
   int numColumns;
   int currentRow;
   int currentColumn;
   char currentColumnLetter;

   scanf("%d", &numRows);
   scanf("%d", &numColumns);

   currentRow = 0;
   currentColumn = 1;
   while (currentRow <= numRows) {
      currentColumnLetter = 'A';
      ++currentRow;
      currentColumn = 1;
      while (currentColumn <= numColumns) {
         printf("%d%c ", currentRow, currentColumnLetter);
         ++currentColumn;
         ++currentColumnLetter;
      }
   }

   printf("\n");

   return 0;
}