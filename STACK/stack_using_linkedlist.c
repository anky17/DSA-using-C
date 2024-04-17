// WAP TO IMPLEMENT ALL THE STACK OPERATION USING SINGLY LINKED LIST

#include <stdio.h>
#include <stdlib.h>

// Node
struct node {
  int data;
  struct node* next;
};
typedef struct node Node;

// Function to initialize the stack using LL
Node* initialize(Node* top) {
  top = NULL;
  return top;
}

// Function to check the empty status of the stack
int isEmpty(Node* top) {
  if (top == NULL) {
    return 1;
  } else {
    return 0;
  }
}

// Function to check the full status of the stack
int isFull(Node* top) {
  Node* p = (Node*)malloc(sizeof(Node));
  if (p == NULL) {  // if it fails to dynamically allocate new memory in heap,
                    // heap is full so stack is full
    return 1;
  } else {
    return 0;
  }
}

// Function to push an element to the stack
Node* push(Node* top, int data) {
  if (isFull(top)) {
    printf("Stack Overflow!\n");
  }
  Node* temp = (Node*)malloc(sizeof(Node));
  temp->data = data;
  temp->next = top;
  top = temp;
  printf("Pushed Element: %d\n", temp->data);
  return top;
}

// Function to pop an element from the stack
void pop(Node** top) {
  if (isEmpty(*top)) {
    printf("Stack underflow!\n");
  } else {
    struct node* temp = *top;
    *top = (*top)->next;
    int x = temp->data;
    free(temp);
    printf("Pop Element: %d\n", x);
  }
}

// Function to get the top element from the stack
void peek(Node* top) {
  if (isEmpty(top)) {
    printf("Stack underflow!\n");
  } else {
    printf("Top Element: %d", top->data);
  }
}

// Function to display all the elements of the stack
void display(Node* top) {
  if (top == NULL) {
    printf("Stack Underflow!\n");

  } else {
    Node* ptr = top;
    while (ptr != NULL) {
      printf("\nElement: %d", ptr->data);
      ptr = ptr->next;
    }
  }
}

// Function to get the stack element from given position
int getElement(Node* top, int pos) {
  Node* ptr = top;
  int i;
  for (i = 0; i < pos - 1 && ptr != NULL; i++) {
    ptr = ptr->next;
  }
  if (ptr != NULL) {
    return ptr->data;
  } else
    return -1;  // Assuming all data are positive
}
int main() {
  Node* top = initialize(top);
  top = push(top, 10);
  top = push(top, 70);
  top = push(top, 60);
  top = push(top, 40);
  top = push(top, 20);
  printf("Element at position 3 is %d", getElement(top, 3));
  display(top);
  printf("\n");
  pop(&top);
  pop(&top);
  peek(top);
}

/*
Output
Pushed Element: 10
Pushed Element: 70
Pushed Element: 60
Pushed Element: 40
Pushed Element: 20
Element at position 3 is 60
Element: 20
Element: 40
Element: 60
Element: 70
Element: 10
Pop Element: 20
Pop Element: 40
Top Element: 60
*/