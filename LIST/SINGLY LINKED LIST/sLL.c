// Aditional Operations related to singly linked list.

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

// Function to reverse the singly linked list
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

// Function to find the middle node in a Singly linked list
struct node *middleNode(struct node *head) {
  struct node *slowPtr = head;
  struct node *fastPtr = head;
  while (fastPtr != NULL && fastPtr->next != NULL) {
    slowPtr = slowPtr->next;
    fastPtr = fastPtr->next->next;
  }
  return slowPtr;
}

// Function to find the nth node from the end
struct node *nthNode(struct node *head, int key) {
  struct node *mainPtr = head;
  struct node *refPtr = head;
  int count = 0;
  while (count < key) {
    refPtr = refPtr->next;
    count++;
  }
  while (refPtr != NULL) {
    refPtr = refPtr->next;
    mainPtr = mainPtr->next;
  }
  return mainPtr;
}

// Function to remove the duplicate data from the list
struct ndoe *remDuplicate(struct node *head) {
  if (head == NULL || head->next == NULL) {
    return head;
  }
  struct node *current = head;
  while (current->next != NULL) {
    if (current->data == current->next->data) {
      struct node *duplicate = current->next;
      current->next = current->next->next;
      free(duplicate);
    } else {
      current = current->next;
    }
  }
  return head;
}

int main() {
  struct node *head = NULL;
  struct node *first = createNode(1);
  struct node *second = createNode(2);
  struct node *third = createNode(2);
  struct node *forth = createNode(5);
  struct node *fifth = createNode(5);

  // Linking nodes
  first->next = second;
  second->next = third;
  third->next = forth;
  forth->next = fifth;
  fifth->next = NULL;

  head = first;

  int choice, index;
  while (1) {
    printf("\n--- Singly Linked List Operations ---\n");
    printf("1. Display list\n");
    printf("2. Find middle node\n");
    printf("3. Reverse list\n");
    printf("4. Find nth node from the end\n");
    printf("5. Remove duplicate element from list\n");
    printf("10. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    printf("\n");
    switch (choice) {
      case 1:
        listTraversal(head);
        break;
      case 2:
        if (head != NULL) {
          struct node *middle = middleNode(head);
          printf("Middle node is: %d\n", middle->data);
        } else {
          printf("List is empty.\n");
        }
        break;
      case 3:
        head = reverse(head);
        printf("List has been reversed.\n");
        listTraversal(head);
        break;
      case 4:
        printf("Enter the node to find: ");
        scanf("%d", &index);
        head = nthNode(head, index);
        printf("The data of the node %d from end is %d.\n", index, head->data);
        break;
      case 5:
        head = remDuplicate(head);
        listTraversal(head);
        break;
      case 10:
        printf("Exiting program.\n");
        exit(0);
      default:
        printf("Invalid choice, please try again.\n");
    }
  }
  return 0;
}