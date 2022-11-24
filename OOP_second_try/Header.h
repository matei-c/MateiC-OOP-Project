#pragma once
#include <string>


class location {
private:
	char name[100] = "Unknown"; // name of the stadium
	int maxNoOfSeats = 1; // total seats available in the stadium
	int noOfRows = 1;
	int noOfColumns = 1;
	int* stands = nullptr; // eg: North, South, East, West formatted as numbers eg: 1,2,3
	char* section = nullptr; // eg: lawn, tribune, VIP, press
	int* zones = nullptr; // each section has more zones counted in numbers eg: 100,101,102

	location(const char* name, int maxNoOfSeats, int noOfRows, int noOfColumns) { // constructor for location
		this->setMaxSeats(maxNoOfSeats);
		this->setName(name);
		this->setRows(noOfRows);
		this->setColumns(noOfColumns);
	}


public:
	std::string getName() { //getter for name as string
		return std::string(this->name);
	}

	char* getNameAsPointer() { //getter for name as pointer
		char* nameCopy = new char[strlen(this->name) + 1];
		strcpy_s(nameCopy, strlen(this->name) + 1, this->name);
		return nameCopy;
	}

	int getMaxSeats() { //getter for max no of seats
		return this->maxNoOfSeats;
	}

	int getRows() {
		return this->noOfRows;
	}

	int getColumns() {
		return this->noOfColumns;
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
			throw std::exception("Value of seats can not be negative or null");
	}

	void setRows(int value) {
		if (value > 0)
			this->noOfRows = value;
		else
			throw std::exception("Value of rows can not be negative or null");
	}

	void setColumns(int value) {
		if (value > 0)
			this->noOfColumns = value;
		else
			throw std::exception("Value of columns can not be negative or null");
	}


};

class ticket {
private:
	int seat = 0; //column of the position in the stand
	int row = 0;
	int stand = 0;
	char* section = nullptr;
	int zone = 0;
	std::string date = "01-01-23"; //date format DD-MM-YY
	std::string time = "00:00"; //time format 15:47
	std::string ID = "00000000"; //nominal ticket, corresponds with a unique identification no.

	ticket(int seat, int row, int stand, int zone, char section) { //constructor
		//seat = 1;
		//row = 1;
		//stand = 1;
		//section = "lawn";
		//zone = 100;
	}
};

class event {
private:
	char* date = nullptr; //date format DD-MM-YY
	char* time = nullptr; //time format 15:47
	char name[100] = "Unknown";
};

//general info about a specific match
//stands available will be East and West, formatted as 1 and 2