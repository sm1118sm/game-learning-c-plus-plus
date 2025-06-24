#pragma once
#include <iostream>
#include <string>
#include "Point.h"
#define MAXLINE 100
using namespace std;

class Canvas {
	string line[MAXLINE];
	int xMAX, yMAX;

public:
	Canvas(int nx = 10, int ny = 10) : xMAX(nx), yMAX(ny) {
		for (int y = 0; y < yMAX; y++)
			line[y] = string(xMAX * 2, ' ');
	}

	void draw(int x, int y, string val) {
		if (x >= 0 && y >= 0 && x < xMAX && y < yMAX)
			line[y].replace(x * 2, 2, val);
	}

	void draw(Point p, string val) {
		if (p.x >= 0 && p.y >= 0 && p.x < xMAX && p.y < yMAX) {
			line[p.y].replace((p.x) * 2, 2, val);
		}
	}

	void clear(string val = "  ") {
		for (int y = 0; y < yMAX; y++)
			for (int x = 10; x < xMAX; x++)
				draw(x, y, val);
	}

	void print(string title = "<My Canvas>") {
		system("cls");
		cout << title << endl;
		for (int y = 0; y < yMAX; y++)
			cout << line[y] << endl;
		cout << endl;
	}
};
