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
