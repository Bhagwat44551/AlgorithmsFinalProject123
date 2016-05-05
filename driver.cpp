/*
 * driver.cpp
 *
 *  Created on: Mar 30, 2016
 *      Author: Christopher
 */

#include <iostream>
#include <cstdlib>
#include "BST.h"

using namespace std;

int main(void) {
	BST<string>* tree = new BST<string>();
	tree->add("Hola");
	tree->add("Adios");
	tree->add("echale");
	tree->add("ganas");
	tree->add("littleDick");
	tree->add("yolo");
	int n = tree->reset(tree->INORDER);
	for (int i = 0; i < n; i++) {
		cout << tree->getNext(tree->INORDER) << endl;
	}
	return 0;
}



