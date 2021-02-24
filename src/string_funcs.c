#include <stdio.h>
#include "tokenizer.h"

int space_char(char c)
{
  if (c == '\t' || c == ' ')
    {
      return 1;
    }
  else 
    {
      return 0;
    }
}

int non_space_char(char c)
{
  if (c == '\t' || c == ' ' || c == '\0')
    {
      return 0;
    }
  else
    {
      return 1;
    }
}

char *word_start(char *str)
{
  while(space_char(*str) == 1)
    {
      str++;
    }
  return str;
}

char *word_terminator(char *word)
{
  while(non_space_char(*word) == 1)
    {
      word++;
    }
  return word-1;
}

int main()
{
  char leo[] = ("Ashe7l9");
  char x = *word_start(leo);
  char end = *word_terminator(leo);
  putchar(x);
  printf("\n");
  putchar(end);
  printf("\n");
}
