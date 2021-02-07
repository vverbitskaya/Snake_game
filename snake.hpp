#include <iostream>
#include <deque>

struct position {
	int x;
	int y;
};

class Apple {
public:
	Apple();
	Apple(position p);
	Apple(position p, int v);
	position GetPosition() const;
	int GetValue() const;
private:
	position pos;
	int value;
};

class AppleGenerator {
	int maxWidth = 50;
	int maxHeight = 50;
public:
	AppleGenerator(int w, int h);
	Apple create();
};

enum direction {
	up, down, left, right
};

class Snake {
public:
	Snake();
	Snake(position h);
private:
	std::deque<position> body;
	position head;
	direction dir;

public:
	void makeStep(bool withGrow);

	void changeDir(direction d);

	bool areYouHere(position p) const;

	bool isHeadHere(position p) const;

	bool isBodyHere(position p) const;
};
