#include "ListNode.h"
#include <string>

ListNode::ListNode():operand(0), operators(' '), type(0), next(nullptr){}

ListNode::ListNode(double new_operand) : operand(new_operand), operators(' '), str(""), type(1), next(nullptr){}

ListNode::ListNode(char new_operators) : operand(0), operators(new_operators), str(""), type(2), next(nullptr){}

ListNode::ListNode(std::string new_string) : operand(0), operators(' '), str(new_string), type(3), next(nullptr) {}