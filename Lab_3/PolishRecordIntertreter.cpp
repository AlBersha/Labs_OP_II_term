#include <iostream>
#include <string>
#include "StackHeader.h"
using namespace std;

double Interpreter(string line) {
	Stack <int> CalcString;
	int num1, num2;
	int result;

	for (int i = 0; i < line.length(); i++) {
		if (isdigit(line[i])) {
			int num = line[i];
			CalcString.push(num - 48);
		}
		else {
			num2 = CalcString.top();
			CalcString.pop()
			num1 = CalcString.top();
			CalcString.top()
			switch(line[i])
			{
			case'+':result = num1 + num2;
				break;
			case '-':result = num1 - num2;
				break;
			case '*':result = num1 * num2;
				break;
			case '/':result = num1 / num2;
				break;
			case '^':result = pow(num1, num2);
				break;
			default: cout << "Result could not be found.\n";
				break;
			}
			CalcString.push(result);
		}
	}
	return CalcString.top();
}
