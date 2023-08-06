#include <iostream>
#include <stdexcept>
#include <iomanip>

#include "Calculator.h"
#include "Dashboard.h"

using namespace std;
void input(Calculator& c) {
	int num1, num2;
	cout << "Enter number 1: ";
	cin >> num1;
	if (cin.fail()) {
		cin.clear();
		cin.ignore();
		throw runtime_error("***** Value must be an integer *****");
	}
	c.setNumber1(num1);
	cout << "Enter number 2: ";
	cin >> num2;
	if (cin.fail()) {
		cin.clear();
		cin.ignore();
		throw runtime_error("***** Value must be an integer *****");
	}
	c.setNumber2(num2);
}

void operatorSelectionAndCalling(Calculator& c) {
	try {
		input(c);
	}
	catch (runtime_error& e) {
		cerr << e.what();
		return;
	}
	char choice;
	cout << "Enter + to add two operators\nEnter - to subtract two operators\nEnter * to multiply two operators\nEnter / to divide two operators";
	cout << "Enter operator which you want to perform: ";
	cin >> choice;
	cout << fixed << setprecision(2);
	switch (choice) {
	case '+':
		cout << "Sum of tow numbers: " << c.sum();
		break;
	case '-':
		cout << "Difference of two numbers: " << c.subtract();
		break;
	case '*':
		cout << "Multiplication of two numbers: " << c.multiplication();
		break;
	case '/':
		cout << "Division of two numbers: " << c.division();
		break;
	default:
		cout << "Wrong operator";
	}
}

void terminateFromProgram(int& choice) { 
	cout << "\nEnter 0 to exit or any other number to continue: ";
	cin >> choice;
}
