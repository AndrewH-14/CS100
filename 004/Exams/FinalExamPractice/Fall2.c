#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **allocSpace(int numRows, int numCols)
{
	int **array;
	array = malloc(sizeof(int *) * numRows);
	for (int a=0; a<numRows; a++)
		array[a] = malloc(sizeof(int) * numCols);
	return array;
}

void freeSpace(int **array, int numRows, int numCols)
{
	for (int a=0; a<numRows; a++)
		free(array[a]);
	free(array);
}

void readArray(FILE *fp, int **x, int numRows, int numCols)
{ 
    for (int i=0; i<numRows; i++) {
        for (int j=0; j<numCols; j++) {
            fscanf(fp, "%d", &x[i][j]);
        }
    }
}

void printArray(int **x, int numRows, int numCols)
{ 
    for (int i=0; i<numRows; i++) {
        for (int j=0; j<numCols; j++) {
            printf("%4d", x[i][j]);
        }
	    printf("\n");
    }
}

void findMax(int **x, int numRows, int numCols, int *pMax, int *pCount)  {

	int Max = x[0][0];
	int Count = 0;

	for (int i = 0; i < numRows; i++) {
		for (int j = 0; j < numCols; j++) {
			if (x[i][j] > Max) {
				Max = x[i][j];
				Count = 0;
			}
			if (x[i][j] == Max) {
				Count++;
			}
		}
	}
	*pMax = Max;
	*pCount = Count;
}

int main(int argc, char *argv[])
{
	if (argc!=2) {
		printf("Usage: %s filename\n", argv[0]);
		return 1;
	}
	FILE *fp=fopen(argv[1], "r");
	if (fp==NULL) {
		printf("unable to open %s for reading\n", argv[1]);
		return 2;
	}
	int numRows, numCols;
	fscanf(fp, "%d%d", &numRows, &numCols);
	int **z=allocSpace(numRows, numCols);
	readArray(fp, z, numRows, numCols);
	// printArray(z, numRows, numCols);

	int max, count;
	findMax(z, numRows, numCols, &max, &count);

	printf("The maximum is %d, and it occurs %d times.\n", max, count);

	freeSpace(z, numRows, numCols);

	return 0;
}
