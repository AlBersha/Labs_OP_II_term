#include <iostream>
#include <string>
#include "QueueArray.h"
using namespace std;

void Queue::push(int value)
{
	if (size>=M_size) {
		cout << "Queue is overload.\n";
	}
	data[back] = value;
	back = (back + M_size - 1) % M_size;
	size++;
}

void Queue::pop()
{
	if (empty()) {
		cout << "Queue is empty.\n";
		return;
	}
	head = (head + M_size - 1) % M_size;
	size--;
}

bool Queue::empty()
{
	if (size == 0) {
		return true;
	}
	return false;
}

char Queue::front()
{
	return data[head];
}
