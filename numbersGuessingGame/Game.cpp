#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdexcept>

#include "Game.h"

using namespace std;

void inputUserNum(int& userNum) {
	cout << "Enter the number which you guess (1 - 100): ";
	cin >> userNum;
	if (cin.fail()) {
		cin.clear();
		cin.ignore();
		throw runtime_error("**** Value must be integer ****");
	}
}

int randomNumberGenerator() {
	int randomNum;
	srand(time(0));
	randomNum = 1 + (rand() % 100);       // generate random number only between 1 and 100
	return randomNum;
}

void Game::play() {
	int randomNum = randomNumberGenerator();
	int userNum;
	bool flag = true;
	do {
		try {
			inputUserNum(userNum);
		}
		catch (runtime_error& e) {
			cerr << e.what();
			return;
		}
		if (randomNum == userNum) {
			cout << "\n-----Congratulations! Guessed number is correct-----\n\n";
			cout << "Random number was: " << randomNum << "\n\n";
			flag = false;
		}
		else if (userNum > randomNum) {
			cout << "------------Too High----------------\n";
		}
		else {
			cout << "------------Too Low------------------\n";
		}
	} while (flag);
}