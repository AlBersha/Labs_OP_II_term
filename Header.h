#pragma once
#include <string>
using namespace std;

class Country {
public:
	string name;
	int *mark;
	int result;

	Country(int num) {
		name = "";
		mark = new int[num];
		result = 0;
	}

	~Country() {};

	void set_country_info(string str, int num);
};

void sort_marks(vector <Country> &Countries_list, int num) {
	int *res = new int[10]{ 12, 10, 8, 7, 6, 5, 4, 3, 2, 1 };

	for (int q = 0; q < num; q++) {
		for (int i = 0; i < num; i++) {
			for (int j = 0; j < num - 1; j++) {
				if (Countries_list[j].mark[q] < Countries_list[j + 1].mark[q]) {
					swap(Countries_list[j], Countries_list[j + 1]);
				}
			}
		}

		for (int i = 0; i < num; i++) {
			Countries_list[i].result += (i >= 10) ? 0 : (res[i]);
		}
	}
}

void sort_result(vector <Country> &Countries_list, int num) {
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num - 1; j++) {
			if (Countries_list[j].result < Countries_list[j + 1].result) {
				swap(Countries_list[j], Countries_list[j + 1]);
			}
		}
	}
}
