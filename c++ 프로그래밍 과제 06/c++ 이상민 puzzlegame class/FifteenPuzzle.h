#include "RankingBoard.h"
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <conio.h>
#include <ctime>

#define DIM 4 // 퍼즐 크기

using namespace std;

enum Direction { Left = 75, Right = 77, Up = 72, Down = 80 };
const int DirKey[4] = { Left, Right, Up, Down };

class FifteenPuzzle {
	int map[DIM][DIM];
	int x, y;
	int replay_x, replay_y;
	int nMove;
	char replay_select;
	clock_t tStart;
	int replay[2000];
	int replay_[2000];
	int replay_map[DIM][DIM];
	RankingBoard ranking;

	int getDirKey() {
		int key = _getche();
		return (key == 224) ? _getche() : 0;
	}

	void init()
	{
		for (int i = 0; i < DIM * DIM - 1; i++)
		{
			map[i / DIM][i % DIM] = i + 1;
		}

		map[DIM - 1][DIM - 1] = 0;
		x = DIM - 1;
		y = DIM - 1;

		srand((unsigned int)time(NULL));
		tStart = clock();
		nMove = 0;
	}

	void display()
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


	bool move(int dir)
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

	void shuffle(int nShuffle)
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
			Sleep(10);
		}
	}

	bool isDone()
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

	void ReplayShuffle()
	{
		for (int i = 0; i < DIM; i++)
		{
			for (int j = 0; j < DIM; j++)
			{
				map[i][j] = replay_map[i][j];
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

public:
	void play(const char* filename) {
		ranking.load(filename);
		init();
		display();
		ranking.print();

		cout << "\n퍼즐을 섞으려면 Enter를 누르세요...";
		_getche();
		shuffle(10);
		for (int i = 0; i < DIM; i++)
		{
			for (int j = 0; j < DIM; j++)
			{
				replay_map[i][j] = map[i][j];
			}
		}

		cout << "\n게임이 시작됩니다...";
		_getche();

		nMove = 0;
		tStart = clock();
		while (!isDone()) {
			move(getDirKey());
			display();
		}

		clock_t t1 = clock();
		double d = (double)(t1 - tStart) / CLOCKS_PER_SEC;

		ranking.add(nMove, d);
		ranking.store(filename);

		ranking.print();

		char num;

		while (true) {
			cout << "키를 누르세요 (게임 종료 : 0,  replay : 1) : ";
			num = _getche();
			if (num == '0')
			{
				break;
			}
			else if (num == '1')
			{
				ReplayShuffle();
				break;
			}
			else
			{
				continue;
			}
		}

	}


};
