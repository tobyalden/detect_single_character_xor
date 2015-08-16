#include <stdio.h>
#include <stdlib.h>
#include "single_byte_xor_cipher.h"

const int LINE_LENGTH = 60;

// compile with gcc main.c single_byte_xor_cipher.c -lgmp
int main(int argc, char *argv[])
{
  FILE *data;
  data = fopen("data.txt", "r");
  if (data == NULL)
  {
    fprintf(stderr, "data.txt not found\n");
    exit(1);
  }

  char c, line[LINE_LENGTH+1], *highest_scoring;
  int i = 0;
  double high_score = 0;

  while((c = fgetc(data)) != EOF)
  {
    line[i] = c;
    i++;
    if(c == '\n')
    {
      i = 0;
      char *decrypt_attempt;
      double score = single_byte_xor_cipher(line, &decrypt_attempt);
      if(score > high_score)
      {
        high_score = score;
        highest_scoring = decrypt_attempt;
      }
    }
  }
  printf("%s", highest_scoring);
}
