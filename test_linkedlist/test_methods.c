#include <stdlib.h>
#include "test_methods.h"

Element square(Element);
Status is_even(Element);
Element add(Element, Element);
void add_1(Element);

void test_map_for_empty_linked_list(void);
void test_map_for_linked_list(void);
void test_filter_for_empty_linked_list(void);
void test_filter_for_linked_list(void);
void test_reduce_for_empty_linked_list(void);
void test_reduce_for_linked_list(void);

Element square(Element element)
{
  int number = DEREF (Int_ptr)element;
  Element new_el = malloc(sizeof(int));

  DEREF (Int_ptr)new_el = number * number;

  return new_el;
}

Status is_even(Element element)
{
  int number = DEREF (Int_ptr)element;

  return number % 2 == 0 ? Success : Failure;
}

Element add(Element el_1, Element el_2)
{
  int num_1 = DEREF (Int_ptr)el_1;
  int num_2 = DEREF (Int_ptr)el_2;

  Element new_el = malloc(sizeof(int));
  DEREF (Int_ptr)new_el = num_1 + num_2;

  return new_el;
}

void add_1(Element element)
{
  DEREF (Int_ptr)element += 1;
}

void test_map_for_empty_linked_list(void)
{
  List_ptr linked_list = create_list();

  List_ptr actual_ll = map(linked_list, square);
  List_ptr expected_ll = create_list();

  assert_linked_list_deep_equal(actual_ll, expected_ll, is_int_equal, "should map an empty linked list");
}

void test_map_for_linked_list(void)
{
  int int_array[] = {1, 2, -2, 0, 3};
  List_ptr linked_list = create_list_from_ints(int_array, 5);

  List_ptr actual_ll = map(linked_list, square);

  int squares[] = {1, 4, 4, 0, 9};
  List_ptr expected_ll = create_list_from_ints(squares, 5);

  assert_linked_list_deep_equal(actual_ll, expected_ll, is_int_equal, "should map linked list");
}

void test_filter_for_empty_linked_list(void)
{
  List_ptr linked_list = create_list();

  List_ptr actual_ll = filter(linked_list, is_even);
  List_ptr expected_ll = create_list();

  assert_linked_list_deep_equal(actual_ll, expected_ll, is_int_equal, "should filter an empty linked list");
}

void test_filter_for_linked_list(void)
{
  int int_array[] = {1, 2, 4, 0, 3};
  List_ptr linked_list = create_list_from_ints(int_array, 5);

  List_ptr actual_ll = filter(linked_list, is_even);

  int evens[] = {2, 4, 0};
  List_ptr expected_ll = create_list_from_ints(evens, 3);

  assert_linked_list_deep_equal(actual_ll, expected_ll, is_int_equal, "should filter linked list");
}

void test_reduce_for_empty_linked_list(void)
{
  List_ptr linked_list = create_list();

  Element init = malloc(sizeof(int));
  DEREF (Int_ptr)init = 10;

  Element result = reduce(linked_list, init, add);

  assert_element_deep_equal(result, init, is_int_equal, "should reduce an empty linked list");
}

void test_reduce_for_linked_list(void)
{
  int int_array[] = {1, -2, 4, 0, 3};
  List_ptr linked_list = create_list_from_ints(int_array, 5);

  Element init = calloc(sizeof(int), 1);

  Element result = reduce(linked_list, init, add);

  Element expected_result = malloc(sizeof(int));
  DEREF (Int_ptr)expected_result = 6;

  assert_element_deep_equal(result, expected_result, is_int_equal, "should reduce linked list");
}

void test_map(void)
{
  printf("Testing map()...\n");

  test_map_for_empty_linked_list();
  test_map_for_linked_list();

  printf("\n");
}

void test_filter(void)
{
  printf("Testing filter()...\n");

  test_filter_for_empty_linked_list();
  test_filter_for_linked_list();

  printf("\n");
}

void test_reduce(void)
{
  printf("Testing reduce()...\n");

  test_reduce_for_empty_linked_list();
  test_reduce_for_linked_list();

  printf("\n");
}

void test_reverse(void)
{
  printf("Testing reverse()...\n");

  List_ptr linked_list = create_list();

  List_ptr actual_ll = reverse(linked_list);
  List_ptr expected_ll = create_list();

  assert_linked_list_deep_equal(actual_ll, expected_ll, is_int_equal, "should reverse an empty linked list");

  int int_array[] = {1, 2, -2, 0, 3};
  linked_list = create_list_from_ints(int_array, 5);

  actual_ll = reverse(linked_list);

  int rev_array[] = {3, 0, -2, 2, 1};
  expected_ll = create_list_from_ints(rev_array, 5);

  assert_linked_list_deep_equal(actual_ll, expected_ll, is_int_equal, "should reverse linked list");

  printf("\n");
}

void test_forEach(void)
{
  printf("Testing forEach()...\n");

  List_ptr linked_list = create_list();

  forEach(linked_list, add_1);
  List_ptr expected_ll = create_list();

  assert_linked_list_deep_equal(linked_list, expected_ll, is_int_equal, "should forEach work for an empty linked list");

  int int_array[] = {1, 2, -2, 0, 3};
  linked_list = create_list_from_ints(int_array, 5);

  forEach(linked_list, add_1);

  int rev_array[] = {2, 3, -1, 1, 4};
  expected_ll = create_list_from_ints(rev_array, 5);

  assert_linked_list_deep_equal(linked_list, expected_ll, is_int_equal, "should forEach for a linked list");

  printf("\n");
}
