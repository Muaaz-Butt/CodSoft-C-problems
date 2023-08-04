#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

#include "Cinema.h"
#include "Booking.h"
#include "Movies.h"

using namespace std;

void Cinema::show() {
	int numOfSeats, rows, columns, choice;
	double totalCost;
	string movieName;
	Movies m1("JohnWick", "2:30", 1200);
	Movies m2("FastX", "2:20", 1200);
	Movies m3("M6", "2:00", 1200);
	BookingSystem b;
	b.initializeSeats();
	bool flag = true;
	do {
		cout << "---------------Movies in screen today---------------\n\n";
		cout << "Movie Name   Duration       Price\n";
		cout << "--------------------------------- \n";
		m1.displayMoviesList();
		m2.displayMoviesList();
		m3.displayMoviesList();
		flag = true;
		while (flag) {
			cout << "Enter number of seats you want to book (0 to exit): ";
			cin >> numOfSeats;
			if (numOfSeats == 0) {
				flag = false;
			}
			if (flag) {
				cin.ignore();
				do {
					cout << "Enter Movie Name: ";
					getline(cin, movieName);
					if (!(movieName == m1.getMovieName() || movieName == m2.getMovieName() || movieName == m3.getMovieName())) {
						cout << "Invalid Movie Name\n";
					}
				} while (!(movieName == m1.getMovieName() || movieName == m2.getMovieName() || movieName == m3.getMovieName()));
				b.displaySeats();
				for (int i = 0; i < numOfSeats; i++) {
					do {
						cout << "Enter row and column Example (1 5): ";
						cin >> rows >> columns;
						if (!(rows > 0 && rows < 6 && columns>0 && columns < 11)) {
							cout << "Invalid rows and columns\n";
						}
					} while (!(rows > 0 && rows < 6 && columns>0 && columns < 11));
					if (!(b.isSeatAvailable(rows, columns))) {
						cout << "Seat " << rows << " " << columns << " is already booked. Please choose another seat.\n";
						i--;
					}
					b.bookSeats(rows, columns);
				}
				totalCost = b.calculateTotalCost(numOfSeats);
				cout << "\n-----------------Seats booked successfully!--------------------\n";
				cout << "Movie name: " << movieName << "\n";
				cout <<	"Total cost : RS:" << totalCost << "\n";
				flag = false;
				b.displaySeats();
			}
		}
		cout << "Enter 0 to exit and 1 to again show the menu: ";
		cin >> choice;
	} while (choice==1);
	cout << "\n\n--------------Thank you so much! Hope to see you again------------------\n\n";
}