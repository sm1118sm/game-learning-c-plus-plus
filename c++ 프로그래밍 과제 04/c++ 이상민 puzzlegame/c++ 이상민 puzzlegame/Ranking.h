#include <iostream>  
#include <windows.h>  
#include <cstdlib>    
#include <conio.h>     
#include <ctime>      

struct PlayInfo
{
	char name[200];
	int nMove;
	double tElapsed;
};
extern void loadRanking(const char* filename);
extern void storeRanking(const char* filename);
extern void printRanking();
extern int addRanking(int nMove, double tElap);
extern void ReplayShuffle();