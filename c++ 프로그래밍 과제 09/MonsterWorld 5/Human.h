#pragma once
#include "Monster.h"
#include <conio.h>
enum Direction { Left = 75, Right = 77, Up = 72, Down = 80 };
class Human : public Monster {
public:
    Human(string n = "미래인류", string i = "♀", int px = 0, int py = 0)
        : Monster(n, i, px, py) {}
    virtual ~Human() { cout << "[Human] "; }
    int getDirkey() { return _getche() == 224 ? _getche() : 0; }
    virtual void move(int** map, int maxx, int maxy) {
        if (_kbhit())
        {
            char ch = getDirkey();
            if (ch == Left)x--;
            else if (ch == Right)x++;
            else if (ch == Up)y--;
            else if (ch == Down)y++;
            else return;
            clip(maxx, maxy);
            eat(map);
        }
    }
};
class Tuman : public Human {
public:
    Tuman(string n = "미래투맨", string i = "좌", int px = 0, int py = 0)
        : Human(n, i, px, py) {}
    virtual ~Tuman() { cout << "[Tuman]"; }
    virtual void move(int** map, int maxx, int maxy, char a) {
        if (a == 'a' || a == 'A' || a == Left)x--;
        else if (a == 'd' || a == 'D' || a == Right)x++;
        else if (a == 'w' || a == 'W' || a == Up)y--;
        else if (a == 's' || a == 'S' || a == Down)y++;
        else return;
        clip(maxx, maxy);
        eat(map);
    }
};