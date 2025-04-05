#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <memory.h>
#include <time.h>
#include <ctype.h>

extern void playMineSweeper(int nBomb = 13);

struct PlayInfo
{
	char name[200];      //플레이어 이름
	int nMine;               //지뢰의 개수
	double tElapsed;      //게임 소요 시간
	double Score;         //게임 점수
};

extern void loadRanking(const char* filename);                     //랭킹을 저장하는 파일 읽기
extern void storeRanking(const char* filename);                     //랭킹을 저장하는 파일 쓰기
extern void printRanking();                                             //랭킹을 보여주는 함수
extern int addRanking(int total, double tElap, double score);      //랭킹을 추가해주는 함수
