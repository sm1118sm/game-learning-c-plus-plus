#pragma once
#include "Canvas.h"
#include "Matrix.h"
#include "Monster.h"
#include <Windows.h>
#include "VariousMonsters.h"
#include "Human.h"
#define MAXMONS 20

class MonsterWorld {

	Matrix world;
	int xMax, yMax, nMon, nMove;
	Monster* pMon[MAXMONS];
	Canvas canvas;

	int& Map(int x, int y) { return world.elem(x, y); }

	bool isDone() { return countItems() == 0; }

	int countItems() {
		int nItems = 0;
		for (int y = 0; y < yMax; y++)
			for (int x = 0; x < xMax; x++)
				if (Map(x, y) > 0) nItems++;
		return nItems;
	}

	void print() {
		canvas.clear();
		for (int y = 0; y < yMax; y++)
			for (int x = 0; x < xMax; x++) {
				if (Map(x, y) > 0) canvas.draw(x, y, "■");
				else canvas.draw(x, y, ". ");
			}
		for (int i = 0; i < nMon; i++)
			pMon[i]->draw(canvas);
		canvas.print("[Monster World (신인류 탄생)]");
		cerr << "전체 이동 횟수 = " << nMove << endl;
		cerr << "남은 아이템 수 " << countItems() << endl;
		for (int i = 0; i < nMon; i++)
			pMon[i]->print();
		Monster::printCount();
	}

	void checkStarvation() {
		for (int i = 0; i < nMon; i++) {
			if (pMon[i]->getEnergy() == 0) {
				delete pMon[i];
				cout << "에너지 고갈. 몬스터 한 마리가 사망합니다.";
				getchar();
				pMon[i] = new Monster;
				for (int j = i; j < nMon - 1; j++)
					pMon[j] = pMon[j + 1]; //마지막에 있는 몬스터를 해당위치에 지정
				Monster::mCount--;
				nMon--;
			}
		}
	}

public:
	MonsterWorld(int w, int h) : world(h, w), canvas(w, h), xMax(w), yMax(h) {
		nMon = 0;
		nMove = 0;
		for (int y = 0; y < yMax; y++)
			for (int x = 0; x < xMax; x++)
				Map(x, y) = 1;
	}
	~MonsterWorld() {
		for (int i = 0; i < nMon; i++)
			delete pMon[i];
	}

	void add(Monster* m) {
		if (nMon < MAXMONS) {
			pMon[nMon++] = m;
			Monster::mCount++;
		}
	}

	void play(int maxwalk, int wait) {
		print();
		cerr << "엔터를 누르세요...";
		getchar();
		for (int i = 0; i < maxwalk; i++) {
			for (int k = 0; k < nMon - 2; k++)
				pMon[k]->move(world.Data(), xMax, yMax);

			if (_kbhit()) {
				unsigned char ch = _getche();
				if (ch == 224) {
					ch = _getche();
					((Tuman*)(pMon[nMon - 1]))->move(world.Data(), xMax, yMax, ch);
				}
				else ((Tuman*)(pMon[nMon - 2]))->move(world.Data(), xMax, yMax, ch);
			}

			nMove++;
			print();
			checkStarvation();
			if (isDone()) break;
			if (Monster::mCount == 0) {
				print();
				break;
			}
			Sleep(wait);
		}
	}
};