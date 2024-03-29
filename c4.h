#ifndef C4
#define C4

#include <iostream>
#include <cstring>
#include <vector>
#include "heuristics.h"

class c4 {
private:
	U64 curr, mask;
	U8 moves;
	U8 track[WIDTH];
	bool zug;

	U64 bottom_mask(U8 col);
	U64 top_mask(U8 col);
	bool playable(U8 col);
	bool alignment(U64 c);
	bool draw(U64 c);

	void getZug();
	void giveZug();

	int heuristic_fp();
	int heuristic_sp();

public:
	c4();
	~c4();

	void setZug(bool z);
	U8 getMoves();

	void play(U8 col);
	int result(bool t, bool p);
	int heuristic();

	std::vector<U8> possible();

	void display();
};

#endif