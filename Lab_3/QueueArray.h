#pragma once

class Queue {
	char *data;
	int M_size, size;
	int back, head;

public:
	Queue (){
		M_size = 1000;
		data = new char[size];
		back = head = M_size-1;
	}
	~Queue()
	{
		delete[] data;
	}

	void push(int value);
	void pop();
	bool empty();
	char front();
};