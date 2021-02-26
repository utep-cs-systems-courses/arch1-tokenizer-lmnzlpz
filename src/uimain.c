#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

char **tokenize(char *s)
{
  int count = count_words(s);
  char **ma = (char**)malloc((count+1)*sizeof(char)); // +1 for the \0.
  char *end;
  char *start = word_start(s);
  for (int i = 0; i < count; i++){
    end = word_terminator(start); // makes the action act on the token.
    *(ma+i) = copy_str(start, (end - start));
    start = word_start(end);
  }
  *(ma+(count+1)) = '\0';
  return ma;
}

int main()
{
  char input[100];
  while (1){
      printf(">>>");
      fgets(input, sizeof(input), stdin);

      if(*input == '~')
	  break;
      
      printf("%s\n___________\n", input);
      printf("%s\n", *tokenize(input));
    }
  return 0;
}
