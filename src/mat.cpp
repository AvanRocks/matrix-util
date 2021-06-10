#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "Matrix.h"
using namespace std;

void error(string errorString) {
	cout << errorString << '\n';
	exit(1);
}

int main (int argc, char* argv[]) {
	if (argc > 2) {
		error("Too many arguments");
	}

	bool rowEchelonForm = false;
	if (argc == 2) {
		if (string(argv[1]) == "-ref") {
			rowEchelonForm = true;
		}
	}

	string line;
	vector<vector<int>> data;
	while (getline(cin,line)) {
		if (line.size() == 0) 
			break;
		data.push_back(vector<int>());
		stringstream ss(line);
		int num=0;
		while (ss >> num) {
			data.back().push_back(num);
		}
	}


	for (int i=1;i<data.size();++i) {
		if (data[i].size() != data[i-1].size()) {
			error("Please enter a valid matrix");
		}
	}

	Matrix mat(data); 
	rowEchelonForm ? mat.ref() : mat.rref();
	mat.output();

  return 0;
}
