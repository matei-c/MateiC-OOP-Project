#pragma once
#include <string>
#include <iostream>
#include <fstream>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)

class Location {
protected:
	char* name = nullptr; // name of the stadium
	int noOfRows = 0;
	int noOfZones = 0;
	int* noOfSeatsPerRow = nullptr;

	const static int MIN_SEATS_PER_ROW = 1;
	const static int MAX_SEATS_PER_ROW = 30;

	virtual void printInfo() = 0;

	Location() //default ctor
	{
		std::cout << "\nCalling default constructor for location";
		this->name = new char[strlen("Unknown") + 1];
		strcpy(this->name, "Unknown");
	}

	Location(const char* name, int noOfRows, int noOfZones, int* noOfSeatsPerRow) { //ctor with param
		this->setName(name);
		this->setRows(noOfRows);
		this->setZones(noOfZones);
		this->setNoOfSeatsPerRow(noOfSeatsPerRow, noOfRows);
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

	void setName(const char* name) { //setter for name
		//validating the input
		if (strlen(name) > 99)
			throw std::exception("Name over 100 characters");
		if (this->name != nullptr)
			delete[] this->name;
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}

	int getRows() {
		return this->noOfRows;
	}

	void setRows(int value) {
		if (value > 0)
			this->noOfRows = value;
		else
			throw std::exception("Value of rows can not be negative or null");
	}

	int getZones() {
		return this->noOfZones;
	}

	void setZones(int value) {
		if (value > 0)
			this->noOfZones = value;
		else
			throw std::exception("Value of zones can not be negative or null");
	}

	int* getNoOfSeatsPerRowAsAPointer() {
		int* pointer = this->copyArray(this->noOfSeatsPerRow, this->noOfRows);
		return pointer;
	}

	void setNoOfSeatsPerRow(int* newSeatsPerRow, int newRows) {
		if (newSeatsPerRow == nullptr) throw std::exception("The newSeatsPerRow pointer is null");
		if (newRows <= 0) throw std::exception("The newRows value can not be negative or null");
		for (int i = 0;i < noOfRows;i++) {
			if (newSeatsPerRow[i] < MIN_SEATS_PER_ROW || newSeatsPerRow[i] > MAX_SEATS_PER_ROW) {
				throw std::exception("One of the rows from the new array has a number of seats per row that is not in the specified interval of (1,30)");
			}
			if (this->noOfSeatsPerRow != nullptr)
				delete[] this->noOfSeatsPerRow;
			this->noOfSeatsPerRow = new int[newRows];
			for (int j = 0; j < newRows;j++) {
				this->noOfSeatsPerRow[i] = newSeatsPerRow[i];
			}
			this->noOfRows = newRows;
		}
	}

	Location(const Location& loc) { //copy ctor
		std::cout << "\nCopy constructor called";
		this->setName(loc.name);
		this->setRows(loc.noOfRows);
		this->setZones(loc.noOfZones);
		this->setNoOfSeatsPerRow(loc.noOfSeatsPerRow, loc.noOfRows);
	}

	~Location() { //destructor
		std::cout << "\nDestructor for location called";
		if (this->name != nullptr)
			delete[] this->name;
		if (this->noOfSeatsPerRow != nullptr)
			delete[] this->noOfSeatsPerRow;
	}

	//void showStadiumSeating(int zone, int stand) {
	//	std::cout << "-------------------Pitch-------------------";
	//	for (int i = 0; i < noOfRows; i++)
	//		for (int j = 0; j < noOfColumns;j++)
	//			std::cout << "|_|";
	//	std::cout << std::endl;
	//	//not complete, must add attributes
	//}

	int getTotalNoOfSeats() {
		int totalSeats = 0;
		for (int i = 0; i < noOfZones; i++)
			for (int j = 0; j < noOfRows; j++)
				totalSeats += noOfSeatsPerRow[j];
		return totalSeats;
	}

	Location& operator= (const Location& loc) { //overload for = operator
		if (this != &loc) {
			this->setName(loc.name);
			this->setRows(loc.noOfRows);
			this->setNoOfSeatsPerRow(loc.noOfSeatsPerRow, loc.noOfRows);
			this->setZones(loc.noOfZones);
		}
		return *this;
	}

	bool operator>(Location& loc) {
		if (this->getTotalNoOfSeats() > loc.getTotalNoOfSeats())
			return true;
		else
			return false;
	}

	bool operator<(Location& loc) {
		if (this->getTotalNoOfSeats() < loc.getTotalNoOfSeats())
			return true;
		else
			return false;
	}

	bool operator>=(Location& loc) {
		if (this->getTotalNoOfSeats() >= loc.getTotalNoOfSeats())
			return true;
		else
			return false;
	}

	bool operator<=(Location& loc) {
		if (this->getTotalNoOfSeats() <= loc.getTotalNoOfSeats())
			return true;
		else
			return false;
	}

	bool operator==(Location& loc) {
		if (this->getTotalNoOfSeats() == loc.getTotalNoOfSeats())
			return true;
		else
			return false;
	}

	virtual void printInfo() {
		std::cout << "\nThe number of zones is: " << this->noOfZones;
		std::cout << "\nThe number of rows is: " << this->noOfRows;
		for (int i = 0; i < this->noOfRows;i++) {
			std::cout << "\nThe number of seats for row " << i + 1 << " is: " << this->noOfSeatsPerRow[i];
		}
	}


private:

	static int* copyArray(int* array, int noValues) {
		int* newArray = new int[noValues];
		for (int i = 0; i < noValues;i++)
			newArray[i] = array[i];
		return newArray;
	}

	friend std::istream& operator>>(std::istream& in, Location& loc);

	bool validateNoOfZones(int noOfZones) {
		if (noOfZones < 1) return false;
		else return true;
	}
	bool validateNoOfRows(int noOfRows) {
		if (noOfRows < 1) return false;
		else return true;
	}
	bool validateNoOfSeatsPerRow(int* noOfSeatsPerRow, int noOfRows) {
		for (int i = 0; i < noOfRows; i++) {
			if (noOfSeatsPerRow[i]<Location::MIN_SEATS_PER_ROW || noOfSeatsPerRow[i]>Location::MAX_SEATS_PER_ROW)
				return false;
			else return true;
		}
	}
};

std::ostream& operator<<(std::ostream& out, Location& loc) { //cout operator for LOCATION class
	out << "\nThe name of the location is: " << loc.getName() << std::endl;
	out << "The max no of seats that the location has: " << loc.getTotalNoOfSeats() << std::endl;
	out << "The no of zones is: " << loc.getZones() << std::endl;
	out << "The no of rows is: " << loc.getRows() << std::endl;
	for (int i = 0; i < loc.getRows(); i++) {
		out << "\nRow number " << i + 1 << " has " << loc.getNoOfSeatsPerRowAsAPointer()[i] << " seats";
	}
	return out;
}

std::istream& operator>>(std::istream& in, Location& loc) { //cin operator for LOCATION class
	std::cout << "The name of the location is: " << std::endl;
	std::string str;
	in >> str;
	loc.setName(str.c_str());
	int value;
	std::cout << "Now introduce the no. of zones: " << std::endl;
	in >> value;
	loc.setZones(value);
	while (loc.validateNoOfZones(value) == false) {
		std::cout << "Wrong input. The no. of zones is: " << std::endl;
		in >> value;
		loc.setZones(value);
	}
	std::cout << "The no. of rows is: " << std::endl;
	in >> value;
	loc.setRows(value);
	while (loc.validateNoOfRows(value) == false) {
		std::cout << "Wrong input. The no. of rows is: " << std::endl;
		in >> value;
		loc.setRows(value);
	}
	std::cout << "\nNow entering the number of seats per row.";
	if (loc.noOfSeatsPerRow != nullptr) {
		delete[]loc.noOfSeatsPerRow;
		loc.noOfSeatsPerRow = nullptr;
	}
	loc.noOfSeatsPerRow = new int[loc.noOfRows];
	for (int i = 0; i < loc.noOfRows; i++) {
		std::cout << "\n Number of seats for row " << i + 1 << ": ";
		in >> value;
		while ((value < Location::MIN_SEATS_PER_ROW || value > Location::MAX_SEATS_PER_ROW) == false) {
			std::cout << "\nWrong input. Number of seats for row " << i + 1 << ": ";
			in >> value;
		}
		loc.noOfSeatsPerRow[i] = value;
	}
	return in;
}

class Stadium : public Location {
protected:
	int noOfToilets = 0;
	int noOfFoodPlaces = 0;
	string homeTeam = "";

public:
	Stadium(const char* name, int noOfRows, int noOfZones, int* noOfSeatsPerRow, 
			int noOfToilets, int noOfFoodPlaces, string homeTeam) 
	:Location(name, noOfRows, noOfZones, noOfSeatsPerRow), 
	noOfFoodPlaces(noOfFoodPlaces), noOfToilets(noOfToilets), homeTeam(homeTeam){
		
	}
	void printInfo() {
		this->Location::printInfo();
		cout << "The number of toilets is: " << noOfToilets;
		cout << "The number of food places is: " << noOfFoodPlaces;
		cout << "The home team is: " << homeTeam;
	}
};