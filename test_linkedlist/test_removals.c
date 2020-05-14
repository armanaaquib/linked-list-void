#include "test_removals.h"

void test_remove_from_start(void)
{
  printf("testing remove_from_start()\n");

  int array_1[] = {10, 20};
  List_ptr linked_list = create_list_from_ints(array_1, 2);

  Element removed_el = remove_from_start(linked_list);

  Element exp_removed_el = malloc(sizeof(int));
  DEREF (Int_ptr)exp_removed_el = 10;

  int array_2[] = {20};
  List_ptr expected_ll = create_list_from_ints(array_2, 1);

  assert_element_deep_equal(removed_el, exp_removed_el, is_int_equal, "should return start from the linked list");
  assert_linked_list_deep_equal(linked_list, expected_ll, is_int_equal,"should remove first element of the linked list");

  removed_el = remove_from_start(linked_list);

  exp_removed_el = malloc(sizeof(int));
  DEREF(Int_ptr)exp_removed_el = 20;

  expected_ll = create_list();

  assert_element_deep_equal(removed_el, exp_removed_el, is_int_equal, "should return start from the single value linked list");
  assert_linked_list_deep_equal(linked_list, expected_ll, is_int_equal,"should remove first element of the single value linked list");

  removed_el = remove_from_start(linked_list);

  assert_element_equal(removed_el, NULL, "should return NULL if linked list is empty");

  printf("\n");
}

void test_remove_from_end(void)
{
  printf("testing remove_from_end()\n");

  int array_1[] = {10, 20};
  List_ptr linked_list = create_list_from_ints(array_1, 2);

  Element removed_el = remove_from_end(linked_list);

  Element exp_removed_el = malloc(sizeof(int));
  DEREF (Int_ptr)exp_removed_el = 20;

  int array_2[] = {10};
  List_ptr expected_ll = create_list_from_ints(array_2, 1);

  assert_element_deep_equal(removed_el, exp_removed_el, is_int_equal, "should return end from the linked list");
  assert_linked_list_deep_equal(linked_list, expected_ll, is_int_equal,"should remove last element of the linked list");

  removed_el = remove_from_end(linked_list);

  exp_removed_el = malloc(sizeof(int));
  DEREF(Int_ptr)exp_removed_el = 10;

  expected_ll = create_list();

  assert_element_deep_equal(removed_el, exp_removed_el, is_int_equal, "should return end from the single value linked list");
  assert_linked_list_deep_equal(linked_list, expected_ll, is_int_equal,"should remove last element of the single value linked list");

  removed_el = remove_from_end(linked_list);

  assert_element_equal(removed_el, NULL, "should return NULL if linked list is empty");

  printf("\n");
}

