#include <stdio.h>

int main(int argc, char *argv[]) {

  FILE *fp;
int liczba = 0;
int numread = 0;

  fp = fopen("liczby.txt", "r");
  if (fp == NULL) {
    printf("there was an error opening outfile.txt\n");
    return 1;
  }
  else {

    while (!feof(fp)) {
      fscanf(fp, "%d\n", &liczba);
      printf("%d\n", liczba);

      numread++;
    }
    fclose(fp);
    printf("%d values read, \n", numread);
  }

  return 0;
}
