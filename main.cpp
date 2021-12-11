#include "helper.h"
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

bool isSplitterSuggestion(const char& ch) {
	return ch == '.' || ch == '!' || ch == '?';
}

std::string task(const string& s) {
	std::string strr = "";
	bool isSuggestion = false;
	int startSuggestoin = 0;
	int countSugesstion = 0;
	int number = 1;

	for (int i = 0; i < s.size(); i++) {
		if (isSplitterSuggestion(s[i])) {
			strr.append(s.substr(startSuggestoin, i + 1 - startSuggestoin));
			startSuggestoin = i + 1;
			countSugesstion++;
			if (countSugesstion == 3)
				break;
		}
	}

	if (countSugesstion == 3) {
		string tmpA;
		int endSuggestoin = strr.size() - 1;
		for (int i = strr.size() - 2; i >= 0; i--) {
			if (isSplitterSuggestion(strr[i])) {
				tmpA.append(strr.substr(i + 1, endSuggestoin - i));
				endSuggestoin = i;
			}
			if (i == 0)
				tmpA.append(strr.substr(0, endSuggestoin + 1));
		}
		strr = tmpA;
	}
	else
		strr.clear();

	return !strr.empty() ? strr : "В файле нет 3х предложенимй\n";
}

string readFile(ifstream& input) {
	string s = "";
	string tmpS;
	while (getline(input, tmpS))
		s.append(tmpS).append("\n");
	return s;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string filename;
	processInputNameOfInputFile(filename);
	ifstream input(filename);
	cout << "Результат работы:\n" << task(readFile(input)) << endl;
	input.close();
}