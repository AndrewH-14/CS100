#include <stdio.h>

int main () {

    int quizzes[550] = { 0 };
    
    int size = 0;
    while (1) {
        scanf("%d", &quizzes[size]);
        if (feof(stdin)) break;
        size++;
    }

    

    return 0;
}