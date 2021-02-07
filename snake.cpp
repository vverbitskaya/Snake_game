#include "snake.hpp"

Apple::Apple() {
		this->value = 1;
		this->pos.x = 0;
		this->pos.y = 0;
	}
	
Apple::Apple(position p) {
		pos.x = p.x;
		pos.y = p.y;
		value = 1;
	}
Apple::Apple(position p, int v) {
		pos.x = p.x;
		pos.y = p.y;
		value = v;
	}
position Apple::GetPosition() const{
		return pos;
	}
int Apple::GetValue() const{
		return value;
	}
	
Snake::Snake() {
		dir = right;
		head.x = 10;
		head.y = 10;
	}
Snake::Snake(position h) {
	dir = right;
	head.x = h.x;
	head.y = h.y;
}

void Snake::makeStep(bool withGrow) {
	position newElement = head;
	body.push_back(newElement);

	switch (dir) {
		case up:
			head.y -= 1;
			break;
		case down:
			head.y += 1;
			break;
		case left:
			head.x -= 1;
			break;
		case right:
			head.x += 1;
			break;
		default:
			break;
	}
	if (withGrow != true) {
		body.pop_front();
	}

};

Apple AppleGenerator::create() {
	int resultX = rand() % maxWidth;
	int resultY = rand() % maxHeight;
	position p;
	p.x = resultX;
	p.y = resultY;
	Apple a(p);

	return a;
}
AppleGenerator::AppleGenerator(int width, int height) {
	maxWidth = width;
	maxHeight = height;
}

void Snake::changeDir(direction d) {
		dir = d;
	}

bool Snake::areYouHere(position p) const{
		if (isHeadHere(p) || isBodyHere(p)) {
			return true;
		}

		return false;
	}

bool Snake::isHeadHere(position p) const {
	if (head.x == p.x && head.y == p.y) {
		return true;
	}
	return false;
}

bool Snake::isBodyHere(position p) const {
	for (int counter = 0; counter < body.size(); counter++) {
		position temp = body[counter];
		if (temp.x == p.x && temp.y == p.y) {
			return true;
		}
	}
	return false;
}



