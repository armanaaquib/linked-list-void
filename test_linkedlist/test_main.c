#include "test_linkedlist.h"

void test_create_list(void);

void test_create_list(void)
{
  printf("testing create_list()\n");

  List_ptr linked_list = create_list();
  assert_node_equal(linked_list->first, NULL, "first should be NULL");
  assert_node_equal(linked_list->last, NULL, "last should be NULL");
  assert_int_equal(linked_list->length, 0, "length should be 0");

  printf("\n");
}

int main(void)
{
  test_create_list();

  display_tests_status();

  return 0;
}
