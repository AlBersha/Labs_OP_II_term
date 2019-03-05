#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Header.h"
using namespace std;

void Country::set_country_info(string str, int num)
{
	int pos = str.find(',');
	name = str.substr(0, pos);
	str = str.substr(pos + 1, str.length() + 1);
	for (int i = 0; i < num; i++) {
		string out;
		pos = str.find(',');
		out = str.substr(0, pos);
		mark[i] = stoi(out);
		str = str.substr(pos + 1, str.length() - 1);
	}
}
