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
        cout << "Ű�� �������� (���� ���� : 0,  replay : 1) : ";
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