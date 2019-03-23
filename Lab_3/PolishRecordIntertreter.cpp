#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include "StackHeader.h"
#include "Header.h"
using namespace std;

bool is_operator(char str) {
	switch (str)
	{
	case'+': return true;
		break;
	case'-':return true;
		break;
	case'*':return true;
		break;
	case'/':return true;
		break;
	case'^':return true;
		break;
	default:return false;
		break;
	}
	return false;
}

double Interpreter(string line) {
	Stack <double> CalcString;
	double num1, num2;
	string num;
	double result = 0;

	int i = 0;
	while (i < line.length()) {
		if (line[i] == ' ') {
			i++;
		}
		else if (isdigit(line[i]) || line[i] == '.' || line[i] == ',') {
			num = num + line[i];
			if (i > 0) {
				if (i == 1 && line[i - 1] == '-') {
					CalcString.push(0);
				}
				else if (i > 1) {
					if (isdigit(line[i]) && line[i - 1] == '-' && is_operator(line[i - 2])) {
						CalcString.push(0);
					}
					else if (isdigit(line[i]) && line[i - 1] == '-' && line[i - 2] == '(') {
						CalcString.push(0);
					}
				}
			}

			if (!isdigit(line[i + 1]) && line[i + 1] != '.' && line[i + 1] != ',') {
				CalcString.push(stod(num));
				num = "";
			}
			i++;
		}

		else {
			num2 = CalcString.top();
			CalcString.pop();
			num1 = CalcString.top();
			CalcString.pop();
			switch (line[i])
			{
			case'+':result = (num1) + (num2);
				break;
			case '-':result = (num1) - (num2);
				break;
			case '*':result = (num1) * (num2);
				break;
			case '/':result = (num1) / (num2);
				break;
			case '^':result = pow((num1), (num2));
				break;
			default: cout << "Result could not be found.\n";
				break;
			}
			CalcString.push(result);
			i++;
		}
	}
	return CalcString.top();
}
