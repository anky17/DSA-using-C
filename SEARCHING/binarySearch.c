// WAP TO IMPLEMENT BINARY SEARCH ALGORITHM USING C.

#include <stdio.h>

// Function to perform binary search
int binarySearch(int arr[], int size, int x) {
  int left = 0;
  int right = size - 1;
  while (left <= right) {
    int middle = (left) + (right) / 2;

    // Check if x is present at mid
    if (arr[middle] == x) return middle;

    // If x greater than mid then we ignore left half
    if (arr[middle] < x) (left) = middle + 1;

    // If x is smaller than mid then we ignore right half
    else
      right = middle - 1;
  }

  // If we reach here then the element was not present
  return -1;  // return error
}

int main() {
  int arr[] = {2, 3, 6, 10, 12, 30};
  // int arr[] = {9, 8, 7, 6};
  int n = sizeof(arr) / sizeof(arr[0]);
  int x = 2;
  int result = binarySearch(arr, n, x);
  if (result == -1)
    printf("Element is not present in array");
  else
    printf("Element is present at index %d", result + 1);
  return 0;
}
