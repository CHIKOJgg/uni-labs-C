
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  //     22.	В одномерном массиве, состоящем из n вещественных элементов,
  //     вычислить:
  // - сумму элементов массива с четными номерами;
  // - произведение элементов массива, расположенных между первым и последним
  // положительными элементами.
  int n, sumOfEven, multiplicationOfArr;
  int i = 0;
  multiplicationOfArr = 1;
  sumOfEven = 0;
  srand(time(0));
  int lower = -10;
  int upper = 10;

  printf("enter n");
  scanf_s("%d", &n);
  int *arrayOfInts = (int *)malloc(n * sizeof(int));
  for (int i = 0; i < n; i++) {
    arrayOfInts[i] = (rand() % (upper - lower + 1)) + lower;
  }
  int *pAOF = arrayOfInts + 1;
  int firstEvenElement = *pAOF;

  for (int i = 0; i < n / 2; i++) {

    sumOfEven += *pAOF;
    pAOF += 2;
  }

  for (int i = 0; i < n; i++) {
    printf("%d\n", arrayOfInts[i]);
  }
  printf("sum of even numbers %d\n\n", sumOfEven);
  int *pointerOfFirstPos;
  int *pointerOfLastPos;
  if (pointerOfFirstPos == NULL || pointerOfLastPos == NULL) {
    printf("there are no positive elements.\n");
    return 0;
  }

  for (int i = 0; i < n; i++) {
    if (arrayOfInts[i] > 0) {
      pointerOfLastPos = &arrayOfInts[i];
    }
  }
  for (int i = 0; 0 <= n; n--) {
    if (arrayOfInts[i] > 0) {
      pointerOfFirstPos = &arrayOfInts[i];
      break;
    }
    i++;
  }

  int dist = pointerOfLastPos - pointerOfFirstPos + 1;
  // printf("pointrt of first %p\n", pointerOfFirstPos);
  // printf("pointrt of last %p\n", pointerOfLastPos);

  for (int i = 0; i < dist; i++) {
    multiplicationOfArr *= *pointerOfFirstPos;
    pointerOfFirstPos++;
  }

  printf("multiplication Of Arr %d\n", multiplicationOfArr);
  free(arrayOfInts);
  return 0;
}