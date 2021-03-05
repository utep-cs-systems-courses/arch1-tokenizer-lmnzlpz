#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

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
  char *newStr;
  newStr = copy_str(str, 1000);
  new_node -> str = newStr;
  new_node -> next = NULL;

  int id;
  Item *temp = list -> root;
  while (temp -> next != NULL){
    temp = temp -> next;
  }
  id = temp->id;
  //if statement makes sure there is a max of 3 items in memory.
  if (id == 3){
    id = 0;
    free_history(list);
  }
  new_node->id = id+1;
  temp -> next = new_node;
}

/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char *get_history(List *list, int id){
  Item *temp = list->root;
  while (temp->id != id){
    if (temp->next == NULL){
      return ("Item Not Found\n");
    }
    temp = temp->next;
  }
  return temp->str;
}

//Prints history.
void print_history(List *list){
  Item *temp = list -> root->next;
  if (temp == NULL){
    printf("List is empty\n");
    return;
  }
  while (temp != NULL){
    printf("%d.) %s\n", temp->id,temp->str);
    temp = temp->next;
  }
}

//frees memory allocated for nodes.
void free_history(List *list){
  Item *temp;
  Item *head = list->root -> next;
  while (head != NULL){
    temp = head;
    head = head->next;
    free(temp);
    list->root = (Item*)malloc(sizeof(Item));
  }
}

 
