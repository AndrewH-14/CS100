#include <stdio.h>
#include <ctype.h>

// Find the largest character of a non-empty string
char maxCharOfString(char *str)
{
    if (*str == '\0') return NULL;
    char m1 = maxCharOfString(str + 1);
    if (str[0] > m1) {
        return str[0];
    }
    else {
        return m1;
    }
	// add your recursive code here
}

// Find the largest character of an array of strings
char maxCharOfStringArray(int num, char *array[])
{
    if (num == 0) return '\0';
    else {
        char m1 = maxCharOfStringArray(num - 1, array);
        char m2 = maxCharOfString(array[num - 1]);
        if (m2 > m1) {
            return m2;
        }
        else {
            return m1;
        }
    }
	// add your recursive code here
}

int main(int argc, char *argv[])
{
	if (argc==1) {
		printf("%s requires at least one argument\n", argv[0]);
		return 1;
	}

	printf("The largest character of all arguments is %c\n",
			maxCharOfStringArray(argc-1, argv+1));

    return 0;
}
