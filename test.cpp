#include "snake.hpp"
#include "gtest/gtest.h"

TEST(SnakeTests, AppleTest) {
	position p;
	p.x = 30;
	p.y = 25;
	Apple a(p);

	ASSERT_EQ(a.GetPosition().x, p.x);
	ASSERT_EQ(a.GetPosition().y, p.y);
}

TEST(SnakeTests, SnakeGoRightTest) {
	position pos;
	pos.x = 30;
	pos.y = 45;
	Snake s(pos);
	s.changeDir(direction::right);
	s.makeStep(false);
	position newPos;
	newPos.x = 31;
	newPos.y = 45;
	bool result = s.areYouHere(newPos); 

	ASSERT_TRUE(result);
}

TEST(SnakeTests, SnakeGoLeftTest) {
	position pos;
	pos.x = 30;
	pos.y = 45;
	Snake s(pos);
	s.changeDir(direction::left);
	s.makeStep(false);
	position newPos;
	newPos.x = 29;
	newPos.y = 45;
	bool result = s.areYouHere(newPos);

	ASSERT_TRUE(result);
}

TEST(SnakeTests, SnakeGoUpTest) {
	position pos;
	pos.x = 30;
	pos.y = 45;
	Snake s(pos);
	s.changeDir(direction::up);
	s.makeStep(false);
	position newPos;
	newPos.x = 30;
	newPos.y = 44;
	bool result = s.areYouHere(newPos);

	ASSERT_TRUE(result);
}

TEST(SnakeTests, SnakeGoDownTest) {
	position pos;
	pos.x = 30;
	pos.y = 45;
	Snake s(pos);
	s.changeDir(direction::down);
	s.makeStep(false);
	position newPos;
	newPos.x = 30;
	newPos.y = 46;
	bool result = s.areYouHere(newPos);

	ASSERT_TRUE(result);
}

int main(int argc, char**argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}