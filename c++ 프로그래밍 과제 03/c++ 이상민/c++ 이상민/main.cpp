#include <iostream>
#include "RussianRoulette.h"
#include "speedAdd.h"
#include "speedGugu.h"

using namespace std;

int main() {

    bool repeat = true;

    while (repeat){
        char n;

        cout << "������ �����մϴ� (1 : ���þȷ귿, 2 : ���ϱ�, 3: ���ϱ�) : ";

        cin >> n;

        if (n == '1') {
            cout << '\n';
            cout << "���þ� �귿 ������ �����մϴ�" << '\n';
            playRussianRoulette();
            break;
        }

        else if (n == '2') {
            cout << '\n';
            cout << "���ϱ� ������ �����մϴ�" << '\n';
            playAdd();
            break;
        }

        else if (n == '3') {
            cout << '\n';
            cout << "������ ������ �����մϴ�" << '\n';
            playGugu();
            break;
        }

        else {
            cout << "\n";
            cout << "�ٽ� �Է����ּ���" << '\n';
            cout << "\n";   
        }
    }


 

    return 0;
}