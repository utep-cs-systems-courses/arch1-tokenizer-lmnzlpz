#include <string.h>
#include <stdio.h>

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
      for (int i = 0; i < strlen(input); i++)
      {
        printf("%c", *(input+i));
      }
      printf("\n");
    }
  return 0;
}
