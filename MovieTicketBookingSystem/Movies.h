#pragma once
#ifndef MOVIES_H
#define MOVIES_H

#include <string>

using namespace std;

class Movies {
private:
	string movieName;
	string duration;
	double cost;
public:
	Movies();
	Movies(string movieName, string duration, double price);
	void setMovieName(string movieName);
	string getMovieName()const;
	void setDuration(string duration);
	string getDuration()const;
	void setCost(double cost);
	double getCost()const;
	void displayMoviesList()const;
};


#endif MOVIES_H
