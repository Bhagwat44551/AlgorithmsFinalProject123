/*
 * BSTNode.h
 *
 *  Created on: Mar 29, 2016
 *      Author: Christopher
 */

#ifndef BSTNODE_H_
#define BSTNODE_H_
#include <iostream>

template <class T>
class BSTNode {
private:
	T data;
	BSTNode<T>* left;
	BSTNode<T>* right;
public:
	BSTNode(T data) {
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
	virtual ~BSTNode() {

	}
	void setLeft(BSTNode<T>* left) {
		this->left = left;
	}
	void setRight(BSTNode<T>* right) {
		this->right = right;
	}
	BSTNode<T>*  getLeft() {
		return this->left;
	}
	BSTNode<T>* getRight() {
		return this->right;
	}
	T getData() {
		return this->data;
	}
	void setData(T data) {
		this->data = data;;
	}
};

#endif /* BSTNODE_H_ */

