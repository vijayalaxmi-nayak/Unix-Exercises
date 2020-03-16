#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int strip = 0;

int  vis3(fp)
  FILE *fp;
{
  int c;
  int flag=0; 
  while ((c = getc(fp)) != EOF)
    if (isascii(c) && (isprint(c) || c == '\n' || c == '\t' || c == ' '))
      flag = 1;
    else
    {  
      flag = 0;
      break;
    }
    return flag;
}

void main(argc, argv)
  int argc;
  char *argv[];
{
  int i;
  FILE *fp;

  while(argc > 1 && argv[1][0] == '-')
  {
    switch (argv[1][1])
    {
      case 's': strip = 1;
                break;
      default : fprintf(stderr, "%s: unknown arg %s\n", argv[0], argv[1]);
                exit(1);
    }
    argc--;
    argv++;
  }
  for(i=1;i<argc;i++)
    if ((fp=fopen(argv[i], "r")) == NULL)
    {
      fprintf(stderr, "%s: cant open %s\n", argv[0], argv[1]);
      exit(1);
    }
    else
    {
      if(vis3(fp) == 1)
         printf("%s\n",argv[i]);
      fclose(fp);
    }
  exit(0);
}
