#pragma once

template <typename T>
class Stack
{
	struct elem {
		T symb;
		elem *next;
	};
	elem *head;

public:
	Stack();
	~Stack();
	void push(T value);
	void pop();
	bool empty();
	T top();
};

template <typename T>
Stack<T>::Stack() {
	head = NULL;
}

template <typename T>
Stack<T>::~Stack()
{
	elem *del = head;
	while (head) {
		del = head;
		head = head->next;
		delete del;
	}
}

template <typename T>
void Stack<T>::push(T value) {
	elem *tmp = new elem;
	tmp->symb = value;
	tmp->next = head;
	head = tmp;
}

template <typename T>
void Stack<T>::pop() {
	if (empty()) {
		return ;
	}
	if (!head->next) {
		top = NULL;
	}
	elem *del = head;
	head = head->next;
	delete del;
}

template <typename T>
bool Stack<T>::empty() {
	if (head == NULL) {
		return true;
	}
	return false;
}

template <typename T>
T Stack<T>::top(){
	return head->symb;
}
