#pragma once


/*
* Graph.h
*
*  Created on: March 30, 2016
*      Author: Diego Toledo
*/

#ifndef GRAPH_H_
#define GRAPH_H_

#include <iostream>
#include <string>
#include <vector>
#include "Graph.h"
#include "Flight.h"

using namespace std;

class Graph {
private:
	vector<City>* neighbors;
	vector<int>* dist;
	vector<int>*prev;
	int size;

public:
	Graph() {
		this->neighbors = name;
		this->neighbors = new LinkedList<BST<Flight>>>();
		this->dist = new vector<int>();
		this->prev = new vector<int>();
		this->size = 0;
	}

	vector<int> Dijkstra(City &start, City &end) {
		priority_queue<int, vector<int>, greater<int> > min_heap;
		vector<int> dist(adjacencyMatrix.size());
		vector<int> prev(adjacencyMatrix.size());

		for (int i = 0; i < dist.size(); i++) {
			dist[i] = numeric_limits<int>::max();
		}
		dist[s] = 0;

		for (int i = 0; i < dist.size(); i++) {
			min_heap.push(dist[i]);
		}

		while (!min_heap.empty()) {
			int u = min_heap.top();
			min_heap.pop();

			for (int v = 0; v < adjacencyMatrix.size(); v++) {
				if (adjacencyMatrix[u][v] != 0) {
					if (dist[v] > dist[u] + adjacencyMatrix[u][v]) {
						dist[v] = dist[u] + adjacencyMatrix[u][v];
						prev[v] = u;
						//decreaseKey (H,u)
					}
				}
			}
		}
	}
};

#endif /* QUEUE_H_ */
