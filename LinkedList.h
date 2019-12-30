#pragma once
#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H
#include "ListNode.h"
#include <string>

class LinkedList {
private:
	ListNode *first;
	int size;
public:
	LinkedList();
	void push(double operand);
	void push(char operators);
	void push(std::string new_str);
	int getType(int index) const;
	double getOperand(int index) const;
	char getOperators(int index) const;
	std::string getStr(int index) const;
	void show() const;
	int getSize() const;
	void clear();
};

#endif // !_LINKEDLIST_H