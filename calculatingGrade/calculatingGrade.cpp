#include <iostream>
#include <string>
#include <sstream>
#include <math.h>

using namespace std;

class Student {
private:
	string name;
	double grade;
public:
	Student() {
		name = " ";
		grade = 0.0;
	}

	Student(string name, double grade) : name(name), grade(grade) {}

	~Student() {}

	void setName(string name) {
		this->name = name;
	}

	void setGrade(double grade) {
		this->grade = grade;
	}

	string getName()const {
		return name;
	}

	double getGrade()const {
		return grade;
	}	
};

double calculateAverage(const Student* stu, int size) {
	double sum = 0.0;
	for (int i = 0; i < size; i++) {
		sum += stu[i].getGrade();
	}
	double average = sum / size;
	return average;
}

double findMaxGrade(const Student* stu, int size) {
	double max = stu[0].getGrade();
	for (int i = 0; i < size; i++) {
		if (stu[i].getGrade() > max) {
			max = stu[i].getGrade();
		}
	}
	return max;
}

double findMinGrade(const Student* stu, int size) {
	double min = stu[0].getGrade();
	for (int i = 0; i < size; i++) {
		if (stu[i].getGrade() < min) {
			min = stu[i].getGrade();
		}
	}
	return min;
}

int main() {
	int noOfStudents;
	string name;
	double grade;
	cout << "Enter number of students: ";
	cin >> noOfStudents;
	Student* stu = new Student[noOfStudents];
	for (int i = 0; i < noOfStudents; i++) {
		cout << "Enter name of student " << i + 1<<": ";
		cin.ignore();
		getline(cin, name);
		stu[i].setName(name);
		cout << "Enter Grade of student " << i + 1 << ": ";
		cin >> grade;
		stu[i].setGrade(grade);
	}
	cout << "Average Grade: " << calculateAverage(stu, noOfStudents) << "\n";
	cout << "Highest Grade: " << findMaxGrade(stu, noOfStudents) << "\n";
	cout << "Lowest Grade: " << findMinGrade(stu, noOfStudents) << "\n";
}