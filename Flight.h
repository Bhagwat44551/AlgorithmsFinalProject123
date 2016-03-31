#pragma once


/*
* Flight.h
*
*  Created on: March 30, 2016
*      Author: Diego Toledo
*/

#ifndef FLIGHT_H_
#define FLIGHT_H_

#include <iostream>
using namespace std;

struct Flight{
	int departureTime;
	int arrivalTime;
	int cost;
	int seats;
	int *key;
};

#endif
