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
	std::string section = "";
	int zone = 0;
	std::string date = ""; //date format DD-MM-YY
	std::string time = ""; //time format 15:47
	std::string ID = ""; //nominal ticket, corresponds with a unique identification string of 10 characters

	Ticket(int seat, int row, int stand, std::string section, int zone, std::string date, std::string time, std::string ID):
		seat(seat), row(row), stand(stand), zone(zone), date(date), time(time), ID(ID) { //constructor
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

	//char* getSectionAsPointer() { //getter for section as pointer
	//	char* nameCopy = new char[strlen(this->section) + 1];
	//	strcpy_s(nameCopy, strlen(this->section) + 1, this->section);
	//	return nameCopy;
	//}

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

	Ticket(const Ticket& tick) {
		this->seat = tick.seat;
		this->row = tick.row;
		this->stand = tick.stand;
		this->section = tick.section;
		this->time = tick.time;
		this->zone = tick.zone;
		this->date = tick.date;
		this->ID = tick.ID;
	}

	~Ticket() {
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

	void setSection(std::string section) { 
		if (section.length() > 99)
			throw std::exception("Name over 100 characters");
		this->section = section;
	} 

	void setZone(int zone) {
		if ((zone >= 100 && zone <103) || (zone >= 200 && zone < 203) || (zone >= 300 && zone < 303))
			this->zone = zone;
		else
			throw std::exception("Value of zone can be from these values: 100,101,102,200,201,202,300,301,302");
	}

	void setDate(std::string date) {
		if (date.length() != 8)
			throw std::exception("Wrong date format. Date format must be DD-MM-YY");
		this->date = date;
		//to be added more checks
	}

	void setTime(std::string time) {
		if (time.length() != 5)
			throw std::exception("Wrong time format. Date format must be similar to 15:47");
		this->time = time;
		//to be added more checks
	}

	void setID(std::string ID) {
		if (ID.length() != 10)
			throw std::exception("Wrong ID format. ID must be 10 characters long");
		this->ID = ID;
		//to be added more checks
	}
};

class Event {
private:
	std::string date = ""; //date format DD-MM-YY
	std::string time = ""; //time format 15:47
	char name[100] = "Unknown";
	//int availableTickets = Location.getMaxSeats();

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
	}

private:

	void setName(const char* name) {
		if (strlen(name) < 3)
			throw std::exception("Name under 3 characters");
		if (strlen(name) > 99)
			throw std::exception("Name over 100 characters");
		strcpy_s(this->name, 99, name);

		/*char letter = name[0];
		bool ok = 1;

		if(letter > 'Z' || letter < 'A')
			throw std::exception("Name must contain only letters");

		for (int i = 1; i < strlen(name); i++) {
			letter = name[i];
			for (int j = 'a'; j <= 'z'; j++) {
				if (letter == j)
					ok = 0;
			}
			if (ok == 1)
				throw std::exception("Name must contain only letters");
		}*/
	}
	
	void setDate(std::string date) {
		if (date.length() != 8)
			throw std::exception("Wrong date format. Date format must be DD-MM-YY");
		this->date = date;
		//to be added more checks
	}

	void setTime(std::string time) {
		if (time.length() != 5)
			throw std::exception("Wrong time format. Date format must be similar to 15:47");
		this->time = time;
		
		//to be added more checks
	}

};


//general info about a specific match
//stands available will be East and West, formatted as 1 and 2