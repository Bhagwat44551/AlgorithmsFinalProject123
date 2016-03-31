/*
 * Graph.h
 *
 *  Created on: Mar 30, 2016
 *      Author: Christopher
 */

#ifndef GRAPH_H_
#define GRAPH_H_

template <class T>
class Graph {
private:
	LinkedList<BST<T>*>** adjacencyArray;

public:
	Graph(int nodes) {
		this->adjacencyArray = new LinkedList<BST<T>*>*[nodes];
		for (int i = 0; i < nodes; i++) {
			this->adjacencyArray[i] = new LinkedList<BST<T>*>();
		}
	}
	virtual ~Graph();
	void addNode() {

	}
};

#endif /* GRAPH_H_ */

