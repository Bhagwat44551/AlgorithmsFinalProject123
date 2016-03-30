/*
 * HashTable.h
 *
 *  Created on: Feb 21, 2016
 *      Author: Christopher
 */

#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include "LinkedList.h"

extern bool** randomMatrix;

template <class T>
class HashTable {
public:
	HashTable(int (*h)(int x, int size), int size) {
		this->h = h;
		this->size = size;
		this->hashTable = new LinkedList<T>*[size];
		for (int i = 0; i < size; i++) {
			this->hashTable[i] = new LinkedList<T>();
		}
	}
	~HashTable() {
		for (int i = 0; i < this->size; i++) {
			delete this->hashTable[i];
		}
		delete this->hashTable;
	}
	void add(T element, int key) {
		this->hashTable[h(key, this->size)]->add(element);
	}
	bool search(T element, int key) {
		T data;
		LinkedList<T>* list = this->hashTable[h(key, this->size)];
		list->reset();
		for (int i = 0; i < list->size(); i++) {
			data = list->getNext();
			if (data == element) {
				return true;
			}
		}
		return false;
	}
private:
	LinkedList<T>** hashTable;
	int (*h)(int x, int size);
	int size;
};

#endif /* HASHTABLE_H_ */
