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

Status add_to_start(List_ptr linked_list, Element element)
{
  Node_ptr node = create_node(element);

  if(!node)
  {
    return Failure;
  }

  node->next = linked_list->first;
  linked_list->first = node;
  linked_list->length++;

  if(linked_list->last == NULL)
  {
    linked_list->last = node;
  }

  return Success;
}

Status insert_at(List_ptr linked_list, Element element, int position)
{
  if(position > linked_list->length)
  {
    return Failure;
  }

  Node_ptr node = create_node(element);

  if(!node)
  {
    return Failure;
  }

  Prev_Current_Pair pair;
  pair.current = linked_list->first;
  pair.prev = NULL;

  int pos = 0;

  while(pos < position)
  {
    pair.prev = pair.current;
    pair.current = pair.current->next;
    pos++;
  }

  Ptr_to_node_ptr ptr_to_set = &linked_list->first;

  if(pair.prev != NULL)
  {
    ptr_to_set = &pair.prev->next;
  }

  DEREF ptr_to_set = node;
  node->next = pair.current;
  linked_list->length++;

  if(pair.current == NULL)
  {
    linked_list->last = node;
  }

  return Success;
}

List_ptr reverse(List_ptr linked_list)
{
  List_ptr rev_linked_list = create_list();

  Node_ptr p_walk = linked_list->first;

  while(p_walk != NULL)
  {
    add_to_start(rev_linked_list, p_walk->element);
    p_walk = p_walk->next;
  }

  return rev_linked_list;
}

List_ptr map(List_ptr linked_list, Mapper mapper)
{
  List_ptr new_linked_list = create_list();

  Node_ptr p_walk = linked_list->first;

  while(p_walk != NULL)
  {
    Element new_element = (DEREF mapper)(p_walk->element);
    add_to_list(new_linked_list, new_element);
    p_walk = p_walk->next;
  }

  return new_linked_list;
}

List_ptr filter(List_ptr linked_list, Predicate predicate)
{
  List_ptr new_linked_list = create_list();

  Node_ptr p_walk = linked_list->first;

  while(p_walk != NULL)
  {
    Element el = p_walk->element;

    if((DEREF predicate)(el))
    {
      add_to_list(new_linked_list, el);
    }
      
    p_walk = p_walk->next;
  }

  return new_linked_list;
}

Element reduce(List_ptr linked_list, Element init, Reducer reducer)
{
  Element result = init;

  Node_ptr p_walk = linked_list->first;

  while(p_walk != NULL)
  {
    result = (DEREF reducer)(result, p_walk->element);
    p_walk = p_walk->next;
  }

  return result;
}

void forEach(List_ptr linked_list, ElementProcessor processor)
{
  Node_ptr p_walk = linked_list->first;

  while(p_walk != NULL)
  {
    (DEREF processor)(p_walk->element);
    p_walk = p_walk->next;
  }
}

Element remove_from_start(List_ptr linked_list)
{
  if(linked_list->first == NULL)
  {
    return NULL;
  }

  Node_ptr node_to_remove = linked_list->first;
  linked_list->first = node_to_remove->next;
  linked_list->length--;

  Element removed_el = node_to_remove->element;
  free(node_to_remove);

  if(linked_list->first == NULL)
  {
    linked_list->last = NULL;
  }

  return removed_el;
}
