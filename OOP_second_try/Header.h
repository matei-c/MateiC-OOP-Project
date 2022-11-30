#pragma once
#include <string>


class Location {
private:
	char name[100] = "Unknown"; // name of the stadium
	int maxNoOfSeats = 1; // total seats available in the stadium
	int noOfRows = 1;
	int noOfColumns = 1;
	int* stands = nullptr; // eg: North, South, East, West formatted as numbers eg: 1,2,3
	char* sections = nullptr; // eg: lawn, tribune, VIP, press
	int* zones = nullptr; // each section has more zones counted in numbers eg: 100,101,102

	Location(const char* name, int maxNoOfSeats, int noOfRows, int noOfColumns) { // constructor for location
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

	~Location() {
		if (this->stands != nullptr)
			delete[] this->stands;

		if (this->sections != nullptr)
			delete[] this->sections;

		if (this->zones != nullptr)
			delete[] this->zones;
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

class Ticket {
private:
	int seat = 0; //column of the position in the stand
	int row = 0;
	int stand = 0;
	char* section = nullptr;
	int zone = 0;
	char* date = nullptr; //date format DD-MM-YY
	char* time = nullptr; //time format 15:47
	char* ID = nullptr; //nominal ticket, corresponds with a unique identification string of 10 characters

	Ticket(int seat, int row, int stand, int zone, char section) { //constructor
		//seat = 1;
		//row = 1;
		//stand = 1;
		//section = "lawn";
		//zone = 100;
	}

public:

	int getSeat() {
		return this->seat;
	}

	int getRow() {
		return this->row;
	}

	int getStand() {
		return this->stand;
	}

	std::string getSection() { //getter for section as string
		return std::string(this->section);
	}

	char* getSectionAsPointer() { //getter for section as pointer
		char* nameCopy = new char[strlen(this->section) + 1];
		strcpy_s(nameCopy, strlen(this->section) + 1, this->section);
		return nameCopy;
	}

	int getZone() {
		return this->zone;
	}

	std::string getDate() { //getter for date as string
		return std::string(this->date);
	}

	std::string getTime() { //getter for time as string
		return std::string(this->time);
	}

	std::string getID() { //getter for ID as string
		return std::string(this->ID);
	}

	~Ticket() {
		if (this->section != nullptr)
			delete[] this->section;
		if (this->date != nullptr)
			delete[] this->date;
		if (this->time != nullptr)
			delete[] this->time;
		if (this->ID != nullptr)
			delete[] this->ID;
	}

private:

	void setSeat(int seat) {
		if (seat > 0)
			this->seat = seat;
		else 
			throw std::exception("Value of seat can not be negative or null");
	}

	void setRow(int row) {
		if (row > 0)
			this->row = row;
		else
			throw std::exception("Value of rows can not be negative or null");
	}

	void setStand(int stand) {
		if (stand > 0 && stand < 4)
			this->stand = stand;
		else
			throw std::exception("Value of stand can be between 1 and 3");
	}

	/*void setSection(const char* section) { 
		if (strlen(section) > 99)
			throw std::exception("Name over 100 characters");
		strcpy_s(this->section, 99, section);
	} */

	void setZone(int zone) {
		if ((zone >= 100 && zone <103) || (zone >= 200 && zone < 203) || (zone >= 300 && zone < 303))
			this->zone = zone;
		else
			throw std::exception("Value of zone can be from these values: 100,101,102,200,201,202,300,301,302");
	}

	void setDate(const char* date) {
		if (strlen(date) != 8)
			throw std::exception("Wrong date format. Date format must be DD-MM-YY");
		strcpy_s(this->date, 8, date);
		//to be added more checks
	}

	void setTime(const char* time) {
		if (strlen(time) != 5)
			throw std::exception("Wrong time format. Date format must be similar to 15:47");
		strcpy_s(this->time, 5, time);
		//to be added more checks
	}

	void setID(const char* ID) {
		if (strlen(ID) != 10)
			throw std::exception("Wrong ID format. ID must be 10 characters long");
		strcpy_s(this->ID, 10, ID);
		//to be added more checks
	}
};

class Event {
private:
	char* date = nullptr; //date format DD-MM-YY
	char* time = nullptr; //time format 15:47
	char name[100] = "Unknown";
	//int availableTickets = Location::maxNoOfSeats;

public:

	std::string getName() { //getter for name as string
		return std::string(this->name);
	}

	std::string getDate() { //getter for date as string
		return std::string(this->date);
	}

	std::string getTime() { //getter for time as string
		return std::string(this->time);
	}

	~Event() {
		if (this->date != nullptr)
			delete[] this->date;
		if (this->time != nullptr)
			delete[] this->time;
	}

private:

	void setName(const char* name) {
		if (strlen(name) > 99)
			throw std::exception("Name over 100 characters");
		strcpy_s(this->name, 99, name);
	}
	
	void setDate(const char* date) {
		if (strlen(date) != 8)
			throw std::exception("Wrong date format. Date format must be DD-MM-YY");
		strcpy_s(this->date, 8, date);
		//to be added more checks
	}

	void setTime(const char* time) {
		if (strlen(time) != 5)
			throw std::exception("Wrong time format. Date format must be similar to 15:47");
		strcpy_s(this->time, 5, time);
		//to be added more checks
	}

};


//general info about a specific match
//stands available will be East and West, formatted as 1 and 2