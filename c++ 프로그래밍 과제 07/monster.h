#pragma once
#include "Canvas.h"
#include <conio.h>

#define DIM 40

class Monster {

    string name, icon;
    int x, y, nItem;
    int nEnergy;

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
        else
        {
            if (nEnergy > 0)
                nEnergy--;
        }
    }

public:

    static int mon;

    Monster(string n = "나괴물", string i = "※", int px = 0, int py = 0)
        : name(n), icon(i), x(px), y(py), nItem(0), nEnergy(100) {
        mon++;
    }

    ~Monster()
    {
        cout << "\t" << name << icon << " 물러갑니다~~~\n";
        mon--;
    }

    void draw(Canvas& canvas) { canvas.draw(x, y, icon); }

    void move(int** map, int maxx, int maxy) {
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

    int getEnergy()
    {
        return nEnergy;
    }

    void print() { cout << "\t" << name << icon << ":" << nItem << " E:" << nEnergy << endl; }

    static void printCount()
    {
        cout << "\t전체몬스터 수:" << mon << "\n";
    }

};