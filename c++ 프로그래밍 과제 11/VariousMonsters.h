#pragma once
#include "Monster.h"

class Zombie : public Monster {
public:
	Zombie(string n = "ÇãÁ¢Á»ºñ", string i = "¡×", int x = 0, int y = 0)
		: Monster(n, i, x, y) {}
	~Zombie() { cout << " Zombie"; }
};

class Vampire : public Monster {
public:
	Vampire(string n = "¹ìÆÄÀÌ¾î", string i = "¡Ú", int x = 0, int y = 0)
		: Monster(n, i, x, y) {}
	~Vampire() { cout << " Vampire"; }

	void move(int** map, int maxx, int maxy) {
		int dir = rand() % 4;
		if (dir == 0) p[0]--;
		else if (dir == 1) p[0]++;
		else if (dir == 2) p[1]--;
		else p[1]++;
		clip(maxx, maxy);
		eat(map);
	}
};

class KGhost : public Monster {
public:
	KGhost(string n = "Ã³³à±Í½Å", string i = "¢¾", int x = 0, int y = 0)
		: Monster(n, i, x, y) {}
	~KGhost() { cout << " KGhost"; }

	void move(int** map, int maxx, int maxy) {
		if (!isSleep()) {
			p = Point(rand() % maxx, rand() % maxy);
			clip(maxx, maxy);
			eat(map);
		}
	}
};

class Jiangshi : public Monster {
protected:
	bool	bHori;
public:
	Jiangshi(string n = "´ë·ú°­½Ã", string i = "¡ê", int x = 0, int y = 0, bool bH = true)
		: Monster(n, i, x, y), bHori(bH) {}
	~Jiangshi() { cout << " Jiangshi"; }

	void move(int** map, int maxx, int maxy) {
		int dir = rand() % 2;
		int jump = rand() % 2 + 1;
		if (bHori) p[0] += ((dir == 0) ? -jump : jump);
		else p[1] += ((dir == 0) ? -jump : jump);
		clip(maxx, maxy);
		eat(map);
	}
};

class Smombi : public Monster {
public:
	Smombi(string n = "½º¸öºñ", string i = "¢Â", int x = 0, int y = 0)
		:Monster(n, i, x, y) {}
	~Smombi() { cout << "Smombi"; }

	void move(int** map, int maxx, int maxy) {
		int dir = rand() % 2;
		int jump = rand() % 2;
		(dir == 0) ? (x -= 1) : (y += 1);
		(jump == 0) ? (p[1] -= 1) : (p[1] += 1);
		if (x < 0) p[0] = 1;
		if (x >= maxx) p[0] = maxx - 2;
		if (y < 0) p[1] = 1;
		if (y >= maxy) p[1] = maxy - 2;
		eat(map);
	}
};

class Siangshi : public Jiangshi {
public:
	Siangshi(string n = "½´ÆÛ°­½Ã", string i = "¢¸", int x = 0, int y = 0, bool bH = true)
		:Jiangshi(n, i, x, y, bH) {}
	~Siangshi() { cout << "Siangshi"; }

	void move(int** map, int maxx, int maxy) {
		if (nEnergy == 30 || nEnergy == 70 || nEnergy == 90) {
			if (bHori == true) bHori = false;
			else bHori = true;
		}
		int dir = rand() % 2;
		int jump = rand() % 2 + 1;
		if (bHori) p[0] += ((dir == 0) ? -jump : jump);
		else p[1] += ((dir == 0) ? -jump : jump);
		clip(maxx, maxy);
		eat(map);
	}
};

class Myhost : public KGhost {
public:
	Myhost(string n = "³»°¡ ¸¸µç ±Í½Å", string i = "¢½", int x = 0, int y = 0)
		: KGhost(n, i, x, y) {}
	~Myhost() { cout << " Myhost"; }

	void move(int** map, int maxx, int maxy) {
		p[0] = (rand() % (maxx - 2)) + 1;
		p[1] = (rand() % (maxy - 2)) + 1;
		clip(maxx, maxy);
		eat(map);
	}
};