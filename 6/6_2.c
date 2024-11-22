#include <stdio.h>
#include <stdlib.h>

int main() {
  // 52. Дана целочисленная прямоугольная матрица. Определить номер
  // строки, в которой сумма её элементов наибольшая.
  int i, j, n, m;
  int **matrix, s = 0;
  int maxRowVal = 0, maxRowValIndex = 0;

  printf("Enter number of rows: ");
  scanf_s("%d", &n);
  printf("Enter number of columns: ");
  scanf_s("%d", &m);

  if (n <= 0 || m <= 0) {
    printf("Number of rows and columns must be greater than zero.\n");
    return 1;
  }

  matrix = (int **)malloc(n * sizeof(int *));
  for (i = 0; i < n; i++) {
    *(matrix + i) = (int *)malloc(m * sizeof(int));
  }

  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      printf("Enter element [%d,%d]: ", i + 1, j + 1);
      scanf_s("%d", *(matrix + i) + j);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n ");
  }

  for (i = 0; i < n; i++) {
    s = 0;
    for (j = 0; j < m; j++) {
      s += *(*(matrix + i) + j);
    }
    if (i == 0 || s > maxRowVal) { // Update max if it's the first row or if new
                                   // sum is greater
      maxRowVal = s;
      maxRowValIndex = i;
    }
  }

  printf("Row number with the maximum sum is: %d\n", maxRowValIndex + 1);

  free(matrix);

  return 0;
}
