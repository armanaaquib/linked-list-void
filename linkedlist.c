#include "linkedlist.h"

List_ptr create_list(void)
{
  List_ptr linked_list = (List_ptr)malloc(sizeof(LinkedList));

  linked_list->first = NULL;
  linked_list->last = NULL;
  linked_list->length = 0;

  return linked_list;
}

Node_ptr create_node(Element element)
{
  Node_ptr node = (Node_ptr)malloc(sizeof(Node));

  if(node)
  {
    node->element = element;
    node->next = NULL;
  }
  
  return node;
}
