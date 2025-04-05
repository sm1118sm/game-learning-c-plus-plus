#include "Ranking.h"
#include <iostream>
using namespace std;
#define DIM 4

enum Direction
{
    Left = 75, Right = 77, Up = 72, Down = 80
};

static int DirKey[4] = { Left,Right,Up,Down };
static int map[DIM][DIM];
static int remap[DIM][DIM];
static int x, y;
static int nMove;
static clock_t tStart;
static int replay[1000] = { 0, };

static void init()
{
    for (int i = 0; i < DIM * DIM - 1; i++)
    {
        map[i / DIM][i % DIM] = i + 1;
    }

    map[DIM - 1][DIM - 1] = 0;
    x = DIM - 1;
    y = DIM - 1;

    srand(time(NULL));
    tStart = clock();
    nMove = 0;
}

static void display()
{
    system("cls");
    cout << "\tFifteen Puzzle\n        ";
    cout << "--------------\n        ";
    for (int r = 0; r < DIM; r++)
    {
        for (int c = 0; c < DIM; c++)
        {
            if (map[r][c] > 0)
            {
                if (map[r][c] >= 10) {
                    cout << " " << map[r][c];
                }

                else {
                    cout << "  " << map[r][c];
                }

            }
            else
            {
                cout << "   ";
            }
        } cout << "\n\t";
    }
    cout << "--------------\n       ";
    clock_t t1 = clock();
    double d = (double)(t1 - tStart) / CLOCKS_PER_SEC;
    cout << fixed;
    cout.precision(1);
    cout << "\n\t이동 횟수 :      " << nMove << "\n\t소요 시간 :      " << d << "\n\n";
}

static bool move(int dir)
{
    if (dir == Right && x > 0)
    {
        map[y][x] = map[y][x - 1];
        map[y][--x] = 0;
        replay[nMove] = Right;
    }
    else if (dir == Left && x < DIM - 1)
    {
        map[y][x] = map[y][x + 1];
        map[y][++x] = 0;
        replay[nMove] = Left;
    }
    else if (dir == Up && y < DIM - 1)
    {
        map[y][x] = map[y + 1][x];
        map[++y][x] = 0;
        replay[nMove] = Up;
    }
    else if (dir == Down && y > 0)
    {
        map[y][x] = map[y - 1][x];
        map[--y][x] = 0;
        replay[nMove] = Down;
    }
    else
    {
        return false;
    }

    nMove++;
    return true;
}

static void shuffle(int nShuffle)
{
    for (int i = 0; i < nShuffle; i++)
    {
        int key = DirKey[rand() % 4];

        if (move(key) == false)
        {
            i--;
            continue;
        }
        display();
        Sleep(50);
    }
}

void ReplayShuffle()
{
    for (int i = 0; i < DIM; i++)
    {
        for (int j = 0; j < DIM; j++)
        {
            map[i][j] = remap[i][j];
            if (map[i][j] == 0)
            {
                x = j;
                y = i;
            }
        }
    }

    int count = nMove;
    nMove = 0;
    tStart = clock();
    display();

    for (int i = 0; i < count; i++)
    {
        int key = replay[i];
        move(key);
        display();
        Sleep(100);
    }
}

static bool isDone()
{
    for (int r = 0; r < DIM; r++)
    {
        for (int c = 0; c < DIM; c++)
        {
            if (map[r][c] != r * DIM + c + 1)
            {
                return (r == DIM - 1) && (c == DIM - 1);
            }
        }
    }
    return true;
}

static int getDirkey()
{
    return _getche() == 224 ? _getche() : 0;;
}

int playFifteenPuzzle()
{
    init();
    display();
    printRanking();
    cout << " 퍼즐을 섞어주세요 (엔터)...";
    _getche();
    shuffle(10);
    for (int i = 0; i < DIM; i++)
    {
        for (int j = 0; j < DIM; j++)
        {
            remap[i][j] = map[i][j];
        }
    }
    cout << "\n 게임이 시작됩니다...";
    _getche();

    nMove = 0;
    tStart = clock();

    while (!isDone())
    {
        int dir = getDirkey();
        move(dir);
        display();
    }

    clock_t t1 = clock();
    double d = (double)(t1 - tStart) / CLOCKS_PER_SEC;
    return addRanking(nMove, d);
}