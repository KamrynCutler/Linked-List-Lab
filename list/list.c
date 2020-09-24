// list/list.c
// 
// Implementation for linked list.
//
// <Kamryn Cutler>

#include <stdio.h>

#include <stdlib.h>

#include "list.h"

//int list_size = 0; 

list_t *list_alloc() {
  list_t *list = (list_t*)malloc(sizeof(list_t));
  list->head = NULL;
  return list;
}

void list_free(list_t *l) {
  free(l);
};


void list_print(list_t *l) {
  node_t *current_node;
  //Point to the head of the list
  current_node = l->head;
  
  if (current_node == NULL){
    printf("list is empty\n");
  }
  
  //Loop until the end of the list is reached (NULL)
  while (current_node != NULL){
    printf("%d -> ", current_node->value); //Prints the contents of the node
    current_node = current_node->next; //Advances the pointer to the next node
  }
  printf("\n");
}

int list_length(list_t *l) {
  //Start at the head of the list
  node_t* current_node = l->head;
  
  //Set the counter to 0
  int count = 0;
  
  //Go through each node in the list and add 1 to the counter each time until NULL is reached
  while (current_node != NULL) {
    count++;
    current_node = current_node->next;
  }
  return count;
}

void list_add_to_back(list_t *l, elem value) {
  node_t *current_node; 
  node_t *new_node = (node_t*)malloc(sizeof(node_t)); //Allocates space for the element being put into the list
  new_node->value = value;
  new_node->next = NULL; //Each new node is NULL until filled with a value
  
  //Create a special case for the first one 
  //1. Check to see if the list is empty
  
  if (l->head == NULL){ 
    l->head = new_node; //1.1 If empty - point the head to new node
  }
  else{ //1.2 If not empty - insert new node at the end of the list
    
    //Point to the head of the list
    current_node = l->head;
    
    //1.2.1 Loop until the last node is reached (right before NULL)
    
    //Check if the current next pointer == NULL
    while (current_node->next != NULL){
      current_node = current_node->next; //Advances the pointer to the next node
    }
    current_node->next = new_node;
  }
}

void list_add_to_front(list_t *l, elem value) {
  node_t *current_node; 
  node_t *new_node = (node_t*)malloc(sizeof(node_t));
  new_node->value = value;
  new_node->next = NULL; //Each new node is NULL until filled with a value
  
  //Create a special case for the first one 
  //1. Check to see if the list is empty
  if (l->head == NULL){ 
    l->head = new_node; //1.1 If empty - point the head to new node
  }
  else{ //1.2 If not empty - insert new node at the begining of the list
    //Point to the head of the list
    node_t *current_node = l->head;
    
    //Make the next of new node the head
    new_node->next = l->head;
    
    //Make the head point back to the new node
    l->head = new_node;
  }
}

// Adds a node at specified index. Does nothing if index out of bounds.
void list_add_at_index(list_t *l, elem value, int index) {
  
  //node_t *current_node;
  node_t *new_node = (node_t*)malloc(sizeof(node_t));
  new_node->value = value;
  new_node->next = NULL; //Each new node is NULL until filled with a value
  
  //node_t *prev_node = (node_t*)malloc(sizeof(node_t));
  
  //Point to the head of the list
  node_t *current_node = l->head;
  
  //Check to make sure the specified index is in the size of the list
  if (index < 0) {
    printf("Invalid Index\n");
  }
  
  //Check to see if the index is NULL
  if (index == 0) {
    //Make the next of new node the next of the head
    new_node->next = l->head->next;
    
    //Make the head point back to the new node
    l->head = new_node;
  }
  
  //Create counter variable
  int i = 0;
  
  //Insert the new value into the specified index
  if(index > 0) {
    
    //Loop through the list until it is at the specified index
    while(i + 1 < index) {
      //prev_node = current_node;
      current_node = current_node->next;
      
      //Check to make sure the specified index is in the size of the list
      if (current_node->next == NULL) {
        break;
      }
      i++;
    }
    
    //prev_node->next = new_node;
    
    //Make the next of the new node the next of the current node
    new_node->next = current_node->next;
    
    //Make the current node point back to the new node
    current_node->next = new_node;
  }
}

