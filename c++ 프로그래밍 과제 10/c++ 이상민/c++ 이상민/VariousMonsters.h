#pragma once
#pragma once
#include "Monster.h"

class Zombie : public Monster {
public:
    Zombie(string n = "ÇãÁ¢Á»ºñ", string i = "¡×", int x = 0, int y = 0)
        : Monster(n, i, x, y) {
    }
    ~Zombie() { cout << "Zombie"; }
};

class Vampire : public Monster {
public:
    Vampire(string n = "¹ìÆÄÀÌ¾î", string i = "¡Ú", int x = 0, int y = 0)
        : Monster(n, i, x, y) {
    }
    virtual ~Vampire() { cout << "Vampire"; }

    virtual void move(int** map, int maxx, int maxy) {
        if (!isSleep()) {
            int dir = rand() % 4;
            if (dir == 0)p[0]--;
            else if (dir == 1)p[0]++;
            else if (dir == 2)p[1]--;
            else if (dir == 3)p[1]++;
            clip(maxx, maxy);
            eat(map);
        }

    }
};

class KGhost : public Monster {
public:
    KGhost(string n = "Ã³³à±Í½Å", string i = "¢¾", int x = 0, int y = 0)
        : Monster(n, i, x, y) {
    }
    virtual ~KGhost() { cout << "KGhost"; }

    virtual void move(int** map, int maxx, int maxy) {
        if (!isSleep()) {
            p = Point(rand() % maxx, rand() % maxy);
            clip(maxx, maxy);
            eat(map);
        }

    }
};

class Jiangshi : public Monster {
protected: bool bHori;

public:
    Jiangshi(string n = "´ë·ú°­½Ã", string i = "¡ê", int x = 0, int y = 0, bool bH = true)
        : Monster(n, i, x, y), bHori(bH) {
    }
    virtual ~Jiangshi() { cout << "Jiangshi"; }

    virtual void move(int** map, int maxx, int maxy) {
        if (!isSleep()) {
            int dir = rand() % 2;
            int jump = rand() % 2 + 1;
            if (bHori)p[0] += ((dir == 0) ? -jump : jump);
            else p[1] += ((dir == 0) ? -jump : jump);
            clip(maxx, maxy);
            eat(map);
        }
    }
};

class Smombi : public Monster {
public:
    Smombi(string n = "½º¸öºñ", string i = "¢Í", int x = 0, int y = 0)
        : Monster(n, i, x, y) {
    }
    virtual ~Smombi() { cout << "Smombi"; }

    virtual void move(int** map, int maxx, int maxy) {
        if (!isSleep()) {
            int dir = rand() % 4;
            if (dir == 0)
            {
                p[0]--;
                p[1]++;
            }
            else if (dir == 1)
            {
                p[0]--;
                p[1]--;
            }
            else if (dir == 2)
            {
                p[0]++;
                p[1]++;
            }
            else
            {
                p[0]++;
                p[1]--;
            }
            clip(maxx, maxy);
            eat(map);
        }
    }
};
class Siangshi : public Jiangshi {

public:
    Siangshi(string n = "½´ÆÛ°­½Ã", string i = "¡ê", int x = 0, int y = 0, bool bH = true)
        : Jiangshi(n, i, x, y, bH) {
    }
    virtual ~Siangshi() { cout << "Siangshi"; }
    virtual void move(int** map, int maxx, int maxy) {
        if (!isSleep()) {
            static int a = 1;
            int dir = rand() % 2;
            int jump = rand() % 2 + 1;
            if (a <= 20)
            {
                if (bHori)p[0] += ((dir == 0) ? -jump : jump);
                else p[1] += ((dir == 0) ? -jump : jump);
                clip(maxx, maxy);
                eat(map);
            }
            else
            {
                if (rand() % 2)p[0] += ((dir == 0) ? -jump : jump);
                else p[1] += ((dir == 0) ? -jump : jump);
                clip(maxx, maxy);
                eat(map);
            }
            a++;
        }
    }
};

class sGhost : public KGhost {
public:
    sGhost(string n = "ÀÛÀºÀ¯·É", string i = "¢Ó", int x = 0, int y = 0)
        : KGhost(n, i, x, y) {
    }
    virtual ~sGhost() { cout << "SuperGhost "; }

    virtual void move(int** map, int maxx, int maxy) {
        if (!isSleep()) {
            int a = rand() % 2;
            if (a)
                p[0] = rand() % maxx;
            else
                p[1] = rand() % maxy;
            clip(maxx, maxy);
            eat(map);

        }
    }
};