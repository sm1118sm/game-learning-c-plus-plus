#include "Ranking.h"
#include <iostream>
using namespace std;

extern int playFifteenPuzzle();

int main()
{
    char num;
    while (true)
    {
        loadRanking("ranking.bin");
        int rank = playFifteenPuzzle();
        printRanking();
        storeRanking("ranking.bin");
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