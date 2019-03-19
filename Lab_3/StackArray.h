#pragma once

class Stack {
	char *data;
	int tail;
	int size;

public:
	Stack() {
		size = 10;
		tail = 0;
		data = new char[size];
	}
	~Stack()
	{
		delete[] data;
	}

	void push(char value);
	void pop();
	bool empty();
	void resize();
	char top();
};