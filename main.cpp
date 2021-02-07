#include "snake.hpp"
#include <thread>
#include <conio.h>

void displaySnake(const Snake& s, Apple& a) {
	for (int y = 0; y <= 20; y++) {
		for (int x = 0; x <= 200; x++) {
			position posit;
			posit.x = x;
			posit.y = y;

			position applePosit = a.GetPosition();
			if (s.isHeadHere(posit) == true) {
				std::cout << "X";
			}
			else if (s.isBodyHere(posit) == true) {
				std::cout << "o";
			}
			else if (applePosit.x == posit.x && applePosit.y == posit.y) {
				std::cout << "A";
			}
			else {
				std::cout << " ";
			}
		}
		std::cout << "\n";
	}
}
direction dir = right;

void userInput() {
	while (true) {
		int key = getche();
		if (key == 75) {
			dir = left;
		}
		else if (key == 72) {
			dir = up;
		}
		else if (key == 80) {
			dir = down;
		}
		else if (key == 77) {
			dir = right;
		}
	}
}

int main () {
	AppleGenerator g(20, 25);
	Apple a = g.create();

	std::cout << "Hello" << std::endl;
	std::thread thr(&userInput);
	Snake s;
	displaySnake(s, a);
	while (true) {
		bool b = true;
		s.changeDir(dir);
		s.makeStep(b);
		displaySnake(s, a);
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		a = g.create();
	}

	userInput();
	return 0;
}
