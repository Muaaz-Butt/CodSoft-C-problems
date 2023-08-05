#pragma once
#ifndef STUDENTSLIST_H
#define STUDENTSLIST_H

#include "Student.h"

class StudentsList {
public:
	StudentsList();
	~StudentsList();
	double calculateAverageGrade();
	double findMaxGrade();
	double findMinGrade();
	bool addStudent(Student& student);
	void displayGradeAverages();
	static int getNoOfStudents();
	void displayStudentInfo();
private:
	Student* student;
	int size;
	static int noOfStudents;
	void reSize(int s);
};

#endif MANAGINGSTUDENTS_H
