#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

/*
typedef struct s_Item {
  int id;
  char *str;
  struct s_Item *next;
} Item;

typedef struct s_List {
  struct s_Item *root;
} List;
*/

/* Initialize the linked list to keep the history. */
List* init_history(){
  List *head = (List*)malloc(sizeof(List));
  Item *node = (Item*)malloc(sizeof(Item));
  head -> root = node;
  return head;
}


/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/
void add_history(List *list, char *str){
  Item *new_node = (Item*)malloc(sizeof(Item));
  new_node -> str = str;
  new_node -> next = NULL;

  Item *temp = list -> root;
  while (temp -> next != NULL)
    temp = temp -> next;
  temp -> next = new_node;
}

/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
//char *get_history(List *list, int id){}


void print_history(List *list){
  Item *temp = list -> root -> next;
  if (temp == NULL){
    printf("List is empty\n");
    return;
  }
  while (temp != NULL){
    printf("%d.) %s\n", temp->id,temp->str);
    temp = temp -> next;
  }
}


void free_history(List *list){
  Item *temp;
  Item *head = list->root->next;
  while (head != NULL){
    temp = head;
    head = head->next;
    free(temp);
  }
}

int main(){

  List *x = init_history();
  add_history(x, "Hello");
  add_history(x, "There");
  add_history(x, "Kass");
  //x -> root -> str = "Hello";
  print_history(x);
  printf("Delete LL\n");
  free_history(x);
  print_history(x);
  
 
  /*
  List *x = init_history();
  int count = 0;
  Item *ptr = x->root;
  char input[1000];
  int id = 0;
  */
}

