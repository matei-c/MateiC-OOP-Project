#pragma once
#include <string>
#include <iostream>
#include <fstream>

int Event::AVAILABLE_TICKETS = 300;
int Event::SOLD_TICKETS = 0;

class Event {
private:
	const int id = 0;
	std::string date = ""; //date format DD-MM-YY
	std::string time = ""; //time format 15:47
	char* name = nullptr;
	static int AVAILABLE_TICKETS;
	static int SOLD_TICKETS;

public:

	Event() : id(0) { //ctor without param
		this->name = new char[strlen("Unknown") + 1];
		strcpy(this->name, "Unknown");
		this->date = "";
		this->time = "";
	}

	Event(const int id, const char* name, std::string date, std::string time) : id(id) { //ctor with param
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
		this->date = date;
		this->time = time;
	}

	int getId() {
		return this->id;
	}

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

	~Event() { //destructor
		if (this->name != nullptr)
			delete[] this->name;
	}

	Event(const Event& ev) : id(ev.id) { //copy ctor
		if (this->name != nullptr)
			delete[] this->name;
		this->name = new char[strlen(ev.name) + 1];
		strcpy(this->name, ev.name);
		this->date = ev.date;
		this->time = ev.date;
		this->AVAILABLE_TICKETS = ev.AVAILABLE_TICKETS;
		this->SOLD_TICKETS = ev.SOLD_TICKETS;
	}

	Event& operator=(const Event& ev) { //overload for = operator
		if (this != &ev) {
			if (this->name != nullptr)
				delete[] this->name;
			this->name = new char[strlen(ev.name) + 1];
			strcpy(this->name, ev.name);
		}
		this->date = ev.date;
		this->time = ev.date;
		this->AVAILABLE_TICKETS = ev.AVAILABLE_TICKETS;
		this->SOLD_TICKETS = ev.SOLD_TICKETS;
	}

	void buyTicket(int noTickets) {
		AVAILABLE_TICKETS -= noTickets;
		SOLD_TICKETS += noTickets;
		std::cout << noTickets << " ticket(s) bought";
	}

	void returnTicket(int noTickets) {
		AVAILABLE_TICKETS += noTickets;
		SOLD_TICKETS -= noTickets;
		std::cout << noTickets << " ticket(s) returned";
	}

	bool operator!=(Event ev) {
		if (this->date != ev.date)
			return true;
		else return false;
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

std::ostream& operator<<(std::ostream& out, Event& ev) { //cout operator for EVENT class
	out << "The name is: " << ev.getName() << std::endl;
	out << "The date is: " << ev.getDate() << std::endl;
	out << "The time is: " << ev.getTime() << std::endl;
	out << "No. of available tickets: " << ev.getAvailableTickets() << std::endl;
	out << "No. of sold tickets:" << ev.getSoldTickets() << std::endl;
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
	char* name = nullptr;
	strcpy(name, str.c_str());
	ev.setName(name);
}
