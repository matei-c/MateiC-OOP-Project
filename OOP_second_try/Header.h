#pragma once
#include <string>
#include <iostream>

enum Sections { LAWN, TRIBUNE, VIP, PRESS };

class Location {
private:
	char* name = nullptr; // name of the stadium
	int maxNoOfSeats = 1; // total seats available in the stadium
	int noOfRows = 1;
	int noOfColumns = 1;
	int* stands = nullptr; // eg: North, South, East, West formatted as numbers eg: 1,2,3
	int* zones = nullptr; // each section has more zones counted in numbers eg: 100,101,102
	
	const static int NO_OF_STANDS = 3;
	const static int NO_OF_ZONES = 9;

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

	//friend const int Event::availableTickets;

	int getRows() {
		return this->noOfRows;
	}

	int getColumns() {
		return this->noOfColumns;
	}

	int* getStandsAsPointer() {
		int vector[this->NO_OF_STANDS];
		for (int i = 0; i < NO_OF_STANDS; i++) {
			vector[i] = this->stands[i];
		}
		return vector;
	}

	int* getZonesAsPointer() {
		int vector[this->NO_OF_ZONES];
		for (int i = 0; i < NO_OF_ZONES; i++) {
			vector[i] = this->zones[i];
		}
		return vector;
	}

	int getNO_OF_STANDS() {
		return NO_OF_STANDS;
	}

	int getNO_OF_ZONES() {
		return NO_OF_ZONES;
	}

	~Location() {
		if (this->stands != nullptr)
			delete[] this->stands;

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

	void setStands(int* vector, int noofvalues) {
		if (vector != nullptr && noofvalues == NO_OF_STANDS) {
			for (int i = 0; i < noofvalues; i++) {
				this->stands[i] = vector[i];
			}
		}
		else throw std::exception("Input data incorrect. The vector must have values and noofvalues must be = 3.");
	}

	void setZones(int* vector, int noofvalues) {
		if (vector != nullptr && noofvalues == NO_OF_ZONES) {
			for (int i = 0; i < noofvalues; i++) {
				this->zones[i] = vector[i];
			}
		}
		else throw std::exception("Input data incorrect. The vector must have values and noofvalues must be = 9.");
	}

	friend std::istream& operator>>(std::istream& in, Location& loc);
};

class Ticket {
private:
	int seat = 0; //column of the position in the stand
	int row = 0;
	int stand = 0;
	Sections section = LAWN;
	int zone = 0;
	std::string date = ""; //date format DD-MM-YY
	std::string time = ""; //time format 15:47
	const std::string ID ; //nominal ticket, corresponds with a unique identification string of 10 characters

