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

Status add_to_list(List_ptr linked_list, Element element)
{
  Node_ptr node = create_node(element);

  if(!node)
  {
    return Failure;
  }

  Ptr_to_node_ptr ptr_to_set = &linked_list->first;

  if(linked_list->first != NULL)
  {
    ptr_to_set = &linked_list->last->next;
  }

  DEREF ptr_to_set = node;
  linked_list->last = node;
  linked_list->length++;

  return Success;
}
