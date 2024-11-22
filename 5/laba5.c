#include <stdio.h>

int main() {

  // 5.1: Написать программу:
  // Дана матрица вещественных чисел N х М. Количество строк N и столбцов М
  // задается пользователем. Найти максимальный и минимальный элемент в каждой
  // строке и поменять их местами. Найти сумму элементов на главной диагонали.
  int i, j, n, m;

  printf("Enter the number of rows (N): ");
  scanf_s("%d", &n);
  printf("Enter the number of columns (M): ");
  scanf_s("%d", &m);

  double matrix[n][m];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("Enter element [%d][%d]: ", i + 1, j + 1);
      scanf_s("%lf", &matrix[i][j]);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%.2lf ", matrix[i][j]);
    }
    printf("\n");
  }

  for (int i = 0; i < n; i++) {
    int maxIndex = 0, minIndex = 0;
    double maxVal = matrix[i][0], minVal = matrix[i][0];

    for (int j = 1; j < m; j++) {
      if (matrix[i][j] > maxVal) {
        maxVal = matrix[i][j];
        maxIndex = j;
      }
      if (matrix[i][j] < minVal) {
        minVal = matrix[i][j];
        minIndex = j;
      }
    }

    double temp = matrix[i][maxIndex];
    matrix[i][maxIndex] = matrix[i][minIndex];
    matrix[i][minIndex] = temp;
  }

  if (n == m) {
    double diagonalSum = 0;
    for (int i = 0; i < n && i < m; i++) {
      diagonalSum += matrix[i][i];
    }
    printf("\nSum of the main diagonal elements: %.2lf\n", diagonalSum);
  } else {
    printf("\nmatrix isnt square type");
  }

  printf("\nModified Matrix:\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%.2lf ", matrix[i][j]);
    }
    printf("\n");
  }
  printf("\n");
  printf("\n");

  // 5.2 Дана целочисленная прямоугольная матрица. Определить количество строк,
  // содержащих хотя бы один нулевой элемент; номер столбца, в которой находится
  // самая длинная серия одинаковых элементов.
  int numOfPositiveColumn;
  int sumOfColumn;
  int maxStreakVal = 0;
  int maxStreakValIndex;
  int zeroValAmount = 0;
  int streakValsAmount = 1;
  int StreakValsAmountARR[7];
  int matrixExaple[7][5] = {1, 2,   2, 6,   2, 1, 1, 7,  9, 47, 1, 43,
                            1, 1,   1, 791, 3, 7, 9, 47, 1, 43, 1, 1,
                            1, 791, 9, 6,   8, 1, 1, 1,  9, 5,  2};
  for (int i = 0; i < 7; i++) {
    for (int j = 0; j < 5; j++) {
      printf("%d ", matrixExaple[i][j]);
    }
    printf("\n");
  }

  for (i = 0; i < 7; i++) {
    for (j = 0; j < 5; j++) {
      if (matrixExaple[i][j] == 0) {
        zeroValAmount += 1;
        break;
      }
    }
  }
  for (i = 0; i < 7; i++) {

    for (j = 0; j < 5; j++) {
      if (matrixExaple[i][j] == matrixExaple[i][j + 1]) {
        streakValsAmount += 1;
      }
    }
    StreakValsAmountARR[i] = streakValsAmount;
    streakValsAmount = 0;
  }

  for (i = 0; i < 7; i++) {
    if (maxStreakVal < StreakValsAmountARR[i]) {
      maxStreakVal = StreakValsAmountARR[i];
      maxStreakValIndex = i;
    }
  }

  printf("Amount of lines with zeros %d\n", zeroValAmount);
  printf("Max streak row is  %d\n", maxStreakValIndex + 1);
  //  5.3 Найти в матрице первый столбец, все элементы которого положительны.
  // Знаки элементов предыдущего столбца изменить на противоположные.
  int matrixExaple2[7][5] = {2, 2,  2, 6, 2, 3,  3, 7,  9, 4, 3, -4,
                             1, -1, 3, 7, 3, -7, 9, 4,  3, 4, 1, 3,
                             2, 7,  9, 6, 8, 2,  5, -2, 8, 1, 2};

  for (i = 0; i < 7; i++) {
    for (j = 0; j < 5; j++) {
      printf("%d ", matrixExaple2[i][j]);
    }
    printf("\n");
  }
  printf("\n\n\n");
  for (j = 0; j < 5; j++) {
    for (i = 0; i < 7; i++) {
      if (matrixExaple2[i][j] > 0) {
        sumOfColumn += 1;
        if (sumOfColumn == 7) {
          numOfPositiveColumn = j;
          for (i = 0; i < 7; i++) {
            matrixExaple2[i][j - 1] = -1 * matrixExaple2[i][j - 1];
          };
          break;
        }
      }
    }
    sumOfColumn = 0;
  }
  for (i = 0; i < 7; i++) {
    for (j = 0; j < 5; j++) {
      printf("%d ", matrixExaple2[i][j]);
    }
    printf("\n");
  }
}