#include <stdio.h>

#include "list.h"

int main() {
  
  
  list_t *myList = list_alloc();
  list_print(myList);
  
  

  
 //Add Functions 
  printf("These are the add functions\n");
  printf("\n");
  printf("Adds to back of the list\n");
  list_add_to_back(myList, 5);        //  5 ->
  list_print(myList);
  list_add_to_back(myList, 6);        //  5 -> 6 ->
  list_print(myList);
  printf("\n");
  printf("Adds to front of the list\n");
  list_add_to_front(myList, 2);       //  2 -> 5 -> 6 ->
  list_print(myList);
  list_add_to_front(myList, 1);       //  1 -> 2 -> 5 -> 6 ->
  list_print(myList);
  printf("\n");
  printf("Adds to specified index in the list\n");
  list_add_at_index(myList, 3, 2);    //  1 -> 2 -> 3 -> 5 -> 6 ->
  list_print(myList);
  list_add_at_index(myList, 4, 3);    //  1 -> 2 -> 3 -> 4 -> 5 -> 6
  
  list_print(myList);
  
  printf("\n");
  printf("The current list length is: %d\n", list_length(myList));   //  6
  
  //Remove Functions 
  printf("\n");
  printf("Removes from the back of the list\n");
  list_remove_from_back(myList);      //  1 -> 2 -> 3 -> 4 -> 5 -> 
  list_print(myList);
  printf("\n");
   printf("Removes from the front of the list\n");
  list_remove_from_front(myList);     //  2 -> 3 -> 4 -> 5 ->
  list_print(myList);
  printf("\n");
  printf("Removes at specified index in the list\n");
  list_remove_at_index(myList, 2);    //  2 -> 3 -> 5 -> 
  
  list_print(myList);
  printf("The new list length is: %d\n", list_length(myList)); //3
  
  //  Search Functions
  printf("\n");
  printf("Checks to see if a value is in the list\n");
  printf("Is 1 in the list (Yes = 1, No = 0)? : %d\n", list_is_in(myList, 1));              
  printf("Is 2 in the list (Yes = 1, No = 0)? : %d\n", list_is_in(myList, 2));               
  printf("\n");
  printf("Finds a value in the list\n");
  list_print(myList);
  printf("The element found at index 1 is: %d\n", list_get_elem_at(myList, 1));                
  printf("\n");
  printf("Finds the index of a value in the list\n");
  list_print(myList);
  printf("The index of the value 5 is: %d\n", list_get_index_of(myList, 5));              
  printf("\n");
  
  return 0;
}