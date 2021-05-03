#include <stdio.h>

int length(char *str)
{
}

int main(int argc, char **argv)
{
	for (int i=1; i<argc; i++) {
		printf("length(%s)=%d\n", argv[i], length(argv[i]));
	}

	return 0;
}