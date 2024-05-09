// WAP TO IMPLEMENT REALLOC IN CALLOC FUNCTION

#include <stdio.h>
#include <stdlib.h>

int main() {
  int *p;
  int num, i;
  int newSize;

  printf("Enter the array size:");
  scanf("%d", &num);
  p = (int *)calloc(num, sizeof(int));
  if (p == NULL) {
    printf("Error! memory not allocated.\n");
    exit(0);
  }
  printf("Enter the array elements:\n");
  for (i = 0; i < num; i++) {
    scanf("%d", &p[i]);
  }
  printf("The elements of the array are:\n");
  for (i = 0; i < num; i++) {
    printf("%d ", p[i]);
  }

  printf("\nEnter the new array size:");
  scanf("%d", &newSize);
  if (newSize > num) {
    int *temp = realloc(p, newSize * sizeof(int));
    if (temp == NULL) {
      printf("Error! memory not reallocated.\n");
      free(p);
      exit(0);
    }
    p = temp;
    printf("Enter the remaining array elements:\n");
    for (i = num; i < newSize; i++) {
      scanf("%d", &p[i]);
    }
  }

  printf("The elements of the array after resize are:\n");
  for (i = 0; i < newSize; i++) {
    printf("%d ", p[i]);
  }

  free(p);
  return 0;
}
