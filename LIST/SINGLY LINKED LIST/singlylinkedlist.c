// WAP TO IMPLEMENT THE OPERATION OF SINGLY LINKED LIST USING C.

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
}

// Funtion to insert a node at the front of singly linked list
struct node *insertAtFront(struct node *head, int data) {
  struct node *ptr = (struct node *)malloc(sizeof(struct node));
  ptr->next = head;
  ptr->data = data;
  return ptr;
}

// Funtion to insert a node at a given index of singly linked list
struct node *insertAtIndex(struct node *head, int data, int index) {
  struct node *ptr = (struct node *)malloc(sizeof(struct node));
  struct node *p = head;
  int i = 0;
  while (i != index - 1) {
    p = p->next;
    i++;
  }
  ptr->data = data;
  ptr->next = p->next;
  p->next = ptr;
  return head;
}

// Funtion to insert a node at the end of singly linked list
struct node *insertAtEnd(struct node *head, int data) {
  struct node *ptr = (struct node *)malloc(sizeof(struct node));
  struct node *p = head;
  ptr->data = data;
  while (p->next != NULL) {
    p = p->next;
  }
  p->next = ptr;
  ptr->next = NULL;
  return head;
}

// Funtion to delete a node from the front of singly linked list
struct node *deletefromFront(struct node *head) {
  struct node *ptr = head;
  head = head->next;
  free(ptr);
  return head;
}

// Funtion to delete a node from a given index of singly linked list
struct node *deleteAtIndex(struct node *head, int index) {
  struct node *ptr = head;
  struct node *ptr1 = head->next;
  for (int i = 0; i < index - 1; i++) {
    ptr = ptr->next;
    ptr1 = ptr1->next;
  }
  ptr->next = ptr1->next;
  free(ptr1);
  return head;
}

// Funtion to delete a node from the end of singly linked list
struct node *deletefromEnd(struct node *head) {
  struct node *ptr = head;
  struct node *ptr1 = head->next;
  while (ptr1->next != NULL) {
    ptr = ptr->next;
    ptr1 = ptr1->next;
  }
  ptr->next = NULL;
  free(ptr1);
  return head;
}

struct node *reverse(struct node *head) {
  struct node *current = head;
  struct node *prev = NULL;
  struct node *temp = NULL;

  while (current != NULL) {
    temp = current->next;  // Save next node
    current->next = prev;  // Reverse current node's pointer
    prev = current;        // Move prev one step forward
    current = temp;        // Move current one step forward
  }

  return prev;  // prev is the new head at the end
}

int main() {
  struct node *head = NULL;
  struct node *first = createNode(7);
  struct node *second = createNode(8);
  struct node *third = createNode(9);

  // Linking nodes
  first->next = second;
  second->next = third;
  third->next = NULL;

  head = first;  // head contains the address of the first node.

  printf("Before insertion:\n");
  listTraversal(head);
  head = insertAtFront(head, 11);
  head = insertAtIndex(head, 39, 3);
  head = insertAtEnd(head, 90);
  printf("\nAfter insertion:\n");
  listTraversal(head);

  printf("\nBefore deletion:\n");
  listTraversal(head);
  head = deletefromFront(head);
  head = deleteAtIndex(head, 3);
  head = deletefromEnd(head);
  printf("\nAfter deletion:\n");
  listTraversal(head);

  printf("\nBefore reverse:\n");
  listTraversal(head);

  printf("\nAfter reverse\n:");
  head = reverse(head);
  listTraversal(head);

  return 0;
}

/*
Output

Before insertion:
Elements: 7 8 9
After insertion:
Elements: 11 7 8 39 9 90
Before deletion:
Elements: 11 7 8 39 9 90
After deletion:
Elements: 7 8 39
Before reverse:
Elements: 7 8 39
After reverse
:Elements: 39 8 7

*/
