#include <iostream>
#include <ctime>
#include <cstdlib>

#include "Game.h"

using namespace std;

int Game::randomNumberGenerator() {
	int randomNum;
	srand(time(0));      
	randomNum = 1 + (rand() % 100);       // generate random number only between 1 and 100
	return randomNum;
}

void Game::play() {
	int randomNum = randomNumberGenerator();
	int userNum;
	char choice = 'y';
	bool flag = true;
	do {
		flag = true;
		do {
			cout << "Enter the number which you guess: ";
			cin >> userNum;
			if (randomNum == userNum) {
				cout << "\n------------------Congratulations! Guessed number is correct----------------------\n\n";
				cout << "Random number was: " << randomNum<<"\n\n";
				flag = false;
			}
			else if (userNum > randomNum) {
				cout << "------------Too High----------------\n";
			}
			else {
				cout << "------------Too Low------------------\n";
			}
			if (randomNum != userNum) {
				cout << "Do you want to quit (y/n): ";
				cin >> choice;
				cout << "\n";
				if (choice == 'y') {
					cout << "Random number was: " << randomNum << "\n\n";
					flag = false;
				}
			}
		} while (flag);
		cout << "Do you want to play again (y/n): ";
		cin >> choice;
	} while (choice == 'y');
}