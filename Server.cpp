#include <iostream>
#include <exception>
#include "Network.h"
#include "Flight.h"
#include "City.h"

using namespace std;

void displayMenu();
void performOperation(char* buffer);

Network* server;

int main() {
	int port;
	bool validPort = false;
	cout << "Initializing server daemon" << endl;
	cout << "Type port to enable on server (tcp)" << endl;
	do {
		try {
			cin >> port;
			server = new Network(SERVER, port);
			validPort = true;
		} catch (exception* e) {
			cout << e->what() << endl;
			cout << "Please try to free the port or type another port" << endl;
		}
	} while (!validPort);
	server->listenForConnecctions();
	server->acceptConnection();

	while (server->listening()) {
		do {
			displayMenu();
			performOperation(server->getBuffer());
		} while(server->onConnection());
		server->acceptConnection();
	}

//	Closing Sockets

	server->closeNetwork();

	cout << "\n\nBye!" << endl;

	return 0;
}

void displayMenu() {
	string menu = "";
	menu += "Welcome to Phosphorus Airlines!\n\n";
	menu += "Please select one of the following operations\n";
	menu += "1) Search for a flight between source and destination\n";
	menu += "2) Add a new airport to the database\n";
	menu += "3) Add a new flight to the database\n";
	menu += "4) Display the arrivals board of a certain airport\n";
	menu += "5) Display all destinations from a source airport\n";
	menu += "x) Finish connnection\n";
	menu += "y) Finish connection and kill server\n";
	menu += "\nPlease select a number\n";
	server->sendMessage(menu);
	server->receiveMessage();
}

void performOperation(char* buffer) {
	switch(*buffer) {
	case '1':
		cout << "Flight from x to y" << endl;
		break;
	case '2':
		cout << "Add airport" << endl;
		break;
	case '3':
		cout << "Add flight" << endl;
		break;
	case '4':
		cout << "Display arrivals board" << endl;
		break;
	case '5':
		cout << "Show all destinations of airport x" << endl;
		break;
	case 'x':
		cout << "Finish connection" << endl;
		server->sendMessage("x");
		server->disconnectClient();
		cout << "Listening for new connection" << endl;
		break;
	case 'y':
		cout << "Finish connection" << endl;
		server->sendMessage("x");
		server->closeNetwork();
		cout << "Stopping daemon" << endl;
		cout << "Storing data" << endl;
	default:
		cout << "Please return an answer from the menu" << endl;
		cout << "Server received " << *buffer << endl;
	}
}
