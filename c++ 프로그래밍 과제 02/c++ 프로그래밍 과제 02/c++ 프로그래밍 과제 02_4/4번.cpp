#include <iostream>
#include <conio.h>
using namespace std;

int main() {
    cout << "출제자> 맞출 숫자를 입력하세요 (0~100) : ";

    int number = 0;
    int chance = 1;
    int score = 100;
    int search = 0;
    char ch;
    int first = 0;
    int end = 100;

    while (true) {
        ch = _getch();

        if (ch == 13) {
            break;
        }

        if (ch >= '0' && ch <= '9') {
            cout << "*";
            number = number * 10 + (ch - '0');
        }
    }

    cout << "\n\n";

    while (true) {
        cout << "[ " << chance << "회 ] " << first << " ~ " << end << " 사이의 값 예측 = > ";

        search = 0;

        while (true) {
            ch = _getch();

            if (ch == 13) {
                if (search == 0) {
                    cout << "\n다시 입력하세요!\n";
                    break;
                }
                else {
                    break;
                }
            }
            else if (ch >= '0' && ch <= '9') {
                cout << ch;
                search = search * 10 + (ch - '0');
            }
        }

        if (search == number) {
            cout << "\n   성공 !!! 정답은 " << number << '\n';
            cout << "   최종 점수 = " << score;
            break;
        }
        else if (search < number && search != 0) {
            score -= 10;
            cout << "\n더 큰 숫자입니다!" << '\n';
            first = search;
        }
        else if (search > number && search != 0) {
            score -= 10;
            cout << "\n더 작은 숫자입니다!" << '\n';
            end = search;
        }

        if (search != 0) {
            chance++;
        }

        if (chance > 10) {
            cout << "\nGame Over" << '\n';
            cout << "정답은 " << number << "입니다." << '\n';
            break;
        }
    }

    return 0;
}
