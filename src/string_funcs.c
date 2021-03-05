#include <stdlib.h>
#include <stdio.h>
#include "tokenizer.h"
#include "history.h"

// Determines if a char is a space or tab.
int space_char(char c){
  if (c == '\t' || c == ' ')
    return 1;
  else 
    return 0;
}

// Determines if a char is not a space or tab.
int non_space_char(char c){
  if (c == '\t' || c == ' ' || c == '\0')
    return 0;
  else
    return 1;
}

//Returns a pointer to the start of a word.
char *word_start(char *str){
  while(space_char(*str))
    str++;
  return str;
}

//Returns a pointer to the end of a word.
char *word_terminator(char *word){
  while(non_space_char(*word))
    word++;
  return word;
}

//Counts the number of words in one input instance.
int count_words(char *str){
  int count = 0;
  while (*str != '\0'){
      if (space_char(*str))
	++count;
      str++;
  }
  return count;
}

//Returns a newly allocated memory pointer with a copy of inStr
char *copy_str(char *inStr, short len){
  char *copy = (char*)malloc((len+1)*sizeof(char));
  for (int i = 0; i < len; i++)
    *(copy+i) = *(inStr+i);
  *(copy+(len)) = '\0';
  return copy;
}

//Prints tokens
void print_tokens(char **tokens){
  for (int i = 0; tokens[i] != '\0'; i++){
    printf("%s\n", tokens[i]);
  }
}

//Frees the memory holding the tokens.
void free_tokens(char **tokens){
  for (int i = 0; tokens[i] != '\0'; i++){
    free(tokens[i]);
  }
}

//Tokenize method that turn a string into tokens. 
char **tokenize(char *s){
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
