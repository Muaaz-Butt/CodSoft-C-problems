#include <iostream>

using namespace std;

double sum(double& num1, double& num2) {
	double sum = num1 + num2;
	return sum;
}

double subtract(double& num1, double& num2) {
	double subtract = num1 - num2;
	return subtract;
}

double multiplication(double& num1, double& num2) {
	double multiply = num1 * num2;
	return multiply;
}

double division(double& num1, double& num2) {
	int divide = num1 / num2;
	return divide;
}

void input(double& num1,double& num2) {
	cout << "Enter number 1: ";
	cin >> num1;
	cout << "Enter number 2: ";
	cin >> num2;
}

void operatorSelectionAndCalling(double& num1,double& num2) {
	char choice;
	cout << "Enter + to add two operators\nEnter - to subtract two operators\nEnter * to multiply two operators\nEnter / to divide two operators";
	cout << "Enter operator which you want to perform: ";
	cin >> choice;
	if (choice == '+') {
		cout<<sum(num1,num2);
	}
	else if (choice == '-') {
		cout<<subtract(num1, num2);
	}
	else if (choice == '*') {
		cout<<multiplication(num1, num2);
	}
	else if (choice == '/') {
		cout<<division(num1, num2);
	}
	else {
		cout << "Wrong operator";
	}
}

int main() {
	double num1, num2;
	input(num1, num2);
	operatorSelectionAndCalling(num1, num2);
}