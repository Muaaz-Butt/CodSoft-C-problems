#include <iostream>
#include <string>
#include "Student.h"

using namespace std;

Student::Student(){
	name = "";
	grade = 0.0;
}

Student::Student(string name, double grade) : name(name), grade(grade) {}

Student::~Student() {}

void Student::setName(string name) {
	this->name = name;
}

void Student::setGrade(double grade) {
	this->grade = grade;
}

string Student::getName()const {
	return name;
}

double Student::getGrade()const {
	return grade;
}
