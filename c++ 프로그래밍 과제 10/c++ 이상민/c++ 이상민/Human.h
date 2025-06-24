#pragma once
#include "Monster.h"
#include <conio.h>
enum Direction { Left = 75, Right = 77, Up = 72, Down = 80 };

class Human : public Monster {
protected:
	char get_ch;
public:
	Human(string name = "미래인류", string icon = "♀", int px = 0, int py = 0) : Monster(name, icon, px, py) { }
	virtual ~Human() { cout << "[Human]"; }

	virtual void move(int** map, int maxx, int maxy, char ch) {
		if (ch == Left) p[0]--;
		else if (ch == Right) p[0]++;
		else if (ch == Up) p[1]--;
		else if (ch == Down) p[1]++;
		else return;
		clip(maxx, maxy);
		eat(map);
	}
};

class Tuman :public Human {
public:
	Tuman(string name = "투사람", string icon = "♂", int px = 0, int py = 0) :Human(name, icon, px, py) { }
	virtual ~Tuman() { cout << "[Tuman]"; }

	virtual void move(int** map, int maxx, int maxy, char ch) {
		if (ch >= Up && ch <= Down) {
			Human::move(map, maxx, maxy, ch);
		}
		else {
			if (ch == 'a' || ch == 'A') p[0]--;
			else if (ch == 'd' || ch == 'D') p[0]++;
			else if (ch == 'w' || ch == 'W') p[1]--;
			else if (ch == 's' || ch == 'S') p[1]++;
			else return;
		}
		clip(maxx, maxy);
		eat(map);
	}
};