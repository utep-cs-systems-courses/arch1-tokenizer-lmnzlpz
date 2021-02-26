#include <stdlib.h>
#include <stdio.h>
#include "tokenizer.h"

char *copy_str(char *inStr, short len)
{
  char *mem = (char*)malloc(len*sizeof(char));
  for (int i = 0; i < len; i++){
    *(mem+i) = *(inStr+i);
  }
  return mem;
}

void print_tokens(char **tokens)
{/*
  for (int i = 0; i < sizeof(*tokens); i++)
    printf("%s\n", *(tokens+i));
 */printf("%s", *tokens);
  
}

void free_tokens(char **tokens)
{
  free(*tokens);
  printf("Tokens freed.\n");
}

/* Test code with this.
int main()
{
  char leo[] = "Kass, I love you!";
  char *copy = copy_str(leo, sizeof(leo));
  printf("%s\n", copy);
  printf("__________\n");
  char **ptr = &copy;
  print_tokens(ptr);
  free_tokens(ptr);
  return 0;
}
*/
