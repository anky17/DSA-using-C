// WAP TO PRINT THE EVEN ELEMENT OF THE ARRAY.

#include <stdio.h>

void display(int arr[], int n);
void evenNumber(int arr[], int n, int len);

int main() {
  int arr[] = {2, 5, 7, 4, 9, 8, 6};
  int n = sizeof(arr) / sizeof(arr[0]);
  int evenCount = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] % 2 == 0) {
      evenCount++;
    }
  }
  evenNumber(arr, n, evenCount);
}
void display(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
}
void evenNumber(int arr[], int n, int len) {
  int evenArr[len];
  int idx = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] % 2 == 0) {
      evenArr[idx] = arr[i];
      idx++;
    }
  }
  display(evenArr, idx);
}
