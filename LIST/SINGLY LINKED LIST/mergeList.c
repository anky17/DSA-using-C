// WAP to implement the merge operations of two sorted singly linked list.

#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

// Function to create a node
struct node *createNode(int data) {
  struct node *Node;
  Node = (struct node *)malloc(sizeof(struct node));
  Node->data = data;
  Node->next = NULL;
  return Node;
}

// Function to display all the elements of singly linked list
void listTraversal(struct node *head) {
  printf("Elements: ");
  while (head != NULL) {
    printf("%d ", head->data);
    head = head->next;
  }
  printf("\n");
}

int main() {
  struct node *head = NULL;
  struct node *first = createNode(1);
  struct node *second = createNode(2);
  struct node *third = createNode(3);

  // Linking nodes
  first->next = second;
  second->next = third;

  head = first;
  return 0;
}