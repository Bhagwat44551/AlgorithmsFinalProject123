/*
 * Network.h
 *
 *  Created on: 01/05/2016
 *      Author: christopher
 */

#include <iostream>
#include <exception>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef NETWORK_H_
#define NETWORK_H_

using namespace std;

typedef struct sockaddr_in SocketAddress; //Add meaningful type names to structures
typedef struct sockaddr Address;
typedef enum { SERVER, CLIENT } Type;
const int listenSocket = 0;
const int connectionSocket = 1;

class NetworkException : public exception {
private:
	string details;
public:
	NetworkException(string details) {
		this->details = details;
	}

	virtual const char* what() const throw() {
		return this->details.c_str();
	}
};

class Network {
private:
	int* sockets;
	int port; // TCP/UDP Port number
	int bufferSize;
	char buffer[1024]; //Buffer
	SocketAddress address; //IP Address struct object
	socklen_t size; //Size of the IP Address struct object
	Type type;
public:
	Network(Type type, int port) {
		this->type = type;
		if (this->type == SERVER) {

// ------------------------------------------------- Server Side ----------------------------------------------------------------------

			this->sockets = new int[2];
			this->sockets[listenSocket] = socket(AF_INET, SOCK_STREAM, 0);
			if (this->sockets[listenSocket] < 0) {
				throw new NetworkException("Could not create socket");
			} else {
				cout << "Socket Created" << endl;
			}
			this->port = port;
			this->address.sin_addr.s_addr = htons(INADDR_ANY);
			this->address.sin_port = htons(this->port);
			this->address.sin_family = AF_INET;
			if (bind(this->sockets[listenSocket], (Address*) & this->address, sizeof(this->address)) < 0) {
				throw *(new NetworkException("Could not bind socket"));
			} else {
				cout << "Socket Binded" << endl;
			}
			this->size = sizeof(this->address);
		} else {

// ------------------------------------------------- Client Side ----------------------------------------------------------------------

			this->sockets = new int[1];
			this->sockets[listenSocket] = socket(AF_INET, SOCK_STREAM, 0);
			if (this->sockets[listenSocket] < 0) {
				throw *(new NetworkException("Could not create socket"));
			} else {
				cout << "Socket Created" << endl;
			}
			this->port = port;
			this->address.sin_family = AF_INET;
			this->address.sin_port = htons(this->port);
			if (connect(this->sockets[listenSocket], (Address*) & this->address, sizeof(this->address)) < 0) {
				throw new NetworkException("Could not connect to server on this port");
			} else {
				cout << "Server Found" << endl;
				cout << "Awaiting server response" << endl;
			}
		}
	}
	Network(Type type, string address, int port) {
		this->type = type;
		if (this->type == SERVER) {
			this->sockets = new int[2];
		} else {
			this->sockets = new int[1];
		}
		this->sockets[listenSocket] = socket(AF_INET, SOCK_STREAM, 0);
		if (this->sockets[listenSocket] < 0) {
			cout << "Could not create socket" << endl;
		}
		this->port = port;
		this->address.sin_addr.s_addr = inet_addr(address.c_str());
		this->address.sin_port = htons(this->port);
		this->address.sin_family = AF_INET;
		if (connect(this->sockets[listenSocket], (Address*) & this->address, sizeof(this->address)) < 0) {
			cout << "Could not connect socket to address" << endl;
			exit(-1);
		} else {
			cout << "Connection Done with IP" << endl;
		}
		this->size = sizeof(this->address);
	}
	virtual ~Network() {

	}
	void listenForConnecctions() {
		cout << "Listening for connections" << endl;
		listen(this->sockets[listenSocket], 1);
	}
	void acceptConnection() {
		this->sockets[connectionSocket] = accept(this->sockets[listenSocket], (Address*) & this->address, &(this->size));
		if (this->sockets[connectionSocket] < 0) {
			cout << "Connection was not successful" << endl;
			exit(-1);
		} else {
			cout << "Connection with client established" << endl;
		}
	}
	void sendMessage(string message) {
		if (this->type == SERVER) {
			send(this->sockets[connectionSocket], message.c_str(), 1024, 0);
		} else {
			send(this->sockets[listenSocket], message.c_str(), 1024, 0);
		}
	}
	void receiveMessage() {
		this->clearBuffer();
		if (this->type == SERVER) {
			recv(this->sockets[connectionSocket], this->buffer, 1024, 0);
		} else {
			recv(this->sockets[listenSocket], this->buffer, 1024, 0);
		}
		cout << this->buffer <<  endl;
	}

	bool onConnection() {
		if (this->type == SERVER) {
			return (this->sockets[connectionSocket] > 0);
		} else {
			return (this->sockets[listenSocket] > 0);
		}
	}

	bool listening() {
		if (this->type == SERVER) {
			return (this->sockets[listenSocket] > 0);
		} else {
			return false;
		}
	}

	void clearBuffer() {
		for (int i = 0; i < 1024; i++) {
			this->buffer[i] = (char) 0;
		}
	}

	void closeNetwork() {
		close(this->sockets[listenSocket]);
		this->sockets[listenSocket] = -1;
		if (this->type == SERVER) {
			close(this->sockets[connectionSocket]);
			this->sockets[connectionSocket] = -1;
		}
	}
	void disconnectClient() {
		if (this->type == SERVER) {
			close(this->sockets[connectionSocket]);
			this->sockets[connectionSocket] = -1;
		} else {
			cout << "Operation not permitted" << endl;
		}
	}

	char* getBuffer() {
		return this->buffer;
	}
};

#endif /* NETWORK_H_ */
