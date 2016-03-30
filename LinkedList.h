/*
 * LinkedList.h
 *
 *  Created on: Feb 19, 2016
 *      Author: Christopher
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <iostream>
using namespace std;
#include "LinkedList.h"
#include "Node.h"

template <class T>
class LinkedList {
public:
	LinkedList() {
		this->list = NULL;
		this->iterator = NULL;
		this->numElements = 0;
	}
	virtual ~LinkedList() {

	}
	void add(T element) {
		Node<T>* newNode = new Node<T>(element);
		newNode->setLink(this->list);
		this->list = newNode;
		this->numElements++;
	}
	T pop() {
		T data = this->list->getData();
		Node<T>* toBeDeleted = this->list;
		this->list = this->list->getLink();
		this->numElements--;
		delete toBeDeleted;
		//cout << data << endl;
		return data;
	}
	T getNext() {
		T data = this->iterator->getData();
		if (this->iterator->getLink() == NULL) {
			this->reset();
		} else {
			this->iterator = this->iterator->getLink();
		}
		return data;
	}
	void reset() {
		this->iterator = this->list;
	}
	int size() {
		return this->numElements;
	}

private:
	Node<T>* list;
	int numElements;
	Node<T>* iterator;
};

#endif /* LINKEDLIST_H_ */
