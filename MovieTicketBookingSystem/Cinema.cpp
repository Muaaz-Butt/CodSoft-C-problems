#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

#include "Cinema.h"
#include "Booking.h"
#include "Movies.h"

using namespace std;

void moviesInScreen() {
	cout << "---------------Movies in screen today---------------\n\n";
	cout << fixed << left << setw(15) << "Movie Names";
	cout << fixed << left << setw(15) << "Duration";
	cout << "Price\n\n";
}

void inputNoOfSeats(int& numOfSeats, bool& flag) {
	do {
		cout << "Enter number of seats you want to book (0 to exit): ";
		cin >> numOfSeats;
		if (!(numOfSeats <= 50)) {
			cout << "***** Total Number of seats in cinema is 50 *****";
		}
	} while (!(numOfSeats <= 50));
	if (numOfSeats == 0) {
		flag = false;
	}
}

void inputMovieName(string& movieName, Movies& m1, Movies& m2, Movies& m3) {
	bool invalidMovieName;
	do {
		cout << "Enter Movie Name: ";
		getline(cin, movieName);
		invalidMovieName = !(movieName == m1.getMovieName() || movieName == m2.getMovieName() || movieName == m3.getMovieName());
		if (invalidMovieName) {
			cout << "Invalid Movie Name\n";
		}
	} while (invalidMovieName);
}

void inputSeatNumberAndCheckSeatAvailability(const int numOfSeats, int& rows, int& columns, BookingSystem& booking) {
	for (int i = 0; i < numOfSeats; i++) {
		do {
			cout << "Enter row and column Example (1 5): ";
			cin >> rows >> columns;
			if (!(rows > 0 && rows < 6 && columns > 0 && columns < 11)) {
				cout << "Invalid rows and columns\n";
			}
		} while (!(rows > 0 && rows < 6 && columns>0 && columns < 11));
		if (!(booking.isSeatAvailable(rows, columns))) {
			cout << "Seat " << rows << " " << columns << " is already booked. Please choose another seat.\n";
			i--;
		}
		booking.bookSeats(rows, columns);
	}
}

void displayBookedSeats(int numOfSeats, string movieName, double totalCost) {
	cout << "\n-----------------Seats booked successfully!--------------------\n";
	cout << "No of seats: " << numOfSeats << "\n"; 
	cout << "Movie name: " << movieName << "\n";
	cout << "Total cost: Rs: " << totalCost << "\n";
}

void Cinema::show() {
	int numOfSeats, rows, columns, choice;
	double totalCost;
	string movieName;
	Movies m1("JohnWick", "2:30", 1200);
	Movies m2("FastX", "2:20", 1200);
	Movies m3("M6", "2:00", 1200);
	BookingSystem booking; 
	booking.initializeSeats();
	bool flag = true;
	moviesInScreen();
	m1.displayMoviesList();
	m2.displayMoviesList();
	m3.displayMoviesList();
	while (flag) { //handle loop on basis of choice vaiable
		inputNoOfSeats(numOfSeats, flag);
		if (flag) {
			cin.ignore();
			inputMovieName(movieName, m1, m2, m3);
			booking.displaySeats();
			inputSeatNumberAndCheckSeatAvailability(numOfSeats, rows, columns, booking);
			totalCost = booking.calculateTotalCost(numOfSeats);
			displayBookedSeats(numOfSeats, movieName, totalCost);
			booking.displaySeats();
			flag = false;
		}
	}
	cout << "\n\n--------------Thank you so much! Hope to see you again------------------\n\n";
}