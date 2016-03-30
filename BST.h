/*
 * BST.h
 *
 *  Created on: Mar 29, 2016
 *      Author: Christopher
 */

#ifndef BST_H_
#define BST_H_
#include "BSTNode.h"
#include "Queue.h"

template <class T>
class BST {
private:
	BSTNode<T>* root;
	int size;
	bool found;
	Queue<T> *preorder, *postorder, *inorder;
	T getPredeccesor(BSTNode<T>* node) {
		while(node->getRight() != NULL) {
			node = node->getRight();
		}
		return node->getData();
	}
	BSTNode<T>* removeNode(BSTNode<T>* node) {
		if (node->getLeft() == NULL) {
			return node->getRight();
		} else if (node->getRight()) {
			return node->getLeft();
		} else {
			T data = this->getPredeccesor(node->getLeft());
			node->setData(data);
			node->setLeft(this->recursiveRemove(data, node->getLeft()));
			return node;
		}
	}
	BSTNode<T>* recursiveAdd(T element, BSTNode<T>* tree) {
		if (tree == NULL) {
			tree = new BSTNode<T>(element);
		} else if (tree->getData() >= element) {
			tree->setLeft(this->recursiveAdd(element, tree->getLeft()));
		} else {
			tree->setRight(this->recursiveAdd(element, tree->getRight()));
		}
		return tree;
	}
	BSTNode<T>* recursiveRemove(T element, BSTNode<T>* tree) {
		if (tree == NULL) {
			this->found = false;
		} else if (tree->getData() > element) {
			tree->setLeft(this->recursiveRemove(element, tree->getLeft()));
		} else if (tree->getData < element){
			tree->getLeft(this->recursiveRemove(element, tree->getRight()));
		} else {
			tree = this->removeNode(tree);
			this->found = true;
		}
		return tree;
	}
	void preOrder(BSTNode<T>* tree) {
		if (tree != NULL) {
			this->preorder->enqueue(tree->getData());
			this->preOrder(tree->getLeft());
			this->preOrder(tree->getRight());
		}
	}
	void inOrder(BSTNode<T>* tree) {
		if (tree != NULL) {
			this->inOrder(tree->getLeft());
			this->inorder->enqueue(tree->getData());
			this->inOrder(tree->getRight());
		}
	}
	void postOrder(BSTNode<T>* tree) {
		if (tree != NULL) {
			this->postOrder(tree->getLeft());
			this->postOrder(tree->getRight());
			this->postorder->enqueue(tree->getData());
		}
	}
public:
	int const PREORDER = 0;
	int const INORDER = 1;
	int const POSTORDER = 2;
	BST() {
		this->size = 0;
		this->root = NULL;
		this->found = false;
		this->preorder = NULL;
		this->inorder = NULL;
		this->postorder = NULL;
	}
	~BST() {
		delete this->root;
	}
	void add(T element) {
		this->root = this->recursiveAdd(element, this->root);
		this->size++;
	}
	bool remove(T element) {
		this->root = this->recursiveRemove(element, this->root());
		if (this->found) {
			this->size--;
		}
		return this->found;
	}
	int reset(int order) {
		switch(order) {
			case 0:
				this->preorder = new Queue<T>();
				this->preOrder(this->root);
				break;
			case 1:
				this->inorder = new Queue<T>();
				this->inOrder(this->root);
				break;
			case 2:
				this->postorder = new Queue<T>();
				this->postOrder(this->root);
				break;
		}
		return this->size;
	}
	T getNext(int order) {
		switch (order) {
		case 0:
			return this->preorder->dequeue();
		case 1:
			return this->inorder->dequeue();
		case 2:
			return this->postorder->dequeue();
		}
		return NULL;
	}
};

#endif /* BST_H_ */

