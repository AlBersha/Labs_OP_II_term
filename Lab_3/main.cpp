#include <iostream>
#include <string>
#include <ctime>
//#include "Header.h"
#include "StackHeader.h"
#include "PolishIntertreterHeader.h"
using namespace std;

int main(int argc, const char *argv[]) {

	string line;

	for (int i = 1; i < argc; i++) {
		line += argv[i];
	}

	line = toPostfix(line);
	cout << "Postfix form: " << toPostfix(line) << endl;
	cout << "Result = " << Interpreter(line) << endl;


	system("pause");
}
