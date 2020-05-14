#include "test_linkedlist.h"

unsigned NO_OF_PASSING_TEST = 0;
unsigned NO_OF_FAILING_TEST = 0;

void display_tests_status(void)
{
  printf("Passing %u, ", NO_OF_PASSING_TEST);
  printf("Failing %u\n", NO_OF_FAILING_TEST);
}

void fail_message(Message message)
{
  printf("X %s\n", message);
}

void pass_message(Message message)
{
  printf("- %s\n", message);
}

Status is_int_equal(Element el_1, Element el_2)
{
  return DEREF (Int_ptr)el_1 == DEREF (Int_ptr)el_2;
}

void assert_node_null(Node_ptr node, Message message)
{
  if(node == NULL)
  {
    NO_OF_PASSING_TEST++;
    pass_message(message);
    return;
  }

  NO_OF_FAILING_TEST++;
  fail_message(message);
}

void assert_element_equal(Element el_1, Element el_2, Message message)
{
  if(el_1 == el_2)
  {
    NO_OF_PASSING_TEST++;
    pass_message(message);
    return;
  }

  NO_OF_FAILING_TEST++;
  fail_message(message);
}

void assert_element_deep_equal(Element el_1, Element el_2, Are_Equal is_el_equal, Message message)
{
  if(is_el_equal(el_1, el_2))
  {
    NO_OF_PASSING_TEST++;
    pass_message(message);
    return;
  }

  NO_OF_FAILING_TEST++;
  fail_message(message);
}

void assert_int_equal(int value_1, int value_2, Message mesaage)
{
  if(value_1 == value_2)
  {
    NO_OF_PASSING_TEST++;
    pass_message(mesaage);
    return;
  }

  NO_OF_FAILING_TEST++;
  fail_message(mesaage);
}

void assert_node_equal(Node_ptr node_1, Node_ptr node_2, Message message)
{
  if(node_1 == node_2)
  {
    NO_OF_PASSING_TEST++;
    pass_message(message);
    return;
  }

  NO_OF_FAILING_TEST++;
  fail_message(message);
}

void assert_linked_list(List_ptr list, Node_ptr first, Node_ptr last, int length)
{
  assert_node_equal(list->first, first, "  first");
  assert_node_equal(list->last, last, "  last");
  assert_int_equal(list->length, length, "  length");
}

void assert_linked_list_deep_equal(List_ptr lk_1, List_ptr lk_2, Are_Equal is_element_equal, Message message)
{
  Status are_equals = Success;
  
  are_equals = are_equals && (lk_1->length == lk_2->length);

  if(!are_equals)
  {
    NO_OF_FAILING_TEST++;
    fail_message(message);
    return;
  }

  Node_ptr p_walk_1 = lk_1->first;
  Node_ptr p_walk_2 = lk_2->first;

  while(p_walk_1 != NULL)
  {
    are_equals = are_equals && (DEREF is_element_equal)(p_walk_1->element, p_walk_2->element);
    p_walk_1 = p_walk_1->next;
    p_walk_2 = p_walk_2->next;
  }

  if(are_equals)
  {
    NO_OF_PASSING_TEST++;
    pass_message(message);
    return;
  }

  NO_OF_FAILING_TEST++;
  fail_message(message);
}

List_ptr create_list_from_ints(Int_ptr array, unsigned length)
{
  List_ptr linked_list = create_list();

  for(unsigned i = 0; i < length; i++)
  {
    Element el = malloc(sizeof(int));
    DEREF (Int_ptr)el = array[i];

    add_to_list(linked_list, el);
  }

  return linked_list;
}
