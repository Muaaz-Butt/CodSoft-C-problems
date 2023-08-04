#include <iostream>

#include "Booking.h"

using namespace std;

void BookingSystem::displaySeats() {
	int temp = 65;
	cout << " ----------------------Seating Arrangement---------------------- \n\n";
	cout << "   1 2 3 4 5 6 7 8 9 10\n";
	cout << "   --------------------\n";
	for (int i = 0; i < NUM_ROWS; i++) {
		cout << i + 1 << "| ";
		for (int j = 0; j < NUM_COLUMNS; j++) {
			cout << seats[i][j] << " ";
		}
		temp++;
		cout << "\n";
	}
	cout << "-----------------------------------------------------------------" << endl;
}
void BookingSystem::initializeSeats() {
	for (int i = 0; i < NUM_ROWS; i++) {
		for (int j = 0; j < NUM_COLUMNS; j++) {
			this->seats[i][j] = 'O';
		}
	}
}
bool BookingSystem::isSeatAvailable(int row, int column) {
	if (seats[row-1][column-1] == 'O') {
		return true;
	}
	return false;
}
double BookingSystem::calculateTotalCost(int numOfSeats) {
	double ticketPrice = 1200.0;
	return ticketPrice * numOfSeats;
}
void BookingSystem::bookSeats(int row, int column) {
	seats[row - 1][column - 1] = 'X';
}
