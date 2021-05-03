#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *next;
} Node;

Node *add(Node *head, int data) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->value = data;
    newNode->next = head;
    return newNode;
}

int howMany(Node *, int);

int main(void) {
  int a, num, count;
  Node *head = NULL;
  printf("Enter 10 values : ");
  for (a=0; a<10; a++)
      { scanf("%d", &num); head = add(head, num); }
  printf("Enter a value : ");
  scanf("%d", &num);
  count = howMany(head, num);
  printf("Value %d occurs %d times\n", num, count);
  return 0;
}

