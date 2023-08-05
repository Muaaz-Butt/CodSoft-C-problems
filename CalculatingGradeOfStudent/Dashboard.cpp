#include "Dashboard.h"
#include "StudentsList.h"
#include "Student.h"

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void inputDataOfStudent(Student& s) {
	string name;
	double grade;
	cin.ignore();
	cout << "Enter Name: ";
	getline(cin, name);

	while (name.empty() || !isalpha(name[0]) || name.length() < 3) {
		cout << "***** Invalid name of student *****\n";
		cout << "Enter Name: ";
		getline(cin, name);
	}

	s.setName(name);
	cout << "Enter grade: ";
	cin >> grade;

	while (grade < 0 || grade>100) {
		cout << "***** Invalid grade of student *****\n";
		cout << "Enter grade: ";
		cin >> grade;
	}
	s.setGrade(grade);
}

void showStudentInfo(StudentsList& m) {
	int choice;
	cout << "Enter 1 if you want to see total Number of students, their name and grades: ";
	cin >> choice;
	if (choice == 1) {
		m.displayStudentInfo();
	}
}

void Grade::show() {
	StudentsList m;
	Student s;
	int choice;
	do {
		cout << "Enter 1 to add student\nEnter 2 to display average grades\n";
		cout << "Enter your choice: ";
		cin >> choice;
		if (choice == 1) {
			inputDataOfStudent(s);
			m.addStudent(s);
		}
		else if (choice == 2) {
			m.displayGradeAverages();
		}
	} while ((choice != 2));
	showStudentInfo(m);
}

