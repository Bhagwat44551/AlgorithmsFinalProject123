/*
 * Node.h
 *
 *  Created on: Feb 19, 2016
 *      Author: Christopher
 */

#ifndef NODE_H_
#define NODE_H_

#include <iostream>
using namespace std;

template <class T>
class Node {
public:
	Node(T element) {
		this->element = element;
		this->next = NULL;
	}
	virtual ~Node() {

	}
	void setLink(Node* node) {
		this->next = node;
	}
	Node* getLink() {
		return this->next;
	}
	T getData() {
		return this->element;
	}
	void setData(T element) {
		this->element = element;
	}
private:
	T element;
	Node* next;
};

#endif /* NODE_H_ */
