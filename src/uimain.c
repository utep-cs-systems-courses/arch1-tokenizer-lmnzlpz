#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int main()
{
  printf("The program will reset history every 3 items.\n");
  printf("Enter * to see all history.\nEnter !1-3 to see respective item in memory.\n\n");
  char input[100];
  List *x = init_history();
  char **pointer_array;
  while (1){
      printf(">>>");
      fgets(input, sizeof(input), stdin);

      /*
	The following if statements control the user input
	when the user wants to search for history.
       */
      if (input[0] == '!'){
	if (input[1] == '1'){
	  printf("Stored in memory 1: %s\n", get_history(x,1));
	  continue;
	}
	if (input[1] == '2'){
	  printf("Stored in memory 2: %s\n", get_history(x, 2));
	  continue;
	}
	if (input[1] == '3'){
	  printf("Stored in memory 3: %s\n", get_history(x, 3));
	  continue;
	}
	else{
	  printf("Invalid Input.\n");
	  continue;
	}
      }

      //prints history with symbol *
      if (input[0] == '*'){
	print_history(x);
	continue;
      }
      if(input[0] == '~')
	  break;
      
      printf("Echo: %s\n", input);
      add_history(x, input); //creates a node with the appropriate info.
      pointer_array = tokenize(input); //this array is the array of pointers.
      printf("Pointer Array:\n");
      print_tokens(pointer_array);
   
    }
  print_history(x); //prints left over history.
  free_tokens(pointer_array); //frees memory before ending program.
  return 0;
}
