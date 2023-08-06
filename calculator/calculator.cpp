#include <iostream>
#include <iomanip>

#include "Calculator.h"

using namespace std;

Calculator::Calculator() {
	num1 = 0.0;
	num2 = 0.0;
}

Calculator::Calculator(double num1, double num2) :num1(num1), num2(num2) {}

double Calculator::sum() {   
	return num1 + num2;
}

double Calculator::subtract() {
	return num1 - num2;
}

double Calculator::multiplication() {
	return num1 * num2;
}

double Calculator::division() {
	return num1 / num2;
}

double Calculator::getNumber1()const {
	return num1;
}

double Calculator::getNumber2()const {
	return num2;
}

void Calculator::setNumber1(double num1) {
	this->num1 = num1;
}

void Calculator::setNumber2(double num2) {
	this->num2 = num2;
}
	