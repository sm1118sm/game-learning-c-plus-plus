#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <memory.h>
#include <time.h>
#include <ctype.h>

extern void playMineSweeper(int nBomb, int rows);

struct PlayInfo
{
	char name[200];
	int nMine;
	double tElapsed;
	double Score;
};

extern void loadRanking(const char* filename);
extern void storeRanking(const char* filename);
extern void printRanking();
extern int addRanking(int total, double tElap, double score);