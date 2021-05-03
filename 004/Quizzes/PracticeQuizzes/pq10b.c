#include <stdio.h>
#include <stdlib.h>
typedef struct node {
 char *val;
 struct node *next;
} Node;
int main(int argc, char *argv[]) {
 Node *ptr = NULL;
 for (int i=1; i<argc; i++) {
 Node *temp = malloc( sizeof(Node) );
 temp->val = argv[i];
 temp->next = ptr;
 ptr = temp;
 }
 int i=1;
 while (ptr!=NULL) {
 printf("%d: %s\n", i, ptr->val);
 i++;
 ptr = ptr->next;
 }
 return 0;
}