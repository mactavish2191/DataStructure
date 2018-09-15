#include <cmath>
#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <map>
using namespace std;


int main() {
	ifstream icin("input01.txt", ios::in);
	ofstream icout("out.txt", ios::out);
	long T = 0;
	map<string, long> phonebook;
	icin >> T;
	icin.ignore();
	long scan = T;
	while (scan--) {
		string line;
		string name;
		long number;
		getline(icin, line);
		stringstream ss;
		ss << line;
		ss >> name;
		ss >> number;
		phonebook.insert(make_pair(name, number));
	}

	string line;
	while (getline(icin, line)) {
		auto search = phonebook.find(line);
		if (search != phonebook.end()) {
			icout << search->first << "=" << search->second << "\n";
		}
		else {
			icout << "Not found\n";
		}
	}

	return 0;
}
