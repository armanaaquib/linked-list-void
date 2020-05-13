#include "linkedlist.h"

#ifndef __TEST_LINKEDLIST_H_
#define __TEST_LINKEDLIST_H_

typedef char *Message;

void fail_message(Message message);
void pass_message(Message message);

void assert_node_equal(Node_ptr, Node_ptr, Message);
void assert_int_equal(int, int, Message);

void display_tests_status(void);

#endif
