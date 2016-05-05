/*
 * Client.cpp
 *
 *  Created on: 04/05/2016
 *      Author: christopher
 */

#include "Network.h"

using namespace std;

int main(void) {
	int port;
	string ip;
	bool validPort = false;
	Network* client;
	cout << "Type IP address of server" << endl;
	cin >> ip;
	cout << "Type port:" << endl;
	do {
		try {
			cin >> port;
			client = new Network(CLIENT, ip ,port);
			validPort = true;
		} catch (exception* e) {
			cout << e << endl;
			cout << e->what() << endl;
			cout << "Would you like to try again? (port)" << endl;
		}
	} while (!validPort);
	string m;
	cin.ignore();
	do{
		client->receiveMessage();
		if (*client->getBuffer() == 'x') {
			cout << "Closing connection" << endl;
			client->closeNetwork();
			break;
		}
		getline(cin, m);
		cout << "Sending: " << m << endl;
		client->sendMessage(m);
	} while(client->onConnection());

//	Closing Sockets

	client->closeNetwork();

	return 0;
}
