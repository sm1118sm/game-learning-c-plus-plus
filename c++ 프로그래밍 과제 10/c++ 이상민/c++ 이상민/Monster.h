#pragma once
#include "Canvas.h"
#include "Point.h"
#define INIT_ENERGY 50
#define ADD_ENERGY 8

class Monster {
protected:
	string name, icon;
	int x, y, nItem, nEnergy;
	Point p, q;
	int nSleep;
	double dist, total;

	void clip(int maxx, int maxy) { p(maxx, maxy); }

	void eat(int** map) {
		if (map[p.y][p.x] == 1) {
			map[p.y][p.x] = 0;
			nItem++;
			nEnergy += ADD_ENERGY;
		}
		else {
			if (nEnergy > 0) nEnergy--;
		}
		dist += (double)(p - q);
		total += (double)(p - q);
		q = p;
		if (dist > 20.0) {
			dist = 0.0;
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

public:
	static int mCount;

	Monster(string n = "괴물쓰", string i = "※", int px = 0, int py = 0) :name(n), icon(i), p(px, py), q(px, py), nItem(0), nEnergy(INIT_ENERGY), nSleep(0), dist(0.0), total(0.0) {}
	virtual ~Monster() { cout << "\t" << name << " " << icon << " 거리: " << total << endl; }

	void draw(Canvas& canvas) { canvas.draw(p, icon); }
	virtual void move(int** map, int maxx, int maxy) {
		if (!isSleep()) {
			switch (rand() % 8) {
			case 0: p[1]--; break;
			case 1: p[0]++; p[1]--; break;
			case 2: p[0]++; break;
			case 3: p[0]++; p[1]++; break;
			case 4: p[1]++; break;
			case 5: p[0]--; p[1]++; break;
			case 6: p[0]--; break;
			case 7: p[0]--; p[1]--; break;
			}
			clip(maxx, maxy);
			eat(map);
		}
	}
	void print() {

		if (nSleep == 0) {
			cout << "\t" << name << " " << icon << " : " << nItem << "   E : " << nEnergy << "    휴식카운트 : " << nSleep << endl;
		}
		else {
			cout << "\t" << name << " " << icon << " : " << nItem << "   E : " << nEnergy << "    휴식카운트 : " << nSleep << "  ▲ 휴식 중입니다!" << endl;
		}

	}

	int getEnergy() { return nEnergy; }

	static void printCount() {
		cout << "전체 몬스터 수 : " << mCount << endl;
	}
};