#include "linkedlist.h"

#ifndef __TEST_LINKEDLIST_H_
#define __TEST_LINKEDLIST_H_

typedef char *Message;
typedef int *Int_ptr;

void fail_message(Message message);
void pass_message(Message message);

void assert_node_null(Node_ptr, Message);
void assert_element_equal(Element, Element, Message);
void assert_int_equal(int, int, Message);

void display_tests_status(void);

#endif
