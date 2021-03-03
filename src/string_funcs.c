#include <stdlib.h>
#include <stdio.h>
#include "tokenizer.h"

int space_char(char c)
{
  if (c == '\t' || c == ' ')
    return 1;
  else 
    return 0;
}

int non_space_char(char c)
{
  if (c == '\t' || c == ' ' || c == '\0')
    return 0;
  else
    return 1;
}

char *word_start(char *str)
{
  while(space_char(*str))
    str++;
  return str;
}

char *word_terminator(char *word)
{
  while(non_space_char(*word))
    word++;
  return word - 1;
}

int count_words(char *str) 
{
  int count = 0;
  while (*str != '\0'){
      if (space_char(*str))
	++count;
      str++;
  }
  return count;
}

char *copy_str(char *inStr, short len)
{
  char *mem = (char*)malloc((len+1)*sizeof(char));
  for (int i = 0; i < len; i++)
    *(mem+i) = *(inStr+i);
  *(mem+(len)) = '\0';
  return mem;
}

void print_tokens(char **tokens)
{
  //printf("%d", sizeof(*tokens));
  for (int i = 0; **tokens != '\0'; i++)
    printf("%s\n", *(tokens+i));
}

void free_tokens(char **tokens)
{
  free(*tokens);
  printf("Tokens freed.\n");
}

char **tokenize(char *s)
{
  int count = count_words(s);
  char **pointer_array = (char**)malloc((count+1)*sizeof(char*)); // +1 for the \0.
  char *end;
  char *start = word_start(s);
  for (int i = 0; i < count; i++){
    end = word_terminator(start); // makes word_terminator act on the token.
    *(pointer_array+i) = copy_str(start, (end - start)); // end - start subtracts the addresses.
    start = word_start(end);
  }
  *(pointer_array+count) = NULL;
  return pointer_array;
}
/*
int main()
{
  char leo[] = ("Ashe7l9hellohowareyou hello");
  char x = *word_start(leo);
  char end = *word_terminator(leo);
  putchar(x);
  printf("\n");
  putchar(end);
  printf("\n");

  int count = count_words(leo);
  printf("%d\n", count);
}
*/
