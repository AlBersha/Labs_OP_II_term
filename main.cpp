#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main() {
	ifstream file("eurovision.csv");
	if (!file.is_open()) {
		cout << "File couldn't be open.\n";
	}

	string Num;
	getline(file, Num);
	int num = stoi(Num);

	vector <Country> Countries_list;
	for (int i = 0; i < num; i++) {
		Country country(num);
		string str;
		getline(file, str);
		country.set_country_info(str, num);
		Countries_list.push_back(country);
	}


	file.close();
	system("pause");
}
