#pragma once

template <typename T>
class Stack
{
	struct elem {
		T symb;
		elem *next;
	};
	elem *top;

public:
	Stack();
	~Stack();
	void push(T value);
	T pop();
	bool is_empty();
};

template <typename T>
Stack<T>::Stack() {
	top = NULL;
}

template <typename T>
Stack<T>::Stack(const T &obj) {
	this->top = NULL;
}

template <typename T>
Stack<T>::~Stack()
{
	elem *del = top;
	while (top) {
		del = top;
		top = top->next;
		delete del;
	}
}

template <typename T>
void Stack<T>::push(T value) {
	elem *tmp = new elem;
	tmp->symb = value;
	tmp->next = top;
	top = tmp;
}

template <typename T>
T Stack<T>::pop() {
	if (is_empty()) {
		return 0;
	}
	if (!top->next) {
		T out = top->symb;
		delete top;
		return out;
	}
	T out = top->symb;
	elem *del = top;
	top = top->next;
	delete del;
	return out;
}

template <typename T>
bool Stack<T>::is_empty() {
	if (top == NULL) {
		return true;
	}
	return false;
}

