#include "test_removal.h"

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

  printf("\n");
}
