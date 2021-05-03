#include <stdio.h>
#include <stdlib.h>

int **allocateMatrix(int size)
{
	int **matrix;
	matrix = malloc(sizeof(int *) * size);
	for (int i=0; i<size; i++)
		matrix[i] = malloc(sizeof(int) * size);
	return matrix;
}

void readMatrix(FILE *fp, int **matrix, int size)
{
    for (int i=0; i<size; i++) {
        for (int j=0; j<size; j++) {
            fscanf(fp, "%d", &matrix[i][j]);
        }
    }
}

int sumDiagonals(int **matrix, int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++) {
		if (i != (size - 1 - i)) {
			sum = sum + matrix[i][i] + matrix[i][size - 1 - i];
		}
		else {
			sum = sum + matrix[i][i];
		}
	}
	return sum;
}
int main(int argc, char *argv[]) {
	if (argc!=2) {
		printf("Usage: %s datafile\n", argv[0]);
		return 1;
	}

	FILE *fp=fopen(argv[1], "r");
	if (fp==NULL) {
		printf("Unable to open %s for reading\n", argv[1]);
		return 2;
	}

    int **matrix;
    int size;
	fscanf(fp, "%d", &size);
    matrix = allocateMatrix(size);
    readMatrix(fp, matrix, size);

    int sum = sumDiagonals(matrix, size);
    printf("The sum is %d\n", sum);

    return 0;
}
