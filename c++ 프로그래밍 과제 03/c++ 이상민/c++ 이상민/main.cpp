#include <iostream>
#include "RussianRoulette.h"
#include "speedAdd.h"
#include "speedGugu.h"

using namespace std;

int main() {

    bool repeat = true;

    while (repeat){
        char n;

        cout << "게임을 시작합니다 (1 : 러시안룰렛, 2 : 더하기, 3: 곱하기) : ";

        cin >> n;

        if (n == '1') {
            cout << '\n';
            cout << "러시안 룰렛 게임을 시작합니다" << '\n';
            playRussianRoulette();
            break;
        }

        else if (n == '2') {
            cout << '\n';
            cout << "더하기 게임을 시작합니다" << '\n';
            playAdd();
            break;
        }

        else if (n == '3') {
            cout << '\n';
            cout << "구구단 게임을 시작합니다" << '\n';
            playGugu();
            break;
        }

        else {
            cout << "\n";
            cout << "다시 입력해주세요" << '\n';
            cout << "\n";   
        }
    }


 

    return 0;
}