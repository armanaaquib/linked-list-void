#include <stdio.h>
#include <stdlib.h>
#include "test_linkedlist.h"

void test_create_list(void);
void test_create_node(void);

void test_create_list(void)
{
  printf("testing create_list()\n");

  List_ptr linked_list = create_list();
  assert_node_null(linked_list->first, "first should be NULL");
  assert_node_null(linked_list->last, "last should be NULL");
  assert_int_equal(linked_list->length, 0, "length should be 0");

  printf("\n");
}

void test_create_node(void)
{
  printf("testing create_node()\n");

  Element element = malloc(sizeof(int));
  DEREF(Int_ptr)element = 10;

  Node_ptr node = create_node(element);

  assert_element_equal(node->element, element, "element should be passed element");
  assert_node_null(node->next, "Next should be null");

  printf("\n");
}


int main(void)
{
  test_create_list();
  test_create_node();

  display_tests_status();

  return 0;
}