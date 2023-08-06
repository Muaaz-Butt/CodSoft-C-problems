#pragma once
#ifndef CALCULATOR_H
#define CALCULATOR_H

class Calculator {
private:
	double num1;
	double num2;
public:
	Calculator();
	Calculator(double num1, double num2);
	double sum();
	double subtract();
	double multiplication();
	double division();
	double getNumber1()const;
	double getNumber2()const;
	void setNumber1(double num1);
	void setNumber2(double num2);
};

#endif CALCULATOR_H
