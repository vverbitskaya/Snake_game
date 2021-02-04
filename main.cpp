#include "snake.hpp"

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
		bool b = false;
		s.makeStep(b);
		displaySnake(s);
		std::getchar();
	}

	return 0;
}
