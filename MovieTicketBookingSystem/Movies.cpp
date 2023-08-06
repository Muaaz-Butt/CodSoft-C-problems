#include <iostream>
#include <iomanip>

#include "Movies.h"

using namespace std;

Movies::Movies() {
	movieName = "";
	duration = "";
	cost = 0.0;
}

Movies::Movies(string movieName, string duration, double cost) : movieName(movieName), duration(duration), cost(cost) {}

void Movies::setMovieName(string movieName) {
	this->movieName = movieName;
}

void Movies::setDuration(string duration) {
	this->duration = duration;
}

string Movies::getMovieName()const {
	return movieName;
}

string Movies::getDuration()const{
    return duration;
}
void Movies::setCost(double cost) {
	this->cost = cost;
}
double Movies::getCost()const {
	return cost;
}
void Movies::displayMoviesList()const {
	cout << fixed << left << setw(15) << movieName;
	cout << fixed << left << setw(15) << duration;
	cout << fixed << left << setw(15) << setprecision(2) << cost << "\n";
}