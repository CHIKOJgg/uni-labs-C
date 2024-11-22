
#include <errno.h>
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
int main() {
  char buff[100];
  char str[] = " nction fpummmmmm,u,u,u,uts running";
  char ch;
  FILE *fp = fopen("myfi1le.txt", "w");
  if (fp == NULL) {
    return 1;
  }
  for (int i = 0; i < str[i]; i++) {
    fputc(str[i], fp);
  };
  fclose(fp);

  FILE *wr = fopen("myfile.txt", "w");
  if (wr == NULL) {
    printf("errno %d ", errno);
    perror("myfi1le.txt");
    return 1;
  }
  for (int i = 0; i < str[i]; i++) {
    fseek(wr, 0, SEEK_SET);
    fputc(str[i], wr);
  }
  int i = 0;
  fclose(wr);
  fseek(wr, 0, SEEK_END);
  int lengts = ftell(wr);
  while ((ch = fgetc(wr)) != EOF) {
    buff[i++] = ch;
    buff[i] = '\0';
  }
  for (int i = 1; i <= lengts; i++) {
    fseek(wr, -i, SEEK_END);
    putchar(fgetc(wr));
  }
  putchar('\n');
  fclose(wr);

  return 0;
}
