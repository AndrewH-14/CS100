#include <stdio.h>
#include <string.h>
int main(int argc, char **argv)
{
if (argc==1) {
printf("Usage: %s word\n", argv[0]);
return 1;
}
for (int i=0; i<argc; i++) {
printf("argv[%d]=%s\n", i, argv[i]);
}
for (int i=0; i<argc; i++) {
printf("argv[%d]=%s\n", i, *(argv+i) );
}
for (int i=0; i<argc; i++) {
printf("argv[%d]=", i);
for (int j=0; j<strlen(argv[i]); j++) {
printf("%c", argv[i][j]);
}
printf("\n");
}
for (int i=0; i<argc; i++) {
printf("argv[%d]=", i);
for (int j=0; j<strlen(argv[i]); j++) {
printf("%c", *(*(argv+i)+j) );
}
printf("\n");
}
printf("1. %s\n", *argv );
printf("2. %s\n", *(argv+1) );
printf("3. %s\n", *(argv+1)+1 );
printf("4. %c\n", **(argv+1) );
printf("5. %c\n", *(*(argv+1)+1) );
printf("6. %c\n", **(argv+1)+1 );
printf("7. %c\n", *(*(argv+1)+1)+1 );
return 0;
}