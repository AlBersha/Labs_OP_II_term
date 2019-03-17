#include <iostream>
#include "QueueHeader.h"
using namespace std;

Queue::Queue() {
	top = NULL;
}

Queue::Queue(const int &obj) {
	this->top = NULL;
}

Queue::~Queue()
{
	while (top) {
		if (!top->next) {
			top = NULL;
			break;
		}
		elem *del = top;
		top = top->next;
		delete del;
	}
}

void Queue::push(int value)
{
	elem *tmp = new elem;
	tmp->data = value;
	tmp->next = top;
	top = tmp;
}

int Queue::pop() {
	if (is_empty()) {
		cout << "Queue is empty\n";
		return 0;
	}
	if (!top->next) {
		int out = top->data;
		top = NULL;
		return out;
	}
	elem *prev = top;
	elem *end = top;
	while (end->next) {
		prev = end;
		end = end->next;
	}
	int out = end->data;
	prev->next = NULL;
	delete end;
	return out;
}

bool Queue::is_empty() {
	if (top == NULL) {
		return true;
	}
	return false;
}

void Queue::print() {
	elem *current = top;
	while (current) {
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;
}