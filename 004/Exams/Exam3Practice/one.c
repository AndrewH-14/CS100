#include <stdio.h>
#include <stdlib.h>

int **allocateArray(int r, int c) {
	int **array;
	array = (int **) malloc ( sizeof(int *) * r);
	for (int a=0; a<r; a++)
		array[a] = (int *) malloc (sizeof(int) * c);
	return array;
}
void readArray(int **array, int r, int c) {
	for (int a=0; a<r; a++)
		for (int b=0; b<c; b++)
			scanf("%d", &array[a][b]);
	return;
}
void printArray(int **array, int r, int c) {
	for (int a=0; a<r; a++) {
		for (int b=0; b<c; b++)
			printf("%d ", array[a][b]);
		printf("\n");
	}
	return;
}

int numDups(int **data, int x, int r, int c) {
	int count = 0;
	for (int i = 0 ; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (data[i][j] == x) {
				count++;
			}
		}
	}
	return count;
}

int hasDups(int **data, int r, int c) { // returns 1 if dups exist, else 0
	int numTimes;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			numTimes = numDups(data, data[i][j], r, c);
			if (numTimes != 1) {
				return 1;
			}
		}
	}
	return 0;
}
// int numDups(int **data, int x, int r, int c) {
// 	int count = 1;
// 	for (int i = 0 ; i < r; i++) {
// 		for (int j = 0; j < c; j++) {
// 			if (data[i][j] == x) {
// 				count++;
// 			}
// 		}
// 	}
// 	return count;
// }

int main(void) {
	int **data = allocateArray(5,5);
	readArray(data, 5, 5);
	printArray(data, 5, 5);
	if ( hasDups(data, 5, 5) )
		printf("The matrix has duplicate values\n");
	else
		printf("No duplicates found\n");
	return 0;
}

