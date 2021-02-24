#include <stdio.h>

int strln(char *s)
{
  int n;
  for (n = 0; *s != '\0'; s++)
    n++;
  return n;
}

int main()
{
  char input[100];
  while (1)
    {
      printf(">>>");
      fgets(input, sizeof(input), stdin);

      if(*input == '~')
	{
	  break;
	}

      //printf("%c", *(input+1));
      for (int i = 0; i < strln(input); i++)
      {  
        printf("%c", *(input+i));
      }
      printf("\n");
    }
  return 0;
}
