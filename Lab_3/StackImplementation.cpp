#include <iostream>
#include <string>
#include "StackHeader.h"
using namespace std;

Stack::Stack() {
	top = NULL;
}

Stack::~Stack()
{
	while (top) {
		elem *del = top;
		delete del;
		top = top->next;
	}
}

void Stack::push(string value) {
	elem *tmp = new elem;
	tmp->symb = value;
	tmp->next = top;
	top = tmp;
}

string Stack::pop() {
	if (is_empty()) {
		return 0;
	}
	if (!top->next) {
		string out = top->symb;
		delete top;
		return out;
	}
	string out = top->symb;
	elem *del = top;
	top = top->next;
	delete del;
	return out;
}

bool Stack::is_empty() {
	if (top == NULL) {
		return true;
	}
	return false;
}