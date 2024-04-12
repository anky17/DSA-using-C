// WAP TO REVERSE A GIVEN ARRAY WITHOUT USING SECOND ARRAY.

#include <stdio.h>

void reverseArray(int *arr, int start, int end);
void display(int *arr, int n);

int main() {
  int arr[] = {2, 6, 5, 7, 8, 9, 2, 4};
  int n = sizeof(arr) / sizeof(arr[0]);

  printf("Before reversing the array:\n ");
  display(arr, n);

  printf("\nAfter reversing the array:\n ");
  reverseArray(arr, 0, n - 1);
  display(arr, n);
}

void display(int *arr, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
}

void reverseArray(int *arr, int start, int end) {
  while (start < end) {
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    start++;
    end--;
  }
}