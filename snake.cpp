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

void Snake::changeDir(direction d) {
		dir = d;
	}

bool Snake::areYouHere(position p) const{
		if (head.x == p.x && head.y == p.y) {
			return true;
		}
		return false;
	}
