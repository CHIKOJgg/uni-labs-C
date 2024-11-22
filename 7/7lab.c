// 22.	Даны две матрицы размера M*N. Найти их сумму.(1)
// 22.	Дана строка. Определить количество слов в исходной строке, начинающихся
// на заданную букву(2)

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double firstTaskFunction() {
  int i, j, n, m;
  double **matrix1;
  double **matrix2;
  double **matrixSum;
  int lower = -5;
  int upper = 25;
  srand(time(0));
  printf("Please enter N value ");
  scanf_s("%d", &n);
  printf("Please enter M value ");
  scanf_s("%d", &m);

  matrix1 = (double **)malloc(n * sizeof(double *));
  for (i = 0; i < n; i++) {
    *(matrix1 + i) = (double *)malloc(m * sizeof(double));
  }

  matrix2 = (double **)malloc(n * sizeof(double *));
  for (i = 0; i < n; i++) {
    *(matrix2 + i) = (double *)malloc(m * sizeof(double));
  }

  matrixSum = (double **)malloc(n * sizeof(double *));
  for (i = 0; i < n; i++) {
    *(matrixSum + i) = (double *)malloc(m * sizeof(double));
  }

  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      *(*(matrix1 + i) + j) = (rand() % (upper - lower + 1)) + lower;
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      *(*(matrix2 + i) + j) = (rand() % (upper - lower + 1)) + lower;
    }
  }

  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      *(*(matrixSum + i) + j) =
          (*(*(matrix1 + i) + j)) + (*(*(matrix2 + i) + j));
    }
  }

  printf("matrix1\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      printf("%.1lf ", *(*(matrix1 + i) + j));
    }
    printf("\n");
  }
  printf("\n");
  printf("\n");
  printf("matrix2\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      printf("%.1lf ", *(*(matrix2 + i) + j));
    }
    printf("\n");
  }
  printf("\n");
  printf("\n");
  printf("matrixsum\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      printf("%.1lf ", *(*(matrixSum + i) + j));
    }
    printf("\n");
  }
  for (i = 0; i < n; i++) {
    free(matrix1[i]);
    free(matrix2[i]);
    free(matrixSum[i]);
  }
  free(matrix1);
  free(matrix2);
  free(matrixSum);
  return 0;
}

int secondTaskFunction() {

  // TODO приводить к маленькой  букве. Ограничить ввод до 1 символа
  enum { str_leng = 500 };
  char neededLetter[1];
  int amountOfWordsStartingWith = 0;

  printf("Enter the needed letter: ");
  scanf_s("%1s", neededLetter);

  neededLetter[0] = tolower(neededLetter[0]);

  char str[str_leng] =

      "Phasellus blandit leo ut odio. Maecenas ullamcorper, dui et placerat "
      "a, commodo mollis, magna. Vestibulum ullamcorper mauris at ligu"
      "a, commodo mollis, magna. Vestibulum ullamcorper mauris at ligu"
      "a, commodo mollis, magna. Vestibulum ullamcorper mauris at ligu"
      "a, commodo mollis, magna. Vestibulum ullamcorper mauris at ligu";

  for (int i = 0; str[i] != '\0'; i++) {
    str[i] = tolower(str[i]);
  }
  int i = 0;
  int numberOfWords = 0;
  while (str[i] != '\0') {
    if (str[i] == ' ') {
      numberOfWords++;
    }
    i++;
  }

  for (int i = 0; i < str_leng; i++) {
    if (str[i] == neededLetter[0] && str[i - 1] == ' ') {
      amountOfWordsStartingWith++;
    }
  }
  for (int i = 0; i < str_leng; i++) {
    printf("%c", str[i]);
  }

  printf("\nNumber of words starting with '%c' is %d\n", neededLetter[0],
         amountOfWordsStartingWith);
  printf("\nNumber of words '%d'\n", numberOfWords);
  return 0;
}

int main() {
  int userInputVal;
  printf("press 1 - to run task 1\n");
  printf("press 2 - to run task 2\n");
  printf("press 3 - to exit\n");
  scanf_s("%d", &userInputVal);
  switch (userInputVal) {
  case (1):
    firstTaskFunction();
    break;
  case (2):
    secondTaskFunction();
    break;
  case (3):
    return 0;
  default:
    printf("Please enter valid number");
    break;
  }
}

// посчитать колво заглавных слов прописных
// найти сумму всех строк и расположить строки в порядке возрастания