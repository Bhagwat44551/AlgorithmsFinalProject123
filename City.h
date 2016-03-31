#pragma once


/*
* City.h
*
*  Created on: March 30, 2016
*      Author: Diego Toledo
*/

#ifndef CITY_H_
#define CITY_H_

#include <iostream>
#include <string>
using namespace std;
#include "LinkedList.h"

class City {
private:
	LinkedList<BST<Flight*>*>* neighbors;
	string name;

public:
	City(string name) {
		this->name = name;
		this->neighbors = new LinkedList<BST<Flight>> > ();
	}
};

#endif
