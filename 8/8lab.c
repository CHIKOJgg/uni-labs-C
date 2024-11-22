
#include <stdio.h>
#include <string.h>
// 22.	Структура «Принтер»: марка принтера; скорость ч/б печати; страна
// производства; срок службы
//  Ввести массив структур в соответствии с вариантом. Рассортировать массив в
//  алфавитном порядке по первому полю, входящему в структуру. В программе
//  реализовать меню: 1)	Ввод массива структур; 2)	Сортировка
//  массива структур; 3)	Поиск в массиве структур по заданному параметру;
//  4)	Изменение заданной структуры;
//  5)	Удаление структуры из массива;
//  6)	Вывод на экран массива структур;
//  7)	Выход.
enum { elnum = 10 };
struct printer {
  char producer[20];
  int printingspeed;
  char origin[20];
  int lifespan;
};
struct printer printers[elnum];
struct printer printersVoid;
struct printer buffer;
int counter = 0;
int structFilling_1() {

  int i = 0;
  do {
    printf("Enter printer producer name %d\n", counter + 1);

    scanf_s("%s", &printers[counter].producer);

    printf("Enter printer printingspeed  %d\n", counter + 1);

    scanf_s("%d", &printers[counter].printingspeed);

    printf("Enter printer origin  %d\n", counter + 1);

    scanf_s("%s", &printers[counter].origin);

    printf("Enter printer lifespan  %d\n", counter + 1);

    scanf_s("%d", &printers[counter].lifespan);
    counter += 1;
    printf("temimate entering 1-yes 0-no\n");
    scanf_s("%d", &i);

  } while (!i && counter < 5);

  return 0;
};
int structSort_2() {
  if (counter < 2) {
    printf("Not enough printers to sort.\n");
    return 0;
  }

  struct printer temp;

  for (int i = 0; i < counter - 1; i++) {
    for (int j = 0; j < counter - i - 1; j++) {

      if (strcmp(printers[j].producer, printers[j + 1].producer) > 0) {

        temp = printers[j];
        printers[j] = printers[j + 1];
        printers[j + 1] = temp;
      }
    }
  }
  return 0;
};
int structSearch_3() {
  int n;
  int srcElNumCharact;
  int srcElNum;
  printf("Please enter nubmer of element");
  scanf_s("%d", &srcElNum);
  printf("Please enter charactristic you lookon for\n 1 producer\n "
         "2 printingspeed \n "
         "3 origin\n 4 lifespan\n");
  scanf_s("%d", &srcElNumCharact);

  switch (srcElNumCharact) {
  case (1):
    printf("That is %d producer: %s", srcElNum,
           printers[srcElNum - 1].producer);

    break;
  case (2):
    printf("That is %d printingspeed: %d", srcElNum,
           printers[srcElNum].printingspeed);

    break;
  case (3):
    printf("That is %d origin: %s", srcElNum, printers[srcElNum - 1].origin);

    break;
  case (4):
    printf("That is %d lifespan: %d", srcElNum,
           printers[srcElNum - 1].lifespan);

    break;

  default:
    printf("Please enter valid number you lookon for");
    break;
  }
  return 0;
}
int structChange_4() {
  int n;
  int srcElNumCharact;
  int srcElNum;
  printf("Please enter nubmer of element which you want to change\n");
  scanf_s("%d", &srcElNum);
  printf("Please enter charactristic you lookon for\n 1 producer\n "
         "2 printingspeed \n "
         "3 origin\n 4 lifespan\n");
  scanf_s("%d", &srcElNumCharact);

  switch (srcElNumCharact) {
  case (1):
    char newProducer[20];
    printf("enter new producer\n");
    scanf_s("%s", &newProducer);
    strcpy_s(printers[srcElNum - 1].producer, sizeof(newProducer), newProducer);

    break;
  case (2):
    int newPrintingspeed;
    printf("enter new printingspeed\n");
    scanf_s("%d", &newPrintingspeed);
    printers[srcElNum - 1].printingspeed = newPrintingspeed;

    break;
  case (3):
    char newOrigin[20];
    printf("enter new origin\n");
    scanf_s("%s", &newOrigin);
    strcpy_s(printers[srcElNum - 1].origin, sizeof(newOrigin), newOrigin);

    break;
  case (4):

    int newLifespan;
    printf("enter new lifespan\n");
    scanf_s("%d", &newLifespan);
    printers[srcElNum - 1].lifespan = newLifespan;
    break;

  default:
    printf("Please enter valid number you lookon for");
    break;
  }

  return 0;
}
int structRemove_5() {
  int n;
  printf("Please enter nubmer of element you want to remove specific element "
         "or 10 to remove all elements ");
  scanf_s("%d", &n);
  if (n != 10 && n < 10) {
    for (int i = n - 1; i < elnum; i++) {
      printers[i] = printers[i + 1];
    }
  } else if (n == 10) {
    for (int i = 0; i < elnum; i++) {
      printers[i] = printersVoid;
    }
  }

  return 0;
}
int structsOurtput_6() {
  for (int i = 0; i < sizeof(printers) / sizeof(printers[0]); i++) {
    printf(" producer %s\n\n", printers[i].producer);

    printf(" printingspeed %d\n\n", printers[i].printingspeed);

    printf(" origin %s\n\n", printers[i].origin);

    printf(" lifespan %d\n\n", printers[i].lifespan);
  }
  return 0;
};
int main() {
  int userInput;
  do {

    printf("1) Enter structure array\n");
    printf("2) Sorting array of structures\n");
    printf("3) Search in the array of structures by a given parameter\n");
    printf("4) Change of the specified structure\n");
    printf("5) Remove the structure from the array\n");
    printf("6) Display of the array of structures\n");
    printf("press 7 to exit\n");
    scanf_s("%d", &userInput);
    switch (userInput) {
    case (1):
      structFilling_1();
      break;
    case (2):
      structSort_2();
      break;
    case (3):
      structSearch_3();
      break;
    case (4):
      structChange_4();
      break;
    case (5):
      structRemove_5();
      break;
    case (6):
      structsOurtput_6();
      break;
    case (7):
      return 0;
      break;

    default:
      printf("Please enter valid number");
      break;
    }
  } while (userInput != 7);
}