#include <iostream>
#include <deque>

struct position {
	int x;
	int y;
};

class Apple {
public:
	Apple() {
		this->value = 1;
		this->pos.x = 0;
		this->pos.y = 0;
	}
	Apple(position p) {
		pos.x = p.x;
		pos.y = p.y;
		value = 1;
	}
	Apple(position p, int v) {
		pos.x = p.x;
		pos.y = p.y;
		value = v;
	}
	position GetPosition() const{
		return pos;
	}
	int GetValue() const{
		return value;
	}
private:
	position pos;
	int value;
};

enum direction {
	up, down, left, right
};

class Snake {
public:
	Snake() {
		dir = right;
		head.x = 10;
		head.y = 10;
	}
private:
	std::deque<position> body;
	position head;
	direction dir;

public:
	void makeStep() {
		if (dir==up) {
			head.y -= 1;
		}
		else if (dir == down) {
			head.y += 1;
		}
		else if (dir == left) {
			head.x -= 1;
		}
		else {
			head.x += 1;
		}
	};

	void changeDir(direction d) {
		dir = d;
	}

	bool areYouHere(position p) const{
		if (head.x == p.x && head.y == p.y) {
			return true;
		}
		return false;
	}
};

void displaySnake(const Snake& s) {
	for (int y = 0; y <= 20; y++) {
		for (int x = 0; x <= 20; x++) {
			position posit;
			posit.x = x;
			posit.y = y;
			bool SnakeHere = s.areYouHere(posit);
			if (SnakeHere == true) {
				std::cout << "X";
			}
			else {
				std::cout << " ";
			}
		}
		std::cout << "\n";
	}
}

int main () {
	std::cout << "Hello" << std::endl;
	Snake s;
	displaySnake(s);
	for (int i = 0; i <= 10; i++) {
		s.makeStep();
		displaySnake(s);
		std::getchar();
	}

	return 0;
}