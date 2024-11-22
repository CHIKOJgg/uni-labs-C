#include <stdio.h>
void rotateArray(int arr[], int n, int k) {
  int temp[10];
  for (int i = 0; i < n; i++) {
    temp[(i + k) % n] = arr[i];
  }
  for (int i = 0; i < n; i++) {
    arr[i] = temp[i];
  }
}
int main() {
  // дан одномерный масссив из 10 элементов циклически сдвинуть на к позиций

  int arrayOf10[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int k;
  printf("Enter K: ");
  scanf_s("%d", &k);

  if (k <= 0 || k >= 10) {
    printf("Enter a valid shift for the array\n");
    return 0;
  }

  rotateArray(arrayOf10, 10, k);

  printf("Array after rotation: ");
  for (int i = 0; i < 10; i++) {
    printf("%d ", arrayOf10[i]);
  }
  printf("\n");
}
