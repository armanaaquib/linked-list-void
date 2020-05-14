#include "test_insertions.h"

void test_add_to_list(void)
{
  printf("testing add_to_list()\n");

  List_ptr linked_list = create_list();

  Element element = malloc(sizeof(int));
  DEREF(Int_ptr)element = 10;

  int int_array[] = {10};
  List_ptr expected = create_list_from_ints(int_array, 1);

  assert_int_equal(add_to_list(linked_list, element), Success, "should return Success for empty linked list");
  assert_linked_list_deep_equal(linked_list, expected, is_int_equal, "should add to empty linked list");

  element = malloc(sizeof(int));
  DEREF(Int_ptr)element = 20;
  
  int new_array[] = {10, 20};
  expected = create_list_from_ints(new_array, 2);

  assert_int_equal(add_to_list(linked_list, element), Success, "should return Success for linked list");
  assert_linked_list_deep_equal(linked_list, expected, is_int_equal, "should add to linked list");

  printf("\n");
}

void test_add_to_start(void)
{
  printf("testing add_to_start()\n");

  List_ptr linked_list = create_list();

  Element element = malloc(sizeof(int));
  DEREF(Int_ptr)element = 10;

  int int_array[] = {10};
  List_ptr expected = create_list_from_ints(int_array, 1);

  assert_int_equal(add_to_start(linked_list, element), Success, "should return Success for empty linked list");
  assert_linked_list_deep_equal(linked_list, expected, is_int_equal, "should add to start of empty linked list");

  element = malloc(sizeof(int));
  DEREF(Int_ptr)element = 20;

  int new_array[] = {20, 10};
  expected = create_list_from_ints(new_array, 2);

  assert_int_equal(add_to_start(linked_list, element), Success, "should return Success for linked list");
  assert_linked_list_deep_equal(linked_list, expected, is_int_equal, "should add to start of linked list");

  printf("\n");
}
