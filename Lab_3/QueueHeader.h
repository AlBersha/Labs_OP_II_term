#pragma once
#include <iostream>
using namespace std;

class Queue {
	struct elem {
		int data;
		elem *next;
	};
	elem *top;

public:
	Queue();
	Queue(const int &obj);
	~Queue();
	void push(int value);
	int pop();
	bool is_empty();
	void print();
};

