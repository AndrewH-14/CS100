#include <stdio.h>
#include <ctype.h>

/*int fun2(char *data) {
    if (*data == '\0') return 0;

    int temp=*data;
    if (islower(temp))
        return 1+fun2(data+1);
    else if (isupper(temp))
        return 2+fun2(data+1);
    else if (isdigit(temp))
        return (temp-'0')+fun2(data+1);
    else
        return fun2(data+1);
}
*/

int fun2(char* data) {
    int val = 0;
    for (int i = 0; data[i] != '\0'; i++) {
        if (islower(data[i])) {
            val = val + 1;
        }
        else if (isupper(data[i])) {
            val = val + 2;
        }
        else if (isdigit(data[i])) {
            val = val + (data[i] - '0');
        }
    }
    return val;
}

int main(int argc, char *argv[]) {
    for (int i=1; i<argc; i++) {
        printf("fun2(%s)=%d\n", argv[i], fun2(argv[i]));
    }

    return 0;
}