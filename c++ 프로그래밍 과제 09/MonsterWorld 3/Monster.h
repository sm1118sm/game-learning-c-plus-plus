#pragma once
#include "Canvas.h"
#define DIM 40

class Monster {
protected:
	string name, icon;
	int x, y, nItem, nEnergy;

	void clip(int maxx, int maxy) {
		if (x < 0) x = 0;
		if (x >= maxx) x = maxx - 1;
		if (y < 0) y = 0;
		if (y >= maxy) y = maxy - 1;
	}

	void eat(int** map) {
		if (map[y][x] == 1) {
			map[y][x] = 0;
			nItem++;
			nEnergy += 8;
		}
		else { nEnergy -= 1; }
	}

public:
	static int nMonster;
	Monster(string n = "나괴물", string i = "※", int px = 0, int py = 0)
		: name(n), icon(i), x(px), y(py), nItem(0), nEnergy(50) {
		nMonster += 1;
	}
	virtual ~Monster() {
		nMonster -= 1;
		if (nEnergy < 1) {
			cout << "Monster 하나가 굶어죽습니다.\n게임을 계속 진행하려면 엔터를 누르세요\n";
			getchar();
		}
		else cout << " " << name << icon << " 물러갑니다~~~\n";
	}

	void draw(Canvas& canvas) { canvas.draw(x, y, icon); }
	virtual void move(int** map, int maxx, int maxy) {
		switch (rand() % 8) {
		case 0: y--; break;
		case 1: x++; y--; break;
		case 2: x++; break;
		case 3: x++; y++; break;
		case 4: y++; break;
		case 5: x--; y++; break;
		case 6: x--; break;
		case 7: x--; y--; break;
		}
		clip(maxx, maxy);
		eat(map);
	}

	void print() { cout << "\t" << name << icon << ":" << nItem << " E:" << nEnergy << endl; }
	int getEnergy() { return nEnergy; }
	static void printCount() { cout << "   전체 몬스터의 수 : " << nMonster << endl; };
};