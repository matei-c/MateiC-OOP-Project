#include <string>
#include <iostream>
#include <fstream>
#include "Ticket.h"
#include "Event.h"
#include "Location.h"
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)

using namespace std;

int main() {
	//building the console instructions, the menu
	int option;
	string pass;
	string type;
	string press_id;
	Event events[10];
	int no_events = 0;
	string file_name;
	do {
		Ticket ticket_to_buy;
		cout << "Welcome to the ticketing app! Choose an option by typing the corresponding number:";
		cout << endl << "1. Buy tickets";
		cout << endl << "2. Return tickets";
		cout << endl << "3. Show available events";
		cout << endl << "4. Admin mode";
		cout << endl << "5. Quit application\n";
		cin >> option;
		switch (option) {
		case 1:
			cout << "Functionality not yet implemented. Now quitting...";
			return 0;
			cout << endl << "Type in the event id you want to buy tickets to:";
			int event_id;
			cin >> event_id;
			cout << endl << "Type in the category of ticket you want to buy (choose between LAWN, TRIBUNE, VIP, PRESS";
			cin >> type;
			if (type == "PRESS") {
				cout << endl << "Please provide the press pass identification number. This number will be checked after the ticket will be bought and if it is not correct, the ticket will be refunded.";
				cin >> press_id;
			}

			//add a visual representation of the tickets in the stadium, bought and not bought are different

			cout << endl << "You are about to buy 1 ticket of the following type: " << type;

			cout << "The price for your ticket will be: " << ticket_to_buy.priceCalculator(1, type);

			break;
		case 2:
			cout << "Functionality not yet implemented. Now quitting...";
			return 0;
			break;
		case 3:
			cout << "Functionality not yet implemented. Now quitting...";
			return 0;
			break;
		case 4:
			cout << "Functionality not yet implemented. Now quitting...";
			return 0;
			cin >> pass;
			if (pass == "admin") {
				cout << endl << "Welcome to admin mode. Here you can add manually locations and events. Choose an option by typing the corresponding number:";
				cout << endl << "1. Add an event from a file";
				cout << endl << "2. Delete an event";
				cout << endl << "3. Add a location from a file";
				cout << endl << "4. Delete a location";
				switch (option) {
				case 1:
					if (no_events == 10)
						cout << endl << "Maximum number of events reached. Delete an event before trying to create a new one.";
					else {
						cout << endl << "Type in the file name. Make sure the file contains only one event and it is formatted as one value one line in the correct class order.";
						cin >> file_name;
						ifstream inputFile(file_name.c_str(), ios::in);
						
					}

					break;
				case 2:

					break;
				}
			}
			else
				cout << "Wrong password. Restart the app to try again.";
			break;
		case 5:
			cout << "Thank you for checking out the app!";
			return 0;
		default:
			cout << "Wrong input.";
		}
	} while (option != 5);
	
}