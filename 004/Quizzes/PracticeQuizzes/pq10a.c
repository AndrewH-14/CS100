#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct _node {
 char value;
 struct _node *next;
} Node;
int main(int argc, char *argv[]) {
 Node *ptr=malloc(sizeof(Node));
 ptr->value='*';
 Node *ptr1=ptr;
 for (int i=0; i<strlen(argv[1]); i++) {
 ptr1->next=malloc(sizeof(Node));
 ptr1->next->value=argv[1][i];
 ptr1=ptr1->next;
 }
 ptr1->next=ptr;
 for (int k=2; k<argc; k++) {
 int x = atoi(argv[k]);
 int a = x / 10;
 int b = x % 10;
 for (int i=0; i<a+b; i++) {
 if (i>=a) printf("%c", ptr->value);
 ptr = ptr->next;
 }
 printf("\n");
 }
 return 0;
}