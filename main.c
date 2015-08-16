#include <stdio.h>
#include <stdlib.h>

const int LINE_LENGTH = 60;

int main(int argc, char *argv[])
{
  FILE *data;
  data = fopen("data.txt", "r");
  if (data == NULL)
  {
    fprintf(stderr, "data.txt not found\n");
    exit(1);
  }

  char line[LINE_LENGTH+1];
  char c;
  int i = 0;
  while((c = fgetc(data)) != EOF)
  {
    line[i] = c;
    i++;
    if(c == '\n')
    {
      i = 0;
      printf("%s", line);
    }
  }
}
