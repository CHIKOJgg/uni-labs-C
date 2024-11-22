
#include <stdio.h>
#include <string.h>
#include <time.h>
enum { max_l = 100 };
int main() {

  char buffer[max_l];
  FILE *fl = fopen("F1.txt", "r");
  if (fl == NULL) {
    perror("F1.txt");
    return 1;
  }

  while (fgets(buffer, sizeof(buffer), fl)) {
    puts(buffer);
  }
  for (int i = 1; i <= max_l; i++) {
    fseek(fl, -i, SEEK_END);
    putchar(fgetc(fl));
  }
  fclose(fl);
  return 0;
}