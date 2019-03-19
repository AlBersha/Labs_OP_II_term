#include <iostream>
#include <string>
#include "StackArray.h"
using namespace std;

void Stack::push(char value)
{
	if (tail == size - 1) {
		resize();
	}
	data[tail++] = value;
}

void Stack::pop()
{
	if (empty()) {
		cout << "Stack is empty.\n";
		return;
	}
	tail--;
}

bool Stack::empty()
{
	if (tail == 0) {
		return true;
	}
	return false;
}

void Stack::resize()
{
	char *newQueue = new char[2 * size];
	for (int i = 0; i < size - 1; i++) {
		newQueue[i] = data[i];
	}
	data = newQueue;
	size = size * 2;
}

char Stack::top()
{
	return data[tail];
}
