#include <stdio.h>
#include <iostream>
#include <string>
#include "Header.h"
#include "QueueHeader.h"
#include "StackHeader.h"

using namespace std;

#define is_operator(c) (c == '+' || c == '-' || c == '/' || c == '*' || c == '^')

string toPostfix(string &line) {

	Stack <char> inStack;
	Queue <string> outQueue;

	string result, num, top = "";
	int i = 0;

	while (i < line.length())
	{
		if (isdigit(line[i]) || line[i] == '.' || line[i] == ',') // Если число - в выходную очередь
		{
			num = num + line[i];
			if (i > 0) {
				if (i == 1 && line[i - 1] == '-') {
					string str = "0";
					outQueue.push(str);
				}
				else if (i > 1) {
					if (isdigit(line[i]) && line[i - 1] == '-' && is_operator(line[i - 2])) {
						string str = "0";
						outQueue.push(str);
					}
					else if (isdigit(line[i]) && line[i - 1] == '-' && line[i - 2] == '(') {
						string str = "0";
						outQueue.push(str);
					}
				}
			}

			if (!isdigit(line[i + 1]) && line[i + 1] != '.' && line[i + 1] != ',') {

				outQueue.push(num);
				num = "";
			}
			i++;
		}

		else if (is_operator(line[i])) // Если оператор
		{
			while (!inStack.empty())
			{
				if (is_operator(inStack.top())
					&& (op_priority(line[i]) <= op_priority(inStack.top())))
				{
					top = inStack.top();
					outQueue.push(top);
					inStack.pop();

				}
				else
					break;
			}
			inStack.push(line[i]);
			i++;
		}

		else if (line[i] == '(') {
			inStack.push(line[i]);
			i++;
		}

		else if (line[i] == ')')
		{
			bool logic = false;
			// До появления на вершине стека левой скобки перекладывать операторы из стека в очередь вывода
			while (!inStack.empty())
			{
				if (inStack.top() == '(')
				{
					logic = true;
					break;
				}
				else
				{
					top = inStack.top();
					outQueue.push(top);
					inStack.pop();
				}
			}
			// Если стек кончится до нахождения левой скобки, то была пропущена скобка
			if (!logic)
			{
				cout << "Error: bracket mismatched\n";
				exit(1);
			}
			// выкидываем левую скобку из стека (не добавляем в очередь вывода)
			inStack.pop();
			i++;
		}
		else {
			i++;
		}
	}

	while (!inStack.empty())
	{
		top = inStack.top();
		outQueue.push(top);
		inStack.pop();
	}

	while (!outQueue.empty())
	{
		result += outQueue.front();
		result += " ";
		outQueue.pop();
	}
	return result;
}

int op_priority(const char c) // Приоритет булевой операции
{
	switch (c)
	{
	case '^':
		return 3;
	case '*':
	case '/':
		return 2;

	case '+':
	case '-':
		return 1;
	}
	return 0;
}
