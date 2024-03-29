#include "node.h"

template <typename T>
node<T>::node() {
	data = new T();
	child = nullptr;
	score = 0;
	total = 0;
	move = -1;
}

template <typename T>
node<T>::node(const node<T> &n) {
	data = new T();
	*data = *n.data;
	child = nullptr;
	score = 0;
	total = 0;
	move = n.move;
}

template <typename T>
node<T>::~node() {
	delete data;
	delete child;
	for (node<T> *child : children)
		delete child;
}

template <typename T>
T* node<T>::getData() {
	return data;
}

template <typename T>
node<T>* node<T>::getChild() {
	return child;
}

template <typename T>
void node<T>::setChild(node<T> *n) {
	if (child != nullptr) {
		delete child;
		child = nullptr;
	}
	child = n;
}

template <typename T>
void node<T>::addChild(node<T> *n) {
	children.push_back(n);
}

template <typename T>
std::vector< node<T> *> node<T>::getChildren() {
	return children;
}

template <typename T>
void node<T>::setChildren(std::vector< node<T> *> v) {
	children = v;
}

template <typename T>
int node<T>::getScore() {
	return score;
}

template <typename T>
void node<T>::setScore(int s) {
	score = s;
}

template <typename T>
U8 node<T>::getMove() {
	return move;
}

template <typename T>
void node<T>::play(U8 col) {
	move = col;
	data->play(col);
}

template <typename T>
int node<T>::findMax() {
	int m = -10000000, idx = -1;
	for (uint i = 0; i < children.size(); i++) {
		if (children[i]->getScore() > m) {
			m = children[i]->getScore();
			idx = i;
		}
	}
	return idx;
}

template <typename T>
int node<T>::findMin() {
	int m = 10000000, idx = -1;
	for (uint i = 0; i < children.size(); i++) {
		if (children[i]->getScore() < m) {
			m = children[i]->getScore();
			idx = i;
		}
	}
	return idx;
}

template class node<c4>;
