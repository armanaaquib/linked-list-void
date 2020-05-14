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

void test_insert_at(void)
{
  printf("testing insert_at()\n");

  List_ptr linked_list = create_list();

  Element element = malloc(sizeof(int));
  DEREF (Int_ptr)element = 10;

  int array_1[] = {10};
  List_ptr expected = create_list_from_ints(array_1, 1);

  assert_int_equal(insert_at(linked_list, element, 0), Success, "should return Success for inserting at 0 pos for empty linked list");
  assert_linked_list_deep_equal(linked_list, expected, is_int_equal, "should insert at 0 if linked list is empty");

  element = malloc(sizeof(int));
  DEREF (Int_ptr)element = 20;

  int array_2[] = {10, 20};
  expected = create_list_from_ints(array_2, 2);

  assert_int_equal(insert_at(linked_list, element, 1), Success, "should return Success inserting at end of linked list");
  assert_linked_list_deep_equal(linked_list, expected, is_int_equal, "should insert at end of the linked list");

  element = malloc(sizeof(int));
  DEREF (Int_ptr)element = 15;

  int array_3[] = {10, 15, 20};
  expected = create_list_from_ints(array_3, 3);

  assert_int_equal(insert_at(linked_list, element, 1), Success, "should return Success inserting in middle of the linked list");
  assert_linked_list_deep_equal(linked_list, expected, is_int_equal, "should insert in middle of the linked list");

  element = malloc(sizeof(int));
  DEREF (Int_ptr)element = 5;

  int array_4[] = {5, 10, 15, 20};
  expected = create_list_from_ints(array_4, 4);

  assert_int_equal(insert_at(linked_list, element, 0), Success, "should return Success inserting in begining of the linked list");
  assert_linked_list_deep_equal(linked_list, expected, is_int_equal, "should insert in begining of the linked list");

  assert_int_equal(insert_at(linked_list, element, 5), Failure, "should return Failure if pos is out of range");
  assert_linked_list_deep_equal(linked_list, expected, is_int_equal, "should not insert if pos is out of range");

  assert_int_equal(insert_at(linked_list, element, -1), Failure, "should return Failure if pos is negative");
  assert_linked_list_deep_equal(linked_list, expected, is_int_equal, "should not insert if pos is negative");

  printf("\n");
}

void test_add_unique(void)
{
  printf("testing add_unique()\n");

  int array[] = {5, 10, 20};
  List_ptr linked_list = create_list_from_ints(array, 3);

  Element element = malloc(sizeof(int));
  
  DEREF (Int_ptr)element = 10;
  assert_int_equal(add_unique(linked_list, element, is_int_equal), Failure, "should return failure if element is already present");

  List_ptr expected_ll = create_list_from_ints(array, 3);
  assert_linked_list_deep_equal(linked_list, expected_ll, is_int_equal, "should not add if element is already present");

  DEREF (Int_ptr)element = 15;
  assert_int_equal(add_unique(linked_list, element, is_int_equal), Success, "should add if value is not present in the list");

  int array_1[] = {5, 10, 20, 15};
  expected_ll = create_list_from_ints(array_1, 4);

  assert_linked_list_deep_equal(linked_list, expected_ll, is_int_equal, "should add to list if element is not present in the linked list");

  printf("\n");
}

