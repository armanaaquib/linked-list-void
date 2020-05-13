#include "test_insertions.h"

void test_add_to_list(void)
{
  printf("testing add_to_list()\n");

  List_ptr linked_list = create_list();

  Element element = malloc(sizeof(int));
  DEREF(Int_ptr)element = 10;

  assert_int_equal(add_to_list(linked_list, element), Success, "should add to end of empty linked list");
  assert_linked_list(linked_list, linked_list->first, linked_list->first, 1);

  Node_ptr first = linked_list->first;
  element = malloc(sizeof(int));
  DEREF(Int_ptr)element = 20;

  assert_int_equal(add_to_list(linked_list, element), Success, "should add to end of list");
  assert_linked_list(linked_list, first, linked_list->last, 2);

  printf("\n");
}
