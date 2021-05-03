#include <stdio.h>
#include <stdlib.h>
typedef struct node {
 char ch;
 struct node *next;
} Node;
int main(int argc, char *argv[]) {
 Node a, b, c, d;
 a.ch = 'T'; a.next = &b;
 b.ch = 'I'; b.next = &c;
 c.ch = 'D'; c.next = &d;
 d.ch = 'E'; d.next = &a;
 Node *ptr = &a;
 for (int a=1; a<argc; a++) {
 int x = atoi(argv[a]);
 int y = x / 10;
 int z = x % 10;
 for (int a=0; a<y; a++)
 ptr = ptr->next;
 for (int b=0; b<z; b++)
 printf("%c", ptr->ch);
 printf("\n");
 }
 return 0;
}