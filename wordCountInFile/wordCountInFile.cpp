#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main() {
	int count = 0;
	char myChar;
	string fileName;
	cout << "File format file name.txt \n\n   Example:  file.txt\n\nEnter file name: ";
	cin >> fileName;
	ifstream file;
	file.open(fileName, ios::in);
	if (!file) {
		cout << "Error file not found";
		return 0;
	}
	while (!file.eof()) {
		count++;
		myChar = file.get();
	}
	cout << count - 1;
}