elem list_remove_from_back(list_t *l) {
  //Check to see if the list is empty
  if (l->head == NULL) { 
    printf("list is empty\n");
  }
  
  //Point to the head of the list
  node_t *current_node = l->head;

  if(l->head != NULL) {
    int i = 0;
    //Point to the next of the current node (not the end of the list)
    while(i < list_length(l)-2) { 
      current_node = current_node->next;
      i++;
    }
    //Free up the memory of the last node in the list 
    int value = current_node->next->value;
    free(current_node->next);
    current_node->next = NULL; //Clear the memory stored in the value
    return value;
  }
  return -1; //If the list is empty
}

elem list_remove_from_front(list_t *l) {
  //Check to see if the list is empty
  if (l->head == NULL) { 
    printf("list is empty\n");
  }
  
  if (l->head != NULL) {
    node_t* current_node = l->head; //Point to the head of the list
    int value = current_node->value;
    l->head = l->head->next; //Make the next of the head the new head
    free(current_node); //Free up the memory of the first node in the list
    return value;
  }
}

void node_free(node_t * c){
  free(c);
}

elem list_remove_at_index(list_t *l, int index) { 
  //Create a counter to iterate through the list
  int i = 0;
  
  //Create a counter for the specified element
  //Must be one less than the specified element (like in add to index)
  elem value = (elem) - 1; 
  
  //Check to see if the list is empty
  if (l->head == NULL) { 
    printf("list is empty\n");
  }
  
  //Check to see if the index is at the start of the list
  if (index == 0) {
    return list_remove_from_front(l);
  }
  
  //Find where the value is in the list
  if (index > 0) {
    node_t *current_node = l->head; //Point to the head of the list
    //node_t *temp_node = (node_t*)malloc(sizeof(node_t));
    node_t *temp_node = current_node; //Keep track of the temporary and current node
    
    //1. Make sure that the current node isn't at the end of the list (NULL)
    //1a. Create conditions to find the specified index
    while(current_node != NULL) { 
      //1b. Check to see if the index is at the same position as the counter
      if(i == index) {
        value = current_node->value; 
        temp_node->next = current_node->next;
        node_free(current_node);
        break;
      }
      else { 
        temp_node = current_node;
        current_node = current_node->next;
        i++;
      }
    }
  }
  return value; 
}

bool list_is_in(list_t *l, elem value) {
  //Point to the head of the list
  node_t *current_node = l->head;
  
  //Check to see if the list is empty
  if (l->head == NULL) { 
    printf("list is empty\n");
  }
  
  //Go through the list until the value is found
  while (current_node != NULL){
    if (current_node->value == value){
      return true;
    }
    current_node = current_node->next;
  }
  return false;
}

elem list_get_elem_at(list_t *l, int index) {
  //Create a counter to iterate through the list
  int i = 0;
  elem value = (elem) - 1; 
  
  //Point to the head of the list
  node_t *current_node = l->head;
  
  //Check to see if the list is empty
  if (l->head == NULL) { 
    printf("list is empty\n");
  }
  
  //Check to make sure the specified index is in the size of the list
  if (index < 0) {
    printf("Invalid Index\n");
  }
  
  //Go through the list until the value is found
  while (current_node != NULL){
    if (i == index){
      value = current_node->value;
      return value;
    }
    else {
      current_node = current_node->next;
      i++;
    }
  }
}

int list_get_index_of(list_t *l, elem value) {
  //Create a counter to iterate through the list
  int i = 0;
  
  //Start at the head of the list
  node_t *current_node = l->head;
  
  //Check to see if the list is empty
  if (l->head == NULL) { 
    printf("list is empty\n");
  }
  
  //Check to make sure the specified index is in the size of the list
  if (i < 0) {
    printf("Invalid Index\n");
  }
  
  while (current_node != NULL){
    if (current_node->value == value){
      return i;
    }
    current_node = current_node->next;
    i++;
  }
  
  //Case for if the element is not in the list
  printf("Element cannot be found\n");
  return;
}
