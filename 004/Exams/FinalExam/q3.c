#include <stdio.h>
#include <stdlib.h>

typedef struct _node Node;
typedef struct _list List;

struct _node {
  int value;
  Node* next;
};

struct _list {
  Node* head;
};

void insert(List* list, int value) {
    // Code here
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;

    if (list->head == NULL) {
      list->head = newNode;
    }
    else if (newNode->value < list->head->value) {
      newNode->next = list->head;
      list->head = newNode;
    }
    else {
      Node* prev = list->head;

      while (prev->next != NULL) {

        if (prev->next->value > newNode->value) {
          break;
        }
        prev = prev->next;
      }

      newNode->next = prev->next;
      prev->next = newNode;
    }
}

int main(int argc, char* argv[]) {
    // Code here
    List* list = (List*)malloc(sizeof(List));
    list->head = NULL;

    for (int i = 1; i < argc; i++) {
      insert(list, atoi(argv[i]));
    }

    for (Node* cur = list->head; cur != NULL; cur = cur->next) {
      printf("%d ", cur->value);
    }
    printf("\n");
}
