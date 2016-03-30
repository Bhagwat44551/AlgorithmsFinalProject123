/*
 * Queue.h
 *
 *  Created on: Feb 19, 2016
 *      Author: Christopher
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include <iostream>
using namespace std;
#include "LinkedList.h"

template <class T>
class Queue {
private:
	Node<T>* front;
	Node<T>* rear;
	int numElements;
public:
	Queue() {
		this->front = NULL;
		this->rear = NULL;
		this->numElements = 0;
	}
	void enqueue(T element) {
		Node<T>* newNode = new Node<T>(element);
		if (this->rear == NULL) {
			this->front = newNode;
		} else {
			this->rear->setLink(newNode);
		}
		this->rear = newNode;
		this->numElements++;
	}

	T dequeue() {
		T data = this->front->getData();
		Node<T>* toBeDeleted = this->front;
		this->front = this->front->getLink();
		delete toBeDeleted;
		this->numElements--;
		return data;
	}

	bool isEmpty() {
		return this->numElements == 0;
	}

	int size() {
		return this->numElements;
	}
};



#endif /* QUEUE_H_ */
