// WAP TO IMPLEMENT QUICK SORT TO SORT A GIVEN ARRAY OF INTEGER

#include <stdio.h>

void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void displayArray(int arr[], int size);

int main() {
  int arr[] = {4, 77, 5, 9, 1, 34, 98, 45};
  int n =8;

  printf("Array before sorting:\n");
  displayArray(arr, 8);

  quickSort(arr, 0, n-1);
  printf("\nArray after sorting:\n");
  displayArray(arr, 8);
}

void displayArray(int arr[], int size) {
  int i;
  for (i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
}

int partition(int arr[], int low, int high) {
  int pivot = arr[low];
  int i = low + 1;
  int j = high;

  int temp;
  do {
    while (arr[i] <= pivot) {
      i++;
    }
    while (arr[j] > pivot) {
      j--;
    }

    if (i < j) {
      temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  } while (i < j);

  // Swap arr[low] and arr[j]
  temp = arr[low];
  arr[low] = arr[j];
  arr[j] = temp;

  return j;
}

void quickSort(int arr[], int low, int high) {
  int partitionIndex;
  if (low < high) {

    partitionIndex = partition(arr, low, high);  // partition of array
    quickSort(arr, low , partitionIndex - 1);  // sort left sub-array
    quickSort(arr, partitionIndex + 1, high);     // sort right sub-array
  }
}
