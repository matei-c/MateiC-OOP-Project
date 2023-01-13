#pragma once
#include <string>
#include <iostream>
#include <fstream>

enum Sections { LAWN, TRIBUNE, VIP, PRESS };

class Ticket {
private:
	char* nameOfEvent = nullptr;
	int price = 50;
	int seat = 0; //column of the position in the stand
	int row = 0;
	int stand = 1;
	Sections section = LAWN;
	int zone = 100;
	std::string date = ""; //date format DD-MM-YY
	std::string time = ""; //time format 15:47
	const std::string ID ; //nominal ticket, corresponds with a unique identification string of 10 characters
	
public:
	Ticket() { //ctor without param
		this->nameOfEvent = new char[strlen("Unknown") + 1];
		strcpy(this->nameOfEvent, "Unknown");
		this->price = 50;
		this->seat = 0;
		this->row = 0;
		this->stand = 1;
		this->section = LAWN;
		this->time = "";
		this->zone = 100;
		this->date = "";
	}

	Ticket(int price, int seat, int row, int stand, Sections section, int zone, std::string date, std::string time, std::string ID) //ctor with param
		:ID(ID) { //ctor with param
		this->price = price;
		this->seat = seat;
		this->row = row;
		this->stand = stand;
		this->section = section;
		this->time = time;
		this->zone = zone;
		this->date = date;
	}

	std::string getNameOfEvent() {
		return std::string(this->nameOfEvent);
	}

	int getPrice() {
		return this->price;
	}

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
		this->nameOfEvent = new char[strlen(tick.nameOfEvent) + 1];
		strcpy(this->nameOfEvent, tick.nameOfEvent);
		this->price = tick.price;
		this->seat = tick.seat;
		this->row = tick.row;
		this->stand = tick.stand;
		this->section = tick.section;
		this->time = tick.time;
		this->zone = tick.zone;
		this->date = tick.date;
	}

	void updateTime(std::string time) {
		if (time.length() == 5)
			this->time = time;
		else
			throw std::exception("Wrong time format");
	}

	void updateDate(std::string date) {
		if (time.length() == 10)
			this->date = date;
		else
			throw std::exception("Wrong date format");
	}

	float priceCalculator(int noOfTickets, std::string section) {
		if(section == "LAWN")
			return (float)noOfTickets * (float)price;
		if (section == "TRIBUNE")
			return (float)noOfTickets * (float)price * 1.5;
		if (section == "VIP")
			return (float)noOfTickets * (float)price * 3;
		if (section == "PRESS")
			return 0;
	}

	~Ticket() { //destructor
		if (this->nameOfEvent != nullptr)
			delete[] this->nameOfEvent;
	}

	Ticket& operator=(const Ticket& tick) { //overload for = operator 
		if (this != &tick) {
			if (this->nameOfEvent != nullptr)
				delete[] this->nameOfEvent;
			this->nameOfEvent = new char[strlen(tick.nameOfEvent) + 1];
			strcpy(this->nameOfEvent, tick.nameOfEvent);
			this->seat = tick.seat;
			this->row = tick.row;
			this->stand = tick.stand;
			this->section = tick.section;
			this->time = tick.time;
			this->zone = tick.zone;
			this->date = tick.date;
		}
		return *this;
	}

	Ticket& operator++() {
		this->price++;
		return *this;
	}

	Ticket operator++(int) {
		Ticket tick = *this;
		++this->price;
		return *this;
	}

	explicit operator float() {
		if(this->section == LAWN)
			float a = (float)this->priceCalculator(1, "LAWN");
		else if (this->section == VIP)
			float a = (float)this->priceCalculator(1, "VIP");
		else if (this->section == TRIBUNE)
			float a = (float)this->priceCalculator(1, "TRIBUNE");
		else if (this->section == PRESS)
			float a = (float)this->priceCalculator(1, "PRESS");
	}

private:

	void setPrice(int price) {
		if (price > 0)
			this->price = price;
		else
			throw std::exception("Value of price can not be negative or null");
	}

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