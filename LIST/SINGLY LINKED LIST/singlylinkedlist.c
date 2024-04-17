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

int main() {
  struct node *head = NULL;
  struct node *first = createNode(7);
  struct node *second = createNode(8);
  struct node *third = createNode(9);

  // Linking nodes
  first->next = second;
  second->next = third;
  third->next = NULL;

  int choice, data, index;
  while (1) {
    printf("\n--- Singly Linked List Operations ---\n");
    printf("1. Insert at front\n");
    printf("2. Insert at index\n");
    printf("3. Insert at end\n");
    printf("4. Delete from front\n");
    printf("5. Delete at index\n");
    printf("6. Delete from end\n");
    printf("7. Display list\n");
    printf("8. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter data to insert at front: ");
        scanf("%d", &data);
        head = insertAtFront(head, data);
        break;
      case 2:
        printf("Enter data and index to insert at: ");
        scanf("%d %d", &data, &index);
        head = insertAtIndex(head, data, index);
        break;
      case 3:
        printf("Enter data to insert at end: ");
        scanf("%d", &data);
        head = insertAtEnd(head, data);
        break;
      case 4:
        head = deletefromFront(head);
        break;
      case 5:
        printf("Enter index to delete at: ");
        scanf("%d", &index);
        head = deleteAtIndex(head, index);
        break;
      case 6:
        head = deletefromEnd(head);
        break;
      case 7:
        listTraversal(head);
        break;
      case 8:
        printf("Exiting program.\n");
        exit(0);
      default:
        printf("Invalid choice, please try again.\n");
    }
  }
  return 0;
}