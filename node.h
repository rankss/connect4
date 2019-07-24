#ifndef NODE
#define NODE

#include <atomic>
#include <algorithm>
#include <cstdlib>
#include "c4.h"

template <typename T>
class node {
private:
	T* data;
	
	std::atomic< node<T> *> child;
	std::vector< node<T> *> children;

	std::atomic<int> score, total;
	short move;

public:
	node();
	node(const node<T> &n);
	~node();

	T* getData();
	node<T>* getChild();
	void setChild(node<T> *n);
	void addChild(node<T> *n);
	std::vector< node<T> *> getChildren();
	int getScore();
	void setScore(int s);
	int getMove();
	void setMove(short m);

	bool find(node<T> *n);
};

#endif
