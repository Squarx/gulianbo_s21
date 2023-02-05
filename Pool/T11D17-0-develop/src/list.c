#include "list.h"

struct node* init(struct door* doors) {
  struct node *lst;
  lst = (struct node*)malloc(sizeof(struct node));
  lst -> field = doors;
  lst -> next = NULL;
  return(lst);
}

struct node* add_door(struct node* elem, struct door* door) {
  struct node* temp = NULL, *p;
  if (elem != NULL && door != NULL) {
    temp = malloc(sizeof(struct node));
    p = elem -> next;
    elem -> next = temp;
    temp -> field = door;
    temp -> next = p;
  }
  return (temp);
}

struct node* find_door(int door_id, struct node* root) {
  struct node* temp;
  temp = root;
  while (temp->field->id != door_id) {
    temp = temp -> next;
  }
return temp;
}

struct node* remove_door(struct node* elem, struct node* root) {
  struct node* temp = NULL;
  if (elem != NULL && root != NULL) {
    temp = root;
    while (temp ->next != elem) {
      temp = temp -> next;
    }
    temp -> next = elem -> next;
    free(elem);
  }
  return (temp);
}

void destroy(struct node* root) {
  struct node* temp;
  struct node* temp1;
  temp = root;
  while (temp ->next != NULL) {
    temp1 = temp;
    temp = temp -> next;
    free(temp1);
  }
  free(temp);
}

void print_struct(struct node* root) {
  struct node* p;
  if (root != NULL) {
     p = root;
    while (p ->next != NULL) {
      printf("ID = %d STATUS = %d\n", p -> field -> id, p -> field -> status);
      p = p -> next;
    }
  } else {
    printf("EMPTY");
  }
}
