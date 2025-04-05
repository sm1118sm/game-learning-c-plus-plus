#include "RussianRoulette.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

#define MAX_SIZE 10000  // �ִ� ũ�� ����

using namespace std;

int chamberSize, bulletCount, playerCount;
bool chamber[MAX_SIZE];  // źâ (��ź ���� ����)
int players[MAX_SIZE];   // ���� �÷��̾� ���
int remainingPlayers;    // ���� ���� �÷��̾� ��
int turn = 0;            // ���� ����

void playRussianRoulette() {

    cout << "źâ ũ�� �Է�: ";
    cin >> chamberSize;

    cout << "��ź ���� �Է�: ";
    cin >> bulletCount;

    cout << "������ �� �Է�: ";
    cin >> playerCount;


    if (chamberSize <= 0 || bulletCount <= 0 || playerCount <= 1 || bulletCount >= chamberSize) {
        cout << "�߸��� �Է��Դϴ�. ��ź ������ źâ���� ����, �����ڴ� 2�� �̻��̾�� �մϴ�.\n";
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

   
    cout << "\n���� ����!\n\n";

    while (remainingPlayers > 1 && bulletCount > 0) {
        int currentIndex = turn % remainingPlayers; 
        int player = players[currentIndex]; 
        int shot = turn % chamberSize; 

        cout << "Player " << player << " ��Ƽ踦 ����... ";

        if (chamber[shot]) {
            cout << "Player " << player << " Ż��!\n";

            for (int i = currentIndex; i < remainingPlayers - 1; i++) {
                players[i] = players[i + 1];
            }

            remainingPlayers--; 
            bulletCount--; 
            cout << "���� ��ź ����: " << bulletCount << "\n\n";
        }
        else {
            cout << "�����ߴ�!\n\n";
            turn++; 
        }
    }

    if (bulletCount == 0) {
        cout << "��ź�� ��� �Ҹ�Ǿ����ϴ�! ���� ���!\n";
        cout << "���� ����� ���: ";
        for (int i = 0; i < remainingPlayers; i++) {
            cout << "Player " << players[i] << " ";
        }
        cout << "\n";
    }
    else {
        cout << "\n����ڴ� Player " << players[0] << " �Դϴ�!\n";
    }
}
