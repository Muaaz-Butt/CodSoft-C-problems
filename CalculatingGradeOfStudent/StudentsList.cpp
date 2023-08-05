#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

#include "Student.h"
#include "StudentsList.h"

using namespace std;

int StudentsList::noOfStudents = 0;

StudentsList::StudentsList() {
	student = nullptr;
	size = 1;
}

StudentsList::~StudentsList() {
	if (!student) {
		return;
	}
	delete[]student;
	student = nullptr;
}

void StudentsList::reSize(int s) {
	if (s <= 0) {
		this->~StudentsList();
		return;
	}
	int i = 0;
	Student* p = new Student[s];
	while (i < (s > (size - 1) ? (size - 1) : s - 1)) {
		p[i] = student[i];
		i++;
	}
	this->~StudentsList();
	student = p;
	size = s;
}

double StudentsList::calculateAverageGrade() {
	double sum = 0.0;
	for (int i = 0; i < noOfStudents; i++) {
		sum += student[i].getGrade();
	}
	double average = sum / noOfStudents; 
	return average;
}

double StudentsList::findMaxGrade() {
	double max = student[0].getGrade(); 
	for (int i = 0; i < noOfStudents; i++) {
		if (student[i].getGrade() > max) {
			max = student[i].getGrade();
		}
	}
	return max;
}

double StudentsList::findMinGrade() {
	double min = student[0].getGrade(); 
	for (int i = 0; i < noOfStudents; i++) {
		if (student[i].getGrade() < min) {
			min = student[i].getGrade();
		}
	}
	return min;
}

bool StudentsList::addStudent(Student& student) {
	if (size == noOfStudents + 1) {
		reSize(size * 2);
	}
	this->student[noOfStudents] = student;
	noOfStudents++;
	return true;
}

int StudentsList::getNoOfStudents() {
	return noOfStudents;
}

void StudentsList::displayGradeAverages() {
	cout << fixed << setprecision(2);
	cout << "Average Grade: " << calculateAverageGrade() << "\n";
	cout << "Highest Grade: " << findMaxGrade() << "\n";
	cout << "Lowest Grade: " << findMinGrade() << "\n";
}

void StudentsList::displayStudentInfo() {
	system("cls");
	cout << "\n\n---------------------------------------------------------------\n\n";
	cout << "Total Number of Students are: " << noOfStudents<<"\n";
	cout << fixed << left << setw(20) << "Student Names" << "Grades\n\n";
	cout << fixed << setprecision(2);
	for (int i = 0; i < noOfStudents; i++) {
		cout << fixed << left << setw(20) << student[i].getName();
		cout << fixed << left << setw(20) << student[i].getGrade() << "\n\n";
	}
	cout << "\n\n----------------------------------------------------------------\n\n";
}