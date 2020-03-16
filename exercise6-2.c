#include <stdio.h>
#include <ctype.h>
#define LINE_FOLD 5
void main()
{
  int c;
  int current_length = 0;
  while ((c = getchar()) != EOF)
  {
    current_length++;
    if (c == '\n')
      printf("\\n");
    else if (c == '\t')
      printf("\\t");
    else if (c == '\r')
      printf("\\r");
    else if (c == '\\')
      printf("\\\\");
    else if (isascii(c))
      putchar(c);
    else
      printf("\\%03o",c);
    if (current_length == LINE_FOLD)
    {
      current_length = 0;
      printf("\n>");
    }
   }
   exit(0);
}
