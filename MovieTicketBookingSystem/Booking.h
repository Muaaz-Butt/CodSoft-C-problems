#pragma once
#ifndef BOOKING_H
#define BOOKING_H

const int NUM_ROWS = 5;
const int NUM_COLUMNS = 10;

class BookingSystem {
private:
	char seats[NUM_ROWS][NUM_COLUMNS];
public:
	void displaySeats();
	void initializeSeats();
	bool isSeatAvailable(int row, int column);
	double calculateTotalCost(int numOfSeats);
	void bookSeats(int row, int column);
};

#endif BOOKING_H

