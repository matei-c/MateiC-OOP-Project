#include <string>
#include <iostream>
#include <fstream>
#include "Header.h"

using namespace std;

int main() {
	//building the console instructions, the menu
	cout << "Welcome to the ticketing app! Choose an option by typing the corresponding number:";
	cout << endl << "1. Buy tickets";
	cout << endl << "2. Return tickets";
	cout << endl << "3. Show available events";
	cout << endl << "4. Admin mode";
	int option;
	string pass;
	string type;
	string press_id;
	cin >> option;
	switch (option) {
	case 1:
		cout << "Type in the event id you want to buy tickets to:";
		int event_id;
		cin >> event_id;
		cout << "Type in the category of ticket you want to buy (choose between LAWN, TRIBUNE, VIP, PRESS";
		cin >> type;
		if (type == "PRESS") {
			cout << "Please provide the press pass identification number. This number will be checked after the ticket will be bought and if it is not correct, the ticket will be refunded.";
			cin >> press_id;
		}
		cout << "Type in the amount of tickets:";
		int no_tickets;
		cin >> no_tickets;
		//cout << "The price for your ticket(s) will be: " << Ticket::priceCalculator(no_tickets, press_id);
		
		break;
	case 2:

		break;
	case 3:

		break;
	case 4:
		cin >> pass;
		if (pass == "admin") {
			cout << "Welcome to admin mode. Here you can add manually locations and events. Choose an option by typing the corresponding number:";
			cout << "1. Add an event";
			cout << "2. Add a location";
			switch (option) {
			case 1:

				break;
			case 2:

				break;
			}
		}
		else
			cout << "Wrong password. Restart the app to try again.";
		break;
	default:
		cout << "Wrong input. Restart the app to try again.";
	}
}