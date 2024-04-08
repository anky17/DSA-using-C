// WAP TO SORT AN ARRAY USING INSERTION SORT.

#include <stdio.h>

void insertionSort(int[], int);
void displayArray(int[], int);

int main() {
  int arr[] = {4, 77, 5, 9, 1, 34, 98, 45};

  printf("Array before sorting:\n");
  displayArray(arr, 8);

  insertionSort(arr, 8);
  printf("\nArray after sorting:\n");
  displayArray(arr, 8);
}

void displayArray(int arr[], int size) {
  int i;
  for (i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
}

void insertionSort(int arr[], int size) {
  int i, element, j;
  for (int i = 1; i < size; i++) {
    element = arr[i];  // assume second element of array as sorted.
    j = i - 1;
    while (j >= 0 && arr[j] > element) {
      arr[j + 1] = arr[j];
      --j;
    }
    arr[j + 1] = element;
  }
}