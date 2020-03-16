#include <stdio.h>
#include <ctype.h>

void main()
{
  int c;
  while ((c = getchar()) != EOF)
    if (c == '\n')
      printf("\\n");
    else if (c == '\t')
      printf("\\t");
    else if (c == '\r')
      printf("\\r")
    else if (c == '\\')
      printf("\\\\")
    else if (isascii(c))
      putchar(c);
    else
      printf("\\%03o",c);
   exit(0);
}
