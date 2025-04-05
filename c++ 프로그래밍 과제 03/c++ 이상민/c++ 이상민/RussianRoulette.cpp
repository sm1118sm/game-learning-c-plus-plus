#include "RussianRoulette.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

#define MAX_SIZE 10000  // 최대 크기 설정

using namespace std;

int chamberSize, bulletCount, playerCount;
bool chamber[MAX_SIZE];  // 탄창 (실탄 여부 저장)
int players[MAX_SIZE];   // 생존 플레이어 목록
int remainingPlayers;    // 현재 남은 플레이어 수
int turn = 0;            // 현재 차례

void playRussianRoulette() {

    cout << "탄창 크기 입력: ";
    cin >> chamberSize;

    cout << "실탄 개수 입력: ";
    cin >> bulletCount;

    cout << "참가자 수 입력: ";
    cin >> playerCount;


    if (chamberSize <= 0 || bulletCount <= 0 || playerCount <= 1 || bulletCount >= chamberSize) {
        cout << "잘못된 입력입니다. 실탄 개수는 탄창보다 적고, 참가자는 2명 이상이어야 합니다.\n";
        return;
    }

    remainingPlayers = playerCount; 

    
    for (int i = 0; i < chamberSize; i++) {
        chamber[i] = false; 
    }

    srand(time(0)); 
    int count = 0;
    while (count < bulletCount) {
        int pos = rand() % chamberSize;
        if (!chamber[pos]) { 
            chamber[pos] = true;
            count++;
        }
    }

    
    for (int i = 0; i < playerCount; i++) {
        players[i] = i + 1; 
    }

   
    cout << "\n게임 시작!\n\n";

    while (remainingPlayers > 1 && bulletCount > 0) {
        int currentIndex = turn % remainingPlayers; 
        int player = players[currentIndex]; 
        int shot = turn % chamberSize; 

        cout << "Player " << player << " 방아쇠를 당긴다... ";

        if (chamber[shot]) {
            cout << "Player " << player << " 탈락!\n";

            for (int i = currentIndex; i < remainingPlayers - 1; i++) {
                players[i] = players[i + 1];
            }

            remainingPlayers--; 
            bulletCount--; 
            cout << "남은 실탄 개수: " << bulletCount << "\n\n";
        }
        else {
            cout << "무사했다!\n\n";
            turn++; 
        }
    }

    if (bulletCount == 0) {
        cout << "실탄이 모두 소모되었습니다! 공동 우승!\n";
        cout << "공동 우승자 명단: ";
        for (int i = 0; i < remainingPlayers; i++) {
            cout << "Player " << players[i] << " ";
        }
        cout << "\n";
    }
    else {
        cout << "\n우승자는 Player " << players[0] << " 입니다!\n";
    }
}
