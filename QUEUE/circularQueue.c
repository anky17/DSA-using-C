// WAP TO IMPLEMENT THE CIRCULAR QUEUE AS AN ADT.

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

// Circular Queue Structure
struct queue {
  int front, rear;
  int items[MAX_SIZE];
};

typedef struct queue CircularQ;

// Function to initialize the circular queue
void initializeQueue(CircularQ *q) { q->front = q->rear = MAX_SIZE - 1; }

// Function to check if the queue is empty
int isEmpty(CircularQ *q) {
  if (q->rear < q->front)
    return 1;
  else
    return 0;
}

// Function to check if the queue is full
int isFull(CircularQ *q) {
  if (((q->rear + 1) % MAX_SIZE) == (q->front))
    return 1;
  else
    return 0;
}

// Function to enqueue an element into the circular queue
void enqueue(CircularQ *q, int data) {
  if (isFull(q)) {
    printf("Queue is full. Cannot enqueue.\n");
    return;
  }

  if (isEmpty(q)) q->front = 0;

  q->rear = (q->rear + 1) % MAX_SIZE;
  q->items[q->rear] = data;

  printf("%d enqueued to the circular queue.\n", data);
}

// Function to dequeue an element from the circular q
int dequeue(CircularQ *q) {
  int data = -1; // initialize data = -1

  if (isEmpty(q)) {
    printf("Queue is empty. Cannot dequeue.\n");
  } else {
    data = q->items[q->front];
    if (q->front == q->rear) {
      // If there is only one element in the q
      q->front = q->rear = MAX_SIZE - 1;
    } else {
      // After first element is dequeued point to next q element.
      q->front = (q->front + 1) % MAX_SIZE;
    }

    printf("%d dequeued from the queue.\n", data);
  }

  return data;
}

// Function to display the elements in the circular q
// void displayQueue(CircularQ *q) {
//   if (isEmpty(q)) {
//     printf("Queue is empty.\n");
//   } else {
//     int i = q->front;
//     printf("Elements in the q: ");
//     do {
//       printf("%d ", q->items[i]);
//       i = (i + 1) % MAX_SIZE;
//     } while (i !=
//              (q->rear + 1) % MAX_SIZE);  // if i == last q pointer i.e last
//                                          // queue element then loop
//                                          terminates.
//     printf("\n");
//   }
// }

int main() {
  CircularQ q;
  initializeQueue(&q);

  enqueue(&q, 11);
  enqueue(&q, 12);
  enqueue(&q, 13);
  enqueue(&q, 14);
  enqueue(&q, 15);
  //   displayQueue(&q);

  dequeue(&q);
  dequeue(&q);
  //   displayQueue(&q);

  enqueue(&q, 16);
  //   displayQueue(&q);

  return 0;
}
