#pragma once
#ifndef STUDENT_H
#define STUDENT_H

#include <string>

using namespace std;

class Student
{
public:
	Student();
	Student(string name, double grade);
	~Student();
	void setName(string name);
	void setGrade(double grade);
	double getGrade()const;
	string getName()const;
private:
	string name;
	double grade;
};

#endif STUDENT_H
