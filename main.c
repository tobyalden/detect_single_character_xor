#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  FILE *data;
  data = fopen("data.txt", "r");
  if (data == NULL)
  {
    fprintf(stderr, "data.txt not found\n");
    exit(1);
  }
  int c;

  while ((c = fgetc(data)) != EOF)
  {
    printf("%c", c);
  }
  printf("\n");
}
