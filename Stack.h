#pragma once
#ifndef _STACK_H
#define _STACK_H
#include "ListNode.h"

class Stack {
private:
	ListNode *top;
	int size;
public:
	Stack();
	void push(double operand);
	void push(char operators);
	double getOperand() const;
	char getOperators() const;
	void pop();
	int getSize() const;
	bool Isempty() const;
};

#endif // !_STACK_H