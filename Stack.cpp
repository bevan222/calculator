#include "Stack.h"
#include <cstdlib>
#include <iostream>

Stack::Stack() :size(0), top(nullptr) {}

void Stack::push(double operand) {
	if (Isempty()) {
		top = new ListNode(operand);
		size++;
	}
	else {
		ListNode *newNode = new ListNode(operand);

		newNode->next = top;
		top = newNode;
		size++;
	}

}

void Stack::push(char operators) {
	if (Isempty()) {
		top = new ListNode(operators);
		size++;
	}
	else {
		ListNode *newNode = new ListNode(operators);

		newNode->next = top;
		top = newNode;
		size++;
	}

}

void Stack::pop() {
	if (Isempty()) {
		std::cout << "\nStack is empty, can't pop!!!" << std::endl;
		system("PAUSE");
		exit(1);
	}
	else {
		ListNode *delNode = top;

		top = top->next;
		delete delNode;
		delNode = nullptr;
		size--;
	}
}

int Stack::getSize() const{
	return size;
}

bool Stack::Isempty() const{
	if (size == 0) {
		return true;
	}
	else {
		return false;
	}
}

double Stack::getOperand() const{
	if (Isempty()) {
		std::cout << "\nStack is empty, can't get anything!!!" << std::endl;
		system("PAUSE");
		exit(1);
	}
	return top->operand;
}

char Stack::getOperators() const{
	if (Isempty()) {
		std::cout << "\nStack is empty, can't get anything!!!" << std::endl;
		system("PAUSE");
		exit(1);
	}
	return top->operators;
}