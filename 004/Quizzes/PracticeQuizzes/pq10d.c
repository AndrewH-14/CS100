#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
 char val;
 struct node *next;
} Node;
Node *function(Node *head, char ch) {
 Node *temp1 = malloc( sizeof(Node) );
 temp1->val = ch; temp1->next = head;
 Node *ptr = temp1;
 while (ptr->next) ptr = ptr->next;
 Node *temp2 = malloc( sizeof(Node) );
 temp2->val = ch; temp2->next = NULL;
 ptr->next = temp2;
 return temp1;
}
int main(int argc, char *argv[]) {
 Node *ptr = NULL;
 for (int a=0; a<strlen(argv[1]); a++)
 ptr = function(ptr, argv[1][a]);
 while (ptr){
 printf("%c", ptr->val);
 ptr = ptr->next;
 }
 printf("\n");
 return 0;
}