#pragma once
#include "Monster.h"
#include <conio.h>

enum Direction { Left = 75, Right = 77, Up = 72, Down = 80 };

class Human : public Monster {
public:
	Human(string n = "�̷��η�", string i = "��", int px = 0, int py = 0)
		: Monster(n, i, px, py) {}
	~Human() { cout << " [Human ]"; }

	void move1(int** map, int maxx, int maxy, char ch) {
		if (ch == Left) p[0]--;
		else if (ch == Right) p[0]++;
		else if (ch == Up) p[1]--;
		else if (ch == Down) p[1]++;
		else return;
		clip(maxx, maxy);
		eat(map);
	}
};