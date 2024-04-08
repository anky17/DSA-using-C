// WAP TO SORT AN ARRAY USING SELECTION SORT.

#include <stdio.h>

void selectionSort(int[], int);
void displayArray(int[], int);
void swap(int *a, int *b);

int main() {
  int arr[] = {4, 77, 5, 9, 1, 34, 98, 45};

  printf("Array before sorting:\n");
  displayArray(arr, 8);

  selectionSort(arr, 8);
  printf("\nArray after sorting:\n");
  displayArray(arr, 8);
}

void displayArray(int arr[], int size) {
  int i;
  for (i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
}

// Function to swap two elements
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void selectionSort(int arr[], int n) {
  int i, j, minIndex;
  for (i = 0; i < n - 1; i++) {
    minIndex = i;
    for (j = i + 1; j < n; j++) {
      if (arr[j] < arr[minIndex]) {
        minIndex = j;
      }
    }
    // Swap only if a smaller element is found
    if (minIndex != i) {
      swap(&arr[i], &arr[minIndex]);
    }
  }
}
