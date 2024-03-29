#include "minimax.h"

template <typename T>
minimax<T>::minimax() {
	root = new node<T>();
	first = rand() % 2;
}

template <typename T>
minimax<T>::~minimax() {
	delete root;
}

template <typename T>
void minimax<T>::populate(node<T> *n, int d) {
	// Populates tree until depth d
	if (d == 0 || n->getData()->result(first, false)) {
		//n->getData()->display();
		return;
	}

	node<T> *c;
	for (U8 m : root->getData()->possible()) {
		c = new node<T>(*n);
		c->play(m);
		//c->getData()->display();
		n->addChild(c);
		populate(c, d - 1);
	}
	return;
}

template <typename T>
int minimax<T>::iterate() {
	return 0;
}

template <typename T>
int minimax<T>::alphabeta(node<T> *n, int a, int b, bool maxPlayer) {
	if (n->getChildren().empty()) {
		// n->getData()->display();
		// std::cout << n->getData()->heuristic(first) << std::endl;
		return n->getData()->heuristic();
	}

	int value;
	if (maxPlayer) {
		value = INT_MIN;
		for (node<T> *c : n->getChildren()) {
			value = std::max(value, alphabeta(c, a, b, false));
			a = std::max(a, value);
			n->setScore(a);
			if (a >= b) break;
		}
	} else {
		value = INT_MAX;
		for (node<T> *c : n->getChildren()) {
			value = std::min(value, alphabeta(c, a, b, true));
			b = std::min(b, value);
			n->setScore(b);
			if (a >= b) break;
		}
	}

	return value;
}

template <typename T>
node<T>* minimax<T>::getRoot() {
	return root;
}

template <typename T>
bool minimax<T>::getFirst() {
	return first;
}

template <typename T>
void minimax<T>::select() {
	// AI move
	int idx = -1;
	populate(root, 7);
	alphabeta(root, INT_MIN, INT_MAX, first);
	for (node<T> *c : root->getChildren()) {
		if (c->getChildren().empty()) {
			// Winning move
			//std::cout << "here" << std::endl;
			std::cout << "AI chose: " << c->getMove() << std::endl;
			node<T> *n = new node<c4>(*c);
			delete root;
			root = n;
			return;
		}
	}

	if (first)
		idx = root->findMax();
	else
		idx = root->findMin();

	std::cout << "AI chose: " << root->getChildren()[idx]->getMove() << std::endl;
	node<T> *n = new node<c4>(*root->getChildren()[idx]);
	delete root;
	root = n;
}

template <typename T>
void minimax<T>::play() {
	// Player move
	std::vector<U8> moves = root->getData()->possible();
	std::cout << "Player's turn" << std::endl;

	U8 m;
	std::cout << "Please choose a move: ";
	while (std::cin >> m && std::find(moves.begin(), moves.end(), m) == moves.end())
		std::cout << "Please choose a valid move: ";

	root->play(m);
}

template class minimax<c4>;
