#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void main(argc, argv)
  int argc;
  char *argv[];
{
  int c, strip = 0;

  if (argc > 1 && strcmp(argv[1], "-s") == 0)
    strip = 1;
  while ((c = getchar()) != EOF)
    if (isascii(c) && (isprint(c) || c == '\n' || c == '\t' || c == ' '))
      putchar(c);
    else if (!strip)
      printf("\\%03o",c);
  exit(0);
}
