#include <stdio.h>
#include <ctype.h>

int length(char *str)
{
	if (*str=='\0') return 0;

	return 1+length(str+1);
}

int countLetters(char *str)
{
	if (*str=='\0') return 0;
	
	if (isalpha((int)*str))
		return 1+countLetters(str+1);
	else
		return countLetters(str+1);
}

int countA(char *str)
{
	if (*str=='\0') return 0;
	
	if (*str=='A')
		return 1+countA(str+1);
	else
		return countA(str+1);
}

int main(int argc, char **argv)
{
	for (int i=1; i<argc; i++) {
		printf("length(%s)=%d\n", argv[i], length(argv[i]));
		printf("countLetters(%s)=%d\n", argv[i], countLetters(argv[i]));
		printf("countA(%s)=%d\n", argv[i], countA(argv[i]));
	}

	return 0;
}