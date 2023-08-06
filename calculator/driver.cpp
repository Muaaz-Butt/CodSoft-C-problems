#include "Dashboard.h"
#include "Calculator.h"

int main() {
	Calculator calculator;
	int choice;
	do {
		operatorSelectionAndCalling(calculator);
		terminateFromProgram(choice);
	} while (choice != 0);
}