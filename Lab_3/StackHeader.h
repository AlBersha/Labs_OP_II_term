#pragma once

class Stack
{
	struct elem{
		string symb;
		elem *next;
	};
	elem *top;

public:
	Stack();
	~Stack();
	void push(string value);
	string pop();
	bool is_empty();
};

