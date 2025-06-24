#pragma once
#include "Monster.h"

class Zombie : public Monster {
public:
	Zombie(string n = "«„¡¢¡ª∫Ò", string i = "°◊", int x = 0, int y = 0)
		: Monster(n, i, x, y) {}
	~Zombie() { cout << "[Zombie] "; }
};

class Vampire : public Monster {
public:
	Vampire(string n = "πÏ∆ƒ¿ÃæÓ", string i = "°⁄", int x = 0, int y = 0)
		: Monster(n, i, x, y) {}
	virtual ~Vampire() { cout << "[Vampire] "; }

	virtual void move(int** map, int maxx, int maxy) {
		int dir = rand() % 4;
		if (dir == 0) x--;
		else if (dir == 1) x++;
		else if (dir == 2) y--;
		else y++;
		clip(maxx, maxy);
		eat(map);
	}
};

class KGhost : public Monster {
public:
	KGhost(string n = "√≥≥‡±ÕΩ≈", string i = "¢æ", int x = 0, int y = 0)
		: Monster(n, i, x, y) {}
	virtual ~KGhost() { cout << "[KGhost] "; }

	virtual void move(int** map, int maxx, int maxy) {
		x = rand() % maxx;
		y = rand() % maxy;
		clip(maxx, maxy);
		eat(map);
	}
};

class Jiangshi : public Monster {
protected:
	bool	bHori;

public:
	Jiangshi(string n = "¥Î∑˙∞≠Ω√", string i = "°Í", int x = 0, int y = 0, bool bH = true)
		: Monster(n, i, x, y), bHori(bH) {}
	virtual ~Jiangshi() { cout << "[Jiangshi] "; }

	virtual void move(int** map, int maxx, int maxy) {
		int dir = rand() % 2;
		int jump = rand() % 2 + 1;
		if (bHori) x += ((dir == 0) ? -jump : jump);
		else y += ((dir == 0) ? -jump : jump);
		clip(maxx, maxy);
		eat(map);
	}
};

class Smombi : public Monster {
public:
	Smombi(string n = "Ω∫∏ˆ∫Ò", string i = "¢¬", int x = 0, int y = 0)
		:Monster(n, i, x, y) {}
	virtual ~Smombi() { cout << "[Smombi] "; }

	virtual void move(int** map, int maxx, int maxy) {
		int dir = rand() % 2;
		int jump = rand() % 2;
		(dir == 0) ? (x -= 1) : (x += 1);
		(jump == 0) ? (y -= 1) : (y += 1);
		if (x < 0) x = 1;
		if (x >= maxx) x = maxx - 2;
		if (y < 0) y = 1;
		if (y >= maxy) y = maxy - 2;
		eat(map);
	}
};

class Siangshi : public Jiangshi {
public:
	Siangshi(string n = "Ω¥∆€∞≠Ω√", string i = "°Í", int x = 0, int y = 0, bool bH = true)
		:Jiangshi(n, i, x, y, bH) {}
	virtual ~Siangshi() { }

	virtual void move(int** map, int maxx, int maxy) {
		if (nEnergy == 30 || nEnergy == 70 || nEnergy == 90) {
			if (bHori == true) bHori = false;
			else bHori = true;
		}
		int dir = rand() % 2;
		int jump = rand() % 2 + 1;
		if (bHori) x += ((dir == 0) ? -jump : jump);
		else y += ((dir == 0) ? -jump : jump);
		clip(maxx, maxy);
		eat(map);
	}
};

class sGhost : public KGhost {
public:
	sGhost(string n = "¿€¿∫¿Ø∑…", string i = "¢”", int x = 0, int y = 0)
		: KGhost(n, i, x, y) {}
	virtual ~sGhost() { }

	virtual void move(int** map, int maxx, int maxy) {
		int a = rand() % 2;
		if (a)
			x = rand() % maxx;
		else
			y = rand() % maxy;
		clip(maxx, maxy);
		eat(map);

	}
};