#define _CRT_SECURE_NO_WARNINGS
#define OPNUM 7

#include <iostream>
#include <cstdlib>
#include <string>
#include <string.h>			//strtok strcpy
#include <sstream>
#include <cmath>
#include "LinkedList.h"
#include "ListNode.h"
#include "Stack.h"
using namespace std;

/*define operator and wheir own priority*/
char op[OPNUM] = { '(', '+', '-', '*', '/', '%', '^'};
int op_priority[OPNUM] = { 0, 1, 1, 2, 2, 2, 3 };

/*functions*/
void spilt(string& s, LinkedList& infix);							//spilt the user input to the vector of string
void classification(LinkedList& infix, LinkedList& sort_infix);		//transfer string to char(operator) or double(operand), and save in LinkedList
bool isNum(string str);												//if string is number, return true
bool isInt(double d);												//if double is int, return true
void toPosfix(LinkedList& infix, LinkedList& postfix);				//transfer infix to postfix, and save in LinkedList
double eval(LinkedList& postfix);									//evaluate the result by postfix
int priority(char op_input);										//return the priority of each operator

int main(void) {
	LinkedList classification_infix, postfix, infix;
	string input;

	/*input*/
	cout << "Please enter infix (there is a space which is essential between operand and operator)" << endl;
	cout << "Operators which you can use are ( ) + - * / % ^. Ex:1 + 2 / ( 3 - 4 ) * 4 % 2" << endl;
	cout << "=>";
	getline(cin, input);

	/*spilt, classification and save in LinkedList*/
	spilt(input, infix);
	classification(infix, classification_infix);

	/*show the result*/
	cout << "\nInput:";
	classification_infix.show();
	cout << endl;
	cout << "\nPostfix:";
	toPosfix(classification_infix, postfix);
	postfix.show();
	cout << endl;
	cout << "\nResult:" << eval(postfix) << endl << endl;

	/*free memory*/
	classification_infix.clear();
	postfix.clear();
	infix.clear();

	system("PAUSE");
	return 0;
}

void spilt(string& s, LinkedList& infix) {
	
	infix.clear();									//clear the vector                               
	char* buffer = new char[s.size() + 1];		//new one char array
	strcpy(buffer, s.c_str());					//c_str() change string to char*

	/*token the string by space*/
	char* token = strtok(buffer, " ");    
	do {
		infix.push(token);
	} while ((token = strtok(NULL, " ")));
	
	delete[] buffer;
}

void classification(LinkedList& infix, LinkedList& sort_infix) {
	/*if string is operator(operand) saved as char(double) in LinkedList*/
	/*if string is not operator and operand, show error message then exit*/

	string temp;

	for (int i = 0; i < infix.getSize(); i++) {
		temp = infix.getStr(i);

		if (temp == "(" || temp == ")" || temp == "+" || temp == "-" || temp == "*" || temp == "/" || temp == "%" || temp == "^") {
			sort_infix.push(temp[0]);
		}else if (isNum(temp)) {
			sort_infix.push(stod(temp));
		}
		else {
			cout << "The infix you enter is wrong!!!" << endl;
			system("PAUSE");
			exit(1);
		}
	}
}

bool isNum(string str) {
	stringstream sin(str);
	double d;
	char c;

	/*ex: a123 , 123a , 123*/
	if (!(sin >> d)) {
		return false;	/*a123 return false*/
	}

	if (sin >> c) {
		return false;	/*123a return false*/
	}

	return true;		/*123 return true*/
}

void toPosfix(LinkedList& infix, LinkedList& postfix) {
	Stack stack;
	int size = infix.getSize();
	int type = 0;

	for (int i = 0; i < size; i++) {
		type = infix.getType(i);

		/*1 is operand, push to postfix directly*/
		if (type == 1) {
			postfix.push(infix.getOperand(i));
			continue;
		}
		/*2 is operator*/
		else if (type == 2) {
			switch (infix.getOperators(i)) {
			case'(':
				stack.push('(');
				break;

			case')':
				/*push operators to postfix from stack until '('*/
				while (!stack.Isempty() && stack.getOperators() != '(') {
					postfix.push(stack.getOperators());
					stack.pop();
				}
				
				/*check if there is a '(' before ')'*/
				if (stack.Isempty() || stack.getOperators() != '(') {
					cout << "\nThere is a '(' which is essential before ')'" << endl;
					system("PAUSE");
					exit(1);
				}
				stack.pop();
				break;

			case'+':
			case'-':
			case'*':
			case'/':
			case'%':
			case'^':
				/*if stack is empty, push directly*/
				if (stack.Isempty()) {
					stack.push(infix.getOperators(i));
					break;
				}
				else {
					/*if stack is not empty, compare their priority*/
					while (priority(stack.getOperators()) >= priority(infix.getOperators(i))) {
						postfix.push(stack.getOperators());
						stack.pop();
						if (stack.Isempty()) {
							break;
						}
					}
					stack.push(infix.getOperators(i));
					break;
				}
				
			}
		}
	}

	/*At the end, pop all operators in stack*/
	while (!stack.Isempty()) {
		postfix.push(stack.getOperators());
		stack.pop();
	}
}

int priority(char op_input) {
	for (int i = 0; i < OPNUM; i++) {
		if (op[i] == op_input) {
			return op_priority[i];
		}
	}
    return 0;
}

double eval(LinkedList& postfix) {
	Stack stack;
	double temp1 = 0, temp2 = 0;

	for (int i = 0; i < postfix.getSize(); i++) {
		if (postfix.getType(i) == 1) {
			stack.push(postfix.getOperand(i));
		}
		else if (postfix.getType(i) == 2) {
			temp2 = stack.getOperand();
			stack.pop();
			temp1 = stack.getOperand();
			stack.pop();

			switch (postfix.getOperators(i)) {
			case'+':
				stack.push(temp1 + temp2);
				break;
			case'-':
				stack.push(temp1 - temp2);
				break;
			case'*':
				stack.push(temp1 * temp2);
				break;
			case'/':
				stack.push(temp1 / temp2);
				break;
			case'%':
				if (isInt(temp1) && isInt(temp2)) {
					stack.push( (double) ( (int)temp1 % (int)temp2 ) );
						break;
				}
				else {
					cout << "Double is not proper to use %!!!" << endl;
					system("PAUSE");
					exit(1);
				}
				
				
			case'^':
				stack.push(pow(temp1, temp2));
				break;
			}
		}
	}

	return stack.getOperand();
}

bool isInt(double d) {
	if (d == 0) {
		return true;
	}
	else if (d > 0) {
		if (d == floor(d)) {
			return true;		//10 == 10
		}
		else {
			return false;		//10.2 != 10
		}
	}
	else if (d < 0) {
		if (d == ceil(d)) {
			return true;		//-10 == -10
		}
		else {
			return false;		//-10.2 != -10
		}
	}
    return false;
}
