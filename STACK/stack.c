#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

// Define the stack structure
struct stack {
  int items[MAXSIZE];
  int top;
};

typedef struct stack Stack;

// Function to initialize the stack
void initialize(Stack* stack) { stack->top = -1; }

// Function to check if the stack is empty
int isEmpty(Stack* stack) {
  if (stack->top == -1)
    return 1;
  else
    return 0;
}

// Function to check if the stack is full
int isFull(Stack* stack) {
  if (stack->top == MAXSIZE - 1)
    return 1;
  else
    return 0;
}

// Function to push an item onto the stack
void push(Stack* stack, int data) {
  if (isFull(stack)) {
    printf("Stack overflow! Cannot push more items.\n");
  } else {
    ++stack->top;
    stack->items[stack->top] = data;
    printf("%d pushed to the stack\n", data);
  }
}

// Function to pop an item from the stack
int pop(Stack* stack) {
  if (isEmpty(stack)) {
    printf("Stack underflow! Cannot pop from an empty stack.\n");
    return -1;
  } else {
    return stack->items[stack->top--];
  }
}

// Function to get the top item of the stack without popping it
int peek(Stack* stack) {
  if (isEmpty(stack)) {
    printf("Stack is empty.\n");
    return -1;
  } else {
    return stack->items[stack->top];
  }
}

int main() {
  struct stack Stack;
  initialize(&Stack);

  push(&Stack, 30);
  push(&Stack, 15);
  push(&Stack, 10);

  printf("Top element: %d\n", peek(&Stack));
  printf("Popped element: %d\n", pop(&Stack));
  printf("Popped element: %d\n", pop(&Stack));
  printf("Top element after pop: %d\n", peek(&Stack));

  return 0;
}
