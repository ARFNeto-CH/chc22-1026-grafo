#include <stdio.h>
#include <stdlib.h>

typedef struct st_node {
  int value;
  struct st_node* next;
} Node;

typedef struct {
  unsigned size;  // useful metadata
  Node* head;
} List;

List* create_list();
List* delete_list(List*);
int get_at_index(unsigned index, List* list, int* slot);
int print_list(List*);
int push(int value, List* list);
int pull(List* list);

int main(void) {
  // some tests

  // create and destroy only
  List* list = create_list();
  list = delete_list(list);

  // create list and destroy
  list = create_list();
  print_list(list);
  list = delete_list(list);

  // insert 10 to 1
  list = create_list();
  for (int i = 10; i > 0; i -= 1)
    push(i, list);
  print_list(list);
  list = delete_list(list);

  // insert 10 to 1, then list by position from last to first
  list = create_list();
  for (int i = 10; i > 0; i -= 1)
    push(i, list);
  print_list(list);
  printf(
      "\n\tnow lists elements from tail to head\n\tusing get_at_index(#n)\n");
  int value = 0;
  for (int i = list->size - 1; i >= 0; i -= 1) {
    get_at_index(i, list, &value);
    printf("#%u:\t%d\n", i, value);
  }
  unsigned pos = list->size + 1;
  printf("\n\tnow try get_at_index(#n) for #%u element\n", pos);
  int res = get_at_index(pos, list, &value);
  printf("\n\tget_at_index() returned %d for element #%u\n", res, pos);
  list = delete_list(list);
  return 0;
}

List* create_list() {
  List* lst = (List*)malloc(sizeof(List));
  if (lst == NULL)
    return NULL;
  lst->size = 0;     // needed
  lst->head = NULL;  // not needed
  return lst;
}

List* delete_list(List* lst) {
  if (lst == NULL)
    return NULL;         // no list
  if (lst->size == 0) {  // empty list
    free(lst);
    return NULL;
  }
  // ok, just delete one by one
  Node* this = lst->head;  // just for readability
  for (unsigned i = 0; i < lst->size; i++) {
    Node* next = this->next;  // save addr
    free(this);
    this = next;
  }
  free(lst);
  return NULL;
}

int get_at_index(unsigned index, List* list, int* slot) {
  // return the value at #index in slot
  // or negative value for error
  if (list == NULL)
    return -1;  // no list
  if (slot == NULL)
    return -2;
  if ((list->size == 0) || (index > list->size))
    return -3;  // empty
  if (list->size == 0)
    return -3;  // empty
  Node* p = list->head;
  // skip previous nodes
  for (unsigned i = 0; i < index; i += 1)
    p = p->next;
  // get value
  *slot = p->value;
  return 0;
}

int print_list(List* list) {
  if (list == NULL) {
    printf("list not created\n");
    return 0;  // it is ok
  }
  if (list->size == 0) {
    printf("list is empty\n");
    return 0;  // it is ok
  }
  printf("list has %u elements:\n    [ ", list->size);
  Node* p = list->head;
  for (unsigned i = 0; i < list->size; i++) {
    printf("%d ", p->value);
    p = p->next;
  }
  printf(" ]\n\n");
  return 0;
}

int push(int value, List* list) {  // push an element at the head
  if (list == NULL)
    return -1;  // no list
  Node* new = (Node*)malloc(sizeof(Node));
  if (new == NULL)
    return -2;
  new->value = value;
  new->next = list->head;  // current head
  list->head = new;        // new head
  list->size += 1;         // count one more in
  return 0;
}

int pull(List* list) {
  if (list == NULL)
    return -1;  // no list
  if (list->size == 0)
    return -2;  // empty list
  int value = list->head->value;
  Node* save = list->head->next;
  // now delete node and update list
  free(list->head);
  list->head = save;
  list->size -= 1;  // one less
  return value;     // as expected
}
