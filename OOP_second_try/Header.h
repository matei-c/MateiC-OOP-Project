#pragma once
#include <string>


class location {
private:
	char name[100]; // name of the stadium
	int maxNoOfSeats; // total seats available in the stadium
	int noOfRows;
	int noOfColumns;
	int* stands; // eg: North, South, East, West formatted as numbers eg: 1,2,3
	char* section; // eg: lawn, tribune, VIP, press
	int* zones; // each section has more zones counted in numbers eg: 100,101,102

	location(const char* name, int maxNoOfSeats, int noOfRows, int noOfColumns) { // constructor for location
		this->setMaxSeats(maxNoOfSeats);
		this->setName(name);
	}


public:
	std::string getNameValue() { //getter for name
		return std::string(this->name);
	}

	char* getNameValueAsPointer() {
		char* nameCopy = new char[strlen(this->name) + 1];
		strcpy_s(nameCopy, strlen(this->name) + 1, this->name);
		return nameCopy;
	}

private:
	void setName(const char* name) { //setter for name
		//validating the input
		if (strlen(name) > 99)
			throw std::exception("Name over 100 characters");
		strcpy_s(this->name, 99, name);
	}

	void setMaxSeats(int value) { //setter for max no of seats
		if (value > 0)
			this->maxNoOfSeats = value;
		else
			throw std::exception("Value can not be negative or null");
	}

public:
	int getMaxSeats() { //getter for max no of seats
		return this->maxNoOfSeats;
	}

};

class ticket {
private:
	int seat; //column of the position in the stand
	int row;
	int stand;
	char* section;
	int zone;
	std::string date; //date format DD-MM-YY
	std::string time; //time format 15:47
	std::string ID; //nominal ticket, corresponds with a unique identification no.

	ticket(int seat, int row, int stand, int zone, char section) { //constructor
		seat = 1;
		row = 1;
		stand = 1;
		//section = "lawn";
		zone = 100;
	}
};

class event {
private:
	char* date; //date format DD-MM-YY
	char* time; //time format 15:47
	char name[100];
};

//general info about a specific match
//stands available will be East and West, formatted as 1 and 2