	Ticket(int seat, int row, int stand, Sections section, int zone, std::string date, std::string time, std::string ID):
		seat(seat), row(row), stand(stand), section(section), zone(zone), date(date), time(time), ID(ID) { //constructor
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
		if(this->section = LAWN)
			return std::string("LAWN");
		if (this->section = VIP)
			return std::string("VIP");
		if (this->section = TRIBUNE)
			return std::string("TRIBUNE");
		if (this->section = PRESS)
			return std::string("PRESS");
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

	Ticket(const Ticket& tick): ID(tick.ID) { //copy ctor
		this->seat = tick.seat;
		this->row = tick.row;
		this->stand = tick.stand;
		this->section = tick.section;
		this->time = tick.time;
		this->zone = tick.zone;
		this->date = tick.date;
	}

	~Ticket() { //destructor
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
		if (section == "LAWN")
			this->section = LAWN;
		else if (section == "VIP")
			this->section = VIP;
		else if (section == "TRIBUNE")
			this->section = TRIBUNE;
		else if (section == "PRESS")
			this->section = PRESS;
		else throw std::exception("Section must be one of LAWN, TRIBUNE, VIP, PRESS.");
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

	friend std::istream& operator>>(std::istream& in, Ticket tick);

};

int Event::AVAILABLE_TICKETS = 900;
int Event::SOLD_TICKETS = 0;

class Event {
private:
	std::string date = ""; //date format DD-MM-YY
	std::string time = ""; //time format 15:47
	char name[100] = "Unknown";
	static int AVAILABLE_TICKETS;
	static int SOLD_TICKETS;

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

	int getAvailableTickets() {
		return AVAILABLE_TICKETS;
	}

	int getSoldTickets() {
		return SOLD_TICKETS;
	}

	~Event() {
	}

	void buyTicket() {
		AVAILABLE_TICKETS--;
		SOLD_TICKETS++;
		std::cout << "One ticket bought";
	}

private:

	static void markUnavailableSeats(int value) {
		AVAILABLE_TICKETS -= value;
	}

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

	friend std::istream& operator>>(std::istream& in, Event ev);
};

std::ostream& operator<<(std::ostream& out, Location loc) { //cout operator for LOCATION class
	out << "The name of the location is: " << loc.getName() << std::endl;
	out << "The max no of seats that the location has: " << loc.getMaxSeats() << std::endl;
	out << "The no of rows is: " << loc.getRows() << std::endl;
	out << "The no of columns is: " << loc.getColumns() << std::endl;
	int* stands = loc.getStandsAsPointer();
	int* zones = loc.getZonesAsPointer();
	out << "The " << loc.getNO_OF_STANDS() << " stands are: " << std::endl;
	for (int i = 0; i < loc.getNO_OF_STANDS();i++) {
		out << stands[i] << std::endl;
	}
	out << "The " << loc.getNO_OF_ZONES() << " zones are: " << std::endl;
	out << "The zones are: " << std::endl;
	for (int i = 0; i < loc.getNO_OF_ZONES();i++) {
		out << zones[i] << std::endl;
	}
}

std::ostream& operator<<(std::ostream& out, Ticket& tick) { //cout operator for TICKET class
	out << "The seat is: " << tick.getSeat() << std::endl;
	out << "The row is: " << tick.getRow() << std::endl;
	out << "The stand is: " << tick.getStand() << std::endl;
	out << "The section is: " << tick.getSection() << std::endl;
	out << "The zone is: " << tick.getZone() << std::endl;
	out << "The date is: " << tick.getDate() << std::endl;
	out << "The time is: " << tick.getTime() << std::endl;
	out << "The ticket ID is: " << tick.getID() << std::endl;
}

std::ostream& operator<<(std::ostream& out, Event& ev) { //cout operator for EVENT class
	out << "The name is: " << ev.getName() << std::endl;
	out << "The date is: " << ev.getDate() << std::endl;
	out << "The time is: " << ev.getTime() << std::endl;
	out << "No. of available tickets: " << ev.getAvailableTickets() << std::endl;
	out << "No. of sold tickets:" << ev.getSoldTickets() << std::endl;
}

std::istream& operator>>(std::istream& in, Location& loc) { //cin operator for LOCATION class
	std::cout << "The name is: " << std::endl;
	std::string str;
	in >> str;
	char* name;
	strcpy(name, str.c_str());
	loc.setName(name);
	std::cout << "The max no. of seats available: " << std::endl;
	int value;
	in >> value;
	loc.setMaxSeats(value);
	std::cout << "The no. of rows is: " << std::endl;
	in >> value;
	loc.setRows(value);
	std::cout << "The no. of columns is: " << std::endl;
	in >> value;
	loc.setColumns(value);
	
	std::cout << "Now introduce the no. of stands, which should be exactly 3: " << std::endl;
	int stands;
	in >> stands;
	int standsvector[3];
	
	if (stands == 3) {
		std::cout << "Now introduce each stand number: " << std::endl;
		for (int i = 0; i < stands; i++) {
			in >> standsvector[i];
		}
	}
	else while (stands != 3) {
		in >> stands;
		std::cout << "No. of stands must be = 3.";
	}
	loc.setStands(standsvector, stands);

	std::cout << "Now introduce the no. of zones, which should be exactly 9: " << std::endl;
	int zones;
	in >> zones;
	int zonesvector[9];

	if (stands == 9) {
		std::cout << "Now introduce each zone number: " << std::endl;
		for (int i = 0; i < zones; i++) {
			in >> zonesvector[i];
		}
	}
	else while (zones > 0) {
		in >> zones;
		std::cout << "No. of zones must be = 9.";
	}
	loc.setZones(zonesvector, zones);
}

std::istream& operator>>(std::istream& in, Ticket tick) { //cin operator for TICKET class
	std::cout << "The seat is: "  << std::endl;
	int value;
	in >> value;
	tick.setSeat(value);
	std::cout << "The row is: "  << std::endl;
	in >> value;
	tick.setRow(value);
	std::cout << "The stand is: "  << std::endl;
	in >> value;
	tick.setStand(value);
	std::cout << "The section is: "  << std::endl;
	std::string str;
	in >> str;
	tick.setSection(str);
	std::cout << "The zone is: "  << std::endl;
	in >> value;
	tick.setZone(value);
	std::cout << "The date is: " << std::endl;
	in >> str;
	tick.setDate(str);
	std::cout << "The time is: " << std::endl;
	in >> str;
	tick.setTime(str);
}

std::istream& operator>>(std::istream& in, Event ev) {  //cin operator for EVENT class
	std::cout << "The date is: " << std::endl;
	std::string str;
	in >> str;
	ev.setDate(str);
	std::cout << "The time is: " << std::endl;
	in >> str;
	ev.setTime(str);
	std::cout << "The name is: " << std::endl;
	in >> str;
	char* name;
	strcpy(name, str.c_str());
	ev.setName(name);
}