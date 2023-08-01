#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int randomNumberGenerator() {
	int randomNum;
	srand(time(0));
	randomNum = rand();
	return randomNum;
}

void play() {
	int randomNum = randomNumberGenerator();
	cout << randomNum;
	int userNum;
	char choice = 'y';
	do {
		do {
			cout << "Enter the number which you guess: ";
			cin >> userNum;
			if (randomNum == userNum) {
				cout << "\n------------------Congratulations! Guessed number is correct----------------------\n\n";
			}
			else if (randomNum - userNum > 10000 || randomNum - userNum > 5000 || randomNum - userNum > 1000) {
				cout << "\n---------------Random number is too high---------------\n\n";
			}
			else if (userNum - randomNum > 10000 || userNum - randomNum > 5000 || userNum - randomNum > 1000) {
				cout << "\n---------------Random number is too low---------------\n\n";
			}
			else if (randomNum - userNum < 1000 && randomNum - userNum > 500 || userNum - randomNum < 1000 && userNum - randomNum > 500) {
				cout << "\n----------------You are close---------------\n\n";
			}
			else if (randomNum - userNum < 500 && randomNum - userNum > 100 || userNum - randomNum < 500 && userNum - randomNum  > 100) {
				cout << "\n--------------You are very close to the number---------------\n\n";
			}
			else if (randomNum - userNum < 10 && randomNum - userNum > 0 || userNum - randomNum < 10 && userNum - randomNum > 0) {
				cout << "\n----------------You are almost 10 numbers apart from the random number----------------\n\n";
			}
			else {
				cout << "\n---------------You are just there--------------\n\n";
			}
			if (randomNum != userNum) {
				cout << "Do you want to quit (y/n): ";
				cin >> choice;
				cout << "\n";
				if (choice == 'y') {
					cout << "Random number was: " << randomNum << "\n\n";
				}
			}
		} while (choice != 'y' || randomNum != userNum);
		cout << "Do you want to play again (y/n): ";
		cin >> choice;
	} while (choice == 'y');
}

int main() {
	play();
}