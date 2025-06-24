#pragma once
#include "Canvas.h"
#include "Point.h"

class Monster {
public:
	string name, icon;
	int x, y, nItem, nEnergy;
	Point q, p;
	int nSleep;
	double dist;
	double total;

	void clip(int maxx, int maxy) { p(maxx, maxy); }

	void eat(int** map) {
		if (map[p.y][p.x] == 1) {
			map[p.y][p.x] = 0;
			nItem++;
			nEnergy += 8;
		}
		else { nEnergy -= 1; }
		dist += (double)(p - q);
		total += (double)(p - q);
		q = p;
		if (dist > 20) {
			dist = 0;
			nSleep = 10;
		}
	}

	bool isSleep() {
		if (nSleep > 0) {
			nSleep--;
			return true;
		}
		else return false;
	}

	static int nMonster;
	Monster(string n = "무명괴물", string i = "※", int x = 0, int y = 0)
		: name(n), icon(i), nItem(0), nEnergy(50), p(x, y), q(x, y), nSleep(0), dist(0.0), total(0.0) {
		nMonster += 1;
	}
	~Monster() {
		cout << "\t" << name << icon << " 물러갑니다~~~\n";
	}

	void draw(Canvas& canvas) { canvas.draw(p, icon); }
	virtual void move(int** map, int maxx, int maxy) {
		if (!isSleep()) {
			int num = rand() % 9 + 1;	// 1 ~ 9
			p += Point(num % 3 - 1, num / 3 - 1);
			clip(maxx, maxy);
			eat(map);
		}
	}

	void print() { cout << "\t" << name << icon << ":" << nItem << " E:" << nEnergy << endl; }
	int getEnergy() { return nEnergy; }
	static void printCount() { cout << "   전체 몬스터의 수" << nMonster << endl; };
};