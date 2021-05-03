#include <stdio.h>
#include <string.h>
int main( int argc, char *argv[ ] ) {
 for (int a=1; a<argc; a++) {
for (int b=0; b<a; b++) {
 printf("%c ", argv[a][b]);
}
 printf("\n");
 }
 return 0;
}