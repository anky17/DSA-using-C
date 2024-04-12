// WAP TO MOVE THE 0 ELEMENT TO THE LAST OF THE ARRAY MAINTAINING THE RELATIVE
// POSITION OF THE REMAINING ELEMENT.

#include <stdio.h>

void moveZero(int arr[], int n);
void display(int arr[], int n);

int main() {
  int arr[] = {0, 4, 5, 0, 2, 0, 9};
  int n = sizeof(arr) / sizeof(arr[0]);
  printf("Original Array:\n");
  display(arr, n);

  printf("\nAfter rearranging zero to the last:\n");
  moveZero(arr, n);
  display(arr, n);
}

void display(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
}

void moveZero(int arr[], int n) {
  int j = 0;  // to check zero element position
  for (int i = 0; i < n; i++) {
    if (arr[i] != 0 && arr[j] == 0) {
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
    if (arr[j] != 0) {
      j++;
    }
  }
}