#include <iostream>
#include <string>
#include "StackHeader.h"
using namespace std;

int main() {
	Stack StringStack;
	string str;
	cout << "Enter string:\n";
	getline(cin, str);
	for (int i = 0; i < str.length(); i++) {
		string letter = str[i];
		StringStack.push(letter);
	}

}