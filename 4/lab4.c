#include <stdio.h>
#include <stdlib.h>
int main() {

  // ИНДИВИДУАЛЬНОЕ ЗАДАНИЕ
  // 4.1 Написать программу:
  // Ввести массив вещественных чисел размером n, n вводиться с клавиатуры.
  // Найти его наибольший и наименьший элементы и поменять их местами. Найти
  // сумму и произведение всех элементов массива.

  int n, n1;

  printf("Enter size of arr: ");
  scanf_s("%d", &n);

  float *arrayOfFloats = (float *)malloc(n * sizeof(float));

  if (arrayOfFloats == NULL) {
    printf("Ошибка выделения памяти\n");
    return 1;
  }

  for (int i = 0; i < n; i++) {
    printf("enter  %d: ", i + 1);
    scanf_s("%f", &arrayOfFloats[i]);
  }
  float maxVal = arrayOfFloats[0];
  float minVal = arrayOfFloats[0];
  int minValIndex = 0;
  int maxValIndex = 0;

  for (int i = 0; i < n; i++) {
    if (maxVal < arrayOfFloats[i]) {
      maxVal = arrayOfFloats[i];
      maxValIndex = i;
    }
  }
  for (int i = 0; i < n; i++) {
    if (minVal > arrayOfFloats[i]) {
      minVal = arrayOfFloats[i];
      minValIndex = i;
    };
  }
  float temp = arrayOfFloats[minValIndex];
  arrayOfFloats[minValIndex] = arrayOfFloats[maxValIndex];
  arrayOfFloats[maxValIndex] = temp;

  printf("max val of array %0.1f \n", maxVal);
  printf(" min val of array %0.1f \n", minVal);

  float sumOfArray = 0;
  float multiplOfArray = 1;
  for (int i = 0; i < n; i++) {
    sumOfArray += arrayOfFloats[i];
    multiplOfArray *= arrayOfFloats[i];
  }
  printf("MultOfArray %0.1f \n", multiplOfArray);
  printf("sumOfArray %0.1f \n", sumOfArray);

  // 4.2	В одномерном массиве, состоящем из и вещественных элементов,
  // вычислить:
  //  - сумму элементов массива с нечетными номерами;
  //  - сумму элементов массива, расположенных между первым и последним
  //  отрицательными элементами.
  printf("Enter size of arr: ");
  scanf_s("%d", &n1);

  int *arrayOfInts = (int *)malloc(n * sizeof(int));

  if (arrayOfFloats == NULL) {
    printf("Ошибка выделения памяти\n");
    return 1;
  }

  for (int i = 0; i < n1; i++) {
    printf("enter  %d: ", i + 1);
    scanf_s("%d", &arrayOfInts[i]);
  }
  int i = 0;
  int sumInts = 0;
  int firstNegIndex, lastNegIndex;
  int firstNeg, lastNeg;
  int sumBetwNegs = 0;

  while (i < n1) {
    sumInts += arrayOfInts[i];
    i += 2;
  }

  for (int i = 0; i < n1; i++) {
    if (arrayOfInts[i] < 0) {
      lastNeg = arrayOfInts[i];
      lastNegIndex = i;
    }
  }

  for (int i = n1 - 1; i > 0; i--) {
    if (arrayOfInts[i] < 0) {
      firstNeg = arrayOfInts[i];
      firstNegIndex = i;
    }
  }

  for (int i = firstNegIndex + 1; i < lastNegIndex; i++) {
    sumBetwNegs += arrayOfInts[i];
    printf("sumBetwNegs%d \t\n ", sumBetwNegs);
  }
  if (arrayOfInts[firstNegIndex + 1] == arrayOfInts[lastNegIndex] ||
      arrayOfInts[firstNegIndex] == arrayOfInts[lastNegIndex]) {
    printf("doest exist\n");
  } else {
    printf("sumBetwNegs%d \n ", sumBetwNegs);
  }

  printf("sumInts%d \n ", sumInts);

  // 4.3 	Дан массив А размера n, не содержащий нулевых элементов.
  // Необходимо получить массив А, в которой вначале идут положительные
  // элементы, а затем отрицательные.

  int ArrayA[] = {15,  58, 8,  -555, 88, 88, -6,  -47, -22,
                  -24, 33, 54, 87,   32, 56, 156, 99,  -777};
  for (int i = 0; i < sizeof(ArrayA) / sizeof(ArrayA[1]) - 1; i++) {
    for (int j = 0; j < sizeof(ArrayA) / sizeof(ArrayA[1]) - 1; j++) {
      if (ArrayA[j] < ArrayA[j + 1]) {
        int temp = ArrayA[j];
        ArrayA[j] = ArrayA[j + 1];
        ArrayA[j + 1] = temp;
      }
    }
  }
  for (int i = 0; i < sizeof(ArrayA) / sizeof(ArrayA[1] - 1); i++) {
    printf("%d ", ArrayA[i]);
  }
  // дан одномерный масссив из 10 элементов циклически сдвинуть на к позиций

  int arrayOf10[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  for (int i = 0; i < sizeof(arrayOf10) / sizeof(arrayOf10[1]); i++) {
    int temp;

    arrayOf10[i] = arrayOf10[i + 1];
    temp = arrayOf10[i];
    temp = arrayOf10[10 - i];
  }
  for (i = 0; i < 10; i++) {
    printf("arrayOf10 %d", arrayOf10[i]);
  }

  return 0;
}
