#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int main()
{
  char input[100];
  while (1){
      printf(">>>");
      fgets(input, sizeof(input), stdin);

      if(*input == '~')
	  break;
      
      printf("Echo: %s\n", input);
      printf("Pointer Array: %s\n*********\n", *tokenize(input));
      /*
      char **x = tokenize(input);
      print_tokens(x);
      */
   
    }
  return 0;
}
