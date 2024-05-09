// WAP TO IMPLEMENT ARRAY AS AN ADT

#include <stdio.h>

void traverse(int arr[], int size) {
  int i;
  for (i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void insertionAtIndex(int arr[], int size, int capacity, int data, int index) {
  if (size >= capacity) {
    return;
  }
  for (int i = size - 1; i >= index; i--) {
    arr[i + 1] = arr[i];
  }
  arr[index] = data;
}

void deletionAtIndex(int arr[], int size, int index) {
  for (int i = index; i < size - 1; i++) {
    arr[i] = arr[i + 1];
  }
}
int main() {
  int arr[100] = {2, 5, 7, 89, 67};
  int size = 5;
  int index = 3;
  int data = 12;
  traverse(arr, size);
  insertionAtIndex(arr, size, 100, data, index);
  size += 1;  // 1 element is added so size increases by 1
  traverse(arr, size);
  deletionAtIndex(arr, size, 0);
  size -= 1;
  traverse(arr, size);
}