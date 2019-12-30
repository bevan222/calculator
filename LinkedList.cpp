#include "LinkedList.h"
#include <iostream>
#include <string>

LinkedList::LinkedList() :size(0){
}

void LinkedList::push(double operand) {
	ListNode *newNode = new ListNode(operand);

	if (first == nullptr) {
		first = newNode;
		size++;
	}
	else {
		ListNode *current = first;

		while (current->next != nullptr) {
			current = current->next;
		}
		current->next = newNode;
		size++;
	}
}

void LinkedList::push(char operators) {
	ListNode *newNode = new ListNode(operators);

	if (first == nullptr) {
		first = newNode;
		size++;
	}
	else {
		ListNode *current = first;

		while (current->next != nullptr) {
			current = current->next;
		}
		current->next = newNode;
		size++;
	}
}

void LinkedList::push(std::string new_str) {
	ListNode *newNode = new ListNode(new_str);

	if (first == nullptr) {
		first = newNode;
		size++;
	}
	else {
		ListNode *current = first;

		while (current->next != nullptr) {
			current = current->next;
		}
		current->next = newNode;
		size++;
	}
}

void LinkedList::show() const{
	ListNode* current = first;
	while (current != nullptr) {
		if (current->type == 1) {
			std::cout << current->operand << " ";
		}
		else if (current->type == 2) {
			std::cout << current->operators << " ";
		}
		else if (current->type == 3) {
			std::cout << current->str << " ";
		}

		current = current->next;
	}
}

int LinkedList::getType(int index) const{
	ListNode *current = first;

	for (int i = 0; i < index + 1; i++) {
		if (i == index) {
			return current->type;
		}

		current = current->next;
	}
    return 0 ;
}

double LinkedList::getOperand(int index) const{
	ListNode *current = first;

	for (int i = 0; i < index + 1; i++) {
		if (i == index) {
			return current->operand;
		}

		current = current->next;
	}
    return 0;
}

char LinkedList::getOperators(int index) const{
	ListNode *current = first;

	for (int i = 0; i < index + 1; i++) {
		if (i == index) {
			return current->operators;
		}

		current = current->next;
	}
    return ' ';
}

std::string LinkedList::getStr(int index) const {
	ListNode *current = first;

	for (int i = 0; i < index + 1; i++) {
		if (i == index) {
			return current->str;
		}

		current = current->next;
	}
    return "";
}

int LinkedList::getSize() const{
	return size;
}

void LinkedList::clear() {
	while (first != nullptr) {
		ListNode *current = first;
		
		first = first->next;
		delete current;
		current = nullptr;
	}
}
