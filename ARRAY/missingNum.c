// WAP TO FIND THE MISSING NUMBER FROM THE ARRAY OF THE INTEGER.

#include <stdio.h>

void display(int arr[], int n);
void missingNo(int arr[], int n);

int main() {
  int arr[] = {2, 3, 6, 5, 4};
  int n = sizeof(arr) / sizeof(arr[0]);
  printf("Array:\n");
  display(arr, n);
  missingNo(arr, n + 1);
}

void display(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
}

void missingNo(int arr[], int n) {
  int i = 0;
  int sum = n * (n + 1) / 2;
  while (i < n) {
    sum = sum - arr[i];
    i++;
  }
  printf("\nMissing NUmber: %d", sum);
}