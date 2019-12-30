#pragma once
#ifndef _LISTNODE_H
#define _LISTNODE_H
#include <string>

class ListNode {
private:
	double operand;
	char operators;
	std::string str;
	int type; // 0 is nothing | 1 is operand | 2 is operators | 3 is string
	ListNode *next;

	friend class LinkedList;
	friend class Stack;
public:
	ListNode();
	ListNode(double new_operand);
	ListNode(char new_operators);
	ListNode(std::string new_string);
};

#endif // !_LISTNODE_H