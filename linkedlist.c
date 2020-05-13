#include "linkedlist.h"

List_ptr create_list(void)
{
  List_ptr linked_list = (List_ptr)malloc(sizeof(LinkedList));

  linked_list->first = NULL;
  linked_list->last = NULL;
  linked_list->length = 0;

  return linked_list;
}
