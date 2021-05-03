#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    for(int i = 1; i < (argc - 2); i++) {
        if(atoi(argv[i]) < atoi(argv[i + 1])) {
            continue;
        }
        else {
            printf("Unsorted at %d index.\n", i + 1);
            return 1;
        }
        // if(i == (argc - 1)) {
        //     printf("Sorted\n");
        // }
    }
    printf("Sorted.\n");

    return 0;
}