#include "linkedlist.h"

#ifndef __TEST_LINKEDLIST_H_
#define __TEST_LINKEDLIST_H_

typedef char *Message;
typedef int *Int_ptr;

typedef Status (*Are_Equal)(Element, Element);

void fail_message(Message message);
void pass_message(Message message);

Status is_int_equal(Element, Element);

void assert_node_null(Node_ptr, Message);
void assert_element_equal(Element, Element, Message);
void assert_int_equal(int, int, Message);
void assert_node_equal(Node_ptr, Node_ptr, Message);
void assert_linked_list(List_ptr, Node_ptr, Node_ptr, int);
void assert_linked_list_deep_equal(List_ptr, List_ptr, Are_Equal, Message);

void display_tests_status(void);

List_ptr create_list_from_ints(Int_ptr, unsigned);

#endif