void test_remove_at(void)
{
  printf("testing remove_at()\n");

  int array_1[] = {5, 10, 20, 30};
  List_ptr linked_list = create_list_from_ints(array_1, 4);

  Element removed_el = remove_at(linked_list, 4);

  int array_2[] = {5, 10, 20, 30};
  List_ptr expected_ll = create_list_from_ints(array_2, 4);

  assert_element_equal(removed_el, NULL, "should return NULL if pos is out of range");
  assert_linked_list_deep_equal(linked_list, expected_ll, is_int_equal,"should not remove if pos is out of range");

  removed_el = remove_at(linked_list, 4);

  assert_element_equal(removed_el, NULL, "should return NULL if pos is negative");
  assert_linked_list_deep_equal(linked_list, expected_ll, is_int_equal,"should not remove if pos is negative");

  removed_el = remove_at(linked_list, 0);

  Element exp_removed_el = malloc(sizeof(int));
  DEREF (Int_ptr)exp_removed_el = 5;

  int array_3[] = {10, 20, 30};
  expected_ll = create_list_from_ints(array_3, 3);

  assert_element_deep_equal(removed_el, exp_removed_el, is_int_equal, "should return 0th pos element from the linked list");
  assert_linked_list_deep_equal(linked_list, expected_ll, is_int_equal,"should remove first element of the linked list");

  removed_el = remove_at(linked_list, 1);

  exp_removed_el = malloc(sizeof(int));
  DEREF (Int_ptr)exp_removed_el = 20;

  int array_4[] = {10, 30};
  expected_ll = create_list_from_ints(array_4, 2);

  assert_element_deep_equal(removed_el, exp_removed_el, is_int_equal, "should return middle element from the linked list");
  assert_linked_list_deep_equal(linked_list, expected_ll, is_int_equal,"should remove middle element of the linked list");

  removed_el = remove_at(linked_list, 1);

  exp_removed_el = malloc(sizeof(int));
  DEREF (Int_ptr)exp_removed_el = 30;

  int array_5[] = {10};
  expected_ll = create_list_from_ints(array_5, 1);

  assert_element_deep_equal(removed_el, exp_removed_el, is_int_equal, "should return last element from the linked list");
  assert_linked_list_deep_equal(linked_list, expected_ll, is_int_equal,"should remove last element of the linked list");

  removed_el = remove_at(linked_list, 0);

  exp_removed_el = malloc(sizeof(int));
  DEREF (Int_ptr)exp_removed_el = 10;

  expected_ll = create_list();

  assert_element_deep_equal(removed_el, exp_removed_el, is_int_equal, "should return first element from the one element linked list");
  assert_linked_list_deep_equal(linked_list, expected_ll, is_int_equal,"should remove first element of the one element linked list");

  printf("\n");
}

void test_remove_first_occurrence(void)
{
  printf("testing remove_first_occurrence()\n");

  int array[] = {5, 10, 5, 10};
  List_ptr linked_list = create_list_from_ints(array, 4);

  Element element = malloc(sizeof(int));
  DEREF (Int_ptr)element = 10;

  Element removed_el = remove_first_occurrence(linked_list, element, is_int_equal);

  int array_1[] = {5, 5, 10};
  List_ptr expected_ll = create_list_from_ints(array_1, 3);

  Element exp_removed_el = malloc(sizeof(int));
  DEREF (Int_ptr)exp_removed_el = 10;

  assert_element_deep_equal(removed_el, exp_removed_el, is_int_equal,"should return first occurrance of element");
  assert_linked_list_deep_equal(linked_list, expected_ll, is_int_equal, "should remove first occurrance of element");

  element = malloc(sizeof(int));
  DEREF (Int_ptr)element = 20;

  removed_el = remove_first_occurrence(linked_list, element, is_int_equal);

  assert_element_equal(removed_el, NULL, "should return NULL if element doesn't match");
  assert_linked_list_deep_equal(linked_list, expected_ll, is_int_equal, "should not remove if element doesn't match");

  printf("\n");
}

void test_remove_all_occurrences(void)
{
  printf("testing remove_all_occurrence()\n");

  int array[] = {5, 10, 5, 10, 20};
  List_ptr linked_list = create_list_from_ints(array, 5);

  Element element = malloc(sizeof(int));
  DEREF (Int_ptr)element = 10;

  List_ptr removed_linked_list = remove_all_occurrences(linked_list, element, is_int_equal);
  
  int array_1[] = {10, 10};
  List_ptr expected_ll = create_list_from_ints(array_1, 2);

  assert_linked_list_deep_equal(removed_linked_list, expected_ll, is_int_equal,"should return removed elements linked list");

  int array_2[] = {5, 5, 20};
  expected_ll = create_list_from_ints(array_2, 3);

  assert_linked_list_deep_equal(linked_list, expected_ll, is_int_equal, "should remove all occurrance of element");

  removed_linked_list = remove_all_occurrences(linked_list, element, is_int_equal);

  expected_ll = create_list();

  assert_linked_list_deep_equal(removed_linked_list, expected_ll, is_int_equal, "should return empty liked list if element doesn't match");

  int array_3[] = {5, 5, 20};
  expected_ll = create_list_from_ints(array_3, 3);

  assert_linked_list_deep_equal(linked_list, expected_ll, is_int_equal, "should not remove if element doesn't match");

  printf("\n");
}
