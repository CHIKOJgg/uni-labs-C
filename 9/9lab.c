// 22.	Компоненты файла F1 – целые числа. Создать новый файл с именем F2, в
// который записать числа из файла F1 в обратном порядке.
// Сформировать бинарный файл из элементов, заданной в варианте структуры,
// распечатать его содержимое, выполнить добавление элементов в соответствии со
// своим вариантом и поиск по одному из параметров (например, по фамилии, по
// государственному номеру, по году рождения и т.д.). Формирование, печать,
// добавление, поиск элементов и выбор желаемого действия оформить в виде
// функций. Предусмотреть сообщения об ошибках при открытии файла и выполнении
// операций ввода/вывода.
// 22.	Структура «Принтер»: марка принтера; скорость
// ч/б печати; страна производства; срок службы.
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMS 100

int main() {
  int numbers[MAX_NUMS];
  int count = 0;

  // Open the input file for reading
  FILE *inputFile = fopen("F1.txt", "r");
  if (inputFile == NULL) {
    perror("Error opening F1.txt");
    return 1;
  }

  // Read integers from the input file
  while (fscanf(inputFile, "%d", &numbers[count]) == 1 && count < MAX_NUMS) {
    count++;
  }
  fclose(inputFile);

  // Open the output file for writing
  FILE *outputFile = fopen("F2.txt", "w");
  if (outputFile == NULL) {
    perror("Error opening F2.txt");
    return 1;
  }

  // Write the numbers to the output file in reverse order
  for (int i = count - 1; i >= 0; i--) {
    fprintf(outputFile, "%d\n", numbers[i]);
  }
  fclose(outputFile);

  printf("Numbers have been written to F2.txt in reverse order.\n");
  return 0;
}
