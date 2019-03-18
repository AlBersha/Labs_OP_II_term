#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Queue {
	struct elem {
		T data;
		elem *next;
	};
	elem *top;

public:
	Queue();
	Queue(const T &obj);
	~Queue();
	void push(T value);
	T pop();
	bool is_empty();
	void print();
};

template <typename T>
Queue<T>::Queue() {
	top = NULL;
}

template <typename T>
Queue<T>::Queue(const T &obj) {
	this->top = NULL;
}

template <typename T>
Queue<T>::~Queue()
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

template <typename T>
void Queue<T>::push(T value)
{
	elem *tmp = new elem;
	tmp->data = value;
	tmp->next = top;
	top = tmp;
}

template <typename T>
T Queue<T>::pop() {
	if (is_empty()) {
		cout << "Queue is empty\n";
		return 0;
	}
	if (!top->next) {
		T out = top->data;
		top = NULL;
		return out;
	}
	elem *prev = top;
	elem *end = top;
	while (end->next) {
		prev = end;
		end = end->next;
	}
	T out = end->data;
	prev->next = NULL;
	delete end;
	return out;
}

template <typename T>
bool Queue<T>::is_empty() {
	if (top == NULL) {
		return true;
	}
	return false;
}

template <typename T>
void Queue<T>::print() {
	elem *current = top;
	while (current) {
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;
}