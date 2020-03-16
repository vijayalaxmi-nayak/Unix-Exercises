#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX_LENGTH 100

void main(argc, argv)
  int argc;
  char *argv[];
{
  int c, strip = 0, length=0, n, len;
  char input[MAX_LENGTH];

  if (argc > 1)
    if (strcmp(argv[1], "-s") == 0)
      strip = 1;
    if (strcmp(argv[1], "-sn") == 0)
    {
      strip = 1;
      length = 1;
      n = atoi(argv[2]);
    }

  scanf("%[^\n]",input);
  getchar();
  while (strcmp(input, "quit") != 0)
  {
    len = strlen(input);
    if(length == 0 || (length == 1 && len > n))
    {
      for(int i=0; i<len; i++)
      {
        if (isascii(input[i]) && (isprint(input[i]) || input[i] == '\n' || input[i] == '\t' || input[i] == ' '))
          putchar(input[i]);
        else if (!strip)
          printf("\\%03o", input[i]);
      }
    }
    printf("\n");
    scanf("%[^\n]",input);
    getchar();
  }
  exit(0);
}